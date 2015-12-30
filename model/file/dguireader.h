#ifndef DGUIREADER_H
#define DGUIREADER_H

#include <QString>
#include "model/triggers/dguifile.h"

class DGUIReader
{
public:
    DGUIReader();
    DGUIFile OpenFile(QString *);
    WriteFile(DGUIFile *);

};

#endif // DGUIREADER_H
