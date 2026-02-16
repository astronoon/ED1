/*programa em C que faca uma lista dinamica de
inteiros com insercao em posição arbitraria*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    //variaveis
    int tam_inicial, posicao, novo_valor;
    int *v;

    //primeira entrada: tamanho inicial
    scanf("%d", &tam_inicial);

    //aloca o vetor dinamicamente
    v = malloc(tam_inicial * sizeof(int));
    if (v == NULL) {
        return 1;
    }

    //armazena os valores no vetor
    for (int i = 0; i < tam_inicial; i++) {
        scanf("%d", &v[i]);
    }

    //segunda entrada: novo valor
    scanf("%d", &novo_valor);

    //terceira entrada: posição
    scanf("%d", &posicao);

    //verifica se a posição é válida
    if (posicao < 0 || posicao > tam_inicial) {
        free(v);
        return 1;
    }

    //realoca o vetor para o novo tamanho
    int *temp = realloc(v, (tam_inicial + 1) * sizeof(int));
    if (temp == NULL) {
        free(v);
        return 1;
    }
    //atualiza o ponteiro
    v = temp;

    //desloca os elementos para abrir espaço na posição desejada
    for (int i = tam_inicial; i > posicao; i--) {
        v[i] = v[i - 1];
    }

    //insere o valor novo
    v[posicao] = novo_valor;

    //aumenta o tamanho
    tam_inicial++; 

    //exibe o vetor
    for (int i = 0; i < tam_inicial; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    //libera a memória
    free(v);

    return 0;
}