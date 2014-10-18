// vim: ts=4 sw=4 expandtab

#include <QDebug>

#include "wbufferclosingmessage.h"

WBufferClosingMessage::WBufferClosingMessage()
    : WRelayMessage(WRelayMessage::BufferClosing)
{
}

int WBufferClosingMessage::parse(const QByteArray &data, int start)
{
    // check if this message really contains a hdata
    Q_ASSERT(data.mid(start, 3) == "hda");
    start += 3;

    // parse the hdata from the message
    WHdata hdata;

    int dataRead = hdata.parse(data, start);

    if(hdata.getItems().size() >= 1) {
        const WHdata::HdataItem &item = hdata.getItems()[0];

        m_buffer.fillFromHdataItem(hdata, item);
    }

    return dataRead;
}

void WBufferClosingMessage::debugPrint(void)
{
    qDebug() << "Contents of WChatBufferClosingMessage";
    m_buffer.debugPrint();
}
