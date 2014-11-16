#ifndef WBUFFERSTATE_H
#define WBUFFERSTATE_H

#include <QMap>

#include "../WeechatMessages/wbufferlistmessage.h"
#include "../WeechatMessages/wbufferopenedmessage.h"
#include "../WeechatMessages/wbufferclosingmessage.h"
#include "../WeechatMessages/wbufferlineaddedmessage.h"

#include "wbufferinfo.h"

class WBufferState : public QObject
{
	Q_OBJECT

	public:
		typedef QMap<WPointer::value_type, WBufferInfoPtr> BufferInfoMap;

	private:
		BufferInfoMap m_bufferInfoMap;

	public:
		explicit WBufferState(QObject *parent = 0);

		void processBufferListMessage(WBufferListMessage *message);
		void processBufferOpenedMessage(WBufferOpenedMessage *message);
		void processBufferClosingMessage(WBufferClosingMessage *message);
		void processBufferLineAddedMessage(WBufferLineAddedMessage *message);

		const BufferInfoMap& getBufferInfoMap(void) const { return m_bufferInfoMap; }
		const WBufferInfoPtr getBufferInfo(WPointer::value_type bufPtr) const;

		void debugPrint(void) const;

	signals:
		void bufferListUpdated(const WBufferState::BufferInfoMap &bufferInfoMap);
		void bufferLinesUpdated(const WBufferInfoPtr &bufferInfo);
};

#endif // WBUFFERSTATE_H
