/********************************************************************************
** Form generated from reading UI file 'new_main.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_MAIN_H
#define UI_NEW_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_main
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *new_main)
    {
        if (new_main->objectName().isEmpty())
            new_main->setObjectName(QString::fromUtf8("new_main"));
        new_main->resize(800, 600);
        centralwidget = new QWidget(new_main);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(140, 130, 421, 181));
        new_main->setCentralWidget(centralwidget);
        menubar = new QMenuBar(new_main);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        new_main->setMenuBar(menubar);
        statusbar = new QStatusBar(new_main);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        new_main->setStatusBar(statusbar);

        retranslateUi(new_main);

        QMetaObject::connectSlotsByName(new_main);
    } // setupUi

    void retranslateUi(QMainWindow *new_main)
    {
        new_main->setWindowTitle(QApplication::translate("new_main", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("new_main", "\345\215\225\350\257\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("new_main", "\351\242\221\347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_main: public Ui_new_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_MAIN_H
