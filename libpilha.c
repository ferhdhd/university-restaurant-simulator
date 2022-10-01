#include <stdio.h>
#include <stdlib.h>
#include "libpilha.h"


pilha_t* pilha_cria (int nelem){
   
    if(nelem <= 0)
        return NULL;
    
    pilha_t *pilha = malloc(nelem*sizeof(pilha_t));
    pilha->nelem = nelem;
    pilha->topo = 0;
    pilha->elems = malloc(nelem*sizeof(int));
    return pilha;

}

int pilha_vazia(pilha_t *pilha){
    if(pilha->topo == 0)
        return 1;
    return 0;
}

int pilhaCheia(pilha_t *pilha){
    if(pilha->topo == pilha->nelem)   /* funcao auxiliar que retorna 1 para pilha cheia e 0 para outros casos*/
        return 1;
    return 0;
}

int push(pilha_t *pilha, int elem){

    if(pilhaCheia(pilha)){
        return -1;
    }
    
    pilha->elems[pilha->topo] = elem;
    pilha->topo++;
    return pilha->topo;
    
}

int pop(pilha_t *pilha){

    if(pilha_vazia(pilha)){
        return 0;
    }

    pilha->topo--;
    return pilha->elems[pilha->topo];

}

int pilha_topo(pilha_t* pilha){

    return pilha->elems[pilha->topo];

}

int pilha_tamanho(pilha_t* pilha){

    return pilha->topo;

}

pilha_t* pilha_destroi (pilha_t* pilha){

    free(pilha->elems);
    free(pilha);
    return NULL;

}

void pilha_imprime (pilha_t* pilha){

    int i = 0;
    if(pilha_vazia(pilha) == 1)
        return;
    while(i < pilha->topo-1){
        printf("%d " , pilha->elems[i]);
        i++;
    }
    printf("%d\n" , pilha->elems[i]);
}
