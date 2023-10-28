#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct utente {
    char nome_utente[400];
    int saldo;
    struct utente* altro;
}utente;

utente* crea_utente( char* nuovo_nome, int nuovo_saldo){
    utente* nuovo_utente = (utente*)malloc(sizeof(utente));
    if (nuovo_utente == NULL) {
        perror("Errore nella creazione dell'utente");
        exit(EXIT_FAILURE);
    }

    strncpy(nuovo_utente-> nome_utente, nuovo_nome, sizeof(nuovo_nome));
    nuovo_utente -> saldo = nuovo_saldo;
    nuovo_utente -> altro = NULL;

    return nuovo_utente;

}


void stampa_utenti(utente* lista_utenti){
    utente* utente_corrente = lista_utenti;

    while(utente_corrente != NULL){
        printf("%s", utente_corrente->nome_utente);
        printf("%d", utente_corrente->saldo);

        utente_corrente = utente_corrente -> altro;
    }
      
}
  
int main(){
    utente* lista_utenti = NULL;
    crea_utente("alessandro romeo", 0);
    stampa_utenti(&lista_utenti);





}




