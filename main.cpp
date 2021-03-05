#include "configdialog.h"

#include <QApplication>
#include<QGraphicsView>
#include<QGraphicsScene>
#include"puzzlepiece.h"
#include"puzzlefield.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConfigDialog w;
    w.show();
    return a.exec();
}
