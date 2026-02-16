/* programa em c que  leia do usuario uma lista de numeros
inteiros armazenados em um vetor, a funcao recursiva recebe o vetor
e seu tamanho e retorne a soma de todos os numeros pares contidos nele */

#include <stdio.h>
#include <stdlib.h>

//funcao recursiva que soma os pares
int somador (int *v, int tamanho) {
	//caso base
	if (tamanho == 0) {
		return (0);
	}
	int ultimo = v [tamanho - 1];
	if (ultimo % 2 == 0) {
		return ultimo + somador (v, tamanho - 1);
	} else {
		return somador (v, tamanho - 1);
	}
}

int main() {
	//variaveis
	int *v, tamanho;

	//entrada
	scanf("%d", &tamanho);

	//aloca o vetor dinamicamente
	v = malloc(tamanho * sizeof(int));

	//armazena os valores no vetor
	for (int i = 0; i < tamanho; i++) {
		scanf("%d", &v[i]);
	}

	//saida
	printf("Soma dos pares: %d\n", somador (v, tamanho));

	//libera o vetor
	free (v);

	return 0;
}