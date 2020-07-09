#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "draw.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QMouseEvent>
#include <string>
#include <vector>
#include "line.h"
#include "rect.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int count = 0;
    Draw graphics;
    QPointF a;
    QVector<line> lines;
    QVector <QPointF> edges;
    int len_edges = 0;
    bool poly_flag = false;
    void cyrus_back(QPointF p1, QPointF p2);
    double scalar(QPointF v1, QPointF v2);
    double max(double one, double two);
    double min(double one, double two);

    void mousePressEvent(QMouseEvent *e);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
