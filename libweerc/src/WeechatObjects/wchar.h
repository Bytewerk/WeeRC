// vim: ts=4 sw=4 expandtab

#ifndef WCHAR_H
#define WCHAR_H

#include "wobject.h"
#include <QChar>

class WChar : public WObject
{
private:
    QChar m_value;

public:
    WChar();
    QChar getValue() const { return m_value; }
    void setValue(QChar value) { m_value = value; }

    virtual int parse(const QByteArray& data, uint start);

    virtual QString repr(void) const;
};

#endif // WCHAR_H
