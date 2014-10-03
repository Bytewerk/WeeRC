// vim: ts=4 sw=4 expandtab

#include <QLocale>

#include "wlonginteger.h"

WLongInteger::WLongInteger()
    : WObject(WObject::LongInteger)
{
}

int WLongInteger::parse(const QByteArray &data, uint start)
{
    unsigned char len = data[start];

    QByteArray numdata = data.mid(start + 1, len);
    m_value = numdata.toLongLong();

    return len + 1; // bytes processed
}

QString WLongInteger::repr(void) const
{
    return "[" + WObject::typeToStr(m_objectType) + ":" + QString::number(m_value) + "]";
}
