#include "rect.h"

Rect::Rect()
{

}

Rect::Rect(QPoint tl, QPoint br)
{
    top_left = tl;
    bottom_right = br;
    top_right = QPoint(br.x(), tl.y());
    bottom_left = QPoint(tl.x(), br.y());
}
