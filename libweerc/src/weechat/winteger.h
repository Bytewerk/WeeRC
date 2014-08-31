// vim: ts=4 sw=4 expandtab

#ifndef WINTEGER_H
#define WINTEGER_H

#include "wobject.h"

class WInteger : public WObject
{
private:
    qint32 m_value;

public:
    WInteger();

    qint32 getValue() { return m_value; };
    void setValue(qint32 v) { m_value = v; };

    virtual int parse(const QByteArray& data, uint start);
};

#endif // WINTEGER_H
