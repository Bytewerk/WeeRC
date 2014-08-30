#ifndef WPOINTER_H
#define WPOINTER_H

#include "wobject.h"

class WPointer : public WObject
{
public:
    WPointer();
    qint64 getValue();
    void setValue(qint64);
    virtual int parse(const QByteArray& data, uint start);
private:
    qint64 value;
};

#endif // WPOINTER_H
