#ifndef WBUFFERSTATE_H
#define WBUFFERSTATE_H

#include <QMap>

#include "../WeechatMessages/wbufferlistmessage.h"
#include "../WeechatMessages/wbufferopenedmessage.h"

class WBufferState
{
	public:
		typedef QMap<WPointer::value_type, WChatBufferPtr> BufferInfoMap;

	private:
		BufferInfoMap m_bufferInfoMap;

	public:
		explicit WBufferState(void);

		void processBufferListMessage(WBufferListMessage *message);
		void processBufferOpenedMessage(WBufferOpenedMessage *message);
};

#endif // WBUFFERSTATE_H
