#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton5Q_clicked();

    void on_pushButton30Q_clicked();

    void on_pushButton50Q_clicked();

    void on_pushButton100Q_clicked();

private:
    const QString URL_BASE = "http://localhost:8080/UrbanEDD/rest";
    Ui::MainWindow *ui;
    void enviarPeticion(double monto);
};
#endif // MAINWINDOW_H
