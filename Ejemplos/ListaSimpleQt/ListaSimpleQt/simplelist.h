#ifndef SIMPLELIST_H
#define SIMPLELIST_H
#include <QString>
#include <QTableWidget>

class SimpleNode
{
private:
    QString name;
    QString taxId;

public:
    SimpleNode* next;
    SimpleNode();
    SimpleNode(QString name, QString taxId);
    bool equals(SimpleNode* other);
    QString getName();
    QString getTaxId();
    void setName(QString name);
    void setTaxId(QString taxId);
};

class SimpleList
{
private:
    int quantity;
    SimpleNode* start;
    SimpleNode* end;
    bool firstInsert(SimpleNode* node);
    void insertAtStart(SimpleNode* node);
    void insertAtEnd(SimpleNode* node);

public:
    SimpleList();

    //Methods to insert
    void insert(SimpleNode* node);

    //Method to find
    SimpleNode* find(SimpleNode* node);

    //Method to update
    void update(SimpleNode* old, SimpleNode* node);

    //Methods to delete
    SimpleNode* remove(SimpleNode* node);

    //Miscelanious methods
    void clear();
    int size();
    bool isEmpty();
    void fillTable(QTableWidget* table);

};

#endif // SIMPLELIST_H
