#ifndef PROTOCOLHANDLER_H
#define PROTOCOLHANDLER_H

#include <QObject>

#include <QByteArray>

class MessageParser;

class ProtocolHandler : public QObject
{
	Q_OBJECT

private:
	QByteArray     m_dataBuffer;
	MessageParser *m_parser;
	int            m_offset;

	QString        m_password;
	bool           m_useCompression;

public:
	ProtocolHandler();
	ProtocolHandler(const QString &password, bool enableCompression);
	~ProtocolHandler();

	void initConnection();

	void setPassword(const QString& password) { m_password = password; }
	void setCompression(bool enable) { m_useCompression = enable; }

	void setParser(MessageParser *parser) { m_parser = parser; }

public slots:
	void dataReceived(const QByteArray& data);
};

#endif // PROTOCOLHANDLER_H
