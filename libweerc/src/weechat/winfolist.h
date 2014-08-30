#ifndef WINFOLIST_H
#define WINFOLIST_H

#include "wobject.h"
#include "winfolistitem.h"

class WInfolist : public WObject
{
public:
    WInfolist();
//    void parseFromNetworkData(const QByteArray& data);
    qint64 getCount();
    void setCount(qint64 count);
    QList<WInfolistItem> getItems();
    void setItems(QList<WInfolistItem> items);
    virtual int parse(const QByteArray& data, uint start);
private:
    qint64 count;
    QList<WInfolistItem> items;
};

#endif // WINFOLIST_H
