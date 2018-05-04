#include <QtNetwork>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString donador = ui->lineEdit->text();
    QString monto = ui->lineEdit_2->text();
    QString voucher = ui->lineEdit_3->text();
    QString json = tr("{\"donador\":\"%1\",\"monto\":%2,\"voucher\":\"%3\"}").arg(donador, monto, voucher);

    // create custom temporary event loop on stack
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req( QUrl( QString("http://localhost:8080/DemoServidorEDD-web-1.0-SNAPSHOT/rest/donaciones") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.post(req, json.toUtf8());
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << "Success" <<reply->readAll();
        delete reply;
    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}
