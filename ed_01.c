/*programa em C com lista dinamica de numeros inteiros,
o menu interativo tem 6 opcoes: adicionar um valor,
remover o ultimo valor, calcular e exibir a soma e a média dos valores,
ordenar em ordem crescente e encerrar o programa*/

#include <stdio.h>

#include <stdlib.h>

//funcao para adicionar um valor
void adicionar_valor(int ** valor, int * tamanho, int valor_adicionado) {
    //aloca memoria para o novo valor
    int * novo_valor = realloc( * valor, ( * tamanho + 1) * sizeof(int));

    //se a alocacao foi bem sucedida adiciona o novo valor
    if (novo_valor != NULL) {
        * valor = novo_valor;
        ( * valor)[ * tamanho] = valor_adicionado;
        ( * tamanho) ++;
    }
}

//funcao para remover o ultimo valor
void remover_ultimo_valor(int ** valor, int * tamanho) {
    //verifica se a lista esta vazia
    if ( * tamanho > 0) {
        //diminui o tamanho da lsita
        ( * tamanho) --;
        //libera a memoria
        if ( * tamanho == 0) {
            free( * valor);
            * valor = NULL;
        } else {
            //aloca memoria para o novo tamanho
            int * novo_valor = realloc( * valor, ( * tamanho) * sizeof(int));
            if (novo_valor != NULL) {
                * valor = novo_valor;
            }
        }
    }
}

//funcao para criar a lista
void criar_lista(int * lista, int tamanho) {
    //verifica se a lista esta vazia
    if (tamanho > 0) {
        //imprime a lista
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", lista[i]);
        }
        printf("\n");
    }
}

//funcao para calcular a soma e a media
void calcular_media(int * lista, int tamanho) {
    //verifica se a lista esta vazia
    if (tamanho > 0) {
        //calcula a soma
        int soma = 0;
        for (int i = 0; i < tamanho; i++) {
            soma += lista[i];
        }
        //calcula a media
        double media = (double) soma / tamanho;
        //imprime a soma e a media
        printf("Soma = %d, Média = %.2lf\n", soma, media);
    }

}

//funcao para ordenar em ordem crescente
void ordenar_crescente(int * lista, int tamanho) {
    //verifica se a lista esta vazia
    if (tamanho > 0) {
        //ordena a lista
        for (int i = 0; i < tamanho - 1; i++) {
            for (int j = i + 1; j < tamanho; j++) {
                if (lista[i] > lista[j]) {
                    int temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
            }
        }
    }
}

//funcao para limpar o buffer
void limpar_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    //variaveis
    int opcao;
    int * valores = NULL;
    int tamanho = 0;

    //menu
    do {
        //entrada das opcoes
        scanf("%d", & opcao);
        //limpa o buffer
        limpar_buffer();
        //verificacao das opcoes
        switch (opcao) {
        case 1: {
            //adicionar um valor a lista
            int valor_adicionado;
            scanf("%d", & valor_adicionado);
            limpar_buffer();
            adicionar_valor( & valores, & tamanho, valor_adicionado);
            break;
        }
        case 2:
            //remover o ultimo valor
            remover_ultimo_valor( & valores, & tamanho);
            break;
        case 3:
            //imprimir a lista
            criar_lista(valores, tamanho);
            break;
        case 4:
            //calcular e imprimir a soma e a media
            calcular_media(valores, tamanho);
            break;
        case 5:
            //ordenar em ordem crescente
            ordenar_crescente(valores, tamanho);
            break;
        case 6:
            //encerrar o programa
            break;
        }
    } while (opcao != 6);

    //libera o vetor
    free(valores);

    return 0;
}