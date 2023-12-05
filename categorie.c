
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "categorie.h"



int crea_lista_categorie(nodocategorie* listacategorie){
    *listacategorie = NULL;
    return 0;

}


int crea_nodo_categoria(nodocategorie* listacategorie ,char* nome_categoria){
    nodocategorie n_c;
    n_c = (nodocategorie)malloc(sizeof(struct nodocategorie));
    if(n_c == NULL) return 1;
    int token = crea_categoria(&(n_c->c), nome_categoria);
    if(token == 1){
        free(n_c);
        return 1;
    }
    n_c -> next = *listacategorie;
    *listacategorie = n_c;
    printf("# CATEGORIA CREATA CON SUCCESSO\n\n");
    sleep(1);
    
    
    return 0;
}

categoria cerca_nodo_categoria(nodocategorie listacategorie ,char* nome_categoria){
    while ((listacategorie != NULL)){
        char categoria_corrente[100];
        get_categoria(listacategorie->c, categoria_corrente);
        if(strcmp(nome_categoria, categoria_corrente)==0){
            return listacategorie -> c;
        }
        listacategorie = listacategorie -> next;
        
    }
    return NULL;
    
}


void stampacategorie(nodocategorie listacategorie){
    
    printf("# CATEGORIE PRESENTI NEL CATALOGO:\n");
    
    while( listacategorie != NULL){
        stampa_categoria(listacategorie->c);
        listacategorie = listacategorie -> next;
       
    
    }
    
}
 
void stampa_categorie_e_libri(nodocategorie listacategorie){
    
    printf("# CATEGORIE PRESENTI NEL CATALOGO:\n");
    
    while( listacategorie != NULL){
        stampa_categoria(listacategorie->c);
        stampalibri(listacategorie->c->testa);
        listacategorie = listacategorie -> next;
       
    
    }
    
}
 
                            
void modifica_nodo_categorie(nodocategorie listacategorie, char* categoria_cercata, char* nuova_categoria ){
    categoria categoria_modificata = cerca_nodo_categoria(listacategorie, categoria_cercata);
    if(categoria_modificata==NULL) return;
    set_categoria(categoria_modificata, nuova_categoria);
    return;
}




void elimina_nodo_categorie(nodocategorie* listacategorie,char* categoria_cercata){
    nodocategorie c_corrente = *listacategorie;
    nodocategorie c_precedente = NULL;
    while(c_corrente != NULL){
        char categoria[100];
        get_categoria(c_corrente->c, categoria); 
        if(strcmp(categoria , categoria_cercata)==0){
            if(c_precedente == NULL){
                *listacategorie = c_corrente->next;
                }
            else{
                c_precedente->next = c_corrente->next; 
                }
            distruggi_categoria(&(c_corrente->c));  
            free(c_corrente);// cosi sto andando a rimuovere la memoria dell'incapsulamento
            printf("# LIBRO ELIMINATO CON SUCCESSO\n"); 
            sleep(1);
            return;
        }
        c_precedente = c_corrente;
        c_corrente= c_corrente->next;
    }
    printf("# CATEGORIA O LIBRO NON TROVATI\n \n");
    sleep(1);   
    

}


void elimina_lista_categorie(nodocategorie* listacategorie){
    while(*listacategorie != NULL){
        nodocategorie categoria_corrente = *listacategorie;
        distruggi_categoria(&(categoria_corrente->c));
        *listacategorie= (*listacategorie)-> next;
        free(categoria_corrente);
    }

}

void aggiungi_libro_a_categoria(nodocategorie* listacategorie, char* nome_categoria , char* titolo, char* autore, float costo) {
    categoria categoria_corrente = cerca_nodo_categoria(*listacategorie, nome_categoria);
    if (categoria_corrente != NULL) {
        int token = crea_nodo_libri(&(categoria_corrente->testa), titolo, autore, costo);
        if (token == 0) {
            printf("# LIBRO AGGIUNTO ALLA CATEGORIA CON SUCCESSO\n");
            sleep(1);
            return;
        } else {
            printf("# ERRORE: IMPOSSIBILE AGGIUNGERE IL LIBRO\n");
        }
    } else {
        printf("# CATEGORIA NON TROVATA\n");
    }

    sleep(1);
   
}




 





















