// vim: ts=4 sw=4 expandtab

#include <QtEndian>

#include "wbuffer.h"

WBuffer::WBuffer()
    : WObject(WObject::Buffer)
{
}

int WBuffer::parse(const QByteArray &data, uint start)
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
    } else {
        m_value = data.mid(start + 4, len);
        m_null = false;
    }

    return len + 4;
}
