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
    char p_start[5] = "0000";
    char p_end[5] = "0000";
    QPointF start;
    QPointF end;
    bool visible;
    QLine inside;
    void compute_code(Rect rect);
    void multiply();
    bool check_point_in_rect(int x, int y, Rect rect);
    int binary_search(Rect rect);
//    char* code_point(QPoint p, Rect rect);
//    bool multiply_codes(char code1[5], char code2[5]);
};

#endif // LINE_H
