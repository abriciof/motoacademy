#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[alto]);
    return (i + 1);
}

void quickSort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(vetor, baixo, alto);

        quickSort(vetor, baixo, pi - 1);
        quickSort(vetor, pi + 1, alto);
    }
}

void gerarVetorAleatorio(int vetor[], int n) {
    for (int i = 0; i < n; i++)
        vetor[i] = rand() % 10000;
}

int main() {
    int tamanhos[] = {100, 1000, 10000};
    int numTamanho = sizeof(tamanhos) / sizeof(tamanhos[0]);

    srand(time(NULL));

    for (int i = 0; i < numTamanho; i++) {
        int n = tamanhos[i];
        int *vetor = (int *)malloc(n * sizeof(int));

        gerarVetorAleatorio(vetor, n);

        clock_t inicio = clock();
        quickSort(vetor, 0, n - 1);
        clock_t fim = clock();

        double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        printf("Tamanho do vetor: %d - Tempo de execucao (QuickSort): %.6f segundos\n", n, tempo_execucao);

        free(vetor);
    }

    return 0;
}
