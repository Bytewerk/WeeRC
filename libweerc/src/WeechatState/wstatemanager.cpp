#include <QDebug>

#include "wstatemanager.h"

WStateManager::WStateManager(QObject *parent)
	: QObject(parent)
{
	m_bufferState = new WBufferState();
}

WStateManager::~WStateManager()
{
	delete m_bufferState;
}

bool WStateManager::handleMessage(WRelayMessagePtr message)
{
	switch(message->getType()) {
		case WRelayMessage::BufferList:
			qDebug() << "BufferList message received.";
			m_bufferState->processBufferListMessage(dynamic_cast<WBufferListMessage*>(message.get()));
			break;

		case WRelayMessage::BufferOpened:
			qDebug() << "BufferOpened message received.";
			m_bufferState->processBufferOpenedMessage(dynamic_cast<WBufferOpenedMessage*>(message.get()));
			break;

		case WRelayMessage::BufferClosing:
			qDebug() << "BufferClosing message received.";
			m_bufferState->processBufferClosingMessage(dynamic_cast<WBufferClosingMessage*>(message.get()));
			break;

		case WRelayMessage::BufferLineAdded:
			qDebug() << "BufferLineAdded message received.";
			message->debugPrint();
			break;

		default:
			qDebug() << "Message of unknown type received.";
			message->debugPrint();
			return false;
	}

	m_bufferState->debugPrint();

	return true;
}
