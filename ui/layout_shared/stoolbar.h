#ifndef STOOLBAR_H
#define STOOLBAR_H

#include <QWidget>
#include <QMainWindow>

class SToolbar : QWidget
{
    Q_OBJECT
public:
    static CreateToolbar(QMainWindow* window);


private:
    SToolbar();

public slots:
    newFile();
};

#endif // STOOLBAR_H