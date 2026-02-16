/* Integrantes:
Bruna Rafaela de Souza Weber - 15744172
Laura Tizo Cominali - 15099350 */

/* Trabalho 1 - programa com menu que 
contabiliza o tempo de execucao das operacoes de:
inversao, busca sequencial, busca binaria iterativa
e busca binaria recursiva do vetor */

#include <stdio.h>
#include <stdlib.h>

//funcao que faz a inversao da ordem do vetor
void inverter (int v[], int tamanho, int *invertido){
    int temp; //variavel temporaria para fazer swap
    int j = tamanho-1; //indice do ultimo elemento
    for(int i = 0; i < tamanho/2; i++){ //loop executa ate' metade do vetor
        //swap dos elementos nos extremos
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        j--;
    }
    //sinalizar que o vetor esta invertido ou nao
    if(*invertido == 0){
        *invertido = 1;
    } else {
        *invertido = 0;
    }

}

//funcao que faz a busca sequencial
void busca_sequencial(int v[], int tamanho, int elemento){
    for(int i = 0; i < tamanho; i++){ //varrer o vetor ate' encontrar o elemento
        if(v[i] == elemento){
            printf("SIM\n");
            return;
        }
    }
    printf("NAO\n"); //caso o vetor seja inteiramente varrido e o elemento nao for encontrado
}

//funcao que faz a busca binaria iterativa
void busca_iterativa(int v[], int tamanho, int elemento, int invertido){
    //ponteiros do vetor
    int inferior = 0; 
    int superior = tamanho - 1;
    int meio;

    while(inferior <= superior){
        meio = inferior + (superior - inferior) / 2;
        if(v[meio] == elemento){
            printf("SIM\n");
            return;
        } else {
            if(elemento < v[meio]){ //varrer a metade menor que o elemento do meio
                if(invertido){
                    inferior = meio + 1; //os elementos menores estarao nos maiores indices
                }else{
                    superior = meio - 1;
                }
            } else { //varrer a metade maior que o elemento do meio
                if(invertido){
                    superior = meio - 1; //os elementos maiores estarao nos menores indices
                }else{
                    inferior = meio + 1;
                }
            }
        }
    }
    printf("NAO\n"); //caso o elemento nao seja encontrado

}

//funcao que faz a busca binaria recursiva
void busca_recursiva(int v[], int inferior, int superior, int elemento, int invertido){
    int meio;
    if(inferior > superior){
        printf("NAO\n");
        return;
    } else {
        meio = inferior + (superior - inferior) / 2;
        if(v[meio] == elemento){
            printf("SIM\n");
            return;
        }else{
            if(elemento < v[meio]){
                if(invertido){
                    return busca_recursiva(v, meio + 1, superior, elemento, invertido);
                }else{
                    return busca_recursiva(v, inferior, meio - 1, elemento, invertido);
                }
            }else{
                if(invertido){
                    return busca_recursiva(v, inferior, meio - 1, elemento, invertido);
                }else{
                    return busca_recursiva(v, meio + 1, superior, elemento, invertido);
                }
            }
        }
    }
}

int main() {
    //variaveis
    int opcao, tamanho, elemento, resultado, invertido;

    invertido = 0; //sinaliza se o vetor esta' invertido ou nao

    //primeira entrada: tamanho do vetor
    scanf ("%d", &tamanho);

    //aloca dinamicamente o vetor
    int *v = (int*) malloc (tamanho * sizeof(int));

    //entrada: itens do vetor
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &v[i]);
    }

    //menu
    do {
        //entrada: opcao
        scanf("%d", &opcao);

        //verificacao das opcoes
        switch (opcao){
        case 1: 

            //chamada da funcao que faz a inversao da ordem do vetor
            inverter(v, tamanho, &invertido);

            //imprime o vetor invertido
            for (int i = 0; i < tamanho; i++){
                printf("%d ", v[i]);
            }
            printf("\n");
            
            break;
    
        case 2:
            //entrada do elemento a ser buscado
            scanf("%d", &elemento);

            //chamada da funcao que faz busca sequencial
            busca_sequencial(v, tamanho, elemento);

            break;

        case 3:
            //entrada do elemento a ser buscado
            scanf("%d", &elemento);

            //chamada da funcao que faz a busca iterativa
            busca_iterativa(v, tamanho, elemento, invertido);

            break;

        case 4:
            //entrada do elemento a ser buscado
            scanf("%d", &elemento);

            //chamada da funcao que faz a busca recursiva
            busca_recursiva(v, 0, tamanho-1, elemento, invertido);
            
            break;

        case 5:
            //encerra o programa
            break;
        }
    } while (opcao != 5);
    
    //libera a memoria
    free (v);
    
    return 0;
}