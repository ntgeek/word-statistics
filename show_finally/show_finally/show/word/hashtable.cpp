#include "hashtable.h"
#include <QDebug>
#include <QFile>
#define MAX 1000

HashTable::HashTable()
{

}



int HashTable::how_many = 0;

/*
计算单词长度
*/
int HashTable::HashIndex(QString &str)
{
    char* ch;
    QByteArray ba = str.toLatin1();
    ch = ba.data();
    long sum = 0;
    for(int i = 0;ch[i];i++)
    {
        sum=sum+ch[i];
    }

    //qDebug() << "sum = " << sum;
    return (int)(sum%MAX);
}

/*
散列表
参数：单词
*/
void HashTable::CTable(QString &str, HashTable hash[])
{
    int flag = 0;
    int index = HashIndex(str);
    //qDebug() << "index = " <<index;
    HashTable *p,*q;
    //    if(hash[index].count==0||strcmp(hash[index].word,str)==0)
    if(hash[index].count == 0 || QString::compare(hash[index].word, str) == 0)
    {
        hash[index].count++;
        //strcpy(hash[index].word,str);
        hash[index].word = str;
        qDebug() << hash[index].word << " = " << hash[index].count;
    }
    else
    {
        if(hash[index].next == NULL)
        {
            //p=(HashTable *)malloc(sizeof(HashTable));
            p = new HashTable();
            if(!p)
            {
                //回头改一个Qmessagebox
                qDebug() <<"No enough memory!";
                exit(-1);
            }
            p->count=1;
            p->next=NULL;
            //strcpy(p->word,str);
            p->word = str;
            hash[index].next=p;
            qDebug() << hash[index].next->word << " " << hash[index].next->count;
        }
        else
        {
            q = hash[index].next;
            while(q != NULL)
            {
                //if(strcmp(q->word,str)==0)
                if(QString::compare(q->word, str) == 0)
                {
                    q->count++;
                    flag=1;
                    break;
                }
                else
                {
                    q = q->next;
                }
            }
            /*
             *说明没有任何字符匹配，要创建一个新的节点，链接好
             */
            if(flag == 0)
            {
                //q=(HashTable *)malloc(sizeof(HashTable));
                q = new HashTable();
                if(!q)
                {
                    //同上改个qmessagebox
                    qDebug()<<"No enough memory!";
                    exit(-1);
                }
                q->count=1;
                q->next=NULL;
                //strcpy(q->word,str);
                q->word = str;
                /*
                 * 头插法
                 */
                q->next=hash[index].next;
                hash[index].next=q;
            }
        }
    }
}

void HashTable::put_into_hash(QString &text, HashTable hash[])
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
            //add_Tnode(root, concat_word);
            CTable(concat_word, hash);
            HashTable::how_many++;
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
                //add_Tnode(root, concat_word);
                CTable(concat_word, hash);
                HashTable::how_many++;
                concat_word = "";
            }
            else
            {
                //add_Tnode(root, concat_word);
                CTable(concat_word, hash);
                HashTable::how_many++;
                concat_word = text[i];
                //add_Tnode(root, concat_word);
                CTable(concat_word, hash);
                HashTable::how_many++;
                concat_word = "";
            }
        }
    }
}

/*
初始化哈希表
调用在哈希表之前
*/
void HashTable::initHash(int n, HashTable hash[])
{
    int i;
    for(i=0;i<n;i++)
    {
        hash[i].count=0;
        hash[i].word = "";
        hash[i].next=NULL;
    }
}

void HashTable::hash_FileInput(HashTable hash[], QString path)
{
    initHash(MAX, hash);
    //QString a = "C:\\Users\\86180\\Desktop\\新建文本文档.txt";
    //QString a = "C:\\Users\\86180\\Desktop\\哈利波特英文版全集\\哈利波特英文版全集.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //这里回头放一个qmessagebox
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    int i = 0;
    while (!line.isNull())
    {
        i++;
        qDebug() << HashTable::how_many << "第" << i << "轮";
        put_into_hash(line, hash);
        line = in.readLine();
    }
    //qDebug() << "testing!!!!!!!!";
    HashTable *p = NULL;
    for(int i=0;i<MAX;i++)
    {
        if(hash[i].count!=0)
        {
            qDebug() << hash[i].word << " = " << hash[i].count;
        }
        if(hash[i].next)
        {
            p = hash[i].next;
            while(p)
            {
                qDebug() << p->word << " = " << p->count;
                p=p->next;
            }
        }
    }
}

QString HashTable::get_word()
{
    return this->word;
}

int HashTable::get_count()
{
    return this->count;
}























