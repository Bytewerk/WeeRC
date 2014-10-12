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
			return true;

		case WRelayMessage::BufferOpened:
			qDebug() << "BufferOpened message received.";
			//m_bufferState->processBufferListMessage(dynamic_cast<WBufferListMessage*>(message.get()));
			message->debugPrint();
			return true;

		default:
			qDebug() << "Message of unknown type received.";
			message->debugPrint();
			return false;
	}
}
