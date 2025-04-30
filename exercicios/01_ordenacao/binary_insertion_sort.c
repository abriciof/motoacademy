#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função busca binária
int binarySearch(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

// Algoritmo de ordenação Binary Insertion Sort
void binaryInsertionSort(int arr[], int n) {
    int i, j, selected, loc;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];

        loc = binarySearch(arr, selected, 0, j);

        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

// Função para gerar array com valores
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

int main() {
    int tamanhos[] = {100, 1000, 10000};
    int numTamanho = sizeof(tamanhos) / sizeof(tamanhos[0]);

    srand(time(NULL));

    for (int i = 0; i < numTamanho; i++) {
        int n = tamanhos[i];
        int *arr = (int *)malloc(n * sizeof(int));

        generateRandomArray(arr, n);

        clock_t start = clock();
        binaryInsertionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Tamanho do array: %d - Tempo de execucao: %.6f segundos\n", n, time_taken);

        free(arr);
    }

    return 0;
}