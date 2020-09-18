#ifndef EMITSIGNALONE_H
#define EMITSIGNALONE_H
#include "EmitSignalBase.h"

class CEmitSignalOne : public CEmitSignalBase
{
    Q_OBJECT
public:
    CEmitSignalOne();
    virtual void emitAsignal();
};

#endif // EMITSIGNALONE_H
