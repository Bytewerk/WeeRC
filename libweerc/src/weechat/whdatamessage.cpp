// vim: ts=4 sw=4 expandtab

#include <QDebug>

#include "whdatamessage.h"

WHdataMessage::WHdataMessage()
    : WRelayMessage(WRelayMessage::Hdata)
{
}

int WHdataMessage::parse(const QByteArray &data, int start)
{
    return m_info.parse(data, start);
}

void WHdataMessage::debugPrint(void)
{
    qDebug() << m_info.repr();
}
