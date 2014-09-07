// vim: ts=4 sw=4 expandtab

#include <QtEndian>

#include "wstring.h"

WString::WString()
    : WObject(WObject::String)
{
}

int WString::parse(const QByteArray &data, uint start)
{
    qint32 len_be = 0, len;

    // extract the length
    for(int i = 0; i < 4; i++) {
        len_be |= data[start + i] << (8 * i);
    }

    len = qFromBigEndian(len_be);

    // extract the data
    if(len < 0) {
        m_null = true;
        return 4;
    } else {
        m_value = QString::fromUtf8(data.mid(start + 4, len));
        m_null = false;
        return len + 4;
    }
}

QString WString::repr(void)
{
    if(m_null) {
        return "[" + WObject::typeToStr(m_objectType) + ":" + "NULL" + "]";
    } else {
        return "[" + WObject::typeToStr(m_objectType) + ":" + "\"" + m_value + "\"" + "]";
    }
}
