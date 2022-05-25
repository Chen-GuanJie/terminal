#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QObject>
#include <QUdpSocket>
namespace udp {
class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *p = 0);
    ~Server();

public slots:
    void receive();

private:
    QUdpSocket *uSocket;
};

}

#endif // UDPRECEIVER_H
