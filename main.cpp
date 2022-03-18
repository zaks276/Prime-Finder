#include "findprimes.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindPrimes w;
    w.show();

    return a.exec();
}
