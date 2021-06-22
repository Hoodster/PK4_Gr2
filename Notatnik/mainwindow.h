#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <rysuj.h>
#include <zeszyt.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int openDialog();

private:
    Ui::MainWindow *ui;
    rysuj *poleRysuj;
    //Zeszyt zeszyt;

private slots:
    void on_actionZapisz_triggered();
    void on_actionNowy_triggered();
    void on_actionOtworz_triggered();
    void on_actionZamknij_triggered();
    void on_actionKolor_triggered();
    void on_actionRozmiar_triggered();
    void on_actionGumka_triggered();
    void on_actionNastepna_triggered();
};
#endif // MAINWINDOW_H
