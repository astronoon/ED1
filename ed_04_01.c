/*programa em c com Merge Sort recursivo, 
imprime os passos de divisão e de intercalação 
realizados durante a ordenação.*/

#include <stdio.h>

//funcao que faz a intercalacao
void intercalar(int vetor[], int inicio, int meio, int fim) {
    //calculo dos tamanhos
    int tamanho_esquerda = meio - inicio + 1;
    int tamanho_direita = fim - meio;

    //variaveis
    int i = 0;
    int j = 0;
    int k = inicio;

    //subvetores
    int E[tamanho_esquerda], D[tamanho_direita];

    //copia os elementos para os subvetores
    for (int i = 0; i < tamanho_esquerda; i++)
        E[i] = vetor[inicio + i];
    for (int j = 0; j < tamanho_direita; j++)
        D[j] = vetor[meio + 1 + j];


    //intercala de modo crescente
    while (i < tamanho_esquerda && j < tamanho_direita) {
        if (E[i] <= D[j])
            vetor[k++] = E[i++];
        else
            vetor[k++] = D[j++];
    }

    //copia o resto da esquerda
    while (i < tamanho_esquerda)
        vetor[k++] = E[i++];

    //copia o resto da direita
    while (j < tamanho_direita)
        vetor[k++] = D[j++];

    //saida: imprime o passo da intercalacao
    printf("INTERCALACAO [%d,%d]:", inicio, fim);
    for (int x = inicio; x <= fim; x++)
        printf(" %d", vetor[x]);
    printf("\n");
}

//funcao recursiva que ordena o vetor
void merge_sort(int vetor[], int inicio, int fim) {
    //caso base
    if (inicio < fim) {
        //passo da divisao
        printf("DIVISAO [%d,%d]\n", inicio, fim);

        //calculo do meio
        int meio = inicio + (fim - inicio) / 2;

        //ordena a esquerda
        merge_sort(vetor, inicio, meio);

        //ordena a direita
        merge_sort(vetor, meio + 1, fim);

        //intercala as duas partes
        intercalar(vetor, inicio, meio, fim);
    }
}

int main() {
    //variavel
    int quantidade;

    //entrada da quantidade
    scanf("%d", &quantidade);

    //vetor
    int vetor[quantidade];

    //entrada dos elementos do vetor
    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &vetor[i]);
    }

    //saida: ordenacao com passos
    merge_sort(vetor, 0, quantidade - 1);

    return 0;
}