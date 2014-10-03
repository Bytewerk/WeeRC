// vim: ts=4 sw=4 expandtab

#ifndef WTYPE_H
#define WTYPE_H

#include "wobject.h"

class WType : public WObject
{
private:
    WObject::ObjectType m_value;

public:
    WType();

    WObject::ObjectType getValue() const { return m_value; };

    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void) const;
};

#endif // WTYPE_H
