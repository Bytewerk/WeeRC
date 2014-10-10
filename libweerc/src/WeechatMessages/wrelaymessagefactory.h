// vim: ts=4 sw=4 expandtab

#ifndef WRELAYMESSAGEFACTORY_H
#define WRELAYMESSAGEFACTORY_H

#include "wrelaymessage.h"

#include "../WeechatObjects/wstring.h"

class WRelayMessageFactory
{
public:
    static WRelayMessagePtr fromMessageID(const WString &wstr);
};

#endif // WRELAYMESSAGEFACTORY_H
