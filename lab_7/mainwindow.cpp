#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphics.init_scene(ui->graphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QPointF pt = ui->graphicsView->mapToScene(e->pos());
    if (count == 0) {
        a = pt;
        count++;
    }
    else {
        if (!rect_flag) {
            graphics.draw_line(a, pt, Qt::black);
            lines.push_back(line(a, pt));
            a = pt;
            count = 0;
        } else {
            graphics.draw_rect(QPoint(a.x(), a.y()), QPoint(pt.x(), pt.y()), Qt::red);
            rect = Rect(QPoint(a.x(), a.y()), QPoint(pt.x(), pt.y()));
            a = pt;
            count = 0;
            rect_flag = 0;
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    rect_flag = true;
}
//        std::cout << x.p_start << " | " << x.p_end << " | " << x.visible<< std::endl;
void MainWindow::on_pushButton_2_clicked()
{

    for (auto &x: lines) {
        x.compute_code(rect);
        x.multiply();
    }
    int length= lines.length();
    for (int i = 0; i < lines.length(); i++) {
        lines[i].compute_code(rect);
        lines[i].multiply();
        if (lines[i].visible == false) {
            lines.removeAt(i);
            i--;
        } else {
            lines[i].binary_search(rect);
            graphics.draw_line(lines[i].inside, Qt::blue);
        }
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    lines.clear();
    graphics.clear(ui->graphicsView);
}
