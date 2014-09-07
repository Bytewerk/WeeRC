// vim: ts=4 sw=4 expandtab

#include "wtime.h"

WTime::WTime()
    : WObject(WObject::Time)
{
}

int WTime::parse(const QByteArray &data, uint start)
{
    unsigned char len = data[start];

    QByteArray numdata = data.mid(start + 1, len);
    m_value = numdata.toLongLong();

    return len + 1; // bytes processed
}

QString WTime::repr(void)
{
    return "[" + WObject::typeToStr(m_objectType) + ":" + QString::number(m_value) + "]";
}
