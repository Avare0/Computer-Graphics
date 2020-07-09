#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(600,250);
    QPen pen(Qt::white);
    pen.setBrush(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);

    int r = 50;

    for (r = 50; r < 100 ; r+= 10)
        {
            double d = 1.0 / (double) r;
            int x, y;
            double t = 0;
            while (t <= M_PI_2 + d) {
            x = (round(r * cos(t)));
            y = (round(r * sin(t)));
            painter.drawPoint(x, y);
            painter.drawPoint(-x, y);
            painter.drawPoint(x, -y);
            painter.drawPoint(-x, -y);
            t += d;
        }

    }
//    double radius = 5;


//    double step = 0.01;
//    std::cout << step << std::endl;
//    for (radius = 50; radius < 150; radius += 10)
//    {

//        double a = 100;
//        double b = 50;
//   for (b = 100,a = 50; a < 150; a += 10, b += 10)
//        for (double i = 0; i < 360; i += step) {
//            painter.drawPoint(a*cos(i * 3.14 / 180 ), b * sin(i* 3.14 / 180));
//        };

//    for (radius = 50; radius < 150; radius += 10)
//    {
//      for (double i = -radius; i < radius; i += step)
//          painter.drawPoint(QPointF(i, sqrt(radius*radius - i * i)));
//      for (double i = -radius; i < radius; i += step)
//          painter.drawPoint(QPointF(i, -sqrt(radius* radius - i * i)));
//    }
//    int a = 8;
//    int b = 7;

//          for (double i = 0; i < b + 1; i += 1)
//              painter.drawPoint(QPointF(i, b * sqrt(radius*radius - i * i /a / a)));
//          for (double i = 0; i < a + 1; i += 1)
//              painter.drawPoint(QPointF(b * sqrt(radius* radius - i * i / b / b), i));

// Bres circle
//    int x0 = 0, y0 = 0;
//for (radius = 50; radius <= 150; radius += 10) {
//    int x = 0;
//    int y = radius;
//    int dx = 2 - 2 * radius;
//    int err = 0;
//    while(y >= 0) {
//        painter.drawPoint(x0 + x, y0 + y);
//        painter.drawPoint(x0 + x, y0 - y);
//        painter.drawPoint(x0 - x, y0 + y);
//        painter.drawPoint(x0 - x, y0 - y);
//        err = 2 * (dx + y) - 1;
//        if(dx < 0 && err <= 0) {
//            x++;
//            dx += 2 * x + 1;
//            continue;
//        }
//        err = 2 * (dx - x) - 1;
//        if(dx > 0 && err > 0) {
//            y--;
//            dx += 1 - 2 * y;
//            continue;
//        }
//        x++;
//        dx += 2 * (x - y);
//        y--;
//    }
//}

    // Bres ellipse
//    double b = 100;
//    double a = 200;
//    int x0 = 0, y0 = 0;
//    for (b = 100,a = 200; a <= 350; a += 30, b += 30) {
//            int x = 0;
//            int y = b;
//            a = a * a;
//            int dx = round(b * b / 2 - a * b * 2 + a / 2);
//            b = b*b;
//            int err = 0;
//            while(y >= 0) {
//                painter.drawPoint(x, y);
//                painter.drawPoint(x, -y);
//                painter.drawPoint(-x, y);
//                painter.drawPoint(- x, -y);
//                err = 2 * (dx + a * y) - a;
//                if(dx < 0 && err <= 0) {
//                    x++;
//                    dx += 2 * x * b + b;
//                    continue;
//                }
//                err = 2 * (dx - b*x) - b;
//                if(dx > 0 && err > 0) {
//                    y--;
//                    dx -= 2 * a * y + a;
//                    continue;
//                }
//                x++;
//                dx += 2 * (b * x - a * y) + a + b;
//                y--;
//            }
//            a = sqrt(a);
//            b = sqrt(b);
//    }

//    Middle Circle
//    int x0 = 0, y0 = 0;
//    double r = 100;
//    for (r = 50; r < 150; r += 10) {
//    double x = 0;
//    double y = r;
//    double p = 5 / 4 - r;
//    while (x <= y) {
//        painter.drawPoint(x0 + x, y0 + y);
//        painter.drawPoint(x0 + x, y0 - y);
//        painter.drawPoint(x0 - x, y0 + y);
//        painter.drawPoint(x0 - x, y0 - y);
//        painter.drawPoint(x0 + y, y0 + x);
//        painter.drawPoint(x0 + y, y0 - x);
//        painter.drawPoint(x0 - y, y0 + x);
//        painter.drawPoint(x0 - y, y0 - x);


//        x++;
//        if (p < 0)
//            p += 1 + 2 * x;
//        else {
//            p += 5 + 2 * x - 2 * y;
//            y--;
//        }
//    }
//}

//        Middle Ellipse
//        int x0 = 0, y0 = 0;
//        double r = 100;
//        double a = 100, b = 200;

//        for (b = 100,a = 50; a < 150; a += 10, b += 10) {
//        double x = 0;
//        double y = b;
//        double p = b * b - a * a * b + 0.25 * a * a;
//        a = a * a;
//        b = b * b;
//        while (2 * b * x < 2 * a * y) {
//            painter.drawPoint(x0 + x, y0 + y);
//            painter.drawPoint(x0 + x, y0 - y);
//            painter.drawPoint(x0 - x, y0 + y);
//            painter.drawPoint(x0 - x, y0 - y);


//            x++;
//            if (p < 0)
//                p += 2 * b * x + b;
//            else {
//                y--;
//                p += 2 * b * x - 2 * a * y + b;
//            }

//        }
//        p = b * (x + 0.5) * (x + 0.5) + a * (y - 1) * (y - 1) - a * b;

//        while (y >= 0) {
//            painter.drawPoint(x0 + x, y0 + y);
//            painter.drawPoint(x0 + x, y0 - y);
//            painter.drawPoint(x0 - x, y0 + y);
//            painter.drawPoint(x0 - x, y0 - y);
//            y--;
//            if (p > 0)
//                p -= 2 * a * y + a;
//            else {
//                x++;
//                p += 2 * b * x - 2 * a * y + a;
//            }
//        }
//        a = sqrt(a);
//        b = sqrt(b);

//    }

}

