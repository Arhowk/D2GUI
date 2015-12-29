#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QImage>

#include "smainlayout.h"
#include "ui/layout_shared/foldline.h"
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
    QGridLayout gg;
    gg.addWidget(new SMainLayout(0, &window), 0, 0);
    gg.setSpacing(3);
    gg.setMargin(3);
    widget.setLayout(&gg);
    window.showMaximized();


    return a.exec();
}
