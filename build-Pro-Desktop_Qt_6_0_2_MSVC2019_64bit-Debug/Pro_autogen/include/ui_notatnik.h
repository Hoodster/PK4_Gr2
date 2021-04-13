/********************************************************************************
** Form generated from reading UI file 'notatnik.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTATNIK_H
#define UI_NOTATNIK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notatnik
{
public:
    QAction *kartkaA3;
    QAction *kartkaA4;
    QAction *kartkaA5;
    QWidget *centralwidget;
    QWidget *PanelNazwyZeszytu;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuDodaj_Zeszyt;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Notatnik)
    {
        if (Notatnik->objectName().isEmpty())
            Notatnik->setObjectName(QString::fromUtf8("Notatnik"));
        Notatnik->setEnabled(true);
        Notatnik->resize(800, 600);
        kartkaA3 = new QAction(Notatnik);
        kartkaA3->setObjectName(QString::fromUtf8("kartkaA3"));
        kartkaA4 = new QAction(Notatnik);
        kartkaA4->setObjectName(QString::fromUtf8("kartkaA4"));
        kartkaA5 = new QAction(Notatnik);
        kartkaA5->setObjectName(QString::fromUtf8("kartkaA5"));
        centralwidget = new QWidget(Notatnik);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PanelNazwyZeszytu = new QWidget(centralwidget);
        PanelNazwyZeszytu->setObjectName(QString::fromUtf8("PanelNazwyZeszytu"));
        PanelNazwyZeszytu->setGeometry(QRect(280, 200, 241, 151));
        buttonBox = new QDialogButtonBox(PanelNazwyZeszytu);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 110, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(PanelNazwyZeszytu);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 30, 181, 21));
        Notatnik->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Notatnik);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuDodaj_Zeszyt = new QMenu(menuMenu);
        menuDodaj_Zeszyt->setObjectName(QString::fromUtf8("menuDodaj_Zeszyt"));
        Notatnik->setMenuBar(menubar);
        statusbar = new QStatusBar(Notatnik);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Notatnik->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuDodaj_Zeszyt->menuAction());
        menuDodaj_Zeszyt->addAction(kartkaA3);
        menuDodaj_Zeszyt->addAction(kartkaA4);
        menuDodaj_Zeszyt->addAction(kartkaA5);

        retranslateUi(Notatnik);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PanelNazwyZeszytu, qOverload<>(&QWidget::hide));

        QMetaObject::connectSlotsByName(Notatnik);
    } // setupUi

    void retranslateUi(QMainWindow *Notatnik)
    {
        Notatnik->setWindowTitle(QCoreApplication::translate("Notatnik", "Notatnik", nullptr));
        kartkaA3->setText(QCoreApplication::translate("Notatnik", "A3", nullptr));
        kartkaA4->setText(QCoreApplication::translate("Notatnik", "A4", nullptr));
        kartkaA5->setText(QCoreApplication::translate("Notatnik", "A5", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("Notatnik", "Menu", nullptr));
        menuDodaj_Zeszyt->setTitle(QCoreApplication::translate("Notatnik", "Dodaj Zeszyt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notatnik: public Ui_Notatnik {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTATNIK_H
