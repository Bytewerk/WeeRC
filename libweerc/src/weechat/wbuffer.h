// vim: ts=4 sw=4 expandtab

#ifndef WBUFFER_H
#define WBUFFER_H

#include "wobject.h"

class WBuffer : public WObject
{
private:
    QByteArray m_value;
    bool       m_null;

public:
    WBuffer();

    QByteArray getValue() { return m_value; }
    void setValue(const QByteArray &value) { m_value = value; }

    bool isNull() { return m_null; }
    void setNull(bool null) { m_null = null; }

    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void);
};

#endif // WBUFFER_H
