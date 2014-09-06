// vim: ts=4 sw=4 expandtab

#include "wobject.h"

WObject::WObject()
{
}

WObject::WObject(ObjectType ot)
    : m_objectType(ot)
{
}

WObject::ObjectType WObject::typeFromStr(const QString &str)
{
    // basic types
    if     (str == "chr") { return Char; }
    else if(str == "int") { return Integer; }
    else if(str == "lon") { return LongInteger; }
    else if(str == "str") { return String; }
    else if(str == "buf") { return Buffer; }
    else if(str == "ptr") { return Pointer; }
    else if(str == "tim") { return Time; }
    else if(str == "arr") { return Array; }
    // advanced types
    else if(str == "inf") { return Info; }
    // unknown type
    else                  { return Unknown; }
}
