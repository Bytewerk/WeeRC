// vim: ts=4 sw=4 expandtab

#include <QtEndian>
#include <QString>
#include <QDebug>

#include "weechat/wrelaymessagefactory.h"
#include "weechat/wstring.h"

#include "messageparser.h"

MessageParser::MessageParser()
{
}

int MessageParser::parse(const QByteArray &data, int start)
{
    qint32 len_be = 0;

    // extract the data
    for(int i = 0; i < 4; i++) {
        len_be |= data[start + i] << (8 * i);
    }

    qint32 msglen = qFromBigEndian(len_be);

    // check array length
    if(data.length() < start + msglen) {
        return -1;
    }

    // calculate start of next field
    start += 4;

    bool compression = data[start];

    start += 1;

    QByteArray msgdata = data.mid(start, msglen - 5); // message header is included in length (5 bytes)
    start = 0;

    // TODO: if compression, decompress msgdata


    // message id
    WString wstr;
    start += wstr.parse(msgdata, start);

    qDebug() << "Message ID: " << (wstr.isNull() ? "NULL" : wstr.getValue());

    while(start < msglen) {
        QByteArray type = msgdata.mid(start, 3);
        start += 3;

        WRelayMessagePtr message = WRelayMessageFactory::fromTypeString(type);
        start += message->parse(msgdata, start);
        message->debugPrint();
    }

    return msglen;
}
