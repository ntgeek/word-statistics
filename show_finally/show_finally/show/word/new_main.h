#ifndef NEW_MAIN_H
#define NEW_MAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QDialog>
#include <QTableWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QScrollArea>
#include <QLabel>
#include <QWidget>
#include <QList>
#include "tnoded.h"
#include "double_link_list.h"
#include "hashtable.h"
namespace Ui {
class new_main;
}

class new_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit new_main(QWidget *parent = nullptr);
    void get_list(QList<Tnoded*> list);
    void begin_sort_tnoded();
    void get_link_list(Doubleline* link_list);
    void get_hash(HashTable *hash, int max);
    void quick_sort_tnoded_up(QList<Tnoded*> &list, int left, int right);
    void quick_sort_tnoded_down(QList<Tnoded*> &list, int left, int right);
    void Save_link_list();
    void Save_binary_tree();
    void Save_hash();
    ~new_main();

private slots:
    void end();
    void Save();

    void open();


    void output_list_tnoded(QList<Tnoded*> &list);


private:
    Ui::new_main *ui;
    QLabel *pLabelTitle; //放置滚动页面
    QLabel *pLabelGetInfo;//显示滚动信息
    QScrollArea *scrollArea;//滚动页面
    QScrollBar *scrollBar;//滚动条
    QList<Tnoded*> list;
    Doubleline* link_list;
    HashTable* hash;
    int which_data_struct;//记录当前使用的是什么数据结构 0双向链表 1二叉树 2哈希表
    int max;
    int sort_up;//判断当前是否点击了一次排序，用来更换升序和降序排列算法
    QString path;//用户选择的保存文件路径名

};

#endif // NEW_MAIN_H
