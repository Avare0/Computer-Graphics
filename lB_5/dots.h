#ifndef DOTS_H
#define DOTS_H
#include <QGraphicsView>
#include "ui_mainwindow.h"
#include <QEventLoop>
#include <QTimer>
struct point {
    double x;
    double y;
};

struct link {
    point *p1;
    point *p2;
    int nmax;
    double x;
    double dy;
    double dx;
    bool is_active = false;
};

class Dots : public QMainWindow
{
public:
    Dots();
    point points[20];
    link links[20];
    void draw_point(point l);
    void draw_link1(link l);
    QGraphicsScene *scene;
    link active_links[20];
    int flag_new_fig = 0;
    int len_new = 0;
    int len_active = 0;
    int len_points = 0;
    int len_links = 0;
    void set_scene(QGraphicsView *gv);
    void add_point(int x, int y);
    void sort_nmax();
    void set_next_step(link &a);
    void draw_link(int x1, int y1, int x2, int y2);
    void pop(int i);
    void fill_figure();
    void append();
    int next_node_pos;
    void find_nmax();
    void set_properties(link &l);
    void clear_scene(QGraphicsView *gv);
    void add_new_fig_point(int x, int y);
    void fill_figure_zatravka(QGraphicsView *gv);
    void fill_row(QImage *img, int *x, int y, QStack<QPoint> *stack, int xr, int *xt);
    void fill_figure_zatravka(QGraphicsView *gv, QPoint zatravka_point);
    void fill_row(QImage *img, int *x, int y, QStack<QPoint> *stack, int xr, int *xt, QColor fill, QColor edge);
};


#endif // DOTS_H
