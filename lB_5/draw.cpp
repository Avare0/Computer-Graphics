#include "draw.h"
#include "ui_mainwindow.h"

draw::draw(Ui::MainWindow *ui)
{
    this->scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    this->scene->setSceneRect(0,0,300,300);
}
