// vim: ts=4 sw=4 expandtab

#ifndef WLONGINTEGER_H
#define WLONGINTEGER_H

#include "wobject.h"

class WLongInteger : public WObject
{
public:
    WLongInteger();

    qint64 getValue() const { return m_value; }
    void setValue(qint64 value) { m_value = value; }

    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void) const;

private:
    qint64 m_value;
};

#endif // WLONGINTEGER_H
