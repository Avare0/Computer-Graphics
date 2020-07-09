#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphics.init_scene(ui->graphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cyrus_back(QPointF p1, QPointF p2)
{
    double first = 0;
    double second = 1;
    QPointF d(p2.x() - p1.x(),p2.y() - p1.y() );

    for (int i = 0; i < len_edges; i++) {
        QPointF udal_kon_tochki(p1.x() - edges[i].x(),p1.y() - edges[i].y());
        QPointF norm;
        if (i + 1 == len_edges)
            norm = QPointF(edges[0].y() - edges[i].y(),-1 * (edges[0].x() - edges[i].x()) );
        else
            norm = QPointF(edges[i + 1].y() - edges[i].y(),-1 * (edges[i + 1].x() - edges[i].x()));

        double d_s = scalar(d, norm);
        double w_s = scalar(udal_kon_tochki, norm);
        double k =  - w_s / d_s;
        if (d_s == 0 && w_s < 0) {
                return ;
        } else if (d_s > 0) {
                if (k > 1)
                    return ;
                else
                    first = max(first, k);
            }
            else if (d_s < 0) {
                if (k < 0)
                    return ;
                else
                    second = min(second, k);
            }
        }
    if (first <= second)
        graphics.draw_line(p1.x() + (p2.x() - p1.x())*second,
                           p1.y() + (p2.y() - p1.y())*second,
                           p1.x() + (p2.x() - p1.x())*first,
                           p1.y() + (p2.y() - p1.y())*first, Qt::blue);
}

double MainWindow::scalar(QPointF v1, QPointF v2)
{
        return v1.x() * v2.x() + v1.y() * v2.y();
    }

    double MainWindow::max(double one, double two)
    {
        if (one > two)
            return one;

        return two;
    }
    double MainWindow::min(double one, double two)
    {
        if (one < two)
            return one;

        return two;
    }

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QPointF pt = ui->graphicsView->mapToScene(e->pos());
    if (poly_flag) {
        edges.append(pt);
        len_edges++;
        if (len_edges > 1) {
            graphics.draw_line(edges[len_edges - 2], pt, Qt::red);
        }
    } else {
        if (count == 0) {
            a = pt;
            count++;
        } else {
                graphics.draw_line(a, pt, Qt::black);
                lines.push_back(line(QPoint(a.x(), a.y()), QPoint(pt.x(), pt.y())));
                a = pt;
                count = 0;

        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    poly_flag = true;
}
//        std::cout << x.p_start << " | " << x.p_end << " | " << x.visible<< std::endl;
void MainWindow::on_pushButton_2_clicked()
{

    for(auto i: lines) {
        cyrus_back(i.start, i.end);
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    lines.clear();
    graphics.clear(ui->graphicsView);
}

void MainWindow::on_pushButton_5_clicked()
{
    graphics.draw_line(edges[len_edges - 1],edges[0], Qt::red);
    poly_flag = false;
}
