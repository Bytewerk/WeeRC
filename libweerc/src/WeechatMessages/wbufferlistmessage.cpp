// vim: ts=4 sw=4 expandtab

#include <QDebug>

#include "../WeechatObjects/wstring.h"
#include "../WeechatObjects/winteger.h"

#include "wbufferlistmessage.h"

WBufferListMessage::WBufferListMessage()
    : WRelayMessage(WRelayMessage::BufferList)
{
}

int WBufferListMessage::parse(const QByteArray &data, int start)
{
    // check if this message really contains a hdata
    Q_ASSERT(data.mid(start, 3) == "hda");
    start += 3;

    // parse the hdata from the message
    WHdata hdata;

    int dataRead = hdata.parse(data, start);

    for(int i = 0; i < hdata.getItems().size(); i++) {
        const WHdata::HdataItem &item = hdata.getItems()[i];

        WChatBufferPtr buffer(new WChatBuffer());

        buffer->fillFromHdataItem(hdata, item);

        m_bufferInfo.append(buffer);
    }

    return dataRead;
}

void WBufferListMessage::debugPrint(void)
{
    qDebug() << "Contents of WBufferListMessage";

    for(const WChatBufferPtr &buffer: m_bufferInfo) {
        buffer->debugPrint();
    }
}
