#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <QString>

class HashTable
{
public:
    HashTable();
    void CTable(QString &str, HashTable hash[]);
    void put_into_hash(QString &text, HashTable hash[]);
    void initHash(int n, HashTable hash[]);
    void hash_FileInput(HashTable hash[], QString path);
    int HashIndex(QString &str);
    QString get_word();
    int get_count();
    HashTable *next;
    static int how_many;
private:
    QString word;
    int count;



};

#endif // HASHTABLE_H
