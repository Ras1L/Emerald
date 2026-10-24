#include "Presentation/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Presentation::MainWindow w;

    w.show();

    return QApplication::exec();
}
