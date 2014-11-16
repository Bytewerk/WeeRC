#ifndef WBUFFERINFO_H
#define WBUFFERINFO_H

#include "../WeechatObjects/wpointer.h"

#include "../WeechatModels/wbufferline.h"
#include "../WeechatModels/wchatbuffer.h"

#include <QMap>

class WBufferInfo
{
	public:
		typedef QMap<WPointer::value_type, WBufferLinePtr> BufferLineMap;
		typedef QList<WPointer::value_type> BufferLineList;

	private:
		WChatBufferPtr m_chatBuffer;
		BufferLineMap  m_bufferLines;
		BufferLineList m_bufferLineOrder;

	public:
		explicit WBufferInfo(WChatBufferPtr buffer);

		void appendLine(WBufferLinePtr line);

		const WChatBufferPtr  getBufferPointer(void) const { return m_chatBuffer; }
		const WBufferLinePtr  getLine(WPointer::value_type linePtr) const;
		const BufferLineList& getLineOrder(void) const { return m_bufferLineOrder; }

		void debugPrint(void) const;
};

typedef std::shared_ptr<WBufferInfo> WBufferInfoPtr;

#endif // WBUFFERINFO_H
