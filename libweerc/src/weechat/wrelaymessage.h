// vim: ts=4 sw=4 expandtab

#ifndef WRELAYMESSAGE_H
#define WRELAYMESSAGE_H

#include <QByteArray>

#include <memory>

class WRelayMessage
{
public:
    enum MessageType {
        BufferOpened,
        BufferMoved,
        BufferMerged,
        BufferUnmerged,
        BufferHidden,
        BufferUnhidden,
        BufferRenamed,
        BufferTitleChanged,
        BufferCleared,
        BufferTypeChanged,
        BufferLocalvarAdded,
        BufferLocalvarChanged,
        BufferLocalvarRemoved,
        BufferLineAdded,
        Nicklist,
        NicklistDiff,
        Pong,
        Upgrade,
        UpgradeEnded,
        Info
    };

private:
    MessageType m_type;

public:
    WRelayMessage();
    WRelayMessage(MessageType mt);

    /*!
     * Parse the message from the given data, beginning at start.
     *
     * \returns  The number of bytes read.
     */
    virtual int parse(const QByteArray &data, int start) = 0;

    virtual void debugPrint(void) = 0;
};

typedef std::unique_ptr<WRelayMessage> WRelayMessagePtr;

#endif // WRELAYMESSAGE_H
