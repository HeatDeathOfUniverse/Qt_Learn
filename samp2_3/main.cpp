#include "qwdialogmanual.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWDialogManual w;
    w.show();
    return a.exec();
}
