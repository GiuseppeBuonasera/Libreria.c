//File dove gestisco il menu dell'applicazione posso entrare sia come admin che come utenete
//da admin è possibile andare ad aggiungere, rimuovere libri, gestire la cassa, mentre come untente è possibile 
//vedere quali libri sono disponibili 
#include <stdio.h>
#include <stdlib.h>

void menu(){
    system("clear");
    printf("//////////////////////////////////////////////////////////////\n");
    printf("# BENVENUTO NELL' APPLICAZIONE DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#                COME DESISDERI ACCEDERE:\n");
    printf(" 1)ADMIN\n 2)UTENTE\n 3)ESCI\n");
    
}    

    
void menu_admin(){
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENÙ ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) AGGIUNGI UN LIBRO\n 2) RIMUOVI UN LIBRO\n 3) MODIFICA LIBRO\n 4) VEDI TUTTI I LIBRI PRESENTI\n 5) GESTISCI LA CASSA\n 6) ESCI\n");        
}

void menu_admin_aggiunta_libro(){
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENÙ ADMIN DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf("#                        ");
}

void menu_utente(){
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#     MENÙ UTENTE  DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#       QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) VEDI I LIBRI PRESENTI NEL CATALOGO \n 2) COMPRA UN LIBRO\n 3) ESCI\n"); 
}

void menu_cassa_admin(){
    system("clear");
    printf("/////////////////////////////////////////////////////\n");
    printf("#      MENÙ  DELLA LIBRERIA 'PIAZZA DUOMO'\n");
    printf("#           MENÙ ADMIN: CASSA\n");
    printf("#    QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
    printf(" 1) VISUALIZZA LE VENDITE DI OGGI \n 2) VISUALIZZA IL SALDO TOTALE\n 3) ESCI\n");
 
}

void menu_cassa_utente(){
   system("clear");
   printf("/////////////////////////////////////////////////////\n");
   printf("#      MENÙ  DELLA LIBRERIA 'PIAZZA DUOMO'\n");
   printf("#            MENÙ UTENTE: CASSA\n");
   printf("#    QUALE OPERAZIONE DESISDERI EFFETTUARE?\n");
   printf(" 1) SCEGLI IL LIBRO DA COMPRARE \n 2) VISUALIZZA IL SALDO PERSONALE\n 3) AGGIUNGI SALDO\n 4) ESCI\n");
 


}

int main(){
    int num;
    menu();
    scanf("%d",&num);
    switch(num){
        
        case 1:
        menu_admin();
        scanf("%d",&num);
        switch(num){
            case 4:
            menu_cassa_admin();
            break;
    
        }
        break;

    
        case 2:
        menu_utente();
        scanf("%d",&num);
        switch(num){
            case 2:
            menu_cassa_utente();
            break;
            }
        break;


        case 3:
        exit;
        break;
    }
}     

    
    
    
        

    
    
    

    
    
    


                       