#include <QtCore>
#include <QThread>

#include <iostream>

#include "../../libweerc/src/weechat/whashtable.h"

#include "../../libweerc/src/connection.h"
#include "../../libweerc/src/protocolhandler.h"
#include "../../libweerc/src/messageparser.h"

class ConsoleHandler : public QThread
{
	Q_OBJECT

public:
	void run(void)
	{
		std::string line;

		while(true) {
			std::cout << "> " << std::flush;

			std::getline(std::cin, line);

			emit line_read(QString::fromUtf8(line.data(), line.length()));
		}
	}

signals:
	void line_read(const QString &line);
};

class MainTask : public QObject
{
	Q_OBJECT

private:
	ProtocolHandler *m_protoHandler;
	MessageParser   *m_messageParser;
	ConsoleHandler  *m_consoleHandler;

public:
	MainTask(QObject *parent = 0) : QObject(parent) {}

	~MainTask()
	{
		delete m_messageParser;
		delete m_protoHandler;
	}

public slots:
	void run(void)
	{
		qDebug() << "Hello from Main Task!";

		m_protoHandler = new ProtocolHandler("asdf", false);

		m_messageParser = new MessageParser();
		connect(m_messageParser, SIGNAL(messageParsed(WRelayMessagePtr)), this, SLOT(handleWeechatMessage(WRelayMessagePtr)));
		connect(m_protoHandler, SIGNAL(connectionInitialized()), this, SLOT(connectionInitialized()));

		m_protoHandler->setParser(m_messageParser);

		Connection::instance().setProtocolHandler(m_protoHandler);

		Connection::instance().createConnection("localhost", 8001, false);

		m_consoleHandler = new ConsoleHandler();
		connect(m_consoleHandler, SIGNAL(line_read(const QString&)), this, SLOT(line_read(const QString&)));

		m_consoleHandler->start();
	}

	void connectionInitialized(void)
	{
		qDebug() << "Connection initialized";
		m_protoHandler->registerBufferUpdates();
	}

	void handleWeechatMessage(WRelayMessagePtr message) {
		message->debugPrint();
	}

	void shutdown(void)
	{
		emit finished();
	}

	void line_read(const QString &line)
	{
		Connection::instance().sendData(line.toUtf8() + "\n");
	}

signals:
	void finished();
};

#include "main.moc"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QByteArray test("strint\x00\x00\x00\x03" // map str -> int; 3 elements, 10 bytes
	                "\x00\x00\x00\x0a""0123456789""\x00\x00\xFF\xFF"             // "0123456789" -> 65535, 18 bytes
	                "\x00\x00\x00\x05""tests""\x00\x00\x80\x80"             // "tests" -> 32768+128, 13 bytes
	                "\x00\x00\x00\x05""blubb""\xFF\xFF\xFF\xFF",             // "blubb" -> -1, 13 bytes
	                10+18+13+13
			);

	WHashTable ht;
	ht.parse(test, 0);

	MainTask *task = new MainTask(&a);
	QObject::connect(task, SIGNAL(finished()), &a, SLOT(quit()));
	QTimer::singleShot(0, task, SLOT(run()));

	return a.exec();
}
