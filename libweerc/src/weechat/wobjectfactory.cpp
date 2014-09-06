// vim: ts=4 sw=4 expandtab

#include "wchar.h"
#include "winteger.h"
#include "wlonginteger.h"
#include "wstring.h"
#include "wbuffer.h"
#include "wpointer.h"
#include "wtime.h"
#include "warray.h"
#include "winfo.h"

#include "wobjectfactory.h"

WObjectPtr WObjectFactory::fromTypeString(const QString &str)
{
    return fromType(WObject::typeFromStr(str));
}

WObjectPtr WObjectFactory::fromType(WObject::ObjectType type)
{
    switch(type) {
        // basic types
        case WObject::Char:         return WObjectPtr(new WChar());        break;
        case WObject::Integer:      return WObjectPtr(new WInteger());     break;
        case WObject::LongInteger:  return WObjectPtr(new WLongInteger()); break;
        case WObject::String:       return WObjectPtr(new WString());      break;
        case WObject::Buffer:       return WObjectPtr(new WBuffer());      break;
        case WObject::Pointer:      return WObjectPtr(new WPointer());     break;
        case WObject::Time:         return WObjectPtr(new WTime());        break;
        case WObject::Array:        return WObjectPtr(new WArray());       break;
        // advanced types
        case WObject::Info:         return WObjectPtr(new WInfo());        break;
        // unknown type
        default:           return NULL;
    }
}
