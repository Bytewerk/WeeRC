// vim: ts=4 sw=4 expandtab

#include <QDebug>
#include <QString>

#include "wpointer.h"

WPointer::WPointer()
    : WObject(WObject::Pointer)
{
}

int WPointer::parse(const QByteArray &data, uint start)
{
    unsigned char len = data[start];

    // special case for null pointers
    if(len == 1 && data[start+1] == 0) {
        m_value = 0; // NULL-Pointer
        return 2;
    }

    QString numdata = data.mid(start + 1, len);
    m_value = numdata.toULongLong(NULL, 16);

    qDebug() << len;
    qDebug() << numdata;

    return len + 1; // bytes processed
}

QString WPointer::repr(void) const
{
    return "[" + WObject::typeToStr(m_objectType) + ":" + "0x" + QString::number(m_value, 16) + "]";
}
