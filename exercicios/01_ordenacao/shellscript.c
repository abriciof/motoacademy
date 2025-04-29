/*
MotoAcademy 5.0 - Algoritmos e Estruturas de Dados
Lucas Teixeira de Amorim
29/04/2025
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//Gera um array aleatorio de inteiros
// O tamanho do array e passado como argumento
int *gerarArrayAleatorio(int n) {
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    return arr;
}
// Ordena o array usando o algoritmo ShellSort
// O array e passado como argumento
void shellSort(int *arr, int n) { 
    for (int gap = n / 2; gap > 0; gap /= 2) {// O(log n)
        for (int i = gap; i < n; i++) {// O(n)
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main(void){
    clock_t inicio, fim;
    int tamanhos[] = {50, 100, 500, 5000, 50000, 150000, 500000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    srand(time(NULL));

    printf("Relatorio de Tempo ShellSort\n");
    printf("=====================================================\n");
    printf("| Tamanho | Tempo (segundos) | Tempo (milissegundos)|\n");
    printf("-----------------------------------------------------\n");
    fflush(stdout);
    
    for (int i = 0; i < num_tamanhos; i++) {
        int *vetor = gerarArrayAleatorio(tamanhos[i]);

        inicio = clock();
        shellSort(vetor, tamanhos[i]);
        fim = clock();


        double tempo_execucao_segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
        double tempo_execucao_milisegundos = ((double)(fim - inicio) * 1000) / CLOCKS_PER_SEC;
        
        printf("| %7d | %17f | %20f |\n", tamanhos[i], tempo_execucao_segundos, tempo_execucao_milisegundos);
        fflush(stdout);
        free(vetor);
    }
    
    
    return 0;
}