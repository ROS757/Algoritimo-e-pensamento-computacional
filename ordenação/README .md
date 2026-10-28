# Ordenação de notas com Bubble Sort e Quick Sort

Aplicação em linguagem C que organiza as notas de uma turma usando dois algoritmos de ordenação, **Bubble Sort** e **Quick Sort**, e compara o trabalho de cada um.

## Objetivo

Aplicar na prática os algoritmos Bubble Sort e Quick Sort, ordenando os **mesmos dados** pelos dois métodos, mostrando as informações antes e depois da ordenação e comparando quantas comparações e trocas cada algoritmo precisou fazer.

## Situação-problema

Um professor tem as notas de 10 alunos, registradas fora de ordem. Ele precisa organizá-las em ordem crescente para montar o ranking da turma e identificar rapidamente quem tem as menores notas e precisa de reforço. Sem ordenar, seria preciso procurar manualmente em toda a lista; com a lista ordenada, a leitura é imediata.

## Como executar

Requisito: compilador GCC (Linux, macOS, ou MinGW no Windows).

```bash
gcc ordenacao.c -o ordenacao
./ordenacao        # no Windows: ordenacao.exe
```

Também é possível rodar online, sem instalar nada, pelo OnlineGDB (link na seção "Execução online" abaixo).

## Exemplo de saída

```
=== NOTAS ANTES DA ORDENACAO ===
 1) Ana        nota: 7.5
 2) Bruno      nota: 5.0
 ...
=== DEPOIS DO BUBBLE SORT (crescente) ===
 1) Felipe     nota: 4.5
 2) Bruno      nota: 5.0
 ...
Comparacoes: 45 | Trocas: 20

=== DEPOIS DO QUICK SORT (crescente) ===
 1) Felipe     nota: 4.5
 ...
Comparacoes: 21 | Trocas: 19
```

## Como funcionam os algoritmos

### Bubble Sort

Percorre o vetor várias vezes comparando elementos vizinhos. Se o da esquerda for maior que o da direita, eles trocam de lugar. A cada passada completa, o maior elemento restante "sobe como uma bolha" até a sua posição final. O processo se repete até todo o vetor estar ordenado.

* É simples de entender e de implementar.
* Complexidade de tempo: O(n²) no pior caso e no caso médio. Para 10 elementos faz sempre 45 comparações.

### Quick Sort

Usa a estratégia de **dividir para conquistar**:

1. Escolhe um elemento como **pivô** (nesta implementação, o último do trecho).
2. Faz a **partição**: coloca à esquerda do pivô os elementos menores e à direita os maiores. O pivô fica na posição final correta.
3. Repete o mesmo processo, de forma **recursiva**, para o lado esquerdo e para o lado direito.
4. Quando o trecho tem 0 ou 1 elemento, ele já está ordenado (caso base).
* Complexidade de tempo: O(n log n) no caso médio e O(n²) no pior caso (por exemplo, vetor já ordenado com pivô no extremo).
* Em geral é bem mais rápido que o Bubble Sort em listas grandes.

### Comparação

|Característica|Bubble Sort|Quick Sort|
|-|-|-|
|Estratégia|Comparar vizinhos|Dividir para conquistar|
|Tempo médio|O(n²)|O(n log n)|
|Implementação|Mais simples|Usa recursão|
|Comparações neste exemplo (10 notas)|45|21|

## Estrutura do projeto

```
.
├── ordenacao.c   # código-fonte comentado
└── README.md     # esta documentação
```

## Execução online

Execute direto no navegador pelo OnlineGDB: https://onlinegdb.com/h1e3rWEhV

## Autor

Rafael Oliveira da Silva — Ciência da Computação, disciplina de Algoritmos e Pensamento Computacional, UDF

