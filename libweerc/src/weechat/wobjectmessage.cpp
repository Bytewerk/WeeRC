// vim: ts=4 sw=4 expandtab

#include <QDebug>

#include "wobjectfactory.h"

#include "wobjectmessage.h"

WObjectMessage::WObjectMessage()
    : WRelayMessage(WRelayMessage::Object)
{
}

int WObjectMessage::parse(const QByteArray &data, int start)
{
    QByteArray type = data.mid(start, 3);
    m_object = WObjectFactory::fromTypeString(type);

    return 3 + m_object->parse(data, start + 3);
}

void WObjectMessage::debugPrint(void)
{
    qDebug() << m_object->repr();
}
