#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <QString>
#include <QTableWidget>

class DoubleNode
{
private:
    QString name;
    QString taxId;

public:
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode();
    DoubleNode(QString name, QString taxId);
    bool equals(DoubleNode* other);
    int compare(DoubleNode* other);
    QString getName();
    QString getTaxId();
    void setName(QString name);
    void setTaxId(QString taxId);
    // More data or content
};

class DoubleList
{
private:
    int quantity;
    DoubleNode* start;
    DoubleNode* end;
    bool firstInsert(DoubleNode* node);
    void insertAtStart(DoubleNode* node);
    void insertAtEnd(DoubleNode* node);
    void insert(DoubleNode* node, DoubleNode* a, DoubleNode* z, int range);
    void insertBefore(DoubleNode *node, DoubleNode *pivote);
    void insertAfter(DoubleNode *node, DoubleNode *pivote);

public:
    DoubleList();

    //Methods to insert
    void insert(DoubleNode* node);

    //Method to find
    DoubleNode* find(DoubleNode* node);

    //Method to update
    void update(DoubleNode* old, DoubleNode* node);

    //Methods to delete
    DoubleNode* remove(DoubleNode* node);

    //Miscelanious methods
    void clear();
    int size();
    bool isEmpty();
    void fillTable(QTableWidget* table);

};

#endif // DOUBLELIST_H
