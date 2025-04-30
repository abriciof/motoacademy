/*
 * Autor: Fernanda de Oliveira da Costa
 * Data de criação: 29/04/2025
 * Descrição: Programa que gera vetores de tamanhos variados, ordena e mede o tempo de execução.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para mesclar dois subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função para ordenar um array usando o Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função para gerar um array de tamanho n com valores aleatórios
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;  // Números aleatórios entre 0 e 9999
    }
}

int main() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    
    // Arrays de diferentes tamanhos
    int sizes[] = {100, 1000, 10000, 100000};
    
    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        int arr[size];
        
        generateRandomArray(arr, size);
        
        printf("\nArray original (tamanho %d):\n", size);
        printArray(arr, size);  // Exibe o array original (desordenado)
        
        clock_t start = clock();  // Marca o tempo inicial
        
        mergeSort(arr, 0, size - 1);  // Ordena o array
        
        clock_t end = clock();  // Marca o tempo final
        
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;  // Calcula o tempo de execução
        
        printf("Array ordenado (tamanho %d):\n", size);
        printArray(arr, size);  // Exibe o array ordenado
        
        printf("Tempo de execução para array de tamanho %d: %f segundos\n", size, time_taken);  // Exibe o tempo
    }
    
    return 0;
}
