#include <QApplication>
#include "View/mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    return app.exec();
}