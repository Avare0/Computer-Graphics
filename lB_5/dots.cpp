#include "dots.h"
#include <math.h>
#include <QThread>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QStack>

Dots::Dots()
{
    this->len_points = 0;
    this->len_links = 0;
    this->len_new = 0;

}

void Dots::set_scene(QGraphicsView *gv)
{
    this->scene = new QGraphicsScene(gv);
    gv->setScene(scene);
    this->scene->setSceneRect(0,0,gv->height(),gv->width());
}

void Dots::clear_scene(QGraphicsView *gv)
{
    delete this->scene;
    this->scene = new QGraphicsScene(gv);
    gv->setScene(scene);
    this->scene->setSceneRect(0,0,gv->height(),gv->width());
}

double max(double y1, double y2) {
    if (y1 > y2)
        return y1;
    return y2;
}

double max_x(double x1, double y1,double x2, double y2) {
    if (y1 > y2)
        return x1;
    return x2;
}

double min_x(double x1, double y1,double x2, double y2) {
    if (y1 < y2)
        return x1;
    return x2;
}

double x_coord(double x1, double y1, double x2, double y2, double y) {
    return (x2 - x1) * (y - y1) / (y2 - y1) + x1;
}

double min(double y1, double y2) {
    if (y1 < y2)
        return y1;
    return y2;
}

void Dots::set_properties(link &l) {
    l.nmax = min(l.p1->y, l.p2->y);
    l.dy = fabs(l.p1->y - l.p2->y);
    l.x = min_x(l.p1->x,l.p1->y,l.p2->x, l.p2->y);
    l.dx = 1.0 * (max_x(l.p1->x,l.p1->y,l.p2->x, l.p2->y) - l.x) / l.dy;
}

void Dots::add_point(int x ,int y) {
    points[len_points].x = x;
    points[len_points].y = y;

    draw_point(points[len_points]);

    links[len_links].p1 = &points[len_points];
    links[len_links].p2 = &points[0];

    if (len_links != 0) {
        links[len_links - 1].p2 = &points[len_points];
        set_properties(links[len_links - 1]);
        draw_link1(links[len_links - 1]);
        set_properties(links[len_links]);
    }

    this->len_points++;
    this->len_links++;

}

void Dots::add_new_fig_point(int x ,int y) {
    points[len_points].x = x;
    points[len_points].y = y;

    draw_point(points[len_points]);

    links[len_links].p1 = &points[len_points];
    links[len_links].p2 = &points[flag_new_fig];

    if (len_new != 0) {
        links[len_links - 1].p2 = &points[len_points];
        set_properties(links[len_links - 1]);
        draw_link1(links[len_links - 1]);
        set_properties(links[len_links]);
    }
    else
        this->len_new++;

    this->len_points++;
    this->len_links++;

}

void Dots::sort_nmax() {
    link temp;
    for (int i = 0; i < len_links - 1; i++) {
               for (int j = 0; j < len_links - i - 1; j++) {
                   if (links[j].nmax > links[j + 1].nmax ) {
                       temp = links[j];
                       links[j] = links[j + 1];
                       links[j + 1] = temp;
                   }
               }
           }
}

void Dots::find_nmax() {
    int nmax = links[0].nmax;
    for (int i = 0; i < len_links; i++)
        if (links[i].nmax == nmax) {
            active_links[len_active] = links[i];
            this->len_active++;
        }
    this->next_node_pos = len_active;
}

void Dots::pop(int pos) {
    for (int i = pos; i < len_active - 1; i++)
        active_links[i] = active_links[i + 1];
    this->len_active--;
}

void Dots::append() {
    active_links[len_active] = links[next_node_pos];
    this->len_active++;
    this->next_node_pos++;
}

void Dots::set_next_step(link &a) {
    a.x += a.dx;
    a.dy -= 1;
}

void Dots::fill_figure() {
    int n = links[0].nmax;
    while (len_active != 0) {

        for (int i = 0; i < len_active; i += 2) {
            draw_link(active_links[i].x, n, active_links[i + 1].x, n);
            set_next_step(active_links[i]);
            set_next_step(active_links[i + 1]);

            if (active_links[i].dy == 0)
                pop(i);

            if (active_links[i + 1].dy == 0)
                pop(i + 1);

        }
        n += 1;

        while (n == links[next_node_pos].nmax)
        {
            append();
        }

        QEventLoop el;
        QTimer t;
        connect(&t, SIGNAL(timeout()), &el, SLOT(quit()));
        t.start(50);
        el.exec();
    }

}


void Dots::fill_figure_zatravka(QGraphicsView *gv, QPoint zatravka_point) {
    QPixmap pixMap = gv->grab();
    QImage img = pixMap.toImage();

    QColor fill = Qt::red;
    QColor edge = Qt::black;
    QStack<QPoint> stack;
        QPoint p = zatravka_point;
        stack.append(p);

        while (!stack.isEmpty())
        {
            p = stack.pop();
            int x = p.x();
            int y = p.y();
            int xt = p.x();

            img.setPixelColor(x, y, fill);
            x -= 1;
            while (img.pixelColor(x, y) != edge)
            {
                img.setPixelColor(x, y, fill);
                x -= 1;
            }

            int xl = x + 1;
            x = xt;
            x += 1;

            while (img.pixelColor(x, y) != edge)
            {
                img.setPixelColor(x, y, fill);
                x += 1;
            }
            int xr = x - 1;
            y += 1;
            x = xl;
            fill_row(&img, &x, y, &stack, xr, &xt, fill, edge);
            y -= 2;
            x = xl;
            fill_row(&img, &x, y, &stack, xr, &xt, fill, edge);


            QEventLoop el;
            QTimer t;
            connect(&t, SIGNAL(timeout()), &el, SLOT(quit()));
            t.start(10);
            el.exec();
            pixMap = QPixmap::fromImage(img);
            this->scene->addPixmap(pixMap);
        }
    pixMap = QPixmap::fromImage(img);
    this->scene->addPixmap(pixMap);
}

void Dots::fill_row(QImage *img, int *x, int y, QStack<QPoint> *stack, int xr, int *xt, QColor fill, QColor edge) {
    while (*x <= xr)
    {
        int flag = 0;
        while (img->pixelColor(*x, y) != edge &&
            img->pixelColor(*x, y) != fill && *x <= xr)
        {
            if (!flag)
                flag = 1;
            *x += 1;
        }

        if (flag == 1)
        {
            if (*x == xr && img->pixelColor(*x, y) != edge &&
                    img->pixelColor(*x, y) != fill)
                stack->append(QPoint(*x, y));
            else
                stack->append(QPoint(*x - 1, y));
            flag = 0;
        }

        *xt = *x;
        while ((img->pixelColor(*x, y) == edge ||
               img->pixelColor(*x, y) == fill) && *x < xr)
            *x += 1;
        if (*x == *xt)
            *x += 1;

    }
}


void Dots::draw_link(int x1, int y1, int x2, int y2) {
    this->scene->addLine(x1,y1, x2,  y2, QPen(Qt::red));
}

void Dots::draw_link1(link l) {
    this->scene->addLine(l.p1->x,l.p1->y, l.p2->x,  l.p2->y, QPen(Qt::black));
}


void Dots::draw_point(point l) {
    this->scene->addEllipse(l.x,l.y, 1,  1);
}


