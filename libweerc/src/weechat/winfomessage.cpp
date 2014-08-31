// vim: ts=4 sw=4 expandtab

#include <QDebug>

#include "winfomessage.h"

WInfoMessage::WInfoMessage()
    : WRelayMessage(WRelayMessage::Info)
{
}

int WInfoMessage::parse(const QByteArray &data, int start)
{
    return m_info.parse(data, start);
}

void WInfoMessage::debugPrint(void)
{
    qDebug() << m_info.getName() << " => " << m_info.getValue();
}
