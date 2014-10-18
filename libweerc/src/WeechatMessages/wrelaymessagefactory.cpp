// vim: ts=4 sw=4 expandtab

#include "wobjectmessage.h"
#include "wbufferlistmessage.h"
#include "wbufferopenedmessage.h"
#include "wbufferclosingmessage.h"

#include "wrelaymessagefactory.h"

WRelayMessagePtr WRelayMessageFactory::fromMessageID(const WString &wstr)
{
    if(wstr.isNull()) {
        // message id is not defined. Use the generic WObjectMessage to parse
        // the first object contained in the message.
        return WRelayMessagePtr(new WObjectMessage());
    }

    QString str = wstr.getValue();

    // weechat default messages
    if     (str == QString("_buffer_opened"))  { return WRelayMessagePtr(new WBufferOpenedMessage()); }
    if     (str == QString("_buffer_closing")) { return WRelayMessagePtr(new WBufferClosingMessage()); }
    // specific messages
    else if(str == QString("bufferlist"))      { return WRelayMessagePtr(new WBufferListMessage()); }
    // also use WObjectMessage for unknown IDs
    else                                       { return WRelayMessagePtr(new WObjectMessage()); }
}

