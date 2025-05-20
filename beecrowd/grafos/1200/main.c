#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no TNO;
typedef struct no{
    char chave;
    TNO *esquerda;
    TNO *direita;
}no;

TNO* novoNO(char valor)
{
    TNO* no = (TNO*)malloc(sizeof(TNO));
    no->chave = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

TNO* busca(TNO *raiz, char valor){
    if (raiz == NULL || raiz->chave == valor){
        return raiz;
    }
    if (valor < raiz->chave){
        return busca(raiz->esquerda, valor);
    }else{
        return busca(raiz->direita, valor);
    }
}


TNO* buscaMinimo(TNO* raiz){
    if(raiz == NULL){
        return NULL;
    }else if(raiz->esquerda == NULL){
        return raiz;
    }else{
        return buscaMinimo(raiz->esquerda);
    }
}


TNO* insereNO(TNO* raiz, char valor){
    if (raiz == NULL){
        return novoNO(valor);
    }
    else if (valor < raiz->chave){
        raiz->esquerda = insereNO(raiz->esquerda, valor);
    }
    else if (valor > raiz->chave){
        raiz->direita = insereNO(raiz->direita, valor);
    }
    return raiz;
}


void posOrdem(TNO* raiz, char primeiro)
{
    if (raiz != NULL) {
        posOrdem(raiz->esquerda, primeiro);
        posOrdem(raiz->direita, primeiro);

        if (raiz->chave == primeiro){
            printf("%c", raiz->chave);
        }else{
            printf(" %c", raiz->chave);
        }
    }
}


void inOrdem(TNO* raiz, char primeiro)
{
    if (raiz != NULL) {
        inOrdem(raiz->esquerda, primeiro);
        
        if (raiz->chave == primeiro){
            printf("%c", raiz->chave);
        }else{
            printf(" %c", raiz->chave);
        }

        inOrdem(raiz->direita, primeiro);
    }
}


void preOrdem(TNO *raiz, char primeiro)
{
    if (raiz != NULL) {
        
        if (raiz->chave == primeiro){
            printf("%c", raiz->chave);
        }else{
            printf(" %c", raiz->chave);
        }
        
        preOrdem(raiz->esquerda, primeiro);
        preOrdem(raiz->direita, primeiro);
    }
}


int main(){
    char operacao[11], aux;
    TNO* raiz = NULL;
    TNO* raiz_aux = NULL;

	while (scanf("%s%*c", operacao) != EOF)
	{
        if(strcmp(operacao, "INFIXA") == 0){

            raiz_aux = buscaMinimo(raiz);
            inOrdem(raiz, raiz_aux->chave);
            printf("\n");
        
        }else if(strcmp(operacao, "PREFIXA") == 0){

            preOrdem(raiz, raiz->chave);
            printf("\n");

        }else if(strcmp(operacao, "POSFIXA") == 0){

            raiz_aux = buscaMinimo(raiz);
            posOrdem(raiz, raiz_aux->chave);
            printf("\n");

        }else if(strcmp(operacao, "I") == 0){

            scanf("%c", &aux);
            raiz = insereNO(raiz, aux);

        }else if (strcmp(operacao, "P") == 0){

			scanf("%c", &aux);

			if (busca(raiz, aux)){
				printf("%c existe\n", aux);
            }else{
				printf("%c nao existe\n", aux);
            }

		}
	}

    free(raiz);
    free(raiz_aux);

    return 0;
}
