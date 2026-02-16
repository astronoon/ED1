/* programa em c com funcao recursiva que 
imprime uma sequencia de movimentos de 
uma torre de hanoi com n discos*/  

#include <stdio.h>

//funcao recursiva que faz a movimentacao de discos
void hanoi(int discos, char origem, char destino, char auxiliar) {
    //caso base
    if (discos == 1) {
        printf("Mova o disco 1 de %c para %c\n", origem, destino);
        return;
    }

    //move os discos menores para a torre auxiliar
    hanoi(discos - 1, origem, auxiliar, destino);

    //move o disco maior para o destino
    printf("Mova o disco %d de %c para %c\n", discos, origem, destino);

    //move os discos da torre auxiliar para o destino
    hanoi(discos - 1, auxiliar, destino, origem);
}

int main() {
    //variaveis
    int discos;

    //entrada
    scanf("%d", &discos);

    //saida
    hanoi(discos, 'A', 'C', 'B');

    return 0;
}