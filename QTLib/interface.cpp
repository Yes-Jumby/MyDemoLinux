#include "interface.h"
#include <QDebug>
CInterface::CInterface()
{
}

CInterface::~CInterface()
{
}

void CInterface::test()
{
    QString strcmd = "interface test!!!";
    qDebug()<<strcmd;
}
