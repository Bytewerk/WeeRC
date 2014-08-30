#ifndef WINFO_H
#define WINFO_H

#include "wobject.h"
#include <QString>

class WInfo : public WObject
{
public:
    WInfo();
//    void parseFromNetworkData(const QByteArray& data);
    QString getName();
    void setName(QString name);
    QString getValue();
    void setValue(QString value);
    virtual int parse(const QByteArray& data, uint start);
private:
    QString name;
    QString value;
};

#endif // WINFO_H
