#include <stdio.h>
#include "Hash-TAD-H.h"

int CriaHash(){
    FILE *file = NULL;
    No * aux;
    char nome[20];
    int i;
    long int n;
    for(i=0; i<TAM; i++){
        tabelahash[i].inicio = NULL;
    }
    file = fopen("Correcao_Hash.txt", "r+");
    fseek(file,0,SEEK_SET);
    while(fscanf(file,"%d;",&n)!=EOF){
        fgets(nome, 20, file);
        i = n%40009;
        inserirno(&tabelahash[i], n, nome);
        n = 0;
        aux = tabelahash[i].inicio;
        n = aux->id;
        strcpy(nome, aux->name);
    }
    fclose(file);
    return 0;
}

int BuscaHash(int chave, float media)
{

}

void inserirno(Lista * lista, int a, char * b){
    No *novo = NULL;
    
    novo = (No*) malloc(sizeof(No));
    novo->id = a;
    novo->prox = lista->inicio;
    strcpy(novo->name, b);
    lista->inicio = novo;
}