/* programa em c que calcula o n-C)simo
elemento da sequencia de Fibonacci*/

#include <stdio.h>

//funcao que calcula a sequncia de fibonacci
int fibonacci (int numero) {
	//mensagem
	printf ("Entrando em fibonacci(%d)\n", numero);

	//entrada invalida
	if (numero < 0) {
		return (-1);
	}
	//casos base
	if (numero == 0) {
		//mensagem
		printf ("Caso base atingido: fibonacci(%d) = 0\n", numero);
		return (0);
	}
	if (numero == 1) {
		//mensagem
		printf ("Caso base atingido: fibonacci(%d) = 1\n", numero);
		return (1);
	}

	//passo recursivo
	int resultado = fibonacci (numero - 1) + fibonacci (numero - 2);

	//mensagem
	printf ("Retornando de fibonacci(%d) = %d\n", numero, resultado);

	return (resultado);
}

int main() {
	//variaveis
	int numero, resultado;

	//entrada
	scanf("%d", &numero);

	//mensagem
	printf ("Calculando fibonacci de %d...\n", numero);

	//calculo do resultado
	resultado = fibonacci (numero);

	//saida
	printf("Resultado final: %d\n", resultado);

	return 0;
}