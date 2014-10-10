// vim: ts=4 sw=4 expandtab

#ifndef WOBJECTMESSAGE_H
#define WOBJECTMESSAGE_H

#include "../WeechatObjects/wobject.h"

#include "wrelaymessage.h"

class WObjectMessage : public WRelayMessage
{
private:
    WObjectPtr m_object;

public:
    WObjectMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual void debugPrint(void);
};

#endif // WOBJECTMESSAGE_H
