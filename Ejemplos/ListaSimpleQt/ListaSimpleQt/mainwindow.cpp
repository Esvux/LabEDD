#include <QFile>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jsonreader.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->simpleCustomerList = new SimpleList();
    this->doubleCustomerList = new DoubleList();
}

MainWindow::~MainWindow() {
    delete ui;
    delete this->simpleCustomerList;
    delete this->doubleCustomerList;
}

void MainWindow::on_pushButton_clicked() {
    QString name = ui->txtCustomerName->text();
    QString taxId = ui->txtCustomerTaxId->text();
    SimpleNode* node = new SimpleNode(name, taxId);
    this->simpleCustomerList->insert(node);
    this->updateCustomerTable();
}

void MainWindow::updateCustomerTable() {
    this->simpleCustomerList->fillTable(ui->tableWidgetCustomer);
}

void MainWindow::on_pushButton_2_clicked() {
    QString fileName = QFileDialog::getOpenFileName(NULL, tr("JSON de clientes"));
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QByteArray ba = file.readAll();

    free(this->doubleCustomerList);
    this->doubleCustomerList = NULL;
    this->doubleCustomerList = new DoubleList();

    JsonReader::fillListFromFile(this->doubleCustomerList, ba);
    this->doubleCustomerList->fillTable(ui->tableWidget);
}
