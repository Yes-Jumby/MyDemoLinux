#include "EmitSignalTwo.h"

CEmitSignalTwo::CEmitSignalTwo()
{
    m_str = "CEmitSignalTwo";
}
void CEmitSignalTwo::emitAsignal()
{
    emit myTestSignal(m_str);
    emit myTestSignal("Two");
}
