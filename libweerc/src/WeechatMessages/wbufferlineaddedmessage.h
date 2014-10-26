// vim: ts=4 sw=4 expandtab

#ifndef WBUFFERLINEADDEDMESSAGE_H
#define WBUFFERLINEADDEDMESSAGE_H

#include "../WeechatModels/wbufferline.h"

#include "wrelaymessage.h"

class WBufferLineAddedMessage : public WRelayMessage
{
private:
    WBufferLine m_bufferLine;

public:
    WBufferLineAddedMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual const WBufferLine& getBufferLine(void) { return m_bufferLine; }

    virtual void debugPrint(void);
};

#endif // WBUFFERLINEADDEDMESSAGE_H
