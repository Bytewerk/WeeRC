#include "bufferlistmodel.h"
#include "bufferlinesmodel.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Setup libweerc
	m_protoHandler = new ProtocolHandler("asdf", false);

	m_messageParser = new MessageParser();
	connect(m_protoHandler, SIGNAL(connectionInitialized()), this, SLOT(weechatConnectionInitialized()));

	m_protoHandler->setParser(m_messageParser);

	Connection::instance().setProtocolHandler(m_protoHandler);

	Connection::instance().createConnection("localhost", 8001, false);

	m_stateManager = new WStateManager();
	connect(m_messageParser, SIGNAL(messageParsed(WRelayMessagePtr)), m_stateManager, SLOT(handleMessage(WRelayMessagePtr)));

	connect(m_stateManager, SIGNAL(bufferListUpdated(const WBufferState::BufferInfoMap&)),
	        this, SLOT(bufferListUpdated(const WBufferState::BufferInfoMap&)));
	connect(m_stateManager, SIGNAL(bufferLinesUpdated(const WBufferInfoPtr&)),
	        this, SLOT(bufferLinesUpdated(const WBufferInfoPtr&)));

	connect(ui.sendButton, SIGNAL(clicked()), this, SLOT(sendWeechatCommand()));

	m_bufferListModel = new BufferListModel(m_stateManager, this);
	ui.bufferListView->setModel(m_bufferListModel);

	connect(ui.bufferListView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
				this, SLOT(bufferListSelectionUpdated(const QModelIndex&, const QModelIndex&)));

	m_bufferLinesModel = new BufferLinesModel(m_stateManager, this);
	ui.messageView->setModel(m_bufferLinesModel);
}

MainWindow::~MainWindow()
{
	// Shutdown libweerc
	delete m_messageParser;
	delete m_protoHandler;
	delete m_stateManager;
}


void MainWindow::weechatConnectionInitialized(void)
{
	m_protoHandler->registerBufferUpdates();
}

void MainWindow::sendWeechatCommand(void)
{
	const QString &bufName = m_bufferLinesModel->getAssociatedBufferInfo()->getBufferPointer()->fullName;
	Connection::instance().sendData(("input " + bufName + " " + ui.inputEdit->text()).toUtf8() + "\n");
	ui.inputEdit->setText("");
	ui.inputEdit->setFocus();
}

void MainWindow::bufferListUpdated(const WBufferState::BufferInfoMap &bufferInfoMap)
{
	qDebug() << "\e[1;31mBuffer list updated.\e[0m";

	ui.bufferListView->update();
}

void MainWindow::bufferLinesUpdated(const WBufferInfoPtr &bufferInfo)
{
	static bool first = true;

	if(first) {
		m_bufferLinesModel->setAssociatedBuffer(bufferInfo->getBufferPointer()->pointer);
		first = false;
	}

	qDebug() << "\e[1;31mBuffer lines updated.\e[0m";
}

void MainWindow::bufferListSelectionUpdated(const QModelIndex &current, const QModelIndex &previous)
{
	qDebug() << "\e[1;32mBuffer list selection changed:" << current.row() << ".\e[0m";

	WBufferInfoPtr bufferInfo = m_bufferListModel->getBufferAtIndex(current);

	m_bufferLinesModel->setAssociatedBuffer(bufferInfo->getBufferPointer()->pointer);
}
