#ifndef WTIME_H
#define WTIME_H

#include "wobject.h"

class WTime : public WObject
{
public:
    WTime();
    qint64 getValue();
    void setValue(qint64 value);
    virtual int parse(const QByteArray& data, uint start);
private:
    qint64 value;
};

#endif // WTIME_H
