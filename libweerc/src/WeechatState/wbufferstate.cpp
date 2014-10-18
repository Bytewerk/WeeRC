#include <QDebug>

#include "wbufferstate.h"

WBufferState::WBufferState(void)
{
}

void WBufferState::processBufferListMessage(WBufferListMessage *message)
{
	qDebug() << "Replacing buffer list from WBufferListMessage";

	m_bufferInfoMap.clear();

	for(const WChatBufferPtr& buffer: message->getBufferInfo()) {
		qDebug() << "Adding" << buffer->pointer << "(#" << buffer->number << ":" << buffer->fullName << ")";

		m_bufferInfoMap.insert(buffer->pointer, buffer);
	}
}

void WBufferState::processBufferOpenedMessage(WBufferOpenedMessage *message)
{
	qDebug() << "Adding buffer from WBufferOpenedMessage";

	WChatBufferPtr buffer(new WChatBuffer());
	const WChatBuffer &buf = message->getBuffer();
	buffer->copyFrom(buf);

	qDebug() << "Adding" << buffer->pointer << "(#" << buffer->number << ":" << buffer->fullName << ")";

	m_bufferInfoMap.insert(buffer->pointer, buffer);
}
