#ifndef LIBRO_H
#define LIBRO_H


struct libro{
    char autore[100];
    char titolo[100];
    float costo; 
};

typedef struct libro* libro;

int crea_libro(libro* book,char* nuovo_titolo, char* nuovo_autore, float nuovocosto);

int set_autore(libro book, char* autore);

int set_titolo(libro book, char* titolo);

int set_costo(libro book, float nuovo_costo);

int get_autore(libro book, char* autore);

int get_titolo(libro book, char* titolo);

int get_costo(libro book, float* nuovo_costo);

int print_libro(libro book);

int elimina_libro(libro* book);



















#endif