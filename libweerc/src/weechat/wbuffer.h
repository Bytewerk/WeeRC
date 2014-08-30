#ifndef WBUFFER_H
#define WBUFFER_H

#include "wobject.h"

class WBuffer : public WObject
{
public:
    WBuffer();
    QByteArray getValue();
    void setValue(QByteArray value);
    virtual int parse(const QByteArray& data, uint start);
private:
    QByteArray value();
};

#endif // WBUFFER_H
