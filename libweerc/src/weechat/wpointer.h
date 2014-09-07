// vim: ts=4 sw=4 expandtab

#ifndef WPOINTER_H
#define WPOINTER_H

#include "wobject.h"

class WPointer : public WObject
{
private:
    qint64 m_value;

public:
    WPointer();
    qint64 getValue() { return m_value; }
    void setValue(qint64 value) { m_value = value; }
    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void);
};

#endif // WPOINTER_H
