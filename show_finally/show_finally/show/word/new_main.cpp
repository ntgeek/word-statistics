#include "new_main.h"
#include "ui_new_main.h"
#include "double_link_list.h"
#include <QDebug>
#include <QTableWidget>
#include <QFile>


new_main::new_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::new_main)
{
    ui->setupUi(this);

    //打开统计结果窗口
    QDialog *dialog = new QDialog(this);
    this->hide();
    QPushButton *btn1 = new QPushButton(this);
    QPushButton *btn2 = new QPushButton(this);
    QPushButton *btn3 = new QPushButton(this);
    //QTableWidget *table=new QTableWidget(this);
    QIcon icon3;
    QIcon icon2;
    QIcon icon1;

    //设置保存按钮
    icon2.addFile("C:\\Users\\ASUS\\Desktop\\show_finally\\show_finally\\show\\image\\save.png");
    btn2->setIcon(icon2);
    btn2->setMinimumSize(116,50);
    btn2->setMaximumSize(116,50);
    btn2->setIconSize(QSize(116,50));
    btn2->move(157,320);
    connect(btn2, SIGNAL(clicked()), this, SLOT(open()));

    //设置关闭按钮
    icon1.addFile("C:\\Users\\ASUS\\Desktop\\show_finally\\show_finally\\show\\image\\close.png");
    btn1->setIcon(icon1);
    btn1->setMinimumSize(116,50);
    btn1->setMaximumSize(116,50);
    btn1->setIconSize(QSize(116,50));
    btn1->move(432,320);
    connect(btn1, SIGNAL(clicked()), this, SLOT(end()));

    //设置排序按钮
    icon3.addFile("C:\\Users\\ASUS\\Desktop\\show_finally\\show_finally\\show\\image\\sort.png");
    btn3->setIcon(icon3);
    btn3->setMinimumSize(116,50);
    btn3->setMaximumSize(116,50);
    btn3->setIconSize(QSize(116,50));
    btn3->move(297,320);
    connect(btn3, &QPushButton::clicked, this, &new_main::begin_sort_tnoded);
    //connect(btn2, SIGNAL(clicked()), this, SLOT(Save2()));

    //设置背景图片
    this->setWindowTitle("统计结果");
    this->resize(QSize(704,449));
    this->setFixedSize(704,449);//固定窗口大小避免拉伸
    QPixmap pixmap = QPixmap("C:\\Users\\ASUS\\Desktop\\show_finally\\show_finally\\show\\image\\bg2.png").scaled(this->size());
    QPalette palette(dialog->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    this->show();

    sort_up = 1;//默认升序排列
}

void new_main::output_list_tnoded(QList<Tnoded*> &list)
{
    for(int i = 0; i < list.size(); i++)
    {
       qDebug() << list.at(i)->get_word() << "=" << list.at(i)->get_count();
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(list.at(i)->get_word()));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(list.at(i)->get_count())));
    }
}

void new_main::quick_sort_tnoded_up(QList<Tnoded*> &list, int left, int right)
{

    if (left < right)
    {
        int i = left, j = right;
        Tnoded* pivot = list.at(left);
        while (i < j)
        {
            while(i < j && list.at(j)->get_count() >= pivot->get_count())
            {
                j--;
            }
            if(i < j)
            {
                list.swap(i++, j);
            }
            while(i < j && list.at(i)->get_count() < pivot->get_count())
            {
                i++;
            }
            if(i < j)
                list.swap(j--, i);
        }
        list.replace(i, pivot);
        quick_sort_tnoded_up(list, left, i - 1); // 递归调用
        quick_sort_tnoded_up(list, i + 1, right);
    }
}

void new_main::quick_sort_tnoded_down(QList<Tnoded*> &list, int left, int right)
{

    if (left < right)
    {
        int i = left, j = right;
        Tnoded* pivot = list.at(left);
        while (i < j)
        {
            while(i < j && list.at(j)->get_count() <= pivot->get_count())
            {
                j--;
            }
            if(i < j)
            {
                list.swap(i++, j);
            }
            while(i < j && list.at(i)->get_count() > pivot->get_count())
            {
                i++;
            }
            if(i < j)
                list.swap(j--, i);
        }
        list.replace(i, pivot);
        quick_sort_tnoded_down(list, left, i - 1); // 递归调用
        quick_sort_tnoded_down(list, i + 1, right);
    }
}

void new_main::begin_sort_tnoded()
{
    if(which_data_struct != 1)
    {
        QMessageBox::warning(this, "此数据结构不是二叉树", "对不起，当前所选数据结构并非二叉树，因此未能提供排序功能！");
        return;
    }
    if(sort_up == 1)
    {
        quick_sort_tnoded_up(list, 0, list.length()-1);
        sort_up = 0;
    }
    else
    {
        quick_sort_tnoded_down(list, 0, list.length()-1);
        sort_up = 1;
    }
    qDebug() << "begin sort-----------------------------------------------------";
    output_list_tnoded(list);
}

void new_main::get_list(QList<Tnoded*> list)
{
    which_data_struct = 1;
    this->list = list;
    ui->tableWidget->setItem(-1, 0, new QTableWidgetItem("单词"));
    ui->tableWidget->setItem(-1, 1, new QTableWidgetItem("频率"));
    //统计结果展示窗口，写入你们跑出来的数据
    for(int i = 0; i < list.size(); i++)
    {
       //添加新行
       ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(list.at(i)->get_word()));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(list.at(i)->get_count())));
    }
}

new_main::~new_main()
{
    delete ui;
}

/*
 * 哈希表
 */
void new_main::get_hash(HashTable *hash, int max)
{
    which_data_struct = 2;
    this->hash = hash;
    this->max = max;
    ui->tableWidget->setItem(-1, 0, new QTableWidgetItem("单词"));
    ui->tableWidget->setItem(-1, 1, new QTableWidgetItem("频率"));
    int count = 0;
    HashTable *p = NULL;
    for(int i = 0;i<max;i++)
    {
        if(hash[i].get_count()!=0)
        {
            //qDebug() << hash[i].get_word() << " = " << hash[i].get_count();
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(count,0,new QTableWidgetItem(hash[i].get_word()));
            ui->tableWidget->setItem(count,1,new QTableWidgetItem(QString::number(hash[i].get_count())));
            count++;
        }
        if(hash[i].next)
        {
            p = hash[i].next;
            while(p)
            {
                //qDebug() << p->get_word() << " = " << p->get_count();
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(count,0,new QTableWidgetItem(hash[i].get_word()));
                ui->tableWidget->setItem(count,1,new QTableWidgetItem(QString::number(hash[i].get_count())));
                p=p->next;
                count++;
            }
        }
    }
}

void new_main::Save()
{
    //保存文件操作
    this->show();
}

void new_main::end()
{
    this->close();
}

/*
 * 双向链表
 */
void new_main::get_link_list(Doubleline* link_list)
{
    which_data_struct = 0;
    this->link_list = link_list;
    line* p = link_list->head->next;
    int i = 0;
    for(; p != NULL ;p = p->next)
    {
        //qDebug << p->data.words << " " << p->data.number;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->data.words));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(p->data.number)));
        i++;
    }
}

void new_main::Save_link_list()
{
    //QString fileName = QFileDialog::getSaveFileName(this,tr("保存统计结果"),"",tr("统计结果(*.txt)"));
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::critical(this, "文件保存失败", tr("您已取消保存！"),QMessageBox::Yes, QMessageBox::Yes);
    }
    else
    {
        QTextStream stream(&file);
        line* p = link_list->head->next;
        for(; p != NULL ;p = p->next)
        {
            stream << p->data.words << " " << p->data.number << "\n";
        }
        file.close();
        QMessageBox::information(this, "保存成功", "词频统计结果已经成功保存到文件中！");
        qDebug() << "finshi";
    }
}

void new_main::Save_binary_tree()
{
    //QString fileName = QFileDialog::getSaveFileName(this,tr("保存统计结果"),"",tr("统计结果(*.txt)"));
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::critical(this, "文件保存失败", tr("您已取消保存！"),QMessageBox::Yes, QMessageBox::Yes);
    }
    else
    {
        QTextStream stream(&file);
        for(int i = 0; i < list.size(); i++)
        {
           stream << list.at(i)->get_word() << " " << list.at(i)->get_count() << "\n";
        }
        file.close();
        QMessageBox::information(this, "保存成功", "词频统计结果已经成功保存到文件中！");
        qDebug() << "finshi";
    }
}

void new_main::Save_hash()
{
    //QString fileName = QFileDialog::getSaveFileName(this,tr("保存统计结果"),"",tr("统计结果(*.txt)"));
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::critical(this, "文件保存失败", tr("您已取消保存！"),QMessageBox::Yes, QMessageBox::Yes);
    }
    else
    {
        QTextStream stream(&file);
        for(int i = 0; i < list.size(); i++)
        {
           stream << list.at(i)->get_word() << " " << list.at(i)->get_count() << "\n";
        }
        HashTable *p = NULL;
        for(int i = 0; i < max; i++)
        {
            if(hash[i].get_count()!=0)
            {
                stream << hash[i].get_word() << " " << hash[i].get_count() << "\n";
            }
            if(hash[i].next)
            {
                p = hash[i].next;
                while(p)
                {
                    stream << p->get_word() << " " << p->get_count() << "\n";
                    p=p->next;
                }
            }
        }
        file.close();
        QMessageBox::information(this, "保存成功", "词频统计结果已经成功保存到文件中！");
        qDebug() << "finshi";
    }
}

void new_main::open()
{
    this->hide();//选择文件时隐藏主窗口
    //测试,打开一个本地文件选择对话框
    QFileDialog *fileDialog = new QFileDialog(this);//创建对象
    fileDialog->setWindowTitle(tr("打开文件"));//设置文件保存对话框的标题
    //设置默认文件路径
    fileDialog->setDirectory("../");

    //设置文件过滤器,支持的文件类型
    fileDialog->setNameFilter(tr("*"));

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
        if(which_data_struct == 0)
        {
            Save_link_list();
        }
        else if(which_data_struct == 1)
        {
            Save_binary_tree();
        }
        else if(which_data_struct == 2)
        {

        }
    }
    else
    {
        this->show();//选择文件后窗口重新显示
        QMessageBox::warning(this, "未找到文件" ,"对不起，您选择的文件并不存在");
    }
}







