#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"

lista_t* lista_cria(){

    lista_t *lista = malloc(sizeof(lista_t));

    if(lista == 0){
        printf("Erro de alocação de memória");
        return NULL;
    }

    lista->ini = NULL;
    lista->tamanho = 0;
    
    return lista;

}

lista_t* lista_destroi(lista_t* l){

    nodo_l_t *aux;

    if(lista_vazia(l) != 1) {
        while(l->ini != NULL) {
            aux = l->ini->prox;
            free(l->ini);
            l->ini = aux;
        }
    }
    
    free(l);
    return l;

}

int lista_vazia (lista_t* l){

    if(l->tamanho == 0)
        return 1;
    return 0;

}

int lista_tamanho (lista_t* l){

    return l->tamanho;

}

int lista_insere_inicio (lista_t* l, int elemento){

    nodo_l_t *novoNodo = malloc(sizeof(nodo_l_t));

    if(novoNodo == NULL){
        return 0;
    }

    novoNodo->elemento = elemento;

    if(lista_vazia(l) == 0){
        novoNodo->prox = l->ini;
    } else {
        novoNodo->prox = NULL;
    }
    l->ini = novoNodo;
    l->tamanho++;
    return 1;

}

int lista_insere_fim (lista_t* l, int elemento){

    nodo_l_t *novoNodo = malloc(sizeof(nodo_l_t));
    nodo_l_t *aux = l->ini;

    if(novoNodo == NULL){
        return 0;
    }

    novoNodo->elemento = elemento;
    novoNodo->prox = NULL;

    if(lista_vazia(l) == 1){
        l->ini = novoNodo;
    } else {
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoNodo;
    }
    
    l->tamanho++;
    return 1;

}

int lista_insere_ordenado (lista_t* l, int elemento){
    
    if(lista_vazia(l) == 1 || elemento <= l->ini->elemento){
        lista_insere_inicio(l, elemento);
        return 1;
    }
    
    nodo_l_t *novoNodo = malloc(sizeof(nodo_l_t));
   
    if(novoNodo == NULL) {
        printf("Erro de alocação de memória");
        return 0;
    }
    
    nodo_l_t *aux = l->ini;
    aux = l->ini;
    novoNodo->elemento = elemento;

    while((aux->prox != NULL) && (elemento > aux->prox->elemento))
        aux = aux->prox;
    
    novoNodo->prox = aux->prox;
    aux->prox = novoNodo;
    l->tamanho++;

    return 1;
}

int lista_retira_inicio (lista_t* l, int* elemento){

    nodo_l_t *aux = l->ini;
    
    if(lista_vazia(l) == 0){
        l->ini = aux->prox;
        aux->prox = NULL;
        *elemento = aux->elemento;
        free(aux);
        l->tamanho--;
        return 1;
    }
    
    return 0;

}

int lista_retira_fim (lista_t* l, int* elemento){

    nodo_l_t *aux = l->ini;
    nodo_l_t *aux2;

    if(lista_vazia(l) == 0){
        if(l->tamanho == 1){
            lista_retira_inicio(l, elemento);
            return 1;
        }

        while(aux->prox->prox != NULL)
            aux = aux->prox;

        aux2 = aux->prox;
        *elemento = aux2->elemento;
        aux->prox = NULL;
        free(aux2);
        l->tamanho--;
        return 1;

    }
    
    return 0;
}

int lista_retira_elemento (lista_t *l, int *elemento){

    nodo_l_t *aux = l->ini;
    nodo_l_t *aux2;

    if(lista_vazia(l) == 0){
        if(l->ini->elemento == *elemento){
            lista_retira_inicio(l, elemento);
            return 1;
        }
        
        while(aux->prox != NULL){
            
            if(aux->prox->elemento == *elemento){
                
                if(aux->prox->prox == NULL){
                    lista_retira_fim(l, elemento);
                    return 1;
                }
                
                aux2 = aux->prox;
                aux->prox = aux2->prox; 
                aux2->prox = NULL;
                free(aux2);
                l->tamanho--;
                return 1;
            }
            
            aux = aux->prox;
        }
            
    }
    return 0;
}

int lista_pertence (lista_t* l, int elemento) {

    nodo_l_t *aux = l->ini;

    if(lista_vazia(l) == 0){
        
        if(l->ini->elemento == elemento)
            return 1;

        while(aux->prox != NULL){

            if(aux->prox->elemento == elemento)
                return 1;
            aux = aux->prox;
            
        }    
    }      
    return 0;

}

void lista_imprime (lista_t* l){

    nodo_l_t *aux = l->ini;
    if(aux == NULL)
        return;
    while(aux->prox != NULL){
        printf("%d " , aux->elemento);
        aux = aux->prox;
    }
    printf("%d\n" , aux->elemento);

}