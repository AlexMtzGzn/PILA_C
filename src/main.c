#include <stdlib.h>
#include "pila.h"

int main(void)
{

    struct Pila *pila = malloc(sizeof(struct Pila));

    if(pila == NULL)
        return -1;
        
    pila->cima = NULL;

    menu(pila);
    free(pila);

    return 0;
}
