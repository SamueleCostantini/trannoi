#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "gamelib.h"


int main(void){
  system("clear");
  //presentazione();
  short int fine=0;
  short int n;
  short int scelta;



  //imposta_gioco ritorna un valore bool, se true l'impostazione è completa
  //e si può iniziare a giocare
  do{
    
    puts("Benvenuto in Trannoi..");
    puts("Menu': \n1. Imposta gioco \n2. Gioca \n3. Termina gioco \nDigita 1, 2 o 3 per decidere cosa fare! \nScelta: ");
    scanf("%hd", &scelta); //getchar();
    switch (scelta) {
      case 1: n=imposta_gioco();//numero_crewmate=imposta_gioco();
      break;
      case 2: fine=gioca(n);//gioca(numero_crewmate, &gioco_finito);
      break;
      case 3: {termina_gioco(); return 0;}//if(termina_gioco()==true) return 0;
      break;
      default: puts("Carattere inserito non valido, riprova!");
      break;

    }
  }while(fine!=1);


return 0;
}
