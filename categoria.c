#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "categoria.h"
#include "libri.h"


int crea_categoria(categoria* nuova_categoria, char* nomeCategoria){
    (*nuova_categoria) = (categoria)malloc(sizeof(struct categoria));
    if ((*nuova_categoria) == NULL) return 1;
    set_categoria(*nuova_categoria, nomeCategoria);
    crea_lista_libri(&((*nuova_categoria)->testa));
    
    return 0;
}


int set_categoria(categoria categoria_corrente, char* nomeCategoria){
    if(categoria_corrente==NULL) return 1;
    strcpy(categoria_corrente->nome_categoria, nomeCategoria );
    return 0;
}


int get_categoria(categoria categoria_corrente, char* nomeCategoria){
    if(categoria_corrente==NULL) return 1;
    strcpy(  nomeCategoria, categoria_corrente->nome_categoria);
    return 0;
}

int distruggi_categoria(categoria* categoria_corrente){
    if(*categoria_corrente == NULL) return 1;
    elimina_lista_libri(&((*categoria_corrente)->testa));
    free(*categoria_corrente);
    *categoria_corrente = NULL;
    return 0;
} 

int stampa_categoria(categoria categoria_corrente){
    if(categoria_corrente == NULL) return 1;
    printf("%s\n", categoria_corrente -> nome_categoria );
    stampalibri(&(*(categoria_corrente)->testa));
    return 0;
}








