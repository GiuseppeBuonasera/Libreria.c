#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//perte di gestione del catalogo del libro al momneto è possibile eseguire le seguentoi operazioni:
//creare categoria, creare libro, aggiungere un libro ad una categoria (creando il libro), stampare il catalogo


//dichiiaro il nodo della lista secondaria                                    
typedef struct nodolibri{
    char autore[400];
    char libro[400];
    struct nodolibri* prossimo; 
}nodolibri;


 //dichiaro il nodo della lista princiapale
typedef struct nodocategorie{
    char categoria[40];
    nodolibri* testa; //testa della lista secondaria
    struct nodocategorie* prossima;
}nodocategorie;


nodocategorie* crea_categoria(char* categoria){
    nodocategorie* nuova_categoria = (nodocategorie*)malloc(sizeof(nodocategorie));
    
    if (nuova_categoria == NULL) {
     perror("Errore nella creazione della categoria");
     exit(EXIT_FAILURE);
    }
    
    strncpy(nuova_categoria->categoria, categoria, sizeof(nuova_categoria->categoria));
    nuova_categoria->testa = NULL; //iniziallizzando la nuova cetegoria 
    //il puntatore alla lista secodnaria deve puntare a null
    nuova_categoria->prossima = NULL; //adesso devo aggiornare il puntatore della testa della lista

    return nuova_categoria;
}


//funzione che permette di andare ad aggiungere un libro al catalogo 
nodolibri* crea_libro(char* libro, char* autore){
    nodolibri* nuovo_libro = (nodolibri*)malloc(sizeof(nodolibri));
    
    if (nuovo_libro == NULL) {
        perror("Errore nella creazione del libro");
        exit(EXIT_FAILURE);
    }

    strncpy(nuovo_libro->libro, libro, sizeof(nuovo_libro->libro));
    strncpy(nuovo_libro->autore, autore, sizeof(nuovo_libro->libro));
    
    nuovo_libro->prossimo= NULL;

    return nuovo_libro;
}


//funzione che permette di aggiungere un ilbro ad una categoria creando un libro
void aggiungi_libro_a_categoria(nodocategorie* categoria,  char* libro, char* autore) {
    nodolibri* nuovo_libro = crea_libro(libro, autore);

    if (categoria->testa == NULL) {
        categoria->testa = nuovo_libro;
    } else {
        nuovo_libro->prossimo = categoria->testa;
        categoria->testa = nuovo_libro;
    }
}


//funzione che epremtte di andare a visualizzare tutti i libri presenti in catalogo  
void stampalistadiliste(nodocategorie* lista_categorie ){

    while (lista_categorie != NULL){
        printf("LIBRI PRESENTI NELLA CATEGORIA %s:\n",lista_categorie->categoria );
    
        nodolibri* libro_corrente = lista_categorie->testa;
        while (libro_corrente != NULL){
            printf("%s, %s\n", libro_corrente->libro, libro_corrente->autore);
            libro_corrente= libro_corrente->prossimo;
            
        }
    lista_categorie = lista_categorie->prossima;
    }
}

void modifica_categoria();
void elimina_categoria();
void modifica_libro();
void elimina_libro();
void cerca_libro();
void cerca_categoria();





int main(){
    nodocategorie* romanzo= crea_categoria("ROMANZO");
    aggiungi_libro_a_categoria(romanzo, "HARRY POTTER" , "JK ROwiling");
    aggiungi_libro_a_categoria(romanzo, "cazzo", "nel culo");

    stampalistadiliste(romanzo);

    return 0;
    }
    



