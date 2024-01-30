#include "barras.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Barras w;
    w.show();
    return a.exec();
}
