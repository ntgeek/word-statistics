#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QString>
#include <QDialog>
#include <QDebug>
#include <QList>
#include <QProgressDialog>

#include "new_main.h"
#include "tnoded.h"
#include "double_link_list.h"
#include "hashtable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    new_main *new_mainw;
    ~MainWindow();
    void FileInput();


private slots:
    void showdata();
    QString input();
    QString open();

private:
    Ui::MainWindow *ui;
    QString path;
    Tnoded* root;
    double_link_list* link_list;
    HashTable hash[1000];
};

#endif // MAINWINDOW_H
