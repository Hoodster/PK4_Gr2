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
    poleRysuj->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete poleRysuj;
    delete z.strona;
}

int MainWindow::openDialog()    // okno wyswietlane podczas zamykaniu / otwieraniu zeszytu
{
    QMessageBox dialog(QMessageBox::Question, tr("Notatnik"), tr("Czy chcesz zapisać zmiany?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
    dialog.setButtonText(QMessageBox::Yes, tr("Tak"));
    dialog.setButtonText(QMessageBox::No, tr("Nie"));
    dialog.setButtonText(QMessageBox::Cancel, tr("Anuluj"));
    dialog.setDefaultButton(QMessageBox::Yes);

    return dialog.exec();
}

//void MainWindow::zapiszRysowanie()  // zapisywanie strony stara wersja
//{
//    QImage saveDrawing = poleRysuj->pobierzObraz();
//    QString filePath = QFileDialog::getSaveFileName(this, "Zapisz obraz", "", "PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)");
//    saveDrawing.save(filePath);
//}


void MainWindow::on_actionZapisz_triggered()    // zapisywanie strony nowa wersja
{
    QImage saveDrawing = poleRysuj->pobierzObraz(); // pobranie aktualnej strony
    QString sciezka = "C:/zeszyty/"+z.nazwaZeszytu; // pobieranie glownej sciezki, wraz z nazwa zeszytu
    QString path(sciezka);
    if (!dir.exists(path))
      dir.mkpath(path);     // tworzenie katalogu o podanej nazwie


    QString t = QString::number(z.strona->aktualnyNrStr);   // pobieranie aktualnego numeru strony
    QString fP = sciezka + "/" + t + ".png";    // sciezka do zapisu strony
    saveDrawing.save(fP);       // zapis
}

void MainWindow::on_actionNowy_triggered()  // tworzenie nowego zeszytu
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

        ui->centralwidget->setFixedSize(ui->centralwidget->width(), ui->centralwidget->height());   //dopasowanie rozmiaru, ktory zostal wybrany
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

void MainWindow::on_actionZamknij_triggered()   // zamykanie projektu i ewentualny jego zapis
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

void MainWindow::on_actionKolor_triggered() // zmienianie koloru pedzla / olowka
{
    QColor customColor = QColorDialog::getColor(Qt::white, this, QString("Wybierz kolor"), QColorDialog::ShowAlphaChannel);
    poleRysuj->ustawKolor(customColor);
}

void MainWindow::on_actionRozmiar_triggered()   // ustawianie rozmiaru pedzla / olowka
{
        bool correct = false;

        int size = QInputDialog::getInt(this, "Wybierz rozmiar", "Rozmiar", 1, 1, 50, 1, &correct); // 1- aktualny rozmiar, 1- minimalny rozmiar, 50- maksymalny rozmiar, 1- o ile ma sie zmieniac rozmiar (strzalki)

        if (correct)
        {
            poleRysuj->setBrushWidth(size);
        }
}


void MainWindow::on_actionGumka_triggered() // ustawienie gumki
{
    if(ui->actionGumka->isChecked() == true)    // wybranie gumki
    {
       poleRysuj->ustawPoprzedniKolor(poleRysuj->pobierzKolor());   // zapamietanie poprzedniego koloru olowka
       poleRysuj->ustawKolor(Qt::white);    //ustawia kolor gumki
    }
    if(ui->actionGumka->isChecked() == false) // powrot do uzywania pedzla
    {
        poleRysuj->ustawKolor(poleRysuj->pobierzPoprzedniKolor());  // pobiera kolor z pamieci przed wybraniem gumki
    }
}

void MainWindow::on_actionNastepna_triggered()  // przechodzenie do nastepnej strony zeszytu
{

    on_actionZapisz_triggered();    // zapisanie strony
    if( z.strona->numerStrony > z.strona->aktualnyNrStr) {  // sprawdzenie, czy aktualna strona jest ostatnia w naszym zeszycie

        z.strona->aktualnyNrStr++;  // inkrementacja numeru strony i przejscie na nowa DOBRA strone MOCY! :D
        poleRysuj->otwieranieObrazu(QString::number(z.strona->aktualnyNrStr),z.nazwaZeszytu);   // otworzenie nastepnej strony

    }
    else
    {
        z.strona->dodajStrone(&z.strona);   // dodanie nowej strony
        z.strona->aktualnyNrStr++;  // inkrementacja numeru strony i przejscie na nowa DOBRA strone MOCY! :D
        poleRysuj->clear(); // wyczyszcenie strony
        update();
   }
}

void MainWindow::on_actionPoprzednia_triggered()    // przechodzenie do poprzedniej strony zeszytu
{
    on_actionZapisz_triggered();   //zapisanie strony
    if(z.strona->aktualnyNrStr>1){  // sprawdzenie, czy wyswietlana jest pierwsza strona
        poleRysuj->otwieranieObrazu(QString::number(z.strona->aktualnyNrStr-1),z.nazwaZeszytu);   // otwarcie poprzedniej strony w naszym zeszycie
        z.strona->aktualnyNrStr--;  // dekrementacja numeru strony i przejscie na nowa CIEMNA strone MOCY! :D
    }
}

