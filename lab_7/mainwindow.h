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
    Rect rect;
    QPointF a;
    QVector<line> lines;
    bool rect_flag = false;

    void mousePressEvent(QMouseEvent *e);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
