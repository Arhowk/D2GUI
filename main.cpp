#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QImage>
#include <QDir>
#include <QToolBar>

#include "smainlayout.h"
#include "ui/layout_shared/foldline.h"
#include "ui/layout_shared/stoolbar.h"

#include "model/triggers/dguifile.h"
#include "model/triggers/dguikeydatabase.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
   // SBetaLayout h;
   // h.show();=
    qDebug("0");
    DGUIKeyDatabase::init();
    DGUIFile::CreateBetaFile();
    qDebug("3");
    qDebug("%d", DGUIKeyDatabase::argumentDatabase.length());
    qDebug("%d", DGUIKeyDatabase::triggerDatabase.length());
    QMainWindow window;
    SToolbar::CreateToolbar(&window);
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
