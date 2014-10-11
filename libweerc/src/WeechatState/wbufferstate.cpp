#include <QDebug>

#include "wbufferstate.h"

WBufferState::WBufferState(void)
{
}

void WBufferState::processBufferListMessage(WBufferListMessage *message)
{
	qDebug() << "Replacing buffer list from WBufferListMessage";

	m_bufferInfoMap.clear();

	for(const WBufferListMessage::BufferInfo& bi: message->getBufferInfo()) {
		qDebug() << "Adding" << bi.pointer << "(#" << bi.number << ":" << bi.full_name << ")";

		WBufferState::BufferInfo newEntry;
		newEntry.number = bi.number;
		newEntry.full_name = bi.full_name;

		m_bufferInfoMap.insert(bi.pointer, newEntry);
	}
}
