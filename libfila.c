#include <stdio.h>
#include <stdlib.h>
#include "libfila.h"


fila_t* fila_cria (){

    fila_t *fila = malloc(sizeof(fila_t));

    if(fila == 0){
        printf("Erro de alocação de memória");
        return NULL;
    }

    fila->ini = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    
    return fila;

}

fila_t* fila_destroi (fila_t* f){
    nodo_f_t *aux;

    if (fila_vazia(f) != 1) {
        while (f->ini != NULL) {
            aux = f->ini;
            f->ini = f->ini->prox;
            free(aux);
        }
    }

    free(f);
    return f;
}

int fila_vazia(fila_t* f) {

    if (f->tamanho == 0)
        return 1;
    return 0;
}

int fila_tamanho(fila_t* f) {

    return f->tamanho;

}

int fila_topo(fila_t *f){

    return f->fim->chave;

}

int queue (fila_t* f, int elemento){
   
    nodo_f_t *novoNodo;

    novoNodo = malloc(sizeof(nodo_f_t));
    if(novoNodo == NULL){
        printf("Erro de alocação de memória");
        return 0;
    }
    
    novoNodo->chave = elemento;
    novoNodo->prox = NULL;
    if(f->ini == NULL){
        f->ini = novoNodo;
    } else {
        f->fim->prox = novoNodo;
    }
    f->fim = novoNodo;
    f->tamanho++;
    return 1;

}

int dequeue (fila_t* f, int* elemento){

    nodo_f_t *aux = f->ini;
    
    if(fila_vazia(f) == 0){
        f->ini = aux->prox;
        aux->prox = NULL;
        *elemento = aux->chave;
        free(aux);
        f->tamanho--;
        return 1;
    }
    
    return 0;

}

void fila_imprime (fila_t* f){

    nodo_f_t *aux = f->ini;
    if(aux == NULL)
        return;
    while(aux->prox != NULL){
        printf("%d " , aux->chave);
        aux = aux->prox;
    }
    printf("%d\n" , aux->chave);


}