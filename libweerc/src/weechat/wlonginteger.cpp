// vim: ts=4 sw=4 expandtab

#include <QLocale>

#include "wlonginteger.h"

WLongInteger::WLongInteger()
    : WObject(WObject::Longinteger)
{
}

int WLongInteger::parse(const QByteArray &data, uint start)
{
    unsigned char len = data[start];

    QByteArray numdata = data.mid(start + 1, len);
    m_value = QLocale::c().toLongLong(numdata);

    return len + 1; // bytes processed
}
