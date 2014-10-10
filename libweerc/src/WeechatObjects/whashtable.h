#ifndef WHASHTABLE_H
#define WHASHTABLE_H

#include "wobject.h"
#include <QMap>

class WHashTable : public WObject
{
public:
    WHashTable();

    WObject::ObjectType getKeysType() const { return m_keysType; }
    WObject::ObjectType getValuesType() const { return m_valuesType; }
    int getCount() const { return m_hashtable.size(); }

    virtual int parse(const QByteArray& data, uint start);
		QString repr(void) const;

private:
    WObject::ObjectType m_keysType;
    WObject::ObjectType m_valuesType;

    QMap<WObjectPtr, WObjectPtr> m_hashtable;
};

#endif // WHASHTABLE_H
