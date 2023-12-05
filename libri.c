#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#include "libri.h"
#include "libro.h"

int crea_lista_libri(nodolibri* lista_libri){
    *lista_libri = NULL;
    return 0;
}


//funzione che permette di andare ad aggiungere un libro al catalogo 
int crea_nodo_libri(nodolibri* lista_libri, char* nuovo_titolo, char* nuovo_autore, float nuovocosto){
    nodolibri nuovo_nodo;
    nuovo_nodo = (nodolibri)malloc(sizeof(struct nodolibri));
    if (nuovo_nodo == NULL) {
        printf("# ERRORE: LIBRO NON CREATO\n\n");
        sleep(1);
        return 1;
    }
    int token = crea_libro(&(nuovo_nodo -> n), nuovo_titolo, nuovo_autore, nuovocosto);
    if(token == 1) return 1;
    nuovo_nodo -> prossimo = *lista_libri;
    *lista_libri = nuovo_nodo;
    printf("# LIBRO CREATO CON SUCCESSO\n\n");
    sleep(1);
    return 0;
}

libro cerca_libro(nodolibri lista_libri, char* titolo_cercato){
    while(lista_libri != NULL){
        char titolo[20];
        get_titolo(lista_libri -> n , titolo);
        if(strcmp(titolo_cercato, titolo) == 0){
            return lista_libri->n;
        }
        lista_libri = lista_libri -> prossimo;       
        
        
    }         
}


    
void modifica_libro(nodolibri lista_libri ,char* titolo_cercato, char* nuovo_titolo, char* nuovo_autore, float nuovocosto){
    libro libro_in_lista = cerca_libro(lista_libri, titolo_cercato); 
    if (libro_in_lista == NULL) return;
    int campo1 = 0;
    int campo2 = 0;
    int campo3 = 0;
    if(nuovo_titolo[0] != '\0')
        campo1 = set_titolo(libro_in_lista, nuovo_titolo);
    if(nuovo_autore[0] != '\0')
        campo2 = set_autore(libro_in_lista, nuovo_autore);
    if(nuovocosto != 0)
        campo3 = set_costo(libro_in_lista, nuovocosto);
    if (campo1 && campo2 && campo3) return;
    return;
}
    


void elimina_nodo_libro(nodolibri* lista_libri, char* titolo_cercato) {
    nodolibri librocorrente = *lista_libri; //creo due puntatori uno alla testa e uno a null
    nodolibri libroprecedente = NULL;

    while (librocorrente != NULL) {
        char titolo[100];
        get_titolo(librocorrente->n, titolo);

        if (strcmp(titolo, titolo_cercato) == 0) {
            if (libroprecedente == NULL) {
                *lista_libri = librocorrente->prossimo;
                //in questo modo se il libro eliminato e' in testa aggiorno il puntatore alla testa;
            } else {
                libroprecedente->prossimo = librocorrente->prossimo;
               
            }
            free(librocorrente);  

            printf("# LIBRO ELIMINATO CON SUCCESSO\n");
            sleep(1);
            return;
        }

        libroprecedente = librocorrente;
        librocorrente = librocorrente->prossimo;
    }

    printf("# CATEGORIA O LIBRO NON TROVATI\n \n");
    sleep(1);
}


void elimina_lista_libri(nodolibri* lista_libri){
    while(*lista_libri != NULL){
        nodolibri librocorrente = *lista_libri;
        elimina_libro(&(librocorrente -> n));
        *lista_libri = (*lista_libri)->prossimo;
        free(librocorrente);
    }

}   


 
void stampalibri(nodolibri lista_libri ){
    nodolibri librocorrente = lista_libri;
    while (librocorrente != NULL){
        print_libro( librocorrente-> n);
        librocorrente = librocorrente -> prossimo;
        } 

}

