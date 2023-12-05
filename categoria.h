#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "libri.h"



struct categoria{
    char nome_categoria[100];
    nodolibri testa; 
};

nodolibri lista_libri;

typedef struct categoria* categoria;

int crea_categoria(categoria* nuova_categoria, char* nome_categoria);

int set_categoria(categoria categoria_corrente, char* nome_categoria);

int get_categoria(categoria categoria_corrente, char* nome_categoria);

int distruggi_categoria(categoria* categoria_corrente);

int stampa_categoria(categoria categoria_corrente);


#endif
