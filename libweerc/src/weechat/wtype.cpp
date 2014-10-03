// vim: ts=4 sw=4 expandtab

#include <QLocale>

#include "wtype.h"

WType::WType()
    : WObject(WObject::Type)
{
}

int WType::parse(const QByteArray &data, uint start)
{
    QString typestr = data.mid(start, 3);
    m_value = WObject::typeFromStr(typestr);

    return 3; // bytes processed
}

QString WType::repr(void) const
{
    return "[" + WObject::typeToStr(m_objectType) + ": " + QString::number(m_value) + "]";
}
