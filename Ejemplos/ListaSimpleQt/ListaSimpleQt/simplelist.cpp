#include "simplelist.h"
#include <QString>

SimpleList::SimpleList() {
    this->quantity = 0;
    this->start = NULL;
    this->end = NULL;
}

void SimpleList::insert(SimpleNode* node) {
    insertAtStart(node);
}

void SimpleList::insertAtStart(SimpleNode* node) {
    if(! firstInsert(node)) {
        this->end->next = node;
        this->end = node;
        this->quantity++;
    }
}

void SimpleList::insertAtEnd(SimpleNode* node) {
    if(! firstInsert(node)) {
        node->next = this->start;
        this->start = node;
        this->quantity++;
    }
}

bool SimpleList::firstInsert(SimpleNode* node) {
    if(this->start == NULL && this->end == NULL) {
        this->start = node;
        this->end = node;
        this->quantity++;
        return true;
    }
    return false;
}

SimpleNode* SimpleList::find(SimpleNode *node) {
    if(this->start == NULL)
        return NULL;
    SimpleNode* temp = this->start;
    while(temp != NULL) {
        if(temp->equals(node))
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void SimpleList::fillTable(QTableWidget *table) {
    if(this->start == NULL)
        return;
    SimpleNode* temp = this->start;
    table->clearContents();
    for(int i=0; temp != NULL; i++) {
        QTableWidgetItem* nameItem = new QTableWidgetItem(temp->getName());
        QTableWidgetItem* taxIdItem = new QTableWidgetItem(temp->getTaxId());
        table->setRowCount(i + 1);
        table->setItem(i, 0, nameItem);
        table->setItem(i, 1, taxIdItem);
        temp = temp->next;
    }
}

void SimpleList::update(SimpleNode *old, SimpleNode *node) {
}

SimpleNode* SimpleList::remove(SimpleNode *node) {
    if(this->isEmpty())
        return NULL;
    SimpleNode* temp = this->start;
    SimpleNode* prev = NULL;
    while(temp != NULL) {
        if(temp->equals(node))
            break;
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL)
        return NULL;
    if(prev==NULL) {
        start = start->next;
    } else {
        prev->next = temp->next;
    }
    quantity--;
    return temp;
}

bool SimpleList::isEmpty() {
    return this->quantity == 0 || this->start == NULL || this->end == NULL;
}

int SimpleList::size() {
    return this->quantity;
}

void SimpleList::clear() {
    this->quantity = 0;
    this->start = NULL;
    this->end = NULL;
}

/**
 * SimpleNode class
 *
 *  +--------------+------+
 *  |              |      |
 *  |     Body     | Next |
 *  |              |      |
 *  +--------------+------+
 *
 */
SimpleNode::SimpleNode() {
    this->name = "";
    this->taxId = "";
    this->next = NULL;
}

SimpleNode::SimpleNode(QString name, QString taxId) {
    this->name = name;
    this->taxId = taxId;
    this->next = NULL;
}

void SimpleNode::setName(QString name) {
    this->name = name;
}

void SimpleNode::setTaxId(QString taxId) {
    this->taxId = taxId;
}

QString SimpleNode::getName() {
    return this->name;
}

QString SimpleNode::getTaxId() {
    return this->taxId;
}

bool SimpleNode::equals(SimpleNode* other) {
    if(other==NULL)
        return false;
    if(this->taxId == NULL)
        return other->taxId == NULL;
    if(other->taxId == NULL)
        return false;
    return this->taxId == other->taxId;
}
