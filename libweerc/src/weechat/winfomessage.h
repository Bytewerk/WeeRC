// vim: ts=4 sw=4 expandtab

#ifndef WINFOMESSAGE_H
#define WINFOMESSAGE_H

#include "winfo.h"

#include "wrelaymessage.h"

class WInfoMessage : public WRelayMessage
{
private:
    WInfo m_info;

public:
    WInfoMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual void debugPrint(void);
};

#endif // WINFOMESSAGE_H
