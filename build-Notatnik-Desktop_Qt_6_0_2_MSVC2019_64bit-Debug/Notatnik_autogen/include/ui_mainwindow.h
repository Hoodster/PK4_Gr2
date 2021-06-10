/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionZapisz;
    QAction *actionNowy;
    QAction *actionOtworz;
    QAction *actionZamknij;
    QAction *actionKolor;
    QAction *actionRozmiar;
    QAction *actionGumka;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuStyl;
    QMenu *menuGumka;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionZapisz = new QAction(MainWindow);
        actionZapisz->setObjectName(QString::fromUtf8("actionZapisz"));
        actionNowy = new QAction(MainWindow);
        actionNowy->setObjectName(QString::fromUtf8("actionNowy"));
        actionOtworz = new QAction(MainWindow);
        actionOtworz->setObjectName(QString::fromUtf8("actionOtworz"));
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QString::fromUtf8("actionZamknij"));
        actionKolor = new QAction(MainWindow);
        actionKolor->setObjectName(QString::fromUtf8("actionKolor"));
        actionRozmiar = new QAction(MainWindow);
        actionRozmiar->setObjectName(QString::fromUtf8("actionRozmiar"));
        actionGumka = new QAction(MainWindow);
        actionGumka->setObjectName(QString::fromUtf8("actionGumka"));
        actionGumka->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuStyl = new QMenu(menubar);
        menuStyl->setObjectName(QString::fromUtf8("menuStyl"));
        menuGumka = new QMenu(menubar);
        menuGumka->setObjectName(QString::fromUtf8("menuGumka"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuStyl->menuAction());
        menubar->addAction(menuGumka->menuAction());
        menuFile->addAction(actionNowy);
        menuFile->addAction(actionOtworz);
        menuFile->addAction(actionZapisz);
        menuFile->addAction(actionZamknij);
        menuStyl->addAction(actionKolor);
        menuStyl->addAction(actionRozmiar);
        menuGumka->addAction(actionGumka);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionZapisz->setText(QCoreApplication::translate("MainWindow", "Zapisz", nullptr));
        actionNowy->setText(QCoreApplication::translate("MainWindow", "Nowy", nullptr));
        actionOtworz->setText(QCoreApplication::translate("MainWindow", "Otworz", nullptr));
        actionZamknij->setText(QCoreApplication::translate("MainWindow", "Zamknij", nullptr));
        actionKolor->setText(QCoreApplication::translate("MainWindow", "Kolor", nullptr));
        actionRozmiar->setText(QCoreApplication::translate("MainWindow", "Rozmiar", nullptr));
        actionGumka->setText(QCoreApplication::translate("MainWindow", "Gumka", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Plik", nullptr));
        menuStyl->setTitle(QCoreApplication::translate("MainWindow", "Styl", nullptr));
        menuGumka->setTitle(QCoreApplication::translate("MainWindow", "Narzedzia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
