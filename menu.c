//File dove gestisco il menu dell'applicazione posso entrare sia come admin che come utenete
//da admin è possibile andare ad aggiungere, rimuovere libri, gestire la cassa, mentre come untente è possibile 
//vedere quali libri sono disponibili 
#include <stdio.h>
#include <stdlib.h>
#include "catalogo.h"
#include "menu.h"
#include "cassa.h"
#include <stdbool.h>
#include <unistd.h> 

void menu_principale(void){
    int i;
    system("clear");
    
    printf("//////////////////////////////////////////////////////////////\n");
    printf("# BENVENUTO NELL' APPLICAZIONE DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#                COME DESISDERI ACCEDERE:\n");
    printf(" 1)UTENTE\n 2)ADMIN\n 3)ESCI\n");
    scanf("%d", &i);
    switch (i){
    case 1:
        menu_utente();
        break;
    
    case 2:
        menu_admin();
        break;
    default:
        exit(0);

    }
    
}    

    
void menu_admin(void){
    int a;
    int i;
    char categoria[400];
    
    system("clear");
    
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) AGGIUNGI UN LIBRO\n 2) AGGIUNGI CATEGORIA\n 3) RIMUOVI UN LIBRO\n 4) RIMUOVI CATEGORIA\n 5) MODIFICA LIBRO\n 6) MODIFICA CATEGORIA\n 7) VEDI TUTTI I LIBRI E LE CATEGORIE PRESENTI\n 8) GESTISCI LA CASSA\n 9) TORNA INDIETRO\n");        
    scanf("\n%d", &i);
    switch (i){
    case 1:
        menu_admin_aggiunta_libro();
        break;
    case 2:
        
        system("clear");
        printf("/////////////////////////////////////////////////////\n");
        printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
        printf("#    SELEZIONA LA CATEGORIA CHE VUOI AGGIUNGERE:   ");
        scanf("\n%s", categoria);
        crea_categoria(&listacategorie, categoria);
        menu_admin();
        break;
    case 3:   
        menu_admin_rimozione_libro();
        break;
    case 4:
        
        system("clear");
        printf("/////////////////////////////////////////////////////\n");
        printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
        printf("#    SELEZIONA LA CATEGORIA CHE VUOI RIMUOVERE:   ");
        scanf("\n%s", categoria);
        elimina_categoria(&listacategorie, categoria);
        menu_admin();
        break;
    case 5:
        menu_admin_modifica_libro();
        break;
    case 6:
        menu_admin_modifica_categoria();
        break;
    case 7:
        stampalibri(listacategorie);
        printf("\n \n \n#  PREMI 0 PER TORNARE INDIETRO");
        scanf("\n%d",&a);
        if(a == 0){
            menu_admin();
        }
        
        break;
    case 8:
        menu_cassa_admin();
        break;
    default:
        menu_principale();
        break;
    }
}


void menu_admin_aggiunta_libro(void){
    char autore[400];
    char libro[400];
    char categoria[400];
    float costo;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#  SELEZIONA LA CATEGORIA ALLA QUALE VUOI AGGIUNGERE IL LIBRO\n");
    scanf("\n%s", categoria);
    printf("# SELEZIONA IL TITOLO DEL LIBRO\n");
    scanf("\n%s", libro);
    printf("# SELEZIONA L'AUTORE DEL LIBRO\n");
    scanf("\n%s", autore);
    printf("# SELEZIONA IL COSTO DEL LIBRO\n");
    scanf("\n%f", &costo);
    aggiungi_libro_a_categoria(listacategorie,categoria, libro, autore, costo);
    menu_admin();
}


void menu_admin_rimozione_libro(void){
  
    char libro[400];
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#           QUALE LIBRO DESIDERI RIMUOVERE?  \n");
    scanf("\n%s", libro);
    elimina_libro(listacategorie, libro);
    menu_admin();
}


void menu_admin_modifica_libro(void){
    char autore[400];
    char vecchio[400];
    char libro[400];
    float costo;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#           QUALE LIBRO DESIDERI MODIFICARE?  \n");
    scanf("\n%s", vecchio);
    printf("#           AGGIUNGI IL NUOVO TITOLO  \n");
    scanf("\n%s", libro);
    printf("#           AGGIUNGI IL NUOVO AUTORE");
    scanf("\n%s", autore);
    printf("#           AGGIUNGI IL NUOVO COSSTO");
    scanf("\n%f", &costo);
    modifica_libro(listacategorie, vecchio, libro, autore, costo);
    menu_admin();
}


void menu_admin_modifica_categoria(void){ 
    char categoria_cercata[400];
    char categoria2[400];

    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENU ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#    SELEZIONA LA CATEGORIA CHE VUOI MODIFICARE:   ");
    scanf("\n%s", categoria_cercata);
    printf("#    SELEZIONA iL NUOVO NOME:   ");
    scanf("\n%s", categoria2);
    modifica_categoria(&listacategorie,categoria_cercata, categoria2 ); 
    menu_admin(); 
}


void menu_utente(void){
  
    int i;
    int a;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#     MENU UTENTE  DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) VEDI I LIBRI PRESENTI NEL CATALOGO \n 2) COMPRA UN LIBRO\n 3) TORNA INDIETRO\n"); 
    scanf("\n%d", &i);
    switch (i){
    case 1:
        stampalibri(listacategorie);
        printf("\n \n \n#  PREMI 0 PER TORNARE INDIETRO");
        scanf("\n%d",&a);
        if(a == 0){
            menu_utente();
        }
        
        break;
    case 2: 
        menu_cassa_utente();
        break;
    default:
        menu_principale();
        break;
    }
}

void menu_cassa_admin(void){
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENU DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#               ADMIN: CASSA\n");
    printf("#    QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) VISUALIZZA TUTT LE VENDITE DI OGGI \n 2) VISUALIZZA IL SALDO TOTALE\n 3) ESCI\n");

 
}

void menu_cassa_utente(void){
   char utente[400];
   char libro[400];
   char psw[400];
   float saldo;
   int i;
   system("clear");
   sleep(2);
   printf("/////////////////////////////////////////////////////\n");
   printf("#      MENU DELLA LIBRERIA 'PIAZZA DUOMO'\n");
   printf("#            MENÙ UTENTE: CASSA\n");
   printf("#    QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
   printf(" 1) COMPRA UN LIBRO \n 2) VISUALIZZA IL SALDO PERSONALE\n 3) AGGIUNGI SALDO\n 4) ESCI\n");
   scanf("\n%d", &i);
   switch(i){
   case 1:
       printf("SELEZIONA IL LIBRO CHE DESIDERI ACQUISTARE");
       scanf("\n%s", libro);
       printf("SELEZIONA IL TUO NOME UTENTE ");
       scanf("\n%s", utente);
       printf("SELEZIONA LA PASSWORD: ");
       scanf("\n%s", psw);
       confronta_psw(lista_utenti, utente, psw);
       compra_libro(lista_utenti, utente, libro);
    break;
    case 2:
       printf("SELEZIONA IL TUO NOME UTENTE ");
       scanf("\n%s", utente);
       vedi_saldo(lista_utenti, utente);
    
    case 3:
       printf("SELEZIONA IL TUO NOME UTENTE ");
       scanf("\n%s", utente);
       printf("SELEZIONA IL SADO CHE VUOI AGGIUNGERE ");
       scanf("\n%f", &saldo);
       aggiorna_saldo(lista_utenti, utente, saldo);
       menu_cassa_utente();
    break;
    
    default:
        menu_utente();
    break;
    }


}

int main(){
    
   


    
    nodocategorie* ROMANZO = crea_categoria(&listacategorie, "ROMANZO");
   
    nodocategorie* CRIMINE = crea_categoria(&listacategorie,"CRIMINE");
    
    nodocategorie* HORROR = crea_categoria(&listacategorie, "HORROR");
    

    aggiungi_libro_a_categoria(listacategorie,"ROMANZO", "HARRY POTTER" , "JK ROWLING", 50);
    aggiungi_libro_a_categoria(listacategorie,"CRIMINE", "IT", "ALESSANDRO ROMEO", 50);
    aggiungi_libro_a_categoria(listacategorie,"HORROR", "MARCO ALOISI", "MARCO MI DA I BACETTI", 50);
    
    

    modifica_categoria(&listacategorie,"HORROR","SPAVENTOSO");
    modifica_libro(listacategorie, "HARRY POTTER", "io", "sono", 50);
    elimina_libro(listacategorie, "IT");
    
  
    menu_principale();
    
}    

    
    
    
        

    
    
    

    
    
    


                       