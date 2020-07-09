#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMouseEvent>
#include "dots.h"
#include <QPainter>



namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene *scene;

    void mousePressEvent(QMouseEvent *e);
    Dots points_arr;

    void draw_link(link l);
    void fill_figure();
    int flag_dot_zatr = 0;
    QPoint zatr;
    void pause(int ms);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    void graphics();
    void addPoint(int x, int y);
};
#endif // MAINWINDOW_H
