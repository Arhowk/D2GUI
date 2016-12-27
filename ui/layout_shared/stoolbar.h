#ifndef STOOLBAR_H
#define STOOLBAR_H

#include <QWidget>
#include <QMainWindow>

class SToolbar : QWidget
{
    Q_OBJECT
public:
    void static CreateToolbar(QMainWindow* window);


private:
    SToolbar();

public slots:
    void newFile();
};

#endif // STOOLBAR_H
