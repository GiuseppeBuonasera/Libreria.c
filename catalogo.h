#ifndef CATALOGO_H
#define CATALOGO_H


typedef struct nodolibri{
    char autore[400];
    char libro[400];
    float costo;
    struct nodolibri* prossimo; 
}nodolibri;

typedef struct nodocategorie{
    char categoria[400];
    nodolibri* testa; 
    struct nodocategorie* prossima;
}nodocategorie;

nodocategorie* listacategorie;

nodocategorie* crea_categoria(nodocategorie** listacategorie ,char* categoria);

nodolibri* crea_libro(char* libro, char* autore, float nuovocosto);

void aggiungi_libro_a_categoria(nodocategorie* listadiliste,char* categoria_cercata,  char* libro, char* autore, float costo);

void stampacategorie(nodocategorie* listacategorie);

void stampalibri(nodocategorie* listacategorie );

void modifica_categoria(nodocategorie** listacategorie, char* categoria_cercata, char* nuova_categoria );

void elimina_categoria(nodocategorie** listacategorie,char* categoria_cercata);

void modifica_libro(nodocategorie* listacategorie,char* libro_cercato, char* nuovo_libro, char* nuovo_autore, float nuovocosto);

void elimina_libro(nodocategorie* listacategorie, char* libro_da_eliminare);

nodocategorie* cerca_categoria( nodocategorie* listacategorie, char* categoria_cercata);

nodolibri* cerca_libro(nodocategorie* listacategorie, char* libro_cercato);




#endif
