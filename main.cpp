#include "smainlayout.h"
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include "layout_shared/foldline.h"
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

    SMainLayout layout( &widget, &window );

    window.show();

    return a.exec();
}
