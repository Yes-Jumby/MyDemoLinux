#include "EmitSignalOne.h"

CEmitSignalOne::CEmitSignalOne()
{
    m_str = "CEmitSignalOne";
}
void CEmitSignalOne::emitAsignal()
{
    emit myTestSignal(m_str);
    emit myTestSignal("One");
}
