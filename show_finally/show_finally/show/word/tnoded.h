#ifndef TNODED_H
#define TNODED_H

#include<QString>
#include<QList>


class Tnoded
{
public:
    /*
    每当初始化一个节点，也就是意味着出现了一个新的单词，因此此时count默认已经记录了一个
    同时初始化左右子树分别为NULL
    */
    Tnoded();
    /*
    将节点变成对应字符
    */
    void change_word(QString word);
    QString get_word();
    Tnoded* get_left();
    void change_left(Tnoded* left);
    Tnoded* get_right();
    void change_right(Tnoded* right);
    void count_add();
    int get_count();
    void put_into_list(Tnoded* traverse, QList<Tnoded*> &list);
    void test_output(Tnoded *traverse);
    void first_creat_binery_tree(Tnoded* root, QString &text);
    void creat_binery_tree(Tnoded* root, QString &text);
    void init_root(Tnoded* root, QString &text);
    void add_Tnode(Tnoded* traverse, QString &temp_string);
    void FileInput(Tnoded* root, QString &path);

    /*
     *这个在做排序的时候可以先把所有的内容都放到一共数组中，而数组的大小就是树的
     *节点个数，这个节点格式就可以靠这个在树的生成过程中动态生成
     */
    static int how_many;
    QList<Tnoded*> list;

private:
    QString word;
    int count;
    Tnoded *left;
    Tnoded *right;
};

#endif // TNODED_H
