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
};

#endif // WSTATEMANAGER_H
