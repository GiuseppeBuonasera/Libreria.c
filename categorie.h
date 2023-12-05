#ifndef CATEGORIE_H
#define CATEGORIE_H
#include "categoria.h"

struct nodocategorie{
    categoria c;
    struct nodocategorie* next;
};



typedef struct nodocategorie* nodocategorie;
 
int crea_lista_categorie(nodocategorie* listacategorie);

int crea_nodo_categoria(nodocategorie* listacategorie ,char* nome_categoria);

categoria cerca_nodo_categoria(nodocategorie listacategorie ,char* nome_categoria);

void modifica_nodo_categorie(nodocategorie listacategorie, char* categoria_cercata, char* nuova_categoria );

void elimina_nodo_categorie(nodocategorie* listacategorie,char* categoria_cercata);

void elimina_lista_categorie(nodocategorie* listacategorie);

void stampacategorie(nodocategorie listacategorie);

void stampa_categorie_e_libri(nodocategorie listacategorie);

void aggiungi_libro_a_categoria(nodocategorie* listacategorie, char* nome_categoria,char* titolo, char* autore, float costo);
































#endif