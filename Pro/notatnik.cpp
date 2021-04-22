#include "notatnik.h"
#include "zeszyt.h"
#include "Rozmiary.h"
#include "rysuj.h"
#include "./ui_notatnik.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>

Notatnik::Notatnik(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notatnik)
{
    ui->setupUi(this);
}

Notatnik::~Notatnik()
{
    delete ui;
}

void Notatnik::on_kartkaA3_triggered()
{
    // Zostaje wyświetlanie zeszytów wraz z ich przechowaniem (lista jednokierunkowa) / lista utworzonych zeszytow
    // Utrzymanie aktywnego okna po wprowadzeniu zlej nazwy
    // polaczenie z QDialogiem i QInputDialogiem

    bool ok;
    QMessageBox messe;
    QString nazwaZeszytu = QInputDialog::getText(this, tr("Nowy zeszyt"),tr("Nazwa zeszytu:"), QLineEdit::Normal, QString(), &ok);
    if(ok) {
        if(!nazwaZeszytu.compare("")) {// jesli jestes pusty
            messe.information(this, "Info", "Wpisz nazwę zeszytu!", true);
        }
        else {
            Zeszyt zeszyt(nazwaZeszytu, rozmiar::A3);
            messe.information(this, "Info", "Udało się stworzyć nowy zeszyt o nazwie " + nazwaZeszytu, true);
            // pokaz wszystkie zeszyty - nie musi tu byc ta opcja
        }
    }
}

void Notatnik::on_pushButton_clicked()
{
    Rysuj r;
    r.setModal(true);
    r.exec();
}
