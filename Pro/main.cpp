#include "notatnik.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notatnik w;
    w.show();
    return a.exec();
}
