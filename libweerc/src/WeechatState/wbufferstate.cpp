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
	WChatBufferPtr buffer(new WChatBuffer(message->getBuffer()));

	qDebug() << "Adding to buffer list:" << buffer->pointer << "(#" << buffer->number << ":" << buffer->fullName << ")";

	m_bufferInfoMap.insert(buffer->pointer, buffer);
}

void WBufferState::processBufferClosingMessage(WBufferClosingMessage *message)
{
	WChatBufferPtr buffer(new WChatBuffer(message->getBuffer()));

	qDebug() << "Deleting from buffer list:" << buffer->pointer << "(#" << buffer->number << ":" << buffer->fullName << ")";

	m_bufferInfoMap.remove(buffer->pointer);
}

void WBufferState::processBufferLineAddedMessage(WBufferLineAddedMessage *message)
{
	// TODO
}

void WBufferState::debugPrint(void)
{
	qDebug() << "Contents of WBufferState";
	for(const WChatBufferPtr &bufPtr: m_bufferInfoMap) {
		bufPtr->debugPrint();
	}
}
