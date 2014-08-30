#ifndef WSTRING_H
#define WSTRING_H

#include "wobject.h"
#include <QString>

class WString : public WObject
{
public:
    WString();
    QString getValue();
    void setValue(QString value);
//    void parseFromNetworkData(const QByteArray& data);
    virtual int parse(const QByteArray& data, uint start);
private:
    QString value;
};

#endif // WSTRING_H
