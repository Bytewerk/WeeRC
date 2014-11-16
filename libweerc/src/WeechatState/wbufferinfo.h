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
		const BufferLineList& getLinePointerList(void) const { return m_bufferLineOrder; }
		const WBufferLinePtr  getLinePointer(WPointer::value_type ptr) const { return m_bufferLines[ptr]; }

		void debugPrint(void) const;
};

typedef std::shared_ptr<WBufferInfo> WBufferInfoPtr;

#endif // WBUFFERINFO_H
