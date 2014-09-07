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

QString WObject::typeToStr(ObjectType type)
{
    switch(type) {
    // basic types
    case Char:        return "chr"; break;
    case Integer:     return "int"; break;
    case LongInteger: return "lon"; break;
    case String:      return "str"; break;
    case Buffer:      return "buf"; break;
    case Pointer:     return "ptr"; break;
    case Time:        return "tim"; break;
    case Array:       return "arr"; break;
    // advanced types
    case Info:        return "inf"; break;
    // unknown type
    default:          return "???";
    }
}
