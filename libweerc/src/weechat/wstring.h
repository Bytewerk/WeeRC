// vim: ts=4 sw=4 expandtab

#ifndef WSTRING_H
#define WSTRING_H

#include "wobject.h"
#include <QString>

class WString : public WObject
{
private:
    QString m_value;
    bool    m_null;

public:
    WString();

    QString getValue() { return m_value; }
    void setValue(const QString &value) { m_value = value; }

    bool isNull() { return m_null; }
    void setNull(bool null) { m_null = null; }

    virtual int parse(const QByteArray& data, uint start);
};

#endif // WSTRING_H
