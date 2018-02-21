#include "doublelist.h"
#include <QString>

DoubleList::DoubleList() {
    this->quantity = 0;
    this->start = NULL;
    this->end = NULL;
}

void DoubleList::insert(DoubleNode* node) {
    // Si es el primer elemento en ser insertado, termina la inserción
    if(firstInsert(node))
        return;

    // Inserción binaria
    insert(node, this->start, this->end, this->quantity);
}

void DoubleList::insert(DoubleNode *node, DoubleNode *a, DoubleNode *z, int range) {
    int left = node->compare(a);
    // -1, indica que 'node' es "más pequeño" que el "menor" de los nodos
    // 0, indica que 'node' es igual al "menor"
    // +1, indica que 'node' es "más grande" que el "menor" de los nodos

    int right = node->compare(z);
    // -1, indica que 'node' es "más pequeño" que el "mayor" de los nodos
    // 0, indica que 'node' es igual al "mayor"
    // +1, indica que 'node' es "más grande" que el "mayor" de los nodos

    if(left < 0) { // Insertar antes del nodo "menor"
        insertBefore(node, a);
        return;
    }

    if(right > 0) { // Insertar después del nodo "mayor"
        insertAfter(node, z);
        return;
    }

    if(right == 0 || left == 0) {
        // Nodo repetido
        return;
    }

    // Encontrar el elemento central
    range = range / 2;
    DoubleNode* pivote = a;
    for(int i=0; i < range && pivote != NULL && pivote->next != NULL; i++) {
        pivote = pivote->next;
    }

    int center = node->compare(pivote);
    // -1, indica que el lugar de 'node' está entre 'a' y 'pivote'
    // 0, indica que 'node' es igual a 'pivote'
    // +1, indica que el lugar de 'node' está entre 'pivote' y 'z'

    if(center < 0) {
        if(pivote->prev == a) {
            insertBefore(node, pivote);
            return;
        }
        insert(node, a, pivote, range + 1);
    } else  if(center > 0) {
        if(pivote->next == z) {
            insertAfter(node, pivote);
            return;
        }
        insert(node, pivote, z, range + 1);
    } else {
        // Nodo repetido
    }

}

void DoubleList::insertBefore(DoubleNode *node, DoubleNode *pivote) {
    if(pivote->prev == NULL) {
        insertAtStart(node);
    } else {
        pivote->prev->next = node;
        node->prev = pivote->prev;
        pivote->prev = node;
        node->next = pivote;
        quantity++;
    }
}

void DoubleList::insertAfter(DoubleNode *node, DoubleNode *pivote) {
    if(pivote->next == NULL) {
        insertAtEnd(node);
    } else {
        pivote->next->prev = node;
        node->next = pivote->next;
        pivote->next = node;
        node->prev = pivote;
        quantity++;
    }
}

void DoubleList::insertAtEnd(DoubleNode* node) {
    // Enlazando punteros
    this->end->next = node;
    node->prev = this->end;
    // Redefiniendo el final
    this->end = node;
    // Aumentando la cantidad
    this->quantity++;
}

void DoubleList::insertAtStart(DoubleNode* node) {
    // Enlazando punteros
    node->next = this->start;
    this->start->prev = node;
    // Redefiniendo el inicio
    this->start = node;
    // Aumentando la cantidad
    this->quantity++;
}

bool DoubleList::firstInsert(DoubleNode* node) {
    if(this->start == NULL && this->end == NULL) {
        this->start = node;
        this->end = node;
        this->quantity++;
        return true;
    }
    return false;
}

void DoubleList::fillTable(QTableWidget *table) {
    if(this->start == NULL)
        return;
    DoubleNode* temp = this->start;
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

void DoubleList::update(DoubleNode *old, DoubleNode *node) {
}

bool DoubleList::isEmpty() {
    return this->quantity == 0 || this->start == NULL || this->end == NULL;
}

int DoubleList::size() {
    return this->quantity;
}

void DoubleList::clear() {
    this->quantity = 0;
    this->start = NULL;
    this->end = NULL;
}

/**
 * DoubleNode class
 *
 *  +------+--------------+------+
 *  |      |              |      |
 *  | Prev |     Body     | Next |
 *  |      |              |      |
 *  +------+--------------+------+
 *
 */
DoubleNode::DoubleNode() {
    this->items = new SimpleList();
    this->name = "";
    this->taxId = "";
    this->prev = NULL;
    this->next = NULL;
}

DoubleNode::DoubleNode(QString name, QString taxId) {
    this->items = new SimpleList();
    this->name = name;
    this->taxId = taxId;
    this->prev = NULL;
    this->next = NULL;
}

void DoubleNode::setName(QString name) {
    this->name = name;
}

void DoubleNode::setTaxId(QString taxId) {
    this->taxId = taxId;
}

QString DoubleNode::getName() {
    return this->name;
}

QString DoubleNode::getTaxId() {
    return this->taxId;
}

/**
 * @brief DoubleNode::compare
 * @param other Nodo a comparar, no debería de ser NULL
 * @return -1 si el nodo recibido como parámetro es "menor" que el
 * nodo que sobre el cual se invoca el método, 0 si son "iguales" y
 * +1 si es "mayor".
 */
int DoubleNode::compare(DoubleNode *other) {
    // Nodo a comparar NO válido, normalmente
    // se debería de lanzar una excepción.
    if(other == NULL)
        return -1;

    // El ordenamiento se hará con base en el atributo
    // nombre, NULL se considera inmediatamente "menor"
    // que cualquier otra cadena.
    if(this->name == NULL)
        return other->name == NULL ? 0 : 1;

    // A partir de este punto se tiene la seguridad de que
    // this->name NO es NULL
    if(other->name == NULL)
        return -1;

    // A partir de este punto se tiene la seguridad de que
    // tanto this->name como other->name NO son NULL
    return this->name.compare(other->name);

}

bool DoubleNode::equals(DoubleNode* other) {
    if(other==NULL)
        return false;
    if(this->taxId == NULL)
        return other->taxId == NULL;
    if(other->taxId == NULL)
        return false;
    return this->taxId == other->taxId;
}
