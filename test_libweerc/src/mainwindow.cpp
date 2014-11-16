#include "mainwindow.h"

// TODO: move this out of this file
class BufferListModel : public QAbstractListModel
{
	Q_OBJECT
	
	private:
		WStateManager *m_stateManager;

	public:
		BufferListModel(WStateManager *stateManager, QObject *parent = 0)
			: QAbstractListModel(parent), m_stateManager(stateManager)
		{
			connect(m_stateManager, SIGNAL(bufferListUpdated(const WBufferState::BufferInfoMap&)),
			        this, SLOT(bufferListUpdated(const WBufferState::BufferInfoMap&)));
		}

		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
		{
			if(!index.isValid()) {
				return QVariant();
			}

			if(role == Qt::DisplayRole) {
				WBufferState::BufferInfoMap::const_iterator iter =
					m_stateManager->getBufferState()->getBufferInfoMap().begin();

				QString bufferName = (iter + index.row())->get()->getBufferPointer()->fullName;

				qDebug() << "Entry" << index.row() << "resolves to" << bufferName;

				return bufferName;
			} else {
				return QVariant();
			}
		}

		int rowCount(const QModelIndex &parent) const
		{
			int count = m_stateManager->getBufferState()->getBufferInfoMap().size();
			qDebug() << "Model has" << count << "entries";
			return count;
		}

		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const
		{
			if(role == Qt::DisplayRole) {
				return QString("Buffer Name");
			} else {
				return QVariant();
			}
		}

	private slots:
		void bufferListUpdated(const WBufferState::BufferInfoMap &bufferInfoMap)
		{
			QModelIndex topLeft = createIndex(0, 0);
			QModelIndex bottomRight = createIndex(bufferInfoMap.size(), 0);
			emit dataChanged(topLeft, bottomRight);
		}
};

#include "mainwindow.moc"

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
	Connection::instance().sendData(ui.inputEdit->text().toUtf8() + "\n");
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
	qDebug() << "\e[1;31mBuffer lines updated.\e[0m";
}

