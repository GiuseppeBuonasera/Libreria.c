//File dove gestisco il menu dell'applicazione posso entrare sia come admin che come utenete
//da admin è possibile andare ad aggiungere, rimuovere libri, gestire la cassa, mentre come untente è possibile 
//vedere quali libri sono disponibili 
#include <stdio.h>
#include <stdlib.h>
#include "catalogo.h"

nodocategorie *listacategorie = NULL;

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
    int i;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENÙ ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) AGGIUNGI UN LIBRO\n 2) RIMUOVI UN LIBRO\n 3) MODIFICA LIBRO\n 4) VEDI TUTTI I LIBRI PRESENTI\n 5) GESTISCI LA CASSA\n 6) TORNA INDIETRO\n");        
    scanf("%d", &i);
    switch (i){
    case 1:
        menu_admin_aggiunta_libro();
        break;
    case 2:
        menu_admin_rimozione_libro();
    case 3:
        menu_admin_modifica_libro();
        break;
    case 4:
        stampalibri(listacategorie);
    
    case 5:
        menu_cassa();
    default:
        menu_principale();
    }
}


void menu_admin_aggiunta_libro(void){
    char categoria;
    char libro;
    char autore;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENÙ ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#  SELEZIONA LA CATEGORIA ALLA QUALE VUOI AGGIUNGERE IL LIBRO\n");
    scanf("%c", &categoria);
    printf("# SELEZIONA IL TITOLO DEL LIBRO");
    scanf("%c", &libro);
    printf("# SELEZIONA L'AUTORE DEL LIBRO");
    scanf("%c", &autore);
    aggiungi_libro_a_categoria(categoria, libro,  autore);
    menu_admin();
}


void menu_admin_rimozione_libro(void){
    char libro_cercato;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENÙ ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#           QUALE LIBRO DESIDERI RIMUOVERE?  \n");
    scanf("%c", &libro_cercato);
    elimina_libro(listacategorie, libro_cercato);
    menu_admin();
}


void menu_admin_modifica_libro(void){
    char libro_cercato;
    char nuovo_libro;
    char nuovo_autore;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENÙ ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#           QUALE LIBRO DESIDERI MODIFICARE?  \n");
    scanf("%c", &libro_cercato);
    printf("#           AGGIUNGI IL NUOVO TITOLO  \n");
    scanf("%c", &nuovo_libro);
    printf("#           AGGIUNGI IL NUOVO AUTORE");
    scanf("%c", &nuovo_autore);
    modifica_libro(listacategorie, libro_cercato, nuovo_libro, nuovo_autore);
    menu_admin();
}


void menu_utente(void){
    int i;
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#     MENÙ UTENTE  DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) VEDI I LIBRI PRESENTI NEL CATALOGO \n 2) COMPRA UN LIBRO\n 3) ESCI\n"); 
    scanf("%c", &i);
    switch (i){
    case 1:
        stampalibri(listacategorie);
    case 2: 
          
  


        break;
    
    default:
        break;
    }

}

void menu_cassa_admin(void){
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENÙ  DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#           MENÙ ADMIN: CASSA\n");
    printf("#    QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) VISUALIZZA LE VENDITE DI OGGI \n 2) VISUALIZZA IL SALDO TOTALE\n 3) ESCI\n");
 
}

void menu_cassa_utente(void){
   system("clear");
   printf("/////////////////////////////////////////////////////\n");
   printf("#      MENÙ  DELLA LIBRERIA 'PIAZZA DUOMO'\n");
   printf("#            MENÙ UTENTE: CASSA\n");
   printf("#    QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
   printf(" 1) SCEGLI IL LIBRO DA COMPRARE \n 2) VISUALIZZA IL SALDO PERSONALE\n 3) AGGIUNGI SALDO\n 4) ESCI\n");
 


}

int main(){
}    

    
    
    
        

    
    
    

    
    
    


                       
