#ifndef WINFOLISTITEMELEMENT_H
#define WINFOLISTITEMELEMENT_H

#include "wobject.h"
#include <QString>

class WInfolistItemElement : public WObject
{
public:
    WInfolistItemElement();
    QString getName();
    void setName(QString name);
    QString getValue();
    void setValue(QString value);
    virtual int parse(const QByteArray& data, uint start);
private:
    QString name;
    WObject *value;
};

#endif // WINFOLISTITEMELEMENT_H
