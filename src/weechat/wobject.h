#ifndef WOBJECT_H
#define WOBJECT_H

#include <QByteArray>

class WObject
{
public:
    enum ObjectType {
        Array,
        Buffer,
        Char,
        Hashtable,
        Hdata,
        Info,
        Infolist,
        Integer,
        Longinteger,
        Pointer,
        String,
        Time
    };
protected:
    ObjectType m_objectType;
public:
    WObject();
    WObject(ObjectType ot);
    virtual int parse(const QByteArray& data, uint start) = 0;
    ObjectType getObjectType();
};

#endif // WOBJECT_H
