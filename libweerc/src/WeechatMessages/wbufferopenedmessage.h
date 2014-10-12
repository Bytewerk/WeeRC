// vim: ts=4 sw=4 expandtab

#ifndef WBUFFEROPENEDMESSAGE_H
#define WBUFFEROPENEDMESSAGE_H

#include "../WeechatObjects/whdata.h"
#include "../WeechatObjects/wpointer.h"

#include "wrelaymessage.h"

class WBufferOpenedMessage : public WRelayMessage
{
private:
    WPointer::value_type m_bufferPointer;
    int                  m_bufferNumber;
    QString              m_bufferFullName;

public:
    WBufferOpenedMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual void debugPrint(void);
};

#endif // WBUFFEROPENEDMESSAGE_H
