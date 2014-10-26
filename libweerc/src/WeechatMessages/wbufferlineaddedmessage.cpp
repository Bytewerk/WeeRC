// vim: ts=4 sw=4 expandtab

#include <QDebug>

#include "wbufferlineaddedmessage.h"

WBufferLineAddedMessage::WBufferLineAddedMessage()
    : WRelayMessage(WRelayMessage::BufferLineAdded)
{
}

int WBufferLineAddedMessage::parse(const QByteArray &data, int start)
{
    // check if this message really contains a hdata
    Q_ASSERT(data.mid(start, 3) == "hda");
    start += 3;

    // parse the hdata from the message
    WHdata hdata;

    int dataRead = hdata.parse(data, start);

    const WHdata::HdataItem &item = hdata.getItems()[0];

    m_bufferLine.fillFromHdataItem(hdata, item);

    return dataRead;
}

void WBufferLineAddedMessage::debugPrint(void)
{
    qDebug() << "Contents of WBufferLineAddedMessage";

    m_bufferLine.debugPrint();
}
