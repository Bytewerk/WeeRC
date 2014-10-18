// vim: ts=4 sw=4 expandtab

#ifndef WBUFFEROPENEDMESSAGE_H
#define WBUFFEROPENEDMESSAGE_H

#include "../WeechatModels/wchatbuffer.h"

#include "wrelaymessage.h"

class WBufferOpenedMessage : public WRelayMessage
{
private:
    WChatBuffer m_buffer;

public:
    WBufferOpenedMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual const WChatBuffer& getBuffer(void) const { return m_buffer; }

    virtual void debugPrint(void);
};

#endif // WBUFFEROPENEDMESSAGE_H
