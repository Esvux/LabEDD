#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->arbolito = new Arbol;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    Nodo *nodo;
    nodo = new Nodo(25);
    this->arbolito->insertar(nodo);
    nodo = new Nodo(14);
    this->arbolito->insertar(nodo);
    nodo = new Nodo(6);
    this->arbolito->insertar(nodo);
    nodo = new Nodo(34);
    this->arbolito->insertar(nodo);
    nodo = new Nodo(20);
    this->arbolito->insertar(nodo);
    nodo = new Nodo(30);
    this->arbolito->insertar(nodo);
    nodo = new Nodo(21);
    this->arbolito->insertar(nodo);
    this->arbolito->recorrer();
}
