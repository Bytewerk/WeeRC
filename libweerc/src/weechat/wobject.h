// vim: ts=4 sw=4 expandtab

#ifndef WOBJECT_H
#define WOBJECT_H

#include <QByteArray>
#include <QString>

#include <memory>

class WObject
{
public:
    enum ObjectType {
        Array,
        Buffer,
        Char,
        HashTable,
        Hdata,
        Info,
        Infolist,
        Integer,
        LongInteger,
        Pointer,
        String,
        Time,
        Type,
        Unknown
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

    /*!
     * Get a textual representation of the object.
     *
     * \returns A QString representing the object's data.
     */
    virtual QString repr(void) const = 0;

    static ObjectType typeFromStr(const QString &str);
    static QString typeToStr(ObjectType str);
};

typedef std::shared_ptr<WObject> WObjectPtr;

#endif // WOBJECT_H
