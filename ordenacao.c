/*
 * Aplicação prática: ordenação das notas de uma turma
 * Algoritmos: Bubble Sort e Quick Sort
 *
 * Situação-problema: o professor precisa organizar as notas dos alunos
 * em ordem crescente para montar o ranking da turma e identificar
 * rapidamente quem precisa de reforço.
 *
 * Os MESMOS dados são ordenados pelos dois algoritmos, e o programa
 * mostra quantas comparações cada um precisou fazer.
 */

#include <stdio.h>
#include <string.h>

#define TAM 10   /* quantidade de registros (mínimo exigido: 10) */

/* Cada registro guarda o nome do aluno e a nota dele */
struct Aluno {
    char nome[20];
    float nota;
};

/* Contadores para comparar o trabalho de cada algoritmo */
int comparacoes = 0;
int trocas = 0;

/* Mostra a lista de alunos na tela */
void mostrar(struct Aluno v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%2d) %-10s nota: %.1f\n", i + 1, v[i].nome, v[i].nota);
    }
}

/*
 * BUBBLE SORT
 * Percorre o vetor várias vezes comparando pares vizinhos.
 * Se o da esquerda for maior que o da direita, eles trocam de lugar.
 * A cada passada completa, o maior valor "sobe" como uma bolha
 * até o final do vetor. Por isso, a cada passada (i) precisamos
 * olhar um elemento a menos (n - 1 - i).
 */
void bubbleSort(struct Aluno v[], int n) {
    int i, j;
    struct Aluno temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            comparacoes++;
            if (v[j].nota > v[j + 1].nota) {
                temp = v[j];          /* troca usando uma variável auxiliar */
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocas++;
            }
        }
    }
}

/*
 * PARTIÇÃO (usada pelo Quick Sort)
 * Escolhe o último elemento como PIVÔ.
 * Depois reorganiza o pedaço do vetor de modo que:
 *   - tudo que é menor que o pivô fique à esquerda dele;
 *   - tudo que é maior fique à direita.
 * Devolve a posição final do pivô, que já está no lugar certo.
 */
int particao(struct Aluno v[], int inicio, int fim) {
    float pivo = v[fim].nota;
    int i = inicio - 1;   /* marca o fim da região dos menores */
    int j;
    struct Aluno temp;

    for (j = inicio; j < fim; j++) {
        comparacoes++;
        if (v[j].nota < pivo) {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            trocas++;
        }
    }

    /* coloca o pivô entre os menores e os maiores */
    temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;
    trocas++;

    return i + 1;
}

/*
 * QUICK SORT
 * Usa a ideia de "dividir para conquistar":
 *   1) escolhe um pivô e faz a partição;
 *   2) ordena (com a mesma função) a parte da esquerda do pivô;
 *   3) ordena (com a mesma função) a parte da direita do pivô.
 * Quando o pedaço tem 0 ou 1 elemento, ele já está ordenado (caso base).
 */
void quickSort(struct Aluno v[], int inicio, int fim) {
    int posicaoPivo;

    if (inicio < fim) {
        posicaoPivo = particao(v, inicio, fim);
        quickSort(v, inicio, posicaoPivo - 1);   /* lado esquerdo */
        quickSort(v, posicaoPivo + 1, fim);      /* lado direito  */
    }
}

int main() {
    /* Dados originais (fora de ordem) */
    struct Aluno original[TAM] = {
        {"Ana", 7.5}, {"Bruno", 5.0}, {"Carla", 9.0}, {"Diego", 6.5},
        {"Elisa", 8.0}, {"Felipe", 4.5}, {"Gabriela", 9.5}, {"Heitor", 6.0},
        {"Isabela", 7.0}, {"Joao", 8.5}
    };
    struct Aluno vetorBubble[TAM];
    struct Aluno vetorQuick[TAM];
    int i;

    /* Copia os dados originais para os dois vetores,
       assim os dois algoritmos ordenam exatamente os mesmos dados */
    for (i = 0; i < TAM; i++) {
        vetorBubble[i] = original[i];
        vetorQuick[i] = original[i];
    }

    printf("=== NOTAS ANTES DA ORDENACAO ===\n");
    mostrar(original, TAM);

    /* ---- Bubble Sort ---- */
    comparacoes = 0;
    trocas = 0;
    bubbleSort(vetorBubble, TAM);
    printf("\n=== DEPOIS DO BUBBLE SORT (crescente) ===\n");
    mostrar(vetorBubble, TAM);
    printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);

    /* ---- Quick Sort ---- */
    comparacoes = 0;
    trocas = 0;
    quickSort(vetorQuick, 0, TAM - 1);
    printf("\n=== DEPOIS DO QUICK SORT (crescente) ===\n");
    mostrar(vetorQuick, TAM);
    printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);

    return 0;
}
