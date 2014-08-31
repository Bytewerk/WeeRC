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
