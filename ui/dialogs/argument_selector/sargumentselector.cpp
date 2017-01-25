#include <QBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include "model/triggers/dguiargument.h"

#include "sargumentselector.h"

SArgumentSelector::SArgumentSelector(QWidget *parent, DGUIArgument* replacingArg)
        :QDialog(parent)

{
    QBoxLayout *layout= new QBoxLayout(QBoxLayout::LeftToRight);
    QVBoxLayout *left = new QVBoxLayout();
    QBoxLayout *right= new QBoxLayout(QBoxLayout::TopToBottom);

    QRadioButton *presetRadio = new QRadioButton("&Preset");
    QRadioButton *localRadio = new QRadioButton("&Local Variable");
    QRadioButton *globalsRadio = new QRadioButton("&Global Variable");
    QRadioButton *functionRadio = new QRadioButton("&Function");
    QRadioButton *valueRadio = new QRadioButton("&Value");

    QLabel *label = new QLabel();
    label->setText("left top");
    QLabel *label2 = new QLabel();
    label2->setText("left bottom");

    left->addWidget(presetRadio);
    left->addWidget(localRadio);
    left->addWidget(globalsRadio);
    left->addWidget(functionRadio);
    left->addWidget(valueRadio);


    QLabel *label4 = new QLabel();
    label4->setText("right bottom");

    QWidget *obj_left = new QWidget ();
    obj_left->setLayout(left);

    QWidget *obj_right = new QWidget ();
    obj_right->setLayout(right);

    QComboBox *comboBox = new QComboBox;
    comboBox->addItem(tr("item 1"));
    comboBox->addItem(tr("item 2"));
    comboBox->addItem(tr("item 3"));
    right->addWidget(comboBox);

    left->setSpacing(0);
    left->setMargin(0);

    layout->addWidget(obj_left, 1);
    layout->addWidget(obj_right, 3);

    setMinimumSize(200,200  );
    setLayout(layout);
    setWindowTitle(tr("Hello WOrld"));
    setModal(true);
    show();
}
