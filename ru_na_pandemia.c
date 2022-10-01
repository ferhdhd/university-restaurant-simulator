#include "libpessoa.h"
#include "libpilha.h"
#include "libfila.h"
#include "liblista.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int main() {

    srand(time(NULL));
    int i, retirado;
    

    pilha_t *pMasc = pilhaMasc();
    pilha_t *pRefeicoes = pilhaRefeicoes();
    
    pessoa_t *fPessoas = criaFilaPessoas();
    aleatPessoas(fPessoas);
    
    fila_t *atendimentos = fila_cria();
    lista_t *naoAtendidos = lista_cria();

    data_t *dados = criaData();

    
    for(i = 0; i < 1000; i++) {
        queue(atendimentos,fPessoas[i].ticket);
    }



    while(!(fila_vazia(atendimentos))) {

        /* DEBUFAR FILA */
        dequeue(atendimentos, &retirado);
        /* retirado virou retirado-1 */
        if(pilha_vazia(pRefeicoes)) {

            lista_insere_ordenado(naoAtendidos, fPessoas[retirado-1].ticket);
            dados->naoUtilizados++;
            dados->nRef++;
        }
                
        else if(!(fPessoas[retirado-1].vac)) {
            lista_insere_ordenado(naoAtendidos, fPessoas[retirado-1].ticket);
            dados->naoUtilizados++;
            dados->nVac++;
        }
        else {
            
            if(!(fPessoas[retirado-1].masc)) {
                
                if(pilha_vazia(pMasc) || fPessoas[retirado-1].din < 3.80) {
                    lista_insere_ordenado(naoAtendidos, fPessoas[retirado-1].ticket);
                    dados->naoUtilizados++;
                    dados->nMasc++;
                } 
                
                else if(fPessoas[retirado].din == 3.80) {
                    fPessoas[retirado-1].din -= 2.50;
                    fPessoas[retirado-1].masc = 1;
                    dados->totalDin += 2.50;
                    dados->DinMasc += 2.50;
                    pop(pMasc);
                    queue(atendimentos, retirado);
                }


            }

            else { 

                fPessoas[retirado-1].din -= 1.30;
                dados->DinRefei += 1.30;
                dados->totalDin += 1.30;
                pop(pRefeicoes);

            }

        }

    }


    printf("O total de dinheiro arrecadado foi de R$%.2f\n" , dados->totalDin);
    printf("O dinheiro arrecadado com refeições foi de R$%.2f\n" , dados->DinRefei);
    printf("O dinheiro arrecadado com a venda de mascaras foi de R$%.2f\n" , dados->DinMasc);
    printf("%d tickets nao foram utilizados, sendo eles:\n" , dados->naoUtilizados);
    lista_imprime(naoAtendidos);
    printf("\n");
    printf("%d nao foram utilizados por nao estarem vacinados, %d nao foram utilizados " , dados->nVac, dados->nMasc);
    printf("por falta de mascara e %d nao foram utilizados por falta de refeiçoes\n" , dados->nRef);
    
    destroiPessoa(fPessoas);
    pilha_destroi(pRefeicoes);
    pilha_destroi(pMasc);
    fila_destroi(atendimentos);
    lista_destroi(naoAtendidos);
    free(dados);


    return 0;
}