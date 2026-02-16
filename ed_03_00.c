/*programa em C que calcula o fatorial de um numero de maneira recursiva*/
#include <stdio.h>

//funcao que calcula o fatorial
int fatorial (int numero) {
	printf ("Entrando em fatorial(%d)\n", numero);

	//caso base
	if (numero == 1 || numero == 0) {
		printf ("Caso base atingido: fatorial(%d) = 1\n", numero);
		return (1);
	}

	//passo recursivo
	int resultado = numero*fatorial (numero-1);

	//mensagem
	printf ("Retornando de fatorial(%d) = %d\n", numero, resultado);

	return (resultado);
}

int main() {
	//variaveis
	int numero, resultado;

	//entrada
	scanf ("%d", &numero);

	//mensagem
	printf ("Calculando fatorial de %d...\n", numero);

	//calculo do resultado
	resultado = fatorial (numero);

	//saida
	printf ("Resultado final: %d \n", resultado);

	return 0;
}