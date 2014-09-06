// vim: ts=4 sw=4 expandtab

#ifndef WARRAY_H
#define WARRAY_H

#include "wobject.h"
#include <QList>

class WArray : public WObject
{
public:
    typedef QList<WObjectPtr> ObjectList;

private:
    ObjectList          m_data;
    WObject::ObjectType m_dataType;

public:
    WArray();

    WObject::ObjectType getDataType() { return m_dataType; }
    const ObjectList&   getData()     { return m_data; }

    virtual int parse(const QByteArray& data, uint start);
};

#endif // WARRAY_H
