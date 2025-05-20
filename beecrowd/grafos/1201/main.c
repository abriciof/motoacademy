// Fabrício da Costa Guimarães
// 19/05/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no TNO;
typedef struct no{
    int chave;
    TNO *esquerda;
    TNO *direita;
}no;


TNO* novoNO(int valor)
{
    TNO* no = (TNO*)malloc(sizeof(TNO));
    no->chave = valor;
    no->esquerda = no->direita = NULL;
    return no;
}


TNO* busca(TNO *raiz, int valor){
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


TNO* buscaMaximo(TNO* raiz){
    if(raiz == NULL){
        return NULL;
    }else if(raiz->direita == NULL){
        return raiz;
    }else{
        return buscaMaximo(raiz->direita);
    }
}


TNO* insereNO(TNO* raiz, int valor){
    if (raiz == NULL){
        return novoNO(valor);

    }else if (valor < raiz->chave){
        raiz->esquerda = insereNO(raiz->esquerda, valor);
    }
    else if (valor > raiz->chave){
        raiz->direita = insereNO(raiz->direita, valor);
    }
    return raiz;
}


TNO* removeNO(TNO* raiz, int valor){
    TNO* aux;
    
    if (raiz == NULL){
        return NULL;
    
    }else if(valor < raiz->chave ){
    
        raiz->esquerda = removeNO(raiz->esquerda, valor);
    
    }else if(valor > raiz->chave){
        raiz->direita = removeNO(raiz->direita, valor);
    
    }else{ //achou
        if (raiz->esquerda == NULL && raiz->direita == NULL){
            raiz = NULL;

        }else if(raiz->esquerda == NULL){
            raiz = raiz->direita;

        }else if(raiz->direita == NULL){
            raiz = raiz->esquerda;

        }else{
            aux = buscaMaximo(raiz->esquerda);
            raiz->chave = aux->chave;
            raiz->esquerda = removeNO(raiz->esquerda, aux->chave);
        }
    }

    return raiz;
}


void posOrdem(TNO* raiz, int primeiro)
{
    if (raiz != NULL) {
        posOrdem(raiz->esquerda, primeiro);
        posOrdem(raiz->direita, primeiro);

        if (raiz->chave == primeiro){
            printf("%d", raiz->chave);
        }else{
            printf(" %d", raiz->chave);
        }
    }
}


void inOrdem(TNO* raiz, int primeiro)
{
    if (raiz != NULL) {
        inOrdem(raiz->esquerda, primeiro);

        if (raiz->chave == primeiro){
            printf("%d", raiz->chave);
        }else{
            printf(" %d", raiz->chave);
        }
        
        inOrdem(raiz->direita, primeiro);
    }
}


void preOrdem(TNO *raiz, int primeiro)
{
    if (raiz != NULL) {
        
        if (raiz->chave == primeiro){
            printf("%d", raiz->chave);
        }else{
            printf(" %d", raiz->chave);
        }
        
        preOrdem(raiz->esquerda, primeiro);
        preOrdem(raiz->direita, primeiro);
    }
}


int main(){
    char operacao[11];
    int aux;
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

            scanf(" %d", &aux);
            raiz = insereNO(raiz, aux);

        }else if (strcmp(operacao, "P") == 0){

			scanf(" %d", &aux);

			if (busca(raiz, aux)){
				printf("%d existe\n", aux);
            }else{
				printf("%d nao existe\n", aux);
            }
		}else{

            scanf(" %d", &aux);
            raiz = removeNO(raiz, aux);
        }
	}

    free(raiz);
    free(raiz_aux);

    return 0;
}
