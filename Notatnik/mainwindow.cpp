#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      poleRysuj(new rysuj(this))
{
    ui->setupUi(this);
    QMainWindow::showFullScreen();
    setCentralWidget(poleRysuj);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete poleRysuj;
}

int MainWindow::openDialog()
{
    QMessageBox dialog(QMessageBox::Question, tr("Notatnik"), tr("Czy chcesz zapisać zmiany?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
    dialog.setButtonText(QMessageBox::Yes, tr("Tak"));
    dialog.setButtonText(QMessageBox::No, tr("Nie"));
    dialog.setButtonText(QMessageBox::Cancel, tr("Anuluj"));
    dialog.setDefaultButton(QMessageBox::Yes);

    return dialog.exec();
}


void MainWindow::on_actionZapisz_triggered()
{
    QImage saveDrawing = poleRysuj->getImage();
    QString filePath = QFileDialog::getSaveFileName(this, "Zapisz obraz", "", "PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)");
    saveDrawing.save(filePath);
}

void MainWindow::on_actionNowy_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionZapisz_triggered();
       poleRysuj->start();
       update();
    }
    else if(dialog == QMessageBox::No)
    {
        poleRysuj->start();
        update();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}

void MainWindow::on_actionOtworz_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionZapisz_triggered();
       poleRysuj->openImage();
    }
    else if(dialog == QMessageBox::No)
    {
        poleRysuj->openImage();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}

void MainWindow::on_actionZamknij_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionZapisz_triggered();
       QApplication::quit();
    }
    else if(dialog == QMessageBox::No)
    {
        QApplication::quit();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}

void MainWindow::on_actionKolor_triggered()
{
    QColor customColor = QColorDialog::getColor(Qt::white, this, QString("Wybierz kolor"), QColorDialog::ShowAlphaChannel);
    poleRysuj->setColor(customColor);
}

void MainWindow::on_actionRozmiar_triggered()
{
        bool correct = false;

        int size = QInputDialog::getInt(this, "Wybierz rozmiar", "Rozmiar", 1, 1, 50, 1, &correct);

        if (correct)
        {
            poleRysuj->setBrushWidth(size);
        }
}


void MainWindow::on_actionGumka_triggered()
{
    if(ui->actionGumka->isChecked() == true)
    {
       poleRysuj->setPrevColor(poleRysuj->getColor());
       poleRysuj->setColor(Qt::white);
    }
    if(ui->actionGumka->isChecked() == false)
    {
        poleRysuj->setColor(poleRysuj->getPrevColor());
    }
}
