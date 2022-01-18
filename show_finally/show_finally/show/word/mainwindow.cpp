#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "double_link_list.h"
#include "hashtable.h"

#include <QApplication>
#include "tnoded.h"
#include <QDebug>

#define MAX 1000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(QSize(704,449));
    this->setFixedSize(704,449);//固定窗口大小避免拉伸

    //设置背景图片
    QPixmap pixmap = QPixmap("C:\\Users\\ASUS\\Desktop\\show_finally\\show_finally\\show\\image\\bg1.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    //设置统计词频按钮
    QPushButton *btn = new QPushButton(this);
    QIcon icon;
    icon.addFile("C:\\Users\\ASUS\\Desktop\\show_finally\\show_finally\\show\\image\\bg3.png");//设置按钮背景图片
    btn->setIcon(icon);
    btn->setMinimumSize(180,50);
    btn->setMaximumSize(180,50);
    btn->setIconSize(QSize(180,50));
    btn->move(262,304);

    //链接统计函数
    connect(btn, SIGNAL(clicked()), this, SLOT(showdata()));

    path = "";
    //设置选择文件按钮
    QPushButton *btn2 = new QPushButton("选择文件",this);
    btn2->setMinimumSize(210,45);
    btn2->setMaximumSize(210,45);
    btn2->setIconSize(QSize(210,45));
    btn2->move(87,193);
    connect(btn2, SIGNAL(clicked()), this, SLOT(open()));

    //设置下拉列表框格式
    QStringList QList;
    QList<<tr("双链表")<<tr("二叉树")<<tr("哈希表");
    //QComboBox *cbx = new QComboBox(this);
    ui->comboBox->addItems(QList);
    ui->comboBox->setMinimumSize(210,45);
    ui->comboBox->setMaximumSize(210,45);
    ui->comboBox->setIconSize(QSize(210,45));
    ui->comboBox->move(397,193);
    connect(ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(input()));


    //设置文字居中
    QLineEdit *lineEdit2 = new QLineEdit;
    lineEdit2->setReadOnly(true);
    lineEdit2->setAlignment(Qt::AlignCenter);
    ui->comboBox->setLineEdit(lineEdit2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::input()
{
    //输出下拉选项框文本内容,选择算法

    QString str2 = ui->comboBox->currentText();//获取comboBox选项当前内容
    int flag = ui->comboBox->currentIndex();//获取comboBox选项当前索引
    qDebug()<<flag;
    qDebug()<<str2;
    return str2;
}

void MainWindow::showdata()
{
    if(path == "")
    {
        QMessageBox::information(this, "未选择文件路径", "对不起，您尚未选择要进行词频统计的文件路径");
        return;
    }
    new_mainw = new new_main;
    if(ui->comboBox->currentIndex() == 1)
    {
        root = new Tnoded();
        //QMessageBox::information(this, "Loding...", tr("请稍等,正在统计词频..."),QObject::tr(("OK")));
        QProgressDialog dialog(tr("词频统计操作准备开始"),tr("确定开始"),0,50000,this);
        dialog.setWindowTitle(tr("进度条对话框"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int i=0;i<=500000;i++)
        {
            dialog.setValue(i);
            QCoreApplication::processEvents();//防止界面冻结
            if(dialog.wasCanceled()) break; //取消就中断
        }
        root->FileInput(root, path);
        QMessageBox::information(this,tr("系统提示"),tr("统计完毕"),QMessageBox::Ok);
        new_mainw->get_list(root->list);
    }
    else if(ui->comboBox->currentIndex() == 0)
    {
        //QMessageBox::information(this, "Loding...", tr("请稍等,正在统计词频..."),QObject::tr(("OK")));
        QProgressDialog dialog(tr("词频统计操作准备开始"),tr("确定开始"),0,50000,this);
        dialog.setWindowTitle(tr("进度条对话框"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int i=0;i<=500000;i++)
        {
            dialog.setValue(i);
            QCoreApplication::processEvents();//防止界面冻结
            if(dialog.wasCanceled()) break; //取消就中断
        }
        link_list = new double_link_list();
        link_list->initLine();
        link_list->double_link_list_FileInput(path);
        QMessageBox::information(this,tr("系统提示"),tr("统计完毕"),QMessageBox::Ok);
        Doubleline linelist = link_list->get_linelist();
        new_mainw->get_link_list(&linelist);
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        //QMessageBox::information(this, "Loding...", tr("请稍等,正在统计词频..."),QObject::tr(("OK")));
        QProgressDialog dialog(tr("词频统计操作准备开始"),tr("确定开始"),0,50000,this);
        dialog.setWindowTitle(tr("进度条对话框"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int i=0;i<=500000;i++)
        {
            dialog.setValue(i);
            QCoreApplication::processEvents();//防止界面冻结
            if(dialog.wasCanceled()) break; //取消就中断
        }
        hash[0].hash_FileInput(hash, path);
        QMessageBox::information(this,tr("系统提示"),tr("统计完毕"),QMessageBox::Ok);
        new_mainw->get_hash(hash, MAX);

    }
    new_mainw->show();
}

QString MainWindow::open()
{
    this->hide();//选择文件时隐藏主窗口
    //测试,打开一个本地文件选择对话框
    QFileDialog *fileDialog = new QFileDialog(this);//创建对象
    fileDialog->setWindowTitle(tr("打开文件"));//设置文件保存对话框的标题
    //设置默认文件路径
    fileDialog->setDirectory("../");

    //设置文件过滤器,支持的文件类型
    fileDialog->setNameFilter(tr("Images(*.txt)"));

    //设置可以选择文件夹内的多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);

    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    fileDialog->setViewMode(QFileDialog::List);//列表的形式显示
    fileDialog->setGeometry(500,300,600,400);//设置文件对话框的显示位置

    if(fileDialog->exec() == QDialog::Accepted)
    {
        path = fileDialog->selectedFiles()[0];//得到用户选择的第一个文件夹名
        fileDialog->close();
        this->show();//选择文件后窗口重新显示
        return path;
    }
    else
        this->show();//选择文件后窗口重新显示
        return "未找到文件";
}
