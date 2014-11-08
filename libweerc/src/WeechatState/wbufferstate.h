#ifndef WBUFFERSTATE_H
#define WBUFFERSTATE_H

#include <QMap>

#include "../WeechatMessages/wbufferlistmessage.h"
#include "../WeechatMessages/wbufferopenedmessage.h"
#include "../WeechatMessages/wbufferclosingmessage.h"
#include "../WeechatMessages/wbufferlineaddedmessage.h"

#include "wbufferinfo.h"

class WBufferState
{
	public:
		typedef QMap<WPointer::value_type, WBufferInfoPtr> BufferInfoMap;

	private:
		BufferInfoMap m_bufferInfoMap;

	public:
		explicit WBufferState(void);

		void processBufferListMessage(WBufferListMessage *message);
		void processBufferOpenedMessage(WBufferOpenedMessage *message);
		void processBufferClosingMessage(WBufferClosingMessage *message);
		void processBufferLineAddedMessage(WBufferLineAddedMessage *message);

		void debugPrint(void);
};

#endif // WBUFFERSTATE_H
