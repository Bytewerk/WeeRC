#ifndef WHASHTABLE_H
#define WHASHTABLE_H

#include "wobject.h"
#include <QMap>

class WHashtable : public WObject
{
public:
    WHashtable();
    WObject::ObjectType getKeysType();
    void setKeysType(WObject::ObjectType keysType);
    WObject::ObjectType getValuesType();
    void setValuesType(WObject::ObjectType valuesType);
    qint8 getCount();
    void setCount(qint8 count);
    virtual int parse(const QByteArray& data, uint start);
private:
    WObject::ObjectType keysType;
    WObject::ObjectType valuesType;
    qint8 count;
    QMap<WObject*, WObject*> hashtable;
};

#endif // WHASHTABLE_H
