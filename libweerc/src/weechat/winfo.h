// vim: ts=4 sw=4 expandtab

#ifndef WINFO_H
#define WINFO_H

#include "wobject.h"
#include <QString>

class WInfo : public WObject
{
private:
    QString m_name;
    QString m_value;
public:
    WInfo();

    QString getName() { return m_name; }
    void setName(QString name) { m_name = name; }

    QString getValue() { return m_value; }
    void setValue(QString value) { m_value = value; }

    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void);
};

#endif // WINFO_H
