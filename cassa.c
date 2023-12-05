#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "cassa.h"
#include "menu.h"
#include <stdbool.h>
#include <unistd.h> 


float fondo_cassa = 100;

utente* crea_utente( char* nuovo_nome, float nuovo_saldo, char* nuova_psw){
    utente* nuovo_utente = (utente*)malloc(sizeof(utente));
    if (nuovo_utente == NULL) {
        printf("Errore nella creazione dell'utente");
        return NULL;
    }

    strncpy(nuovo_utente-> nome_utente, nuovo_nome, sizeof(nuovo_nome));
    strncpy(nuovo_utente-> psw,nuova_psw, sizeof(nuova_psw));
    nuovo_utente -> saldo = nuovo_saldo;

   
    nuovo_utente -> altro = lista_utenti;
    lista_utenti = nuovo_utente;

    return nuovo_utente;               
}


void stampa_utenti(utente* lista_utenti){
    utente* utente_corrente = lista_utenti;

    while(utente_corrente != NULL){
        printf("%s  ", utente_corrente->nome_utente);
        printf("%f  ", utente_corrente->saldo);
        printf("%s  ", utente_corrente->psw);


        utente_corrente = utente_corrente -> altro;
    }
      
}
  

void modifica_utente(utente* lista_utenti, char* utente_cercato,char* nuovo_nome, float nuovo_saldo, char* nuova_psw){
    utente* utente_corrente = lista_utenti;

    while(utente_corrente != NULL){
        if(strcmp(utente_corrente -> nome_utente,utente_cercato)==0){
            strncpy(utente_corrente->nome_utente,nuovo_nome, sizeof(nuovo_nome));
            strncpy(utente_corrente->psw,nuova_psw, sizeof(nuovo_nome));
            utente_corrente -> saldo = nuovo_saldo;
        }

        utente_corrente = utente_corrente -> altro;
    }


}


void elimina_utente(utente* lista_utenti, char* utente_da_eliminare){
    utente* utente_corrente = lista_utenti;
    utente* utente_precedente = NULL;

    while(utente_corrente != NULL){
        if(strcmp(utente_corrente -> nome_utente , utente_da_eliminare)== 0){

            if(utente_precedente == NULL){
                lista_utenti = utente_corrente -> altro;
            }
            else{
                utente_precedente->altro = utente_corrente->altro;
            }

            free(utente_corrente);
            return;
        }
        utente_precedente = utente_corrente;
        utente_corrente = utente_corrente -> altro;
        
    }
    printf("# CATEGORIA NON TROVATA");
    sleep(1);
    menu_admin();

    
}

void aggiorna_saldo(utente* lista_utenti, char* utente_cercato, float nuovo_saldo){
    utente* utente_corrente = lista_utenti;
    
    while(utente_corrente != NULL){
        if(strcmp(utente_corrente -> nome_utente , utente_cercato)== 0){
            utente_corrente ->saldo +=  nuovo_saldo;
            
            return;
        }
        utente_corrente = utente_corrente ->altro;
    }
    printf("# NOME UTENTE NON TROVATO");
    sleep(1);
    
}




void compra_libro(utente* lista_utenti,char* utentecercato, char* libro){
    nodolibri* librocorrente;
    librocorrente = cerca_libro(listacategorie, libro);
    float saldo = librocorrente ->costo;
    aggiorna_saldo(lista_utenti,utentecercato,saldo);
    fondo_cassa = fondo_cassa + saldo;
}


void confronta_psw(utente* lista_utenti, char* nome_utente,char* psw){
    utente* utente_corrente = lista_utenti;
    
    while(utente_corrente != NULL){
        if(strcmp(utente_corrente -> nome_utente , nome_utente)== 0){
            if(strcmp(utente_corrente -> psw , psw)== 0){
                return;
            }
            
            
        }
        utente_corrente = utente_corrente ->altro;
    }

    printf("# PSW ERRATA");
    sleep(1);
    menu_cassa_utente();
    
}





void vedi_saldo(utente* lista_utenti, char* no_utente){
    utente* utente_corrente = lista_utenti;
    float saldo;
    while(utente_corrente != NULL){
        if(strcmp(utente_corrente -> nome_utente , no_utente)== 0){
           saldo = utente_corrente -> saldo;
           printf("# ECCO IL TUO SALDO CORRENTE: %f ", saldo);
           
           menu_cassa_utente();
            
            
        }
        utente_corrente = utente_corrente ->altro;
    }

    printf("# NOME UTENTE NON TROVATO");
    sleep(1);
    menu_cassa_utente();
}






















