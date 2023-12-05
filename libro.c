#include <stdio.h>
#include <stdlib.h>
#include "libro.h"
#include <string.h>


int crea_libro(libro* book, char* nuovo_titolo, char* nuovo_autore, float nuovocosto){
    (*book) = (libro)malloc(sizeof(struct libro));
    if((*book) == NULL) return 1;
    set_autore(*book, nuovo_autore);
    set_titolo(*book, nuovo_titolo);
    set_costo(*book, nuovocosto);
    
    return 0;
    
}

int get_autore(libro  book, char* autore){
    if(book == NULL) return 1;
    strcpy(autore, book ->autore);
    return 0;
}


int get_titolo(libro book, char* titolo){
    if(book == NULL) return 1;
    strcpy(titolo, book ->titolo);
    return 0;
}


int get_costo(libro book, float* nuovo_costo){
    if(book == NULL) return 1;
    *nuovo_costo = book->costo;
    return 0;
}

int set_autore(libro book, char* autore){
    if(book == NULL) return 1;
    strcpy( book ->autore,autore);
    return 0;
}


int set_titolo(libro book, char* titolo){
    if(book == NULL) return 1;
    strcpy( book ->titolo,titolo);
    return 0;
}


int set_costo(libro book, float nuovo_costo){
    if(book == NULL) return 1;
    book ->costo = nuovo_costo;
    return 0;
}

int elimina_libro(libro* book){
    if(*book== NULL) return 1;
    free(*book);
    *book = NULL;
    return 0;
}

int print_libro(libro book){
    if(book == NULL) return 1;
    else {
        char titolo[100], autore[100];
        get_titolo(book, titolo);
        get_autore(book, autore);
        printf("%s , %s , %.2f\n", titolo, autore, book->costo);
    }
    return 0;
}



