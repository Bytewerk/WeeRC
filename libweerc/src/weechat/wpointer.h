// vim: ts=4 sw=4 expandtab

#ifndef WPOINTER_H
#define WPOINTER_H

#include "wobject.h"

class WPointer : public WObject
{
public:
    typedef qint64 value_type;

private:
    value_type m_value;

public:
    WPointer();
    value_type getValue() const { return m_value; }
    void setValue(value_type value) { m_value = value; }
    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void) const;
};

#endif // WPOINTER_H
