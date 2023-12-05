#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> 
#include "categorie.h"
#include "categoria.h"
#include "menu.h"




void menu_principale(void){
    int i;
    
    system("clear");
    printf("//////////////////////////////////////////////////////////////\n");
    printf("# BENVENUTO NELL' APPLICAZIONE DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#                A QUALE MENU VUOI ACCEDERE:\n");
    printf(" 1) GESTIONE CATEGORIE\n 2) GESTIONE LIBRI\n 3)ESCI\n");
    scanf("%d", &i);
    switch (i){
    case 1:
        menu_admin_gestione_categorie();
        break;
    
    case 2:
        menu_admin_gestione_libri();
        break;
    default:
        exit(0);

    }
    
}   




void menu_admin_gestione_categorie(void){
    int i;
    char categoria2[100];
    char categorie[100];
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENU GESTIONE CATEGORIE DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) AGGIUNGI CATEGORIA\n 2) RIMUOVI CATEGORIA\n 3) MODIFICA CATEGORIA\n 4) VEDI TUTTE LE CATEGORIE PRESENTI\n 5) CERCA CATEGORIA\n 6) TORNA INDIETRO\n");
    scanf("%d", &i);
    switch (i){
        case 1:
            system("clear");
            printf("/////////////////////////////////////////////////////\n");
            printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
            printf("#    SELEZIONA LA CATEGORIA CHE VUOI AGGIUNGERE:   ");
            scanf("\n%s", categorie);
            crea_nodo_categoria(&listacategorie, categorie);
            menu_admin_gestione_categorie();
            break;
        case 2:
            system("clear");
            printf("/////////////////////////////////////////////////////\n");
            printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
            printf("#    SELEZIONA LA CATEGORIA CHE VUOI RIMUOVERE:   ");
            scanf("\n%s", categorie);
            elimina_nodo_categorie(&listacategorie, categorie);
            menu_admin_gestione_categorie();
            break;
        case 3:
            system("clear");
            printf("/////////////////////////////////////////////////////\n");
            printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
            printf("#    SELEZIONA LA CATEGORIA CHE VUOI MODIFICARE:   ");
            scanf("\n%s", categorie);
            printf("#    SELEZIONA iL NUOVO NOME:   ");
            scanf("\n%s", categoria2);
            modifica_nodo_categorie(listacategorie,categorie, categoria2 ); 
            menu_admin_gestione_categorie(); 
            break;
        case 4:
            stampacategorie(listacategorie);
            printf("\n \n \n#  PREMI 0 PER TORNARE INDIETRO");
            scanf("\n%d",&i);
            if(i == 0){
                menu_admin_gestione_categorie();
            }
            break;
        case 5:
            system("clear");
            printf("/////////////////////////////////////////////////////\n");
            printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
            printf("#           QUALE CATEGORIA DESIDERI CERCARE?  \n");
            scanf("\n%s", categorie);
            cerca_nodo_categoria(listacategorie, categorie);
            break;
        default:
            menu_principale();
            break;

    }
}


void menu_admin_gestione_libri(void){
    int i;
    char vecchio[100];
    char categoria2[100];
    char categorie[100];
    char titoli[100];
    char autori[100];
    float costi;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENU GESTIONE DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) AGGIUNGI UN LIBRO\n 2) RIMUOVI UN LIBRO\n 3) MODIFICA LIBRO\n 4) VEDI TUTTI I LIBRI E LE CATEGORIE PRESENTI\n 5)CERCA LIBRO\n 6) TORNA INDIETRO\n");        
    scanf("\n%d", &i);
    switch (i){
        case 1:
            system("clear");
            printf("/////////////////////////////////////////////////////\n");
            printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
            printf("#  SELEZIONA LA CATEGORIA ALLA QUALE VUOI AGGIUNGERE IL LIBRO\n");
            scanf("\n%s", categorie);
            printf("# SELEZIONA IL TITOLO DEL LIBRO\n");
            scanf("\n%s", titoli);
            printf("# SELEZIONA L'AUTORE DEL LIBRO\n");
            scanf("\n%s", autori);
            printf("# SELEZIONA IL COSTO DEL LIBRO\n");
            scanf("\n%f", &costi);
            aggiungi_libro_a_categoria(&listacategorie, categorie, titoli, autori, costi);
            menu_admin_gestione_libri();
            break;
        case 2:
            system("clear");
            printf("/////////////////////////////////////////////////////\n");
            printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
            printf("#           QUALE LIBRO DESIDERI RIMUOVERE?  \n");
            scanf("\n%s", libri);
            elimina_nodo_libro(&lista_libri, libri);
            menu_admin_gestione_libri();
            break;
        case 3:
            system("clear");
            printf("/////////////////////////////////////////////////////\n");
            printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
            printf("#           QUALE LIBRO DESIDERI MODIFICARE?  \n");
            scanf("\n%s", vecchio);
            printf("#           AGGIUNGI IL NUOVO TITOLO  \n");
            scanf("\n%s", libri);
            printf("#           AGGIUNGI IL NUOVO AUTORE");
            scanf("\n%s", autori);
            printf("#           AGGIUNGI IL NUOVO COSSTO");
            scanf("\n%f", &costi);
            modifica_libro(lista_libri, vecchio, libri, autori, costi);
            menu_admin_gestione_libri();
            break;
        case 4:
            stampa_categorie_e_libri(listacategorie);
            printf("\n \n \n#  PREMI 0 PER TORNARE INDIETRO");
            scanf("\n%d",&i);
            if(i == 0){
                menu_admin_gestione_libri();
            }
            break;
        case 5: 
            system("clear");
            printf("/////////////////////////////////////////////////////\n");
            printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
            printf("#           QUALE LIBRO DESIDERI CERCARE?  \n");
            scanf("\n%s", libri);
            cerca_libro(lista_libri, libri);
            break;
        default:
            menu_principale();
            break;
            }
}



int main(){
    nodocategorie listacategorie;
    crea_lista_categorie(&listacategorie);
    crea_nodo_categoria(&listacategorie, "ROMANZO");
 
    menu_principale();

}