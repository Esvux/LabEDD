#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <QString>

class Nodo {
public:
    Nodo(int id);
    int comparar(Nodo *otro);
    int getId();
    Nodo *izq;
    Nodo *der;
private:
    int id;
};

class Arbol {
public:
    Arbol();
    void insertar(Nodo *nuevo);
    void recorrer();
    int getCantidad();
private:
    Nodo *raiz;
    int cantidad;
    void insertar(Nodo *pivote, Nodo *nuevo);
    void recorrer(Nodo *centro);
};

#endif // ARBOLBINARIO_H
