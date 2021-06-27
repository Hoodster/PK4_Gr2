#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zeszyt.h"
#include <QColorDialog>
#include <QScrollArea>
#include <QDirIterator>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      poleRysuj(new rysuj(this))
{   
    ui->setupUi(this);
    //QMainWindow::showFullScreen();
    poleRysuj->hide();
    //setCentralWidget(poleRysuj);
    //ui->menuStrona->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete poleRysuj;
    delete z.strona;
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

void MainWindow::zapiszRysowanie()
{
    QImage saveDrawing = poleRysuj->pobierzObraz();
    QString filePath = QFileDialog::getSaveFileName(this, "Zapisz obraz", "", "PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)");
    saveDrawing.save(filePath);
}


void MainWindow::on_actionZapisz_triggered()
{
    QImage saveDrawing = poleRysuj->pobierzObraz();
    QString sciezka = "C:/rys";
    QString path(sciezka);
    if (!dir.exists(path))
      dir.mkpath(path);


    QString t = QString::number(z.strona->aktualnyNrStr);
    QString fP = sciezka + "/" + t + ".png";
    saveDrawing.save(fP);
    //saveDrawing.save(filePath);
}

void MainWindow::on_actionNowy_triggered()
{
    bool ok;
    QMessageBox mess;
    QString nazwaZesz = QInputDialog::getText(this, tr("Nowy zeszyt"), tr("Nazwa zeszytu:"), QLineEdit::Normal, QString(), &ok);
    if(!nazwaZesz.compare(""))
        mess.information(this, "Informacja", "Wpisz nazwe zeszytu!", true);
    else {


        z.dodajZeszyt(nazwaZesz);
        z.strona->dodajStrone(&z.strona);


        mess.information(this, "Informacja", "Udalo się stworzyć zeszyt o nazwie " + nazwaZesz, true);
        QStringList rozmiary;
        rozmiary << "A3" << "A4" << "A5";
        QString rozmiar = QInputDialog::getItem(this, "Wybierz rozmiar kartki", "Rozmiar:", rozmiary);

        if(!rozmiar.compare("A3")) {
            ui->centralwidget->resize(1133, 1587);
        }
        else if(!rozmiar.compare("A4")) {
            ui->centralwidget->resize(793, 1133);
        }
        else if(!rozmiar.compare("A5")) {
            ui->centralwidget->resize(566, 793);
        }

        ui->centralwidget->setFixedSize(ui->centralwidget->width(), ui->centralwidget->height());
        poleRysuj->show();
        setCentralWidget(poleRysuj);
        poleRysuj->setWindowTitle(nazwaZesz);
        poleRysuj->start();
        update();
    }

}

void MainWindow::on_actionOtworz_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionZapisz_triggered();
       poleRysuj->otworzObraz();
    }
    else if(dialog == QMessageBox::No)
    {
        poleRysuj->otworzObraz();
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
    poleRysuj->ustawKolor(customColor);
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
       poleRysuj->ustawPoprzedniKolor(poleRysuj->pobierzKolor());
       poleRysuj->ustawKolor(Qt::white);
    }
    if(ui->actionGumka->isChecked() == false)
    {
        poleRysuj->ustawKolor(poleRysuj->pobierzPoprzedniKolor());
    }
}

void MainWindow::on_actionNastepna_triggered()
{

    on_actionZapisz_triggered();
    if( z.strona->numerStrony > z.strona->aktualnyNrStr) {

        z.strona->aktualnyNrStr++;
        poleRysuj->otwieranieObrazu(QString::number(z.strona->aktualnyNrStr));

    }
    else
    {  // numer strony jest rowny 1 i tu dodajemy strone

        z.strona->dodajStrone(&z.strona);
        z.strona->aktualnyNrStr++;
        // inkrementacja numeru strony i przejscie na nowa strone MOCY! :D
        poleRysuj->clear();
        update();
   }
}

void MainWindow::on_actionPoprzednia_triggered()
{
 on_actionZapisz_triggered();

    if(z.strona->aktualnyNrStr>1){
      poleRysuj->otwieranieObrazu(QString::number(z.strona->aktualnyNrStr-1));

      z.strona->aktualnyNrStr--;
    }

}

