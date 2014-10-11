#ifndef WBUFFERSTATE_H
#define WBUFFERSTATE_H

#include <QMap>

#include "../WeechatMessages/wbufferlistmessage.h"

class WBufferState
{
	public:
		struct BufferInfo {
			QString full_name;
			int     number;
		};

		typedef QMap<WPointer::value_type, BufferInfo> BufferInfoMap;

	private:
		BufferInfoMap m_bufferInfoMap;

	public:
		explicit WBufferState(void);

		void processBufferListMessage(WBufferListMessage *message);
};

#endif // WBUFFERSTATE_H
