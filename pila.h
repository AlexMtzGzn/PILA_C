#ifndef PILA_H
#define PILA_H

#include <stdbool.h>

struct Nodo
{
    int valor;
    struct Nodo *siguiente;
};
struct Pila
{
    struct Nodo *cima;
};

void liberarPila(struct Pila *pila);
struct Nodo* crear_Nodo(int *elemento);
bool isEmpty(struct Pila *pila);
void push(struct Pila *pila, int *elemento);
void pop(struct Pila *pila);
int top(struct Pila *pila);
void imprimir(struct Pila *pila);
void menu(struct Pila *pila);

#endif