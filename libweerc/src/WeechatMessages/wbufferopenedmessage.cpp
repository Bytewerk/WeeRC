// vim: ts=4 sw=4 expandtab

#include <QDebug>

#include "../WeechatObjects/wstring.h"
#include "../WeechatObjects/winteger.h"

#include "wbufferopenedmessage.h"

WBufferOpenedMessage::WBufferOpenedMessage()
    : WRelayMessage(WRelayMessage::BufferOpened)
{
}

int WBufferOpenedMessage::parse(const QByteArray &data, int start)
{
    // check if this message really contains a hdata
    Q_ASSERT(data.mid(start, 3) == "hda");
    start += 3;

    // parse the hdata from the message
    WHdata hdata;

    int dataRead = hdata.parse(data, start);

    if(hdata.getItems().size() >= 1) {
        const WHdata::HdataItem &item = hdata.getItems()[0];

        m_bufferPointer = dynamic_cast<const WPointer*>(item.ppath[0].get())->getValue();

        for(int j = 0; j < item.entries.size(); j++) {
            WObjectPtr obj = item.entries[j];
            QString key = hdata.getKeyTypes()[j].first;

            if(key == "number") {
                m_bufferNumber = dynamic_cast<const WInteger*>(obj.get())->getValue();
            } else if(key == "full_name") {
                m_bufferFullName = dynamic_cast<const WString*>(obj.get())->getValue();
            } else {
                qDebug() << "Unhandled key" << key;
            }
        }
    }

    return dataRead;
}

void WBufferOpenedMessage::debugPrint(void)
{
    qDebug() << "Contents of WBufferOpenedMessage";
    qDebug() << "  pointer:  " << m_bufferPointer;
    qDebug() << "  full_name:" << m_bufferFullName;
    qDebug() << "  number:   " << m_bufferNumber;
}
