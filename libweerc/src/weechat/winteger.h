#ifndef WINTEGER_H
#define WINTEGER_H

#include "wobject.h"

class WInteger : public WObject
{
public:
    WInteger();
    qint32 getValue();
    void setValue(qint32);
//    void parseFromNetworkData(const QByteArray& data);
    virtual int parse(const QByteArray& data, uint start);
private:
    qint32 value;
};

#endif // WINTEGER_H
