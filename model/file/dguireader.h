#ifndef DGUIREADER_H
#define DGUIREADER_H

#include <QString>
#include "model/triggers/dguifile.h"

class DGUIReader
{
public:
    DGUIReader();
    DGUIFile OpenFile(QString *);
    void WriteFile(DGUIFile *);

};

#endif // DGUIREADER_H
