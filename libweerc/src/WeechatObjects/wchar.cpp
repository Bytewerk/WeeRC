// vim: ts=4 sw=4 expandtab

#include "wchar.h"

WChar::WChar()
    : WObject(WObject::Char)
{
}

int WChar::parse(const QByteArray &data, uint start)
{
    m_value = data[start];
    return 1;
}

QString WChar::repr(void) const
{
    if(m_value.isPrint()) {
        return "[" + WObject::typeToStr(m_objectType) + ":" + m_value + "]";
    } else {
        return "[" + WObject::typeToStr(m_objectType) + ":" + QString::number(m_value.unicode()) + "]";
    }
}
