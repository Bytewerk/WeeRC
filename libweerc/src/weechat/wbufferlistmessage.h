// vim: ts=4 sw=4 expandtab

#ifndef WBUFFERLISTMESSAGE_H
#define WBUFFERLISTMESSAGE_H

#include "whdata.h"
#include "wpointer.h"

#include "wrelaymessage.h"

class WBufferListMessage : public WRelayMessage
{
public:
    struct BufferInfo {
        int id;
        WPointer::value_type pointer;
        QString name;
    };

    typedef QList<BufferInfo> BufferInfoList;

private:
    BufferInfoList m_bufferInfo;

public:
    WBufferListMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual void debugPrint(void);
};

#endif // WBUFFERLISTMESSAGE_H
