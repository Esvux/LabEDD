#include "arbolbinario.h"
#include <QDebug>

Arbol::Arbol() {
    this->raiz = NULL;
    this->cantidad = 0;
}

void Arbol::insertar(Nodo *nuevo) {
    if(this->raiz == NULL) {
        this->raiz = nuevo;
        this->cantidad++;
        return;
    }
    // Si no es el primer nodo
    insertar(this->raiz, nuevo);
}

void Arbol::insertar(Nodo *pivote, Nodo *nuevo) {
    int comparacion = pivote->comparar(nuevo);
    // 0 son iguales;
    // -1 va antes del pivote
    // +1 va despues del pivote
    if(comparacion<0) {
        if(pivote->izq == NULL) {
            pivote->izq = nuevo;
            this->cantidad++;
            return;
        }
        // pivote->izq != NULL
        insertar(pivote->izq, nuevo);
        return;
    }
    if(comparacion>0) {
        if(pivote->der == NULL) {
            pivote->der = nuevo;
            this->cantidad++;
            return;
        }
        // pivote->der != NULL
        insertar(pivote->der, nuevo);
        return;
    }
    //son iguales
    qInfo() << "Nodo repetido\n";
}

void Arbol::recorrer() {
    recorrer(this->raiz);
}

void Arbol::recorrer(Nodo *centro) {
    if(centro==NULL) {
        return;
    }
    qInfo() << "Nodo: " << centro->getId();
    recorrer(centro->izq);
    recorrer(centro->der);
}

int Arbol::getCantidad() {
    return this->cantidad;
}

Nodo::Nodo(int id) {
    this->id = id;
    this->izq = NULL;
    this->der = NULL;
}

int Nodo::comparar(Nodo *otro) {
    return otro->id - this->id;
}

int Nodo::getId() {
    return this->id;
}
