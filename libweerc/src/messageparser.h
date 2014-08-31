// vim: ts=4 sw=4 expandtab

#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include "weechat/wrelaymessage.h"

class MessageParser
{
public:
    MessageParser();

    virtual int parse(const QByteArray &data, int start);
};

#endif // MESSAGEPARSER_H
