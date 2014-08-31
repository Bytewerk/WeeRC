// vim: ts=4 sw=4 expandtab

#include "winfomessage.h"

#include "wrelaymessagefactory.h"

WRelayMessagePtr WRelayMessageFactory::fromTypeString(const QString &str)
{
    // basic types
    if     (str == QString("inf")) { return WRelayMessagePtr(new WInfoMessage()); }
    // unknown type
    else                           { return NULL; }
}

