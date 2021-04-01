#include "notatnik.h"
#include "./ui_notatnik.h"

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

