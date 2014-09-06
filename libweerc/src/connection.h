#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QTcpSocket>

class ProtocolHandler;

class Connection : public QObject
{
    Q_OBJECT

private:
    explicit Connection(QObject *parent = 0);

    QTcpSocket      *m_socket;
    ProtocolHandler *m_handler;

private slots:
    void encrypted();

    void connectionEstablished();
    void socketError(QAbstractSocket::SocketError e);
    void readSocketData();

public:
    static Connection& instance() {
        static Connection theOneAndOnly;
        return theOneAndOnly;
    }

    Q_INVOKABLE void createConnection(const QString& ip, quint16 port, bool tls = true);

    void setProtocolHandler(ProtocolHandler *handler);

    void sendData(const QByteArray &data);
};

#endif // CONNECTION_H
