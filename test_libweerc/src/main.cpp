#include <QtCore>

#include "../../libweerc/src/connection.h"

class MainTask : public QObject
{
    Q_OBJECT
public:
    MainTask(QObject *parent = 0) : QObject(parent) {}

public slots:
    void run()
    {
	qDebug() << "Hello from Main Task!";

	Connection::instance().createConnection("localhost", 8001, false);
	Connection::instance().wInit("asdf", false);

	QTimer::singleShot(3000, this, SLOT(shutdown()));
    }

    void shutdown(void)
    {
	emit finished();
    }

signals:
    void finished();
};

#include "main.moc"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainTask *task = new MainTask(&a);
    QObject::connect(task, SIGNAL(finished()), &a, SLOT(quit()));
    QTimer::singleShot(0, task, SLOT(run()));

    return a.exec();
}
