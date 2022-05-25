#include <QByteArray>
#include <iostream>
#include "server.h"

const quint16 PORT = 2333;
using namespace udp;
Server::Server(QObject *p) :
    QObject(p)
{
    uSocket = new QUdpSocket;
    uSocket->bind(QHostAddress("127.0.0.1"), PORT);
    connect(uSocket, SIGNAL(readyRead()), this, SLOT(receive()));
}

Server::~Server()
{
    delete uSocket;
}

void Server::receive()
{
    QByteArray ba;
    while(uSocket->hasPendingDatagrams())
    {
        ba.resize(uSocket->pendingDatagramSize());
        uSocket->readDatagram(ba.data(), ba.size());
        std::cout << ba.data() << std::endl;
    }
}
