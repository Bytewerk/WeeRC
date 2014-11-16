#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include "../../libweerc/src/connection.h"
#include "../../libweerc/src/protocolhandler.h"
#include "../../libweerc/src/messageparser.h"
#include "../../libweerc/src/WeechatState/wstatemanager.h"

class BufferListModel;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	private:
		Ui::MainWindow ui;

		ProtocolHandler *m_protoHandler;
		MessageParser   *m_messageParser;
		WStateManager   *m_stateManager;
		BufferListModel *m_bufferListModel;

	private slots:
		void weechatConnectionInitialized(void);
		void sendWeechatCommand(void);

		void bufferListUpdated(const WBufferState::BufferInfoMap &bufferInfoMap);
		void bufferLinesUpdated(const WBufferInfoPtr &bufferInfo);

	public:
		MainWindow(QWidget *parent = 0);
		~MainWindow();
};

#endif // MAINWINDOW_H
