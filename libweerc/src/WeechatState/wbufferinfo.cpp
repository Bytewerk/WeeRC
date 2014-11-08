#include <QDebug>

#include "wbufferinfo.h"

WBufferInfo::WBufferInfo(WChatBufferPtr buffer)
{
	m_chatBuffer = buffer;
}

void WBufferInfo::appendLine(WBufferLinePtr line)
{
	WPointer::value_type ptrval = line->line_pointer;

	m_bufferLines[ptrval] = line;
	m_bufferLineOrder.append(ptrval);
}

void WBufferInfo::debugPrint(void)
{
	qDebug() << "This WBufferinfo contains information about the following buffer:";
	m_chatBuffer->debugPrint();
	qDebug() << "And the following messages";
	for(WPointer::value_type ptrval: m_bufferLineOrder) {
		WBufferLinePtr line = m_bufferLines[ptrval];
		qDebug() << ptrval << line->date << line->prefix << line->message;
	}
}
