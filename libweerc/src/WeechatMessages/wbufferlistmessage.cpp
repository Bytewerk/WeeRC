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

        BufferInfo bi;

        bi.pointer = dynamic_cast<const WPointer*>(item.ppath[0].get())->getValue();

        for(int j = 0; j < item.entries.size(); j++) {
            WObjectPtr obj = item.entries[j];
            QString key = hdata.getKeyTypes()[j].first;

            if(key == "number") {
                bi.number = dynamic_cast<const WInteger*>(obj.get())->getValue();
            } else if(key == "full_name") {
                bi.full_name = dynamic_cast<const WString*>(obj.get())->getValue();
            } else {
                qDebug() << "Unexpected key" << key;
            }
        }

        m_bufferInfo.append(bi);
    }

    return dataRead;
}

void WBufferListMessage::debugPrint(void)
{
    qDebug() << "Contents of WBufferListMessage";

    for(const BufferInfo &bi: m_bufferInfo) {
        qDebug() << "  - " << bi.number << bi.pointer << bi.full_name;
    }
}
