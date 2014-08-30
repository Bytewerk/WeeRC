#ifndef WHDATA_H
#define WHDATA_H

#include "wobject.h"

class WHdata : public WObject
{
public:
    WHdata();
//    void parseFromNetworkData(const QByteArray& data);
    virtual int parse(const QByteArray& data, uint start);
};

#endif // WHDATA_H
