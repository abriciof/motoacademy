/*
 * Autores:
    * Fabrício da Costa Guimarães
    * Fernanda de Oliveira da Costa
    * Jeovana Santos da Costa
    * Lucas Teixeira de Amorim
    * Rômulo Lira
 * Data de criação: 29/04/2025
 * Descrição: Programa que gera vetores de tamanhos variados, ordena e mede o tempo de execução.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>





// #################################### Gerais ###########################################

// Tipo de função de ordenação
typedef void (*ordernador)(int vetor[], int tamanho);

typedef struct {
    const char *nome;
    ordernador ordenacao;
} ordernador_t;


// Cria um vetor randômico
void criar_vetor_random(int vetor[], int tamanho) {
	for(int i=0; i<tamanho; i++ ) {
		vetor[i] = rand() % 10000;
	}
}

// Imprimir um vetor
void imprimir_vetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}


// #################################### Algoritmos #######################################

// ------------- CombSort -------------

// Criar um novo Gap para o CombSort
int cria_novo_gap(int gap) {
	gap = (gap * 10) / 13;
	
    if (gap == 9 || gap == 10)
		gap = 11;

	if (gap < 1)
		gap = 1;
	
    return gap;
}

// Algoritmo de ordenação CombSort
void comb_sort(int vetor[], int tamanho) {
	int gap = tamanho;
	int aux;

	// infinito
	for (;;){
		gap = cria_novo_gap(gap);
		int swapped = 0;
		for (int i = 0; i < tamanho - gap; i++) {
			int j = i + gap;
			if (vetor[i] > vetor[j]){
                // Trocando posições
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;

                // Flag que trocou
				swapped  =  1;
			}
		}

		if (gap  ==  1 && !swapped)
            break;
	}
}

// ------------- ShellSort -------------

// Algoritmo de ordenação ShellSort
void shell_sort(int vetor[], int tamanho) { 
    for (int gap = tamanho / 2; gap > 0; gap /= 2) {// O(log n)
        for (int i = gap; i < tamanho; i++) {// O(n)
            int temp = vetor[i];
            int j;
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = temp;
        }
    }
}

// ------------- MergeSort -------------

// Função para mesclar dois subarrays
void merge(int vetor[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vetor[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

// Algoritmo de ordenação MergeSort
void merge_sort(int vetor[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        merge_sort(vetor, l, m);
        merge_sort(vetor, m + 1, r);
        
        merge(vetor, l, m, r);
    }
}

void merge_sort_main(int vetor[], int tamanho) {
    merge_sort(vetor, 0, tamanho - 1);
}


// ------------- BinaryInsertionSort -------------

// Função busca binária
int binary_search(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binary_search(arr, item, mid + 1, high);
    return binary_search(arr, item, low, mid - 1);
}

// Algoritmo de ordenação BinaryInsertionSort
void binary_insertion_sort(int arr[], int n) {
    int i, j, selected, loc;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];

        loc = binary_search(arr, selected, 0, j);

        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}



// #################################### Main #############################################




// Estrutura para mapear nome ↔ função


int main() {
    srand((unsigned)time(NULL));

    // Defina aqui todos os algoritmos que quer testar
    ordernador_t ordenacoes[] = {
        { "CombSort",            comb_sort },
        { "ShellSort",           shell_sort },
        { "MergeSort",           merge_sort_main },
        { "BinaryInsertionSort", binary_insertion_sort },
    };

    int qtde_ordernacoes = sizeof(ordenacoes) / sizeof(ordenacoes[0]);

    int tamanhos[] = {500, 5000, 10000, 50000, 150000, 500000, 1000000};
    int qtde_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Cabeçalho do relatório
    printf("Relatorio de Tempo de Ordenacao\n");
    printf("===================================================================\n");
    printf("|  Tamanho |       Ordenacao      |   Tempo (s)   |   Tempo (ms)  |\n");
    printf("-------------------------------------------------------------------\n");

    // Percorrendo lista de tamanhos
    for (int ti = 0; ti < qtde_tamanhos; ti++) {

        // Tamanho Atual
        int tamanho_atual = tamanhos[ti];

        // Gera o vetor original
        int *vetor_original = malloc(tamanho_atual * sizeof(int));
        if (!vetor_original) { printf("Falha malloc n=%d\n", tamanho_atual); continue; }
        criar_vetor_random(vetor_original, tamanho_atual);

        // Percorrendo lista de Ordenações
        for (int si = 0; si < qtde_ordernacoes; si++) {

            // Faz uma cópia do vetor original
            int *vetor = malloc(tamanho_atual * sizeof(int));
            if (!vetor) { printf("Falha malloc vetor n=%d\n", tamanho_atual); break; }
            memcpy(vetor, vetor_original, tamanho_atual * sizeof(int));

            // Ordena e mede tempo
            clock_t start = clock();
            ordenacoes[si].ordenacao(vetor, tamanho_atual);
            clock_t end   = clock();
            
            // Converção para Segundos e Milisegundos
            double tempo_segundos = (double)(end - start) / CLOCKS_PER_SEC;
            double tempo_milisegundos = tempo_segundos * 1000.0;


            printf("| %8d | %-20s | %13.6f | %13.3f |\n",
                tamanho_atual, ordenacoes[si].nome, tempo_segundos, tempo_milisegundos);
            
            // Liberando memória do vetor cópia
            free(vetor);
        }

        printf("-------------------------------------------------------------------\n");

        // Liberando memória do vetor original
        free(vetor_original);
    }

    printf("=====================================================================\n");
    return 0;
}