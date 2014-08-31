// vim: ts=4 sw=4 expandtab

#include <QLocale>

#include "winfo.h"

#include "wstring.h"

WInfo::WInfo()
    : WObject(WObject::Info)
{
}

int WInfo::parse(const QByteArray &data, uint start)
{
    WString tmpStr;

    // parse name string
    start += tmpStr.parse(data, start);
    m_name = tmpStr.getValue();

    // parse value string
    start += tmpStr.parse(data, start);
    m_value = tmpStr.getValue();
}
