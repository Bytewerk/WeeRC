#include "connection.h"
#include <QSslConfiguration>
#include <QSsl>

Connection::Connection(QObject *parent) :
    QObject(parent)
{
}

void Connection::createConnection(const QString &ip, quint16 port, bool tls) {
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

void Connection::socketError(QAbstractSocket::SocketError e) {
    qDebug() << "Connection error: " << m_socket->errorString() << "(" << e << ")";
}

void Connection::connectionEstablished() {
    qDebug() << "Connection established!";
}

void Connection::readSocketData() {
    qDebug() << "Fetched data: " << m_socket->readAll().toHex();
}

void Connection::wInit(QString password, bool compression) {
    m_socket->write(("(12) init password=" + password + ",compression=" + (compression ? "on" : "off") + "\n").toUtf8());
    m_socket->write(QString("info version\n").toUtf8());
    qDebug() << "wInit()";
}

void Connection::encrypted()
{
    qDebug() << "SSL handshake was successful!";
}


