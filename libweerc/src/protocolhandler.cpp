#include "messageparser.h"

#include "connection.h"

#include "protocolhandler.h"

ProtocolHandler::ProtocolHandler()
	: m_parser(NULL), m_offset(0)
{
}

ProtocolHandler::ProtocolHandler(const QString &password, bool enableCompression)
	: m_parser(NULL), m_offset(0), m_password(password), m_useCompression(enableCompression)
{
}

ProtocolHandler::~ProtocolHandler()
{
}

void ProtocolHandler::dataReceived(const QByteArray &data)
{
	// add new data to data buffer
	m_dataBuffer += data;

	int dataRead = m_parser->parse(m_dataBuffer, m_offset);

	// TODO: drop already parsed data from the buffer
	if(dataRead > 0) {
		m_offset += dataRead;
	}
}

void ProtocolHandler::initConnection(void)
{
	Connection::instance().sendData(("(12) init password=" + m_password + ",compression=" + (m_useCompression ? "on" : "off") + "\n").toUtf8());
	Connection::instance().sendData(QString("info version\n").toUtf8());
}
