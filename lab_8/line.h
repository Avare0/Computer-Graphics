#ifndef LINE_H
#define LINE_H
#include <string>
#include "rect.h"
#include <QGraphicsView>
class line
{
public:
    line() {};
    line(QPointF start, QPointF end);
    QPointF start;
    QPointF end;
    bool draw = false;
    void compute_code(Rect rect);
    void multiply();
    bool check_point_in_rect(int x, int y, Rect rect);
    int binary_search(Rect rect);
};

#endif // LINE_H
