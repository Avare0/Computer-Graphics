#ifndef RECT_H
#define RECT_H

#include <QGraphicsView>
class Rect
{
public:
    Rect();
    Rect(QPoint tl, QPoint br);

    QPoint top_left;
    QPoint top_right;
    QPoint bottom_left;
    QPoint bottom_right;
};

#endif // RECT_H
