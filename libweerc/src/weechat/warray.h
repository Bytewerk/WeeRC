#ifndef WARRAY_H
#define WARRAY_H

#include "wobject.h"
#include <QList>

class WArray : public WObject
{
public:
    WArray();
    virtual int parse(const QByteArray& data, uint start);
private:
    QList<WObject*> data;
};

#endif // WARRAY_H
