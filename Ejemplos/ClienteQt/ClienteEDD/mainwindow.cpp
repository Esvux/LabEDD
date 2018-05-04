#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::enviarPeticion(double monto) {
    QString json = tr("{\"kiosco\":\"K052336\",\"monto\":%1}").arg(monto);

    // create custom temporary event loop on stack
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req( QUrl( URL_BASE + QString("/tickets") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.post(req, json.toUtf8());
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
        //process response
        QByteArray response = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(response);
        QJsonObject obj = document.object();
        ui->codigoTicket->setText(QString::number(obj["numero"].toInt()));
        ui->verificacionTicket->setText(obj["verificacion"].toString());
        qDebug() << "Success\n" << response;
        delete reply;
    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}

void MainWindow::on_pushButton5Q_clicked() {
    enviarPeticion(5.00);
}

void MainWindow::on_pushButton30Q_clicked() {
    enviarPeticion(30.00);
}

void MainWindow::on_pushButton50Q_clicked() {
    enviarPeticion(50.00);
}

void MainWindow::on_pushButton100Q_clicked() {
    enviarPeticion(100.00);
}
