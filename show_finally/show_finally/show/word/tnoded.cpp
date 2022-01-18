#include "tnoded.h"
#include <QDebug>
#include <QFile>
Tnoded::Tnoded()
{
    this->count = 1;
    this->left = NULL;
    this->right = NULL;
    Tnoded::how_many++;
}

void Tnoded::change_word(QString word)
{
    this->word = word;
}

QString Tnoded::get_word()
{
    return this->word;
}

Tnoded* Tnoded::get_left()
{
    return this->left;
}

void Tnoded::change_left(Tnoded* left)
{
    this->left = left;
}

Tnoded* Tnoded::get_right()
{
    return this->right;
}

void Tnoded::change_right(Tnoded* right)
{
    this->right = right;
}

void Tnoded::count_add()
{
    ++(this->count);
}

int Tnoded::get_count()
{
    return count;
}

int Tnoded::how_many = 0;

void Tnoded::add_Tnode(Tnoded* traverse, QString &temp_string)
{
    Tnoded* temp_node = NULL;
    while (true)
    {
        if ((temp_string).compare(traverse->get_word()) < 0)
        {
            if (traverse->get_left() == NULL)
            {
                Tnoded *new_word = new Tnoded();
                new_word->change_word(temp_string);
                traverse->change_left(new_word);
                break;
            }
            else
            {
                temp_node = traverse->get_left();
                traverse = temp_node;
            }
        }
        else if ((temp_string).compare(traverse->get_word()) == 0)
        {
            traverse->count_add();
            break;
        }
        else if ((temp_string).compare(traverse->get_word()) > 0)
        {
            if (traverse->get_right() == NULL)
            {
                Tnoded *new_word = new Tnoded();
                new_word->change_word(temp_string);
                traverse->change_right(new_word);
                break;
            }
            else
            {
                temp_node = traverse->get_right();
                traverse = temp_node;
            }
        }
    }
}

void Tnoded::init_root(Tnoded* root, QString &text)
{
    QString concat_word = "";
    QString text_word;
    for(int i = 0; i < text.length(); i++)
    {
        text_word = text[i];
        if(QString::compare(text_word, "Z", Qt::CaseSensitive) <= 0 && QString::compare(text_word, "A", Qt::CaseSensitive) >= 0)
        {
            concat_word += text_word.toLower();
        }
        else if(QString::compare(text_word, "z", Qt::CaseSensitive) <= 0 && QString::compare(text_word, "a", Qt::CaseSensitive) >= 0)
        {
            concat_word += text_word;
        }
        else if(QString::compare(text_word, " ", Qt::CaseSensitive) == 0)
        {
            if(concat_word == "")
            {
                continue;
            }
            root->change_word(concat_word);
            break;
        }
        else
        {
            if(concat_word == "")
            {
                concat_word += text_word;
                root->change_word(concat_word);
                break;
            }
            else
            {
                root->change_word(concat_word);
                concat_word = text_word;
                add_Tnode(root, concat_word);
                break;
            }
        }
    }
}



/*
参数：传入二叉树根节点(应该是一个空的节点，但是是一个已经分配了空间的位置)，文件中的一段文字
主要目的是对文件中的文字进行拆分
*/
void Tnoded::creat_binery_tree(Tnoded* root, QString &text)
{
    /*
    需要进行递归遍历,首先需要一个存放新单词的节点，然后需要一个指向当前位置的指针
    */
    QString concat_word = "";

    QString text_word;
    for(int i = 0; i < text.length(); i++)
    {
        text_word = text[i];
        if(QString::compare(text_word, "Z", Qt::CaseSensitive) <= 0 && QString::compare(text_word, "A", Qt::CaseSensitive) >= 0)
        {
            concat_word += text_word.toLower();
        }
        else if(QString::compare(text_word, "z", Qt::CaseSensitive) <= 0 && QString::compare(text_word, "a", Qt::CaseSensitive) >= 0)
        {
            concat_word += text_word;
        }
        else if(QString::compare(text_word, " ", Qt::CaseSensitive) == 0)
        {
            if(concat_word == "")
            {
                continue;
            }
            add_Tnode(root, concat_word);
            concat_word = "";
        }
        else
        {
            /*
            此时不出意外应该是其他字符了
            */
            if(concat_word == "")
            {
                concat_word += text[i];
                add_Tnode(root, concat_word);
                concat_word = "";
            }
            else
            {
                add_Tnode(root, concat_word);
                concat_word = text[i];
                add_Tnode(root, concat_word);
                concat_word = "";
            }
        }
    }
}

void Tnoded::first_creat_binery_tree(Tnoded* root, QString &text)
{

    init_root(root, text);
    /*
    需要进行递归遍历,首先需要一个存放新单词的节点，然后需要一个指向当前位置的指针
    */
    QString concat_word = "";

    QString text_word;
    for(int i = 0; i < text.length(); i++)
    {
        text_word = text[i];
        if(QString::compare(text_word, "Z", Qt::CaseSensitive) <= 0 && QString::compare(text_word, "A", Qt::CaseSensitive) >= 0)
        {
            concat_word += text_word.toLower();
        }
        else if(QString::compare(text_word, "z", Qt::CaseSensitive) <= 0 && QString::compare(text_word, "a", Qt::CaseSensitive) >= 0)
        {
            concat_word += text_word;
        }
        else if(QString::compare(text_word, " ", Qt::CaseSensitive) == 0)
        {
            if(concat_word == "")
            {
                continue;
            }
            add_Tnode(root, concat_word);
            concat_word = "";
        }
        else
        {
            /*
            此时不出意外应该是其他字符了
            */
            if(concat_word == "")
            {
                concat_word += text[i];
                add_Tnode(root, concat_word);
                concat_word = "";
            }
            else
            {
                add_Tnode(root, concat_word);
                concat_word = text[i];
                add_Tnode(root, concat_word);
                concat_word = "";
            }
        }
    }
}

void Tnoded::test_output(Tnoded *traverse)
{
    if (traverse != NULL)
    {
        test_output(traverse->get_left());
        qDebug() << traverse->get_word() << "=" << traverse->get_count();
        test_output(traverse->get_right());
    }
}

void Tnoded::put_into_list(Tnoded* traverse, QList<Tnoded*> &list)
{
    if (traverse != NULL)
    {
        put_into_list(traverse->get_left(), list);
        list.append(traverse);
        put_into_list(traverse->get_right(), list);
    }
}

void Tnoded::FileInput(Tnoded* root, QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    if(!line.isNull())
    {
        first_creat_binery_tree(root, line);
    }
    line = in.readLine();
    int i = 0;
    while (!line.isNull())
    {
        i++;
        qDebug() << Tnoded::how_many << "第" << i << "轮";
        creat_binery_tree(root, line);
        line = in.readLine();
    }
    qDebug() << "testing!!!!!!!!";
    test_output(root);
    put_into_list(root, this->list);
}

