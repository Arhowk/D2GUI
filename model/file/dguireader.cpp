#include "model/file/dguireader.h"
#include <QBuffer>
#include <QFile>

DGUIReader::WriteFile(DGUIFile * file)
{
    QBuffer * buf = new QBuffer;
    //Fill the buffer

    //Open the file
    QFile * f = new QFile("C:\temp.dgui");
    f->open(QIODevice::WriteOnly);

    //Write the file

    //Close the file

}

DGUIFile DGUIReader::OpenFile(QString * path)
{

}

DGUIReader::DGUIReader()
{

}
