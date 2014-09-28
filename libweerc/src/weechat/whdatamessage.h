// vim: ts=4 sw=4 expandtab

#ifndef WHDATAMESSAGE_H
#define WHDATAMESSAGE_H

#include "whdata.h"

#include "wrelaymessage.h"

class WHdataMessage : public WRelayMessage
{
private:
    WHdata m_info;

public:
    WHdataMessage();

    virtual int parse(const QByteArray &data, int start);

    virtual void debugPrint(void);
};

#endif // WHDATAMESSAGE_H
