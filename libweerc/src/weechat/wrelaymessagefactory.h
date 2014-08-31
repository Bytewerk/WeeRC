// vim: ts=4 sw=4 expandtab

#ifndef WRELAYMESSAGEFACTORY_H
#define WRELAYMESSAGEFACTORY_H

#include "wrelaymessage.h"

class WRelayMessageFactory
{
public:
    static WRelayMessagePtr fromTypeString(const QString &str);
};

#endif // WRELAYMESSAGEFACTORY_H
