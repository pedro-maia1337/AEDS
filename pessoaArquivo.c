#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    int id;
    char nome[50];
    int idade;
} Pessoa;

void adicionarPessoa(){
    Pessoa p1;
    FILE *arquivo = fopen("arquivo.txt", "ab");

    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo");
        getchar();
        return;
    }

    printf("Insira o ID: ");
    scanf("%d", &p1.id);

    getchar();

    printf("Insira o nome: ");
    fgets(p1.nome, sizeof(p1.nome), stdin);

    printf("Insira a idade: ");
    scanf("%d", &p1.idade);

    fwrite(&p1, sizeof(p1), 1, arquivo);
    fclose(arquivo);
    printf("Dados salvos com sucesso\n\n");
}

void visualizarPessoa(){
    Pessoa p1;
    FILE *arquivo = fopen("arquivo.txt", "rb");

    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo");
        getchar();
        return;
    }

    while(fread(&p1, sizeof(p1), 1, arquivo) == 1){
        printf("\nNome: %s", p1.nome);
        printf("ID: %d\n", p1.id);
        printf("Idade: %d\n", p1.idade);
    }

    fclose(arquivo);
}

int main(void){
    int n;

    do {
        printf("\n1 - Adicionar Pessoa\n");
        printf("2 - Visualizar Pessoa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &n);

        switch(n) {
        case 1:
            adicionarPessoa();
            break;

        case 2:
            visualizarPessoa();
            break;
        
        default:
            break;
        }

    } while(n =! 0);
}