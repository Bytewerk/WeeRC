// vim: ts=4 sw=4 expandtab

#ifndef WBUFFERCLOSINGMESSAGE_H
#define WBUFFERCLOSINGMESSAGE_H

#include "../WeechatModels/wchatbuffer.h"

#include "wrelaymessage.h"

class WBufferClosingMessage : public WRelayMessage
{
private:
    WChatBuffer m_buffer;

public:
    WBufferClosingMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual const WChatBuffer& getBuffer(void) const { return m_buffer; }

    virtual void debugPrint(void);
};

#endif // WBUFFERCLOSINGMESSAGE_H
