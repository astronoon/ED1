/*programa em C com menu que registra
nome completo, 3 notas e mostra a maior
media de ate 50 alunos*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definicoes globais
#define TAMANHO_NOME 41
#define NUM_NOTAS 3
#define NUM_ALUNOS 50

//struct do tipo aluno
typedef struct {
    char nome [TAMANHO_NOME];
    float notas [NUM_NOTAS];
    float media;
}aluno;

//funcao para limpar o buffer
void limpar_buffer(){
    char c;
    while (((c = getchar()) != '\n') && (c != EOF));
}

//funcao para adicionar um aluno
void adiciona_aluno (aluno alunos[], int *num_alunos) {
    //verificacao
    if (*num_alunos == NUM_ALUNOS) {
        printf("ja atingiu o maximo.\n");
        return;
    }

    aluno novo;

    //ler o nome    
    printf("digite o nome:");
    fgets(novo.nome, TAMANHO_NOME, stdin);
   
    //ler notas
    for (int i=0; i < NUM_NOTAS ; i++){
        printf("digite a nota %d: ", i);
        scanf("%f", &novo.notas[i]);
    }

    //calcular media
    float media = 0;
    for (int i = 0; i < NUM_NOTAS; i++) {
        media = media + novo.notas[i];
    }
    media = media / NUM_NOTAS;
    novo.media = media;

    alunos[*num_alunos] = novo;
    *num_alunos = *num_alunos + 1;
}


//funcao para listar os alunos
void listar_alunos(const aluno alunos[], int num_alunos){
    if (num_alunos == 0) {
        printf("lista vazia\n");
        return;
    }
    for (int i = 0; i < num_alunos; i++) {
        printf("%s %.2f\n", alunos[i].nome, alunos[i].media);
    }
}

//funcao para imprimir o aluno com a maior media
void maior_media(const aluno alunos[], int num_alunos) {
    int indice_maior = 0;
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].media > alunos[indice_maior].media) {
            indice_maior = i;
        }
    }
    printf("%s %.2f",
           alunos[indice_maior].nome,
           alunos[indice_maior].media);
}



int main() {
    //variaveis do programa
    int opcao;
    //vetor de alunos
    aluno alunos [NUM_ALUNOS];
    int num_alunos = 0;
    //menu
    do{
        //opcoes
        printf("1. Adicionar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Imprimir aluno com maior media\n");
        printf("0. Sair\n");
       
        //entrada da opcao
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        //verificacao de opcao
        switch (opcao){
            case 1:
            //adicionar o aluno
            adiciona_aluno(alunos, &num_alunos);
            break;
            case 2:
            //listar o aluno
            listar_alunos(alunos, num_alunos);
            break;
            case 3:
            //imprimir aluno com a maior media
            maior_media(alunos, num_alunos);
            break;
            case 0:
            printf("fim do programa\n");
            break;
        }
    } while (opcao!=0);

    return 0;
}