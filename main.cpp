#include "sbetalayout.h"
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include "foldline.h"
#include <QImage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

   // SBetaLayout h;
   // h.show();=

    QMainWindow window;
    QWidget widget;
    window.setCentralWidget(&widget);

    SBetaLayout layout( &widget, &window );

    window.show();

    return a.exec();
}
