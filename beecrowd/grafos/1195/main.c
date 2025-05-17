#include <stdio.h>
#include <stdlib.h>

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

TNO* insere(TNO* raiz, int valor){
    if (raiz == NULL){
        return novoNO(valor);
    }
    if (valor < raiz->chave){
        raiz->esquerda = insere(raiz->esquerda, valor);
    }
    else if (valor > raiz->chave){
        raiz->direita = insere(raiz->direita, valor);
    }
    return raiz;
}

void posOrdem(TNO* raiz)
{
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf(" %d", raiz->chave);
    }
}

void inOrdem(TNO* raiz)
{
    if (raiz != NULL) {
        inOrdem(raiz->esquerda);
        printf(" %d", raiz->chave);
        inOrdem(raiz->direita);
    }
}

void preOrdem(TNO *raiz)
{
    if (raiz != NULL) {
        printf(" %d", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

int main() {

    int entradas, tamanho, aux;
    scanf("%d", &entradas);

    for(int i = 0; i < entradas; i++){
        
        TNO* raiz = NULL;

        scanf("%d", &tamanho);


        for(int j =0; j < tamanho; j++){
            scanf("%d", &aux);
            raiz = insere(raiz, aux);
        }

        printf("Case %d:", i+1);
        printf("\nPre.:"); preOrdem(raiz);
        printf("\nIn..:"); inOrdem(raiz);
        printf("\nPost:"); posOrdem(raiz);
        printf("\n\n");

        free(raiz);
    }


    return 0;
}