// vim: ts=4 sw=4 expandtab

#ifndef WOBJECT_H
#define WOBJECT_H

#include <QByteArray>

#include <memory>

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
    ObjectType getObjectType();

    /*!
     * Parse the object from the given QByteArray, beginning at start.
     *
     * \returns  The number of bytes processed.
     */
    virtual int parse(const QByteArray& data, uint start) = 0;
};

typedef std::unique_ptr<WObject> WObjectPtr;

#endif // WOBJECT_H
