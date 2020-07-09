#ifndef DRAW_H
#define DRAW_H
#include "line.h"
class Draw
{
public:
    Draw();

    QGraphicsScene *scene;

    void init_scene(QGraphicsView *gv);
    void draw_line(QPointF start, QPointF end, QColor color);
    void draw_line(QLine line, QColor color);
    void draw_rect(QPoint start, QPoint end, QColor color);
    void clear(QGraphicsView *gv);
};

#endif // DRAW_H
