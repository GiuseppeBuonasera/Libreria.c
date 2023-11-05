
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"


nodocategorie* crea_categoria(nodocategorie** listacategoire ,char* categoria){
    nodocategorie* nuova_categoria = (nodocategorie*)malloc(sizeof(nodocategorie));
    
    if (nuova_categoria == NULL) {
     perror("Errore nella creazione della categoria");
     exit(EXIT_FAILURE);
    }
    
    strncpy(nuova_categoria->categoria, categoria, sizeof(nuova_categoria->categoria));
    nuova_categoria->testa = NULL; //iniziallizzando la nuova cetegoria 
    //il puntatore alla lista secodnaria deve puntare a null
    nuova_categoria->prossima = *listacategoire; //adesso devo aggiornare il puntatore della testa della lista
    *listacategoire = nuova_categoria;
    
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
    
    nuovo_libro->prossimo = NULL;

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
    printf("# LIBRO AGGIUNTO CON SUCCESSO\n");
    
}
 
 
 
void stampacategorie(nodocategorie* listacategorie){
    nodocategorie* categoriacorrente = listacategorie;
    printf("CATEGORIE PRESENTI NEL CATALOGO:\n");
    

    while(categoriacorrente != NULL){
        printf("%s\n", categoriacorrente -> categoria);
        categoriacorrente = categoriacorrente -> prossima;
    
    }
    
}
 

//funzione che permette di andare a visualizzare tutti i libri presenti in catalogo  
void stampalibri(nodocategorie* listacategorie ){
    nodocategorie* categoriacorrente = listacategorie;
    while (categoriacorrente != NULL){
        printf("LIBRI PRESENTI NELLA CATEGORIA %s:\n",categoriacorrente->categoria );
    
        nodolibri* libro_corrente = categoriacorrente->testa;
        while (libro_corrente != NULL){
            printf("%s, %s\n", libro_corrente->libro, libro_corrente->autore);
            libro_corrente= libro_corrente->prossimo;
            
        }
        categoriacorrente = categoriacorrente -> prossima;
    }
}
                            
void modifica_categoria(nodocategorie** listacategorie, char* categoria_cercata, char* nuova_categoria ){
    nodocategorie* categoria_corrente = *listacategorie; 
    nodocategorie* categoria_precedente = NULL;

    while( categoria_corrente != NULL){
        //creo un nuovo nodo categoria con la cat. desiderata
        if(strcmp(categoria_corrente->categoria, categoria_cercata)==0){
            nodocategorie* nuovo_nodo = crea_categoria(*&listacategorie, nuova_categoria);
            nuovo_nodo -> testa = categoria_corrente -> testa;
            nuovo_nodo -> prossima = categoria_corrente -> prossima;
            // vado a sistemare il puntatore nel caso in cui il nuvo nodo fosse in testa
            if(categoria_precedente == NULL){
                *listacategorie = nuovo_nodo;
            }else{ // senno' aggancio il puntatore precedente
                categoria_precedente->prossima = nuovo_nodo;
            }
            nuovo_nodo->prossima = categoria_corrente->prossima;
            
            free(categoria_corrente);
            return;


        }
        categoria_precedente = categoria_corrente;
        categoria_corrente = categoria_corrente->prossima;

    }

    printf("categoria non trovata");

}


void elimina_categoria(nodocategorie** listacategorie,char* categoria_cercata){
    nodocategorie* categoria_corrente = *listacategorie;
    nodocategorie* categoria_precedente = NULL;
    
    while(categoria_corrente != NULL){
        if(strcmp(categoria_corrente->categoria , categoria_cercata)==0){

            if(categoria_precedente == NULL){ //la categoria trovata quindi e' in testa
                *listacategorie = categoria_corrente->prossima;
                }
            else{
                categoria_precedente ->prossima = categoria_corrente-> prossima;
            }

            free(categoria_corrente);
            return;
        }
        categoria_precedente = categoria_corrente;
        categoria_corrente = categoria_corrente->prossima;

    }

printf("categoria non trovata");


}


void modifica_libro(nodocategorie* listacategorie ,char* libro_cercato, char* nuovo_libro, char* nuovo_autore){
    nodocategorie* categoria_corrente = listacategorie;

    while (categoria_corrente != NULL){
    
            nodolibri* libro_corrente = categoria_corrente ->testa;

            
            while(libro_corrente != NULL){
                if(strcmp(libro_corrente->libro, libro_cercato)==0){

                    strncpy(libro_corrente->autore, nuovo_autore, sizeof(nuovo_autore));
                    strncpy(libro_corrente->libro, nuovo_libro, sizeof(nuovo_libro));

                    return;
                    
                    }
                libro_corrente = libro_corrente -> prossimo;
            
            } 

            categoria_corrente = categoria_corrente -> prossima;
        }

      
    printf("categoria o libro non trovati");
}




void elimina_libro(nodocategorie* listacategorie, char* libro_da_eliminare){
    nodocategorie* categoria_corrente = listacategorie;

    while (categoria_corrente != NULL){
        
            nodolibri* librocorrente = categoria_corrente->testa;
            nodolibri* libroprecedente = NULL;
            
            while(librocorrente != NULL){
                if(strcmp(librocorrente ->libro , libro_da_eliminare)==0){
                    
                    if(libroprecedente == NULL){
                        categoria_corrente->testa = librocorrente->prossimo;
                        //aggancio il puntatore (in categoria) alla testa della lista secondaria al puntatore succesivo (prossimo)
                    }
                    else{
                        libroprecedente->prossimo  = librocorrente->prossimo; 

                    }
                free(librocorrente);
                return;
                
                }
            libroprecedente = librocorrente;
            librocorrente = librocorrente->prossimo;

            }
        
    categoria_corrente = categoria_corrente->prossima;  
    printf("#  LIBRO ELIMINATO CON SUCCESSO\n"); 

    }

    printf("categoria o libro non trovati");
   
}


 nodocategorie* cerca_categoria( nodocategorie* listacategorie, char* categoria_cercata){
    nodocategorie* categoria_corrente = listacategorie;

    while(categoria_corrente != NULL){
        if(strcmp(categoria_corrente->categoria, categoria_cercata)==0){
            return categoria_corrente;
        }
     categoria_corrente = categoria_corrente-> prossima;
    }
    return NULL;
}



 




nodolibri* cerca_libro (nodocategorie* listacategorie, char* categoria_cercata, char* libro_cercato ){
    nodocategorie* categoria_corrente = listacategorie;
    
    while(categoria_corrente != NULL){
        if(strcmp(categoria_corrente->categoria,categoria_cercata)==0){
            nodolibri* libro_corrente = categoria_corrente->testa;
            while(libro_corrente!=NULL){
                if(strcmp(libro_corrente->libro, libro_cercato)==0){
                    return libro_corrente;
                }
                libro_corrente = libro_corrente->prossimo;
            }
            
        }
        categoria_corrente = categoria_corrente->prossima; 


    }
   

}











int main(){
    nodocategorie* listacategorie = NULL;
    
    nodocategorie* ROMANZO = crea_categoria(&listacategorie, "ROMANZO");
   
    nodocategorie* CRIMINE = crea_categoria(&listacategorie,"CRIMINE");
    
    nodocategorie* HORROR = crea_categoria(&listacategorie, "HORROR");
    

    aggiungi_libro_a_categoria(ROMANZO, "HARRY POTTER" , "JK ROWLING");
    aggiungi_libro_a_categoria(CRIMINE, "IT", "ALESSANDRO ROMEO" );
    aggiungi_libro_a_categoria(HORROR, "MARCO ALOISI", "MARCO MI DA I BACETTI");
    
    
    stampacategorie(listacategorie);

    modifica_categoria(&listacategorie,"HORROR","SPAVENTOSO");
    modifica_libro(listacategorie, "HARRY POTTER", "io", "sono");
    elimina_libro(listacategorie, "IT");
    
    stampalibri(listacategorie);
    
    }
    



