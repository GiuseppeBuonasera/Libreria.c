
#ifndef LIBRI_H
#define LIBRI_H
#include "libro.h"

struct nodolibri{
    libro n;
    struct nodolibri* prossimo; 
};

char libri[100];
 
typedef struct nodolibri* nodolibri;

int crea_lista_libri(nodolibri* lista_libri);

int crea_nodo_libri(nodolibri* lista_libri, char* nuovo_titolo, char* nuovo_autore, float nuovocosto);

libro cerca_libro(nodolibri lista_libri, char* titolo_cercato);

void modifica_libro(nodolibri lista_libri ,char* titolo_cercato, char* nuovo_titolo, char* nuovo_autore, float nuovocosto);

void elimina_nodo_libro(nodolibri* lista_libri, char* titolo_cercato);

void elimina_lista_libri(nodolibri* lista_libri);

void stampalibri(nodolibri lista_libri);

#endif