#ifndef CATALOGO_H
#define CATALOGO_H


typedef struct nodolibri{
    char autore[400];
    char libro[400];
    struct nodolibri* prossimo; 
}nodolibri;

typedef struct nodocategorie{
    char categoria[400];
    nodolibri* testa; //testa della lista secondaria
    struct nodocategorie* prossima;
}nodocategorie;

nodocategorie* crea_categoria(nodocategorie** listacategoire ,char* categoria);

nodolibri* crea_libro(char* libro, char* autore);

void aggiungi_libro_a_categoria(nodocategorie* categoria,  char* libro, char* autore);

void stampacategorie(nodocategorie* listacategorie);

void stampalibri(nodocategorie* listacategorie );

void modifica_categoria(nodocategorie** listacategorie, char* categoria_cercata, char* nuova_categoria );

void elimina_categoria(nodocategorie** listacategorie,char* categoria_cercata);

void modifica_libro(nodocategorie* listacategorie,char* libro_cercato, char* nuovo_libro, char* nuovo_autore);

void elimina_libro(nodocategorie* listacategorie, char* libro_da_eliminare);

nodocategorie* cerca_categoria( nodocategorie* listacategorie, char* categoria_cercata);

nodolibri* cerca_libro(nodocategorie* listacategorie, char* categoria_cercata, char* libro_cercato);




#endif
