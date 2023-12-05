
#ifndef CASSA_H
#define CASSA_H


typedef struct utente {
    char nome_utente[400];
    char psw[400];
    float saldo;
    struct utente* altro;
}utente;

utente* lista_utenti;


utente* crea_utente( char* nuovo_nome, float nuovo_saldo, char* nuova_psw);

void stampa_utenti(utente* lista_utenti);

void modifica_utente(utente* lista_utenti, char* utente_cercato,char* nuovo_nome, float nuovo_saldo, char* nuova_psw);

void elimina_utente(utente* lista_utenti, char* utente_da_eliminare);

void aggiorna_saldo(utente* lista_utenti, char* utente_cercato, float nuovo_saldo);

void compra_libro(utente* lista_utenti,char* utentecercato, char* libro);

void confronta_psw(utente* lista_utenti, char* nome_utente, char* psw);

void vedi_saldo(utente* lista_utenti, char* utente);

























#endif