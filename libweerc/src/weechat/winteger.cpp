// vim: ts=4 sw=4 expandtab

#include <QtEndian>

#include "winteger.h"

WInteger::WInteger()
    : WObject(WObject::Integer)
{
}

int WInteger::parse(const QByteArray &data, uint start)
{
    qint32 v_be = 0;

    // extract the data
    for(int i = 0; i < 4; i++) {
        v_be |= data[start + i] << (8 * i);
    }

    m_value = qFromBigEndian(v_be);

    return 4; // bytes read
}
