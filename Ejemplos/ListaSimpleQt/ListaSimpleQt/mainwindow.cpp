#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->customerList = new SimpleList();
}

MainWindow::~MainWindow() {
    delete ui;
    delete this->customerList;
}

void MainWindow::on_pushButton_clicked() {
    QString name = ui->txtCustomerName->text();
    QString taxId = ui->txtCustomerTaxId->text();
    SimpleNode* node = new SimpleNode(name, taxId);
    this->customerList->insert(node);
    this->updateCustomerTable();
}

void MainWindow::updateCustomerTable() {
    customerList->fillTable(ui->tableWidgetCustomer);
}
