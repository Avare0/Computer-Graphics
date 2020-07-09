#include "draw.h"


Draw::Draw()
{

}

void Draw::init_scene(QGraphicsView *gv)
{
    this->scene = new QGraphicsScene(gv);
    gv->setScene(scene);
    this->scene->setSceneRect(0,0,gv->height(),gv->width());
}

void Draw::draw_line(QPointF start, QPointF end, QColor color) {
    scene->addLine(start.x(),start.y(), end.x(),end.y(), color);
}

void Draw::draw_line(QLine line, QColor color)
{
    QPen pen;
    pen.setColor(color);
    pen.setWidth(2);
    scene->addLine(line, pen);
}

void Draw::draw_rect(QPoint start, QPoint end, QColor color)
{
    scene->addRect(QRect(start,end), QPen(color));
}

void Draw::clear(QGraphicsView *gv)
{
    delete this->scene;
    this->scene = new QGraphicsScene(gv);
    gv->setScene(scene);
    this->scene->setSceneRect(0,0,gv->height(),gv->width());
}

void Draw::draw_line(double x_start, double y_start, double x_end, double y_end, QColor color)
{
    QPen pen;
    pen.setColor(color);
    pen.setWidth(2);
    scene->addLine(x_start, y_start, x_end,y_end, pen);
}

