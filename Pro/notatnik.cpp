#include "notatnik.h"
#include "Rozmiary.h"
#include "./ui_notatnik.h"

Notatnik::Notatnik(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notatnik)
{
    ui->setupUi(this);
    rozmiary R = rozmiary::A3;

}

Notatnik::~Notatnik()
{
    delete ui;
}

