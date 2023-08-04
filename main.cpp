#include "mainwindow.h"
#include "dvd.h"
#include<iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Articolo a("Pane", "pane verde", 3, 2020);
     DVD d("Pane", "pane verde", 3, 2020);
     string x = d.getDescrizione();
     std::cout<< x;

    return a.exec();
}
