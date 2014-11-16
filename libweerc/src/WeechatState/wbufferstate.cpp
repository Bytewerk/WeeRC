#include <QDebug>

#include "wbufferstate.h"

WBufferState::WBufferState(QObject *parent)
	: QObject(parent)
{
}

void WBufferState::processBufferListMessage(WBufferListMessage *message)
{
	qDebug() << "Replacing buffer list from WBufferListMessage";

	m_bufferInfoMap.clear();

	for(const WChatBufferPtr& buffer: message->getBufferInfo()) {
		qDebug() << "Adding" << buffer->pointer << "(#" << buffer->number << ":" << buffer->fullName << ")";

		WBufferInfoPtr bufferInfo(new WBufferInfo(buffer));
		m_bufferInfoMap.insert(buffer->pointer, bufferInfo);
	}

	emit bufferListUpdated(m_bufferInfoMap);
}

void WBufferState::processBufferOpenedMessage(WBufferOpenedMessage *message)
{
	WChatBufferPtr buffer(new WChatBuffer(message->getBuffer()));
	WBufferInfoPtr bufferInfo(new WBufferInfo(buffer));

	qDebug() << "Adding to buffer list:" << buffer->pointer << "(#" << buffer->number << ":" << buffer->fullName << ")";

	m_bufferInfoMap.insert(buffer->pointer, bufferInfo);

	emit bufferListUpdated(m_bufferInfoMap);
}

void WBufferState::processBufferClosingMessage(WBufferClosingMessage *message)
{
	WChatBufferPtr buffer(new WChatBuffer(message->getBuffer()));

	qDebug() << "Deleting from buffer list:" << buffer->pointer << "(#" << buffer->number << ":" << buffer->fullName << ")";

	m_bufferInfoMap.remove(buffer->pointer);

	emit bufferListUpdated(m_bufferInfoMap);
}

void WBufferState::processBufferLineAddedMessage(WBufferLineAddedMessage *message)
{
	WBufferLinePtr line(new WBufferLine(message->getBufferLine()));
	WBufferInfoPtr bufferInfo = m_bufferInfoMap[line->buffer_pointer];

	qDebug() << "Adding line " << line->message << "to buffer" << bufferInfo->getBufferPointer()->fullName;

	bufferInfo->appendLine(line);

	emit bufferLinesUpdated(bufferInfo);
}

const WBufferInfoPtr WBufferState::getBufferInfo(WPointer::value_type bufPtr) const
{
	Q_ASSERT(m_bufferInfoMap.contains(bufPtr));

	return m_bufferInfoMap[bufPtr];
}

void WBufferState::debugPrint(void) const
{
	qDebug() << "Contents of WBufferState";
	for(const WBufferInfoPtr &bufInfo: m_bufferInfoMap) {
		bufInfo->debugPrint();
	}
}
