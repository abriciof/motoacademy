#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000 


void obter_pos_ordem(char pre_ordem[], int pre_ordem_inicio, int pre_ordem_fim, 
              char em_ordem[],  int em_ordem_inicio,   int em_ordem_fim){
    
    // DBACEGF 0 6 ABCDEFG 0 6

    // 0 > 6
    if (pre_ordem_inicio > pre_ordem_fim){
        return;
    }

    // D
    char raiz = pre_ordem[pre_ordem_inicio];

    // Encontrar o índice de D no percurso EM ORDEM
    int indice_raiz = em_ordem_inicio;
    while (indice_raiz <= em_ordem_fim && em_ordem[indice_raiz] != raiz){
        indice_raiz++;
    }

    // indice_raiz -> 3

    // 3 - 0 = 0
    int tamanho_esquerda = indice_raiz - em_ordem_inicio;

    // Resolvendo o lado esquerdo (ANTES da RAIZ do EM ORDEM)
    obter_pos_ordem(
        pre_ordem,
        pre_ordem_inicio + 1,
        pre_ordem_inicio + tamanho_esquerda,
        em_ordem,
        em_ordem_inicio,
        indice_raiz - 1
    );

    // Resolvendo o lado direito (DEPOIS da RAIZ do EM ORDEM)
    obter_pos_ordem(
        pre_ordem,
        pre_ordem_inicio + tamanho_esquerda + 1,
        pre_ordem_fim,
        em_ordem,
        indice_raiz + 1,
        em_ordem_fim
    );

    // Mostrando o valor da RAIZ por último por ser PÓS ORDEM
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