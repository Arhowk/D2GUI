#include "model/triggers/dguifile.h"
#include "model/triggers/dguiline.h"
#include "dguikeydatabase.h"
DGUIFile::DGUIFile()
{

}

DGUIFile DGUIFile::CreateBetaFile()
{
    DGUILine * event1;
    DGUILine * event2;
    DGUILine * condition1;
    DGUILine * condition2;
    DGUILine * action1;
    DGUILine * action2;
    DGUILine * action3;

    DGUILine protoEvt1 = DGUIKeyDatabase::getKeyWithIndex(0);
    event1 = protoEvt1.branch();
    event1->setArgument(0, new DGUIArgument(0, new QString("-1")));
    event1->setArgument(1, new DGUIArgument(0, new QString("-1")));
    event1->setArgument(2, new DGUIArgument(0, new QString("1")));
    qDebug(event1->toPrintString());
}
