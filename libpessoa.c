#include "libpessoa.h"
#include "libpilha.h"
#include<stdlib.h>
#include<stdio.h>
#include <stdio.h>

int aleat(int a, int b) {

    a = (rand()%b) + a;
    return a;

}

pessoa_t* criaFilaPessoas() {

    pessoa_t* pessoa = malloc(1000*sizeof(pessoa_t));
    if(pessoa == NULL)
        return NULL;
    
    return pessoa;

}


void aleatPessoas(pessoa_t* p) {

    int i = 0;  

    for(i = 0; i < 1000; i++) {
        int aleatVac = aleat(1,100);
        int aleatMasc = aleat(1,100);
        int aleatDin = aleat(1,100);

        p[i].ticket = i+1;

        if(aleatVac > 90) {
            p[i].vac = 0;
        }
        else{
            p[i].vac = 1;
        }

        if(aleatMasc > 85) {
            p[i].masc = 0;
        }
        else{
            p[i].masc = 1;
        }

        if(aleatDin > 60) {
            p[i].din = 3.80;
        }
        else{
            p[i].din = 1.30;
        }
    }
    return;

}

pilha_t* pilhaMasc() {

    int j;
    int numMask = aleat(1,100);

    pilha_t* pilha = pilha_cria(numMask);

    for(j = numMask; j > 0; j--)
        push(pilha, j);
    
    return pilha;

}

pilha_t* pilhaRefeicoes() {

    int j;
    int numRefeicoes = aleat(500,1000);

    pilha_t* pilha = pilha_cria(numRefeicoes);

    for(j = numRefeicoes; j > 0; j--)
        push(pilha, j);
    
    return pilha;


}

data_t* criaData() {

    data_t* data = malloc(sizeof(data_t));
    if(data == NULL)
        return NULL;
    
    data->totalDin = 0;
    data->DinMasc = 0;
    data->DinRefei = 0;
    data->naoUtilizados = 0;
    /* variaveis abaixo nao eram inicializadas */
    data->nMasc = 0;
    data->nVac = 0;
    data->nRef = 0;

    return data;
}

pessoa_t* destroiPessoa(pessoa_t *p) {

    free(p);
    return p;

}