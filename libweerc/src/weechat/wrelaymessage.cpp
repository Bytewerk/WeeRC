// vim: ts=4 sw=4 expandtab

#include "wrelaymessage.h"

WRelayMessage::WRelayMessage()
{
}

WRelayMessage::WRelayMessage(WRelayMessage::MessageType mt)
    : m_type(mt)
{
}
