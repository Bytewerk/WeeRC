// vim: ts=4 sw=4 expandtab

#ifndef WBUFFERLISTMESSAGE_H
#define WBUFFERLISTMESSAGE_H

#include "../WeechatModels/wchatbuffer.h"

#include "wrelaymessage.h"

class WBufferListMessage : public WRelayMessage
{
public:
    typedef QList<WChatBufferPtr> BufferInfoList;

private:
    BufferInfoList m_bufferInfo;

public:
    WBufferListMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual const BufferInfoList& getBufferInfo(void) { return m_bufferInfo; }

    virtual void debugPrint(void);
};

#endif // WBUFFERLISTMESSAGE_H
