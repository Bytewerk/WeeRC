// vim: ts=4 sw=4 expandtab

#ifndef WTIME_H
#define WTIME_H

#include "wobject.h"

class WTime : public WObject
{
private:
    qint64 m_value;

public:
    WTime();
    qint64 getValue() { return m_value; }
    void setValue(qint64 value) { m_value = value; }
    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void);
};

#endif // WTIME_H
