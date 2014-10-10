// vim: ts=4 sw=4 expandtab

#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include "WeechatMessages/wrelaymessage.h"

#include <QObject>

class MessageParser : public QObject
{
    Q_OBJECT

public:
    MessageParser();
    virtual ~MessageParser();

    virtual int parse(const QByteArray &data, int start);

signals:
    void messageParsed(WRelayMessagePtr message);
};

#endif // MESSAGEPARSER_H
