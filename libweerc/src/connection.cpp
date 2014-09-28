// vim: ts=4 sw=4 expandtab

#include "connection.h"
#include <QSslConfiguration>
#include <QSsl>

#include "messageparser.h"
#include "protocolhandler.h"

Connection::Connection(QObject *parent) :
    QObject(parent), m_handler(NULL)
{
}

void Connection::createConnection(const QString &ip, quint16 port, bool tls)
{
    if (tls) {
        QSslSocket *sslSocket = new QSslSocket(this);
        QSslConfiguration config = sslSocket->sslConfiguration();
        config.setProtocol(QSsl::TlsV1);
        sslSocket->setSslConfiguration(config);
        sslSocket->ignoreSslErrors();
        connect(sslSocket, SIGNAL(encrypted()), this, SLOT(encrypted()));
        sslSocket->connectToHostEncrypted(ip, port);

        if (!sslSocket->waitForEncrypted()) {
            qDebug() << sslSocket->errorString();
        }

        m_socket = sslSocket;
    } else {
        QTcpSocket *tcpSocket = new QTcpSocket(this);
        tcpSocket->connectToHost(ip, port);
        m_socket = tcpSocket;
    }   

    connect(m_socket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(readSocketData()));
}

void Connection::socketError(QAbstractSocket::SocketError e)
{
    qDebug() << "Connection error: " << m_socket->errorString() << "(" << e << ")";
}

void Connection::connectionEstablished()
{
    qDebug() << "Connection established!";
    m_handler->initConnection();
}

void Connection::readSocketData()
{
    QByteArray data = m_socket->readAll();

    qDebug() << "Fetched data: " << data.toPercentEncoding();

    m_handler->dataReceived(data);
}

void Connection::encrypted()
{
    qDebug() << "SSL handshake was successful!";
}

void Connection::setProtocolHandler(ProtocolHandler *handler)
{
    m_handler = handler;
}

void Connection::sendData(const QByteArray &data)
{
    m_socket->write(data);
}
