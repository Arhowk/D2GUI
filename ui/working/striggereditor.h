#ifndef STRIGGEREDITOR_H
#define STRIGGEREDITOR_H

#include <QWidget>

class STriggerEditor : public QWidget
{
    Q_OBJECT
public:
    explicit STriggerEditor(QWidget *parent = 0);
    static STriggerEditor *instance;
    static STriggerEditor* getInstance();

    int changeFile(QString);
signals:

public slots:
    onLinkClicked(QString);
};

#endif // STRIGGEREDITOR_H
