/*
 * Autor: Fabrício da Costa Guimarães
 * Data de criação: 28/04/2025
 * Descrição: Programa que gera vetores de tamanhos variados, ordena e mede o tempo de execução.
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 // Cria um vetor randomico
 void criar_vetor_random(int vetor[], int tamanho) {
     for(int i=0; i<tamanho; i++ ) {
         vetor[i] = rand()%(10000);
     }
 }
 
 // Criar um novo Gap para o CombSort
 int cria_novo_gap(int gap) {
     gap = (gap * 10) / 13;
     if (gap == 9 || gap == 10)
         gap = 11;
     if (gap < 1)
         gap = 1;
     return gap;
 }
 
 // Ordenação com Comb Sort
 void comb_sort(int a[], int aSize) {
     int gap = aSize;
     int temp, i;
 
     // infinito
     for (;;)
     {
         gap = cria_novo_gap(gap);
         int swapped = 0;
         for (i = 0; i < aSize - gap; i++) {
             int j = i + gap;
             if (a[i] > a[j])
             {
                 temp = a[i];
                 a[i] = a[j];
                 a[j] = temp;
                 swapped  =  1;
             }
         }
         if (gap  ==  1 && !swapped)
             break;
     }
 }
 
 
 // Função main
 int main() {
     srand((unsigned)time(NULL));
 
     int tamanhos[] = {50, 100, 500, 5000, 50000, 150000, 500000, 1000000};
     int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
 
     // Criar tabela de resultados
     printf("Relatorio de Tempo CombSort\n");
     printf("=====================================================\n");
     printf("| Tamanho | Tempo (segundos) | Tempo (milissegundos)|\n");
     printf("-----------------------------------------------------\n");
 
     for (int t = 0; t < num_tamanhos; t++) {
         int tamanho = tamanhos[t];
         
         // Alocar vetor dinamicamente
         int *vetor = (int *)malloc(tamanho * sizeof(int));
         if (vetor == NULL) {
             printf("Erro ao alocar memória para tamanho %d\n", tamanho);
             continue;
         }
 
         criar_vetor_random(vetor, tamanho);
 
         clock_t inicio, fim;
         inicio = clock();
         comb_sort(vetor, tamanho);
         fim = clock();
 
         double tempo_segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
         double tempo_milisegundos = ((double)(fim - inicio) * 1000) / CLOCKS_PER_SEC;
 
         printf("| %7d | %15.6f | %21.3f |\n", tamanho, tempo_segundos, tempo_milisegundos);
 
         // Liberar memória depois de usar
         free(vetor);
     }
 
     printf("=====================================================\n");
 
     return 0;
 }