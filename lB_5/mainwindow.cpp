#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dots.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    points_arr.set_scene(ui->graphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::mousePressEvent(QMouseEvent *e)
{

    QPointF pt = ui->graphicsView->mapToScene(e->pos());
    if (flag_dot_zatr == 1) {
        this->zatr = QPoint(pt.x() - 20, pt.y() - 30);
        points_arr.scene->addEllipse(pt.x() - 20, pt.y() - 30, 1, 1);
    }
    else {
    if (true) {
        points_arr.add_point(pt.x() - 20, pt.y() - 30);
        QTableWidgetItem *x = new QTableWidgetItem(QString::number(pt.x() - 20));
        QTableWidgetItem *y = new QTableWidgetItem(QString::number(pt.y() - 30));
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, x);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, y);
    }

    else if (points_arr.flag_new_fig != 0) {
        points_arr.add_new_fig_point(pt.x() - 20, pt.y() - 30);
        QTableWidgetItem *x = new QTableWidgetItem(QString::number(pt.x() - 20));
        QTableWidgetItem *y = new QTableWidgetItem(QString::number(pt.y() - 30));
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, x);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, y);
    }
    }
}



//void MainWindow::fill_figure() {
//    for (int i = 0; i < points_arr.len_links_for_fill; i++)
//        draw_link(points_arr.links_for_fill[i]);
//}


void MainWindow::on_pushButton_clicked()
{
    points_arr.draw_link1(points_arr.links[points_arr.len_links - 1]);
    points_arr.fill_figure_zatravka(ui->graphicsView, zatr);

//    points_arr.sort_nmax();
//    points_arr.find_nmax();
//    points_arr.fill_figure();
}



void MainWindow::on_pushButton_2_clicked()
{
    points_arr.clear_scene(ui->graphicsView);
    this->flag_dot_zatr = 0;
    points_arr.len_points = 0;
    points_arr.len_links = 0;
    points_arr.len_active = 0;
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    this->flag_dot_zatr = 1;

}

void MainWindow::on_pushButton_9_clicked()
{
    points_arr.scene->addEllipse(ui->lineEdit_3->text().toInt() - ui->lineEdit_6->text().toInt() / 2,
                                 ui->lineEdit_4->text().toInt() - ui->lineEdit_5->text().toInt() / 2,
                                 ui->lineEdit_5->text().toInt(),
                                 ui->lineEdit_6->text().toInt(), QPen(Qt::yellow));
}

void MainWindow::on_pushButton_10_clicked()
{
    points_arr.scene->addEllipse(ui->lineEdit_7->text().toInt() - ui->lineEdit_8->text().toInt() / 2,
                                 ui->lineEdit_10->text().toInt() - ui->lineEdit_8->text().toInt() / 2,
                                 ui->lineEdit_8->text().toInt() * 2,
                                 ui->lineEdit_8->text().toInt() * 2, QPen(Qt::yellow));
}
