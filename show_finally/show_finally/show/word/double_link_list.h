#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H

#include <QString>

typedef struct word{
    QString words;
    int number;
}Word;

typedef struct line{
    struct line * prior; //指向直接前趋
    Word data;
    struct line * next; //指向直接后继
}line;

typedef struct Doubleline{
    struct line * head;
    struct line * Tail;
}Doubleline;

class double_link_list
{
public:
    double_link_list();
    void process_line(QString line,int &i,int &j);
    Doubleline initLine();
    Doubleline addLine(QString info);
    ~double_link_list();
    void double_link_list_FileInput(QString &path);
    Doubleline get_linelist();

private:
    QString passage;
    Doubleline linelist;
};



#endif // DOUBLE_LINK_LIST_H
