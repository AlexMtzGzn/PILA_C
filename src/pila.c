#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pila.h"

bool isEmpty(struct Pila *pila)
{
    return pila->cima == NULL;
}

struct Nodo* crear_Nodo(int *elemento){

    struct Nodo *nodoNuevo = malloc(sizeof(struct Nodo));

    if(nodoNuevo == NULL)
        return nodoNuevo;

    nodoNuevo->valor = *elemento;
    nodoNuevo->siguiente = NULL;

    return nodoNuevo;
}

void push(struct Pila *pila, int *elemento)
{
    struct Nodo *nodoNuevo = crear_Nodo(elemento);

    if (nodoNuevo != NULL)
    {
        nodoNuevo->siguiente = pila->cima;
        pila->cima = nodoNuevo;
    }
    else
        printf("\nError al asignar memoria al nodo.");
}

void pop(struct Pila *pila)
{
    if (!isEmpty(pila))
    {
        struct Nodo *nodoAux = pila->cima;
        pila->cima = nodoAux->siguiente;
        free(nodoAux);
    }
}

int top(struct Pila *pila)
{
    if (isEmpty(pila))
        return -1;
    else
        return pila->cima->valor;
}

void imprimir(struct Pila *pila)
{
    if (isEmpty(pila))
        printf("\nLa pila está vacía.");
    else
    {
        struct Nodo *nodo = pila->cima;
        printf("\nPila\n");
        while (nodo != NULL)
        {
            printf("\n%i", nodo->valor);
            nodo = nodo->siguiente;
        }
    }
}

void liberarPila(struct Pila *pila)
{
    while (isEmpty(pila) != true)
        pop(pila);

    pila->cima = NULL;
}

void menu(struct Pila *pila)
{
    int opcion;
    do
    {
        printf("\n\nPILA");
        printf("\n\n1- Push.");
        printf("\n2- Pop.");
        printf("\n3- Top.");
        printf("\n4- isEmpty.");
        printf("\n5- Imprimir Pila.");
        printf("\n6- Vaciar Pila.");
        printf("\n7- Salir.");
        printf("\nIngresa la opción: ");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:
            int elemento;
            printf("\nIngresa el elemento: ");
            scanf("%i", &elemento);
            push(pila, &elemento);
            imprimir(pila);
            break;
        case 2:
            if (!isEmpty(pila))
                pop(pila);
            imprimir(pila);
            break;
        case 3:
            if (!isEmpty(pila))
                printf("\nTope: %i\n", top(pila));
            imprimir(pila);        
            break;
        case 4:
            if (!isEmpty(pila))
                printf("\nLa pila no está vacía\n");
            imprimir(pila);
            break;
        case 5:
            imprimir(pila);
            break;
        case 6:
            liberarPila(pila);
            imprimir(pila);
            break;
        case 7:
            printf("\nSaliendo...");  
            break;  
        default:
            printf("\nOpción Inválida");
            break;
        }
    } while (opcion != 7);
}
