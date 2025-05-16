#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000 


void obter_pos_ordem(char pre_ordem[], int pre_ordem_inicio, int pre_ordem_fim, 
              char em_ordem[],  int em_ordem_inicio,   int em_ordem_fim){
    
    if (pre_ordem_inicio > pre_ordem_fim){
        return;
    }

    char raiz = pre_ordem[pre_ordem_inicio];

    int posicao_raiz = em_ordem_inicio;
    while (posicao_raiz <= em_ordem_fim && em_ordem[posicao_raiz] != raiz){
        posicao_raiz++;
    }

    int tamanho_esquerda = posicao_raiz - em_ordem_inicio;

    obter_pos_ordem(
        pre_ordem,
        pre_ordem_inicio + 1,
        pre_ordem_inicio + tamanho_esquerda,
        em_ordem,
        em_ordem_inicio,
        posicao_raiz - 1
    );

    obter_pos_ordem(
        pre_ordem,
        pre_ordem_inicio + tamanho_esquerda + 1,
        pre_ordem_fim,
        em_ordem,
        posicao_raiz + 1,
        em_ordem_fim
    );


    printf("%c", raiz);


}


int main(){
    int indice, tamanho;
    char pre_ordem[MAXSIZE], em_ordem[MAXSIZE];

	while (scanf("%s %s", pre_ordem, em_ordem) != EOF)
	{
		tamanho = strlen(pre_ordem);
		obter_pos_ordem(pre_ordem, 0, tamanho-1, em_ordem, 0, tamanho-1);
		printf("\n");

	}

    return 0;
}