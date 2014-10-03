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

    QString getValue() const { return m_value; }
    void setValue(const QString &value) { m_value = value; }

    bool isNull() const { return m_null; }
    void setNull(bool null) { m_null = null; }

    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void) const;
};

#endif // WSTRING_H
