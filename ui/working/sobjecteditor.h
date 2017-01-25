#ifndef SOBJECTEDITOR_H
#define SOBJECTEDITOR_H
#include <QString>
#include "model/objects/dgobjectdataset.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QPushButton>
#include <QLineEdit>
#include <QScrollArea>
#include <QLabel>

class SObjectEditor : public QScrollArea
{
       Q_OBJECT
public:
    explicit SObjectEditor(QWidget *parent = 0);

    QVBoxLayout *mainLayout, *widgetViewLayout, *listView, *iconSection, *descSection;
    QHBoxLayout *header, *headerBar;
    QWidget *headerWidget;
    QLabel *image;
    QPushButton *changeImage;

    QLineEdit *name, *desc, *mid, *bot;

    void showIcon(bool show = true);
    void showChangeIconButton(bool show = true);
    void showDescriptions(QString upperDescription, QString middleDescription="", QString lowerDescription="");
    void appendSet(QString name, DGObjectDataSet *set);
signals:
public slots:

};

#endif // SOBJECTEDITOR_H
