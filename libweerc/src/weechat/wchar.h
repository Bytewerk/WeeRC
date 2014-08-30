#ifndef WCHAR_H
#define WCHAR_H

#include "wobject.h"
#include <QChar>

class WChar : public WObject
{
public:
    WChar();
    QChar getValue();
    void setValue(QChar value);
    virtual int parse(const QByteArray& data, uint start);
private:
    QChar m_value;
};

#endif // WCHAR_H
