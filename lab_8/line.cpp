#include "line.h"
#include <string.h>
line::line(QPointF start, QPointF end)
{
    this->start = start;
    this->end = end;
}

//void line::compute_code(Rect rect)
//{
//    if (start.y() < rect.top_left.y())
//        p_start[0] = '1';
//    if (start.y() > rect.bottom_left.y())
//        p_start[1] = '1';
//    if (start.x() < rect.top_left.x())
//        p_start[3] = '1';
//    if (start.x() > rect.top_right.x())
//        p_start[2] = '1';


//    if (end.y() < rect.top_left.y())
//        p_end[0] = '1';
//    if (end.y() > rect.bottom_left.y())
//        p_end[1] = '1';
//    if (end.x() < rect.top_left.x())
//        p_end[3] = '1';
//    if (end.x() > rect.top_right.x())
//        p_end[2] = '1';
//}

//void line::multiply()
//{
//    char result[5] = "0000";
//    for (int i = 0; i < 4; i++)
//        if (!(p_end[i] == '0' || p_start[i] == '0'))
//            result[i] = '1';
//    if (strcmp(result, "0000") == 0)
//        visible = true;
//    else
//        visible = false;
//}

bool line::check_point_in_rect(int x, int y, Rect rect)
{
    if (x > rect.top_left.x() &&
            x < rect.top_right.x() &&
            y > rect.top_left.y() &&
            y < rect.bottom_left.y())
        return true;
    return false;
}

//int line::binary_search(Rect rect)
//{
//    QLine line = QLine(start.x(), start.y(), end.x(), end.y());
//    QPoint cen = line.center();
//    while(line.dy() > 2) {
//        if (check_point_in_rect(cen.x(), cen.y(), rect))
//            line.setP1(cen);
//        else
//            line.setP2(cen);
//         cen = line.center();
//    }


//    QPoint p1(line.center());
//    if (strcmp(p_start, "0000") == 0) {
//        inside = QLine(p1.x(), p1.y(), start.x(), start.y());
//        return 1;
//    }
//    else if (strcmp(p_end, "0000") == 0) {
//        inside = QLine(p1.x(), p1.y(), end.x(), end.y());
//        return 1;
//    }


//    line = QLine(start.x(), start.y(), end.x(), end.y());
//    cen = line.center();
//    line.setP2(cen);
//    cen = line.center();
//    while(line.dy() > 3) {
//    if (check_point_in_rect(cen.x(), cen.y(), rect))
//    line.setP2(cen);
//    else
//    line.setP1(cen);
//    cen = line.center();
//    }
//    QPoint p2(line.center());
//    inside = QLine(p1,p2);
//    return 0;
//}





