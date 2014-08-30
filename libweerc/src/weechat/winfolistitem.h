#ifndef WINFOLISTITEM_H
#define WINFOLISTITEM_H

#include "wobject.h"
#include "winfolistitemelement.h"
#include <QList>

class WInfolistItem
{
public:
    WInfolistItem();
    qint64 getCount();
    void setCount(qint64 count);
    QList<WInfolistItemElement> getItemElement();
    void setItemElement(QList<WInfolistItemElement>);
    virtual int parse(const QByteArray& data, uint start);
private:
    qint64 count;
    QList<WInfolistItemElement> itemElement;
};

#endif // WINFOLISTITEM_H
