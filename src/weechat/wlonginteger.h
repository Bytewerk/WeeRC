#ifndef WLONGINTEGER_H
#define WLONGINTEGER_H

#include "wobject.h"

class WLongInteger : public WObject
{
public:
    WLongInteger();
    qint64 getValue();
    void setValue(qint64);
//    void parseFromNetworkData(const QByteArray& data);
    virtual int parse(const QByteArray& data, uint start);
private:
    qint64 value;
};

#endif // WLONGINTEGER_H
