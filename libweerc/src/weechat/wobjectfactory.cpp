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
    // basic types
    if     (str == "chr") { return WObjectPtr(new WChar()); }
    else if(str == "int") { return WObjectPtr(new WInteger()); }
    else if(str == "lon") { return WObjectPtr(new WLongInteger()); }
    else if(str == "str") { return WObjectPtr(new WString()); }
    else if(str == "buf") { return WObjectPtr(new WBuffer()); }
    else if(str == "ptr") { return WObjectPtr(new WPointer()); }
    else if(str == "tim") { return WObjectPtr(new WTime()); }
    else if(str == "arr") { return WObjectPtr(new WArray()); }
    // advanced types
    else if(str == "inf") { return WObjectPtr(new WInfo()); }
    // unknown type
    else                  { return NULL; }
}
