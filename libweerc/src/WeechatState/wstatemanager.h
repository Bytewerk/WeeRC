#ifndef WSTATEMANAGER_H
#define WSTATEMANAGER_H

#include <QObject>

#include "wbufferstate.h"

#include "../WeechatMessages/wrelaymessage.h"

class WStateManager : public QObject
{
	Q_OBJECT

	private:
		WBufferState *m_bufferState;

	public:
		explicit WStateManager(QObject *parent = 0);
		virtual ~WStateManager();

	public slots:
		bool handleMessage(WRelayMessagePtr message);

		const WBufferState* getBufferState(void) { return m_bufferState; }

	signals:
		void bufferListUpdated(const WBufferState::BufferInfoMap &bufferInfoMap);
		void bufferLinesUpdated(const WBufferInfoPtr &bufferInfo);
};

#endif // WSTATEMANAGER_H
