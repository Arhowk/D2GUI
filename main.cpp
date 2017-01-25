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

#include "ui/dialogs/argument_selector/sargumentselector.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
   // SBetaLayout h;
   // h.show();=
    DGUIKeyDatabase::init();
    DGUIFile::CreateBetaFile();
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

    SArgumentSelector selector(&window, new DGUIArgument(0, new QJsonValue(1), 0));
    return a.exec();
}
