#include <QtWidgets>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonObject>
#include <stdlib.h>
#include "server.h"

Server::Server(QWidget *parent)
    : QDialog(parent)
    , statusLabel(new QLabel)
    , tcpServer(Q_NULLPTR)
    , networkSession(0)
{
    initUI();
    initNetworkManager();
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::sendFortune);
}

void Server::sendFortune()
{
    //Hacer clientConnection variable global
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QAbstractSocket::disconnected, clientConnection, &QObject::deleteLater);

    //Agregar señal para leer la data que viene desde el cliente
    connect(clientConnection, &QIODevice::readyRead, this, &Server::readDataFromClient);

    //Escribir la respuesta al cliente, estas instrucciones deberian
    //ser movidas al final del metodo que ha procesado la informacion enviada
    //por el cliente... ver readDataFromClient
    //clientConnection->write(block);
    //clientConnection->disconnectFromHost();
}

void Server::readDataFromClient()
{
    qDebug() << "Reading data...";
    QByteArray request = clientConnection->readAll();

    //Se procesa la info del cliente en este metodo
    //Aqui inicia la magia
    QString result = processRequest(request);

    //Variables para escribir la respuesta al cliente
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    //Se escribe la respuesta para el cliente
    out << result;

    //Se envia la respuesta para el cliente
    clientConnection->write(block);

    //Se cierra la conexion con el cliente
    clientConnection->disconnectFromHost();
}

QString Server::processRequest(QByteArray request)
{
    QJsonDocument doc = QJsonDocument::fromJson(request);
    QJsonObject obj = doc.object();
    QJsonValue val = obj["operacion"];
    if(val.isUndefined() || val.isNull() || ! val.isString()) {
        return "Error: no se ha definido la operacion a realizar";
    }
    QString result = "Advertencia: Operacion no soportada";
    QString op = val.toString().trimmed().toLower();
    //Hacer login
    if(op == "login") {
        //result = doLogin(user, pass);
        return "Bienvenido... este es un mensaje por defecto";
    }
    //Obtener archivos
    else if(op == "get_archivos") {
        //result = getArchivos(user);
    }
    //Liberar un archivo
    else if(op == "liberar_archivo") {
        //result = unlockFile(file);
    }
    //Retorno del resultado
    return result;
}
