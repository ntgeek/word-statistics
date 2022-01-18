#include "double_link_list.h"
#include <QDebug>
#include <QFile>

double_link_list::double_link_list(){}

Doubleline double_link_list::get_linelist()
{
    return this->linelist;
}

Doubleline double_link_list::initLine(){
    linelist.head= new line;
    linelist.Tail=linelist.head;
    linelist.head->prior=NULL;
    linelist.head->next=NULL;
    linelist.head->data.number=0;
    linelist.head->data.words="0";
    return linelist;
}

Doubleline double_link_list::addLine(QString info)
{
    line *p = new line;
    p->data.words = info;
    p->data.number = 1;
    p->prior = linelist.Tail;
    p->next = NULL;

    linelist.Tail->next = p;
    linelist.Tail = p;
    return linelist;
}

void double_link_list::process_line(QString lline,int &i,int &j)
{
   qDebug()<<"process_line";
   QString st2 = lline.simplified(); //去除多余空格（多留一）
   QString::iterator a; //字符数组迭代器
   QString singleword;  //读入单词识别器

   for(a = st2.begin(); a!=st2.end() ;++a) //对变量该行的每个字符
   {

        if(*a == ' ')  //遇空格识别为一个单词
        {
           int x = 0;  //标记
           line* p = linelist.head;
           line* q = linelist.Tail;
           for(; p!=q ;p = p->next,q=q->prior)
           {
               if(p->data.words == singleword)
               {
                   i++;
                   qDebug()<<j<<" "<<i<<" "<<singleword;
                   p->data.number++;
                   x = 1;  //已在链表中
                   break;
               }else if(q->data.words == singleword){
                   i++;
                   qDebug()<<j<<" "<<i<<" "<<singleword;
                   q->data.number++;
                   x = 1;  //已在链表中
                   break;
               }
           }
           if(x == 1)  //判断是否已经记录在单词链表中
           {
               singleword.clear();
           }else{
               i++;
               j++;
               qDebug()<<j<<" "<<i<<" "<<singleword;
               Word newwords;
               newwords.number = 1;
               newwords.words = singleword;
               addLine(singleword);
               singleword.clear();
           }
        }else if(*a>='!' && *a <='@')  //忽略不属于单词的字符
        {
            continue;
        }else{
            singleword.append(*a);
        }
   }
    qDebug()<<"process_line over";
}

void double_link_list::double_link_list_FileInput(QString &path)
{
//    QString a = "C:\\Users\\86180\\Desktop\\哈利波特英文版全集\\哈利波特英文版全集.txt";
//    QString a = "C:\\Users\\86180\\Desktop\\新建文本文档.txt";
    qDebug()<<"Fileinput";
    QFile file(path);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;

     QTextStream in(&file);
     QString line = in.readLine();

     int i = 0,j = 0;
     while (!line.isNull()){
         process_line(line,i,j);
         line = in.readLine();
     }
     qDebug()<<"Fileinputover";
}
