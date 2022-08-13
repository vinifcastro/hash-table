#include "Hash-TAD-H.h"

int CriaHash(){
    FILE *file = NULL;
    No * aux;
    char nome[20];
    char *x;
    int i;
    int n;
    for(i=0; i<TAM; i++){
        tabelahash[i].inicio = NULL;
    }
    file = fopen("Correcao_Hash.txt", "r+");
    fseek(file,0,SEEK_SET);
    while(fscanf(file,"%d;",&n)!=EOF){
        x = fgets(nome, 20, file);
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
    No* aux;
    int k=1;
    int i = chave%40009, j = 1;
    aux = tabelahash[i].inicio;
    while(aux){
        if(aux->id == chave){ 
            printf("Nome referente a chave %d e: %s\nNumero de buscas: %d\n", chave, aux->name, k);
            j=0;
            break;
        }
        aux = aux->prox;
        k++;
    }
    if(j){
        printf("Chave %d nao encontrada!\n\nNumero de buscas %d.\n", chave, k);
    }
    return 0;
}

void inserirno(Lista * lista, int a, char * b){
    No *novo = NULL;
    
    novo = (No*) malloc(sizeof(No));
    novo->id = a;
    novo->prox = lista->inicio;
    strcpy(novo->name, b);
    lista->inicio = novo;
}

void liberahashtable(No**raiz){
    No * aux;
    if(*raiz==NULL) return;
    else{
        while(*raiz!=NULL){
            aux = *raiz;
            *raiz = aux->prox;
            free(aux);
        }
    }
}