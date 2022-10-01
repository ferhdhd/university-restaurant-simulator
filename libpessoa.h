#include "libpilha.h"

struct pessoa {
    
    int ticket;
    int vac;
    int masc;
    double din;

}; 
typedef struct pessoa pessoa_t;

struct data {

    double totalDin;
    double DinRefei;
    double DinMasc;
    int naoUtilizados;
    int nMasc;
    int nVac;
    int nRef;

};
typedef struct data data_t;


int aleat(int a, int b);

pessoa_t* criaFilaPessoas();

void aleatPessoas(pessoa_t *p);

pilha_t* pilhaMasc();

pilha_t* pilhaRefeicoes();

data_t* criaData();

pessoa_t* destroiPessoa(pessoa_t *p);
