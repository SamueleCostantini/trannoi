#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "gamelib.h"


  void stampaTipoStanza(int i){
    switch (i) {
      case 0: printf("%s", "vuota"); break;
      case 1: printf("%s", "quest semplice"); break;
      case 2: printf("%s", "quest complicata"); break;
      case 3: printf("%s", "botola"); break;
      default: puts("error");
    }
  }
  void stampaStatoGiocatore(int i){
    switch (i) {
      case 0: printf("%s", "astronauta"); break;
      case 1: printf("%s", "impostore"); break;
      case 2: printf("%s", "assassinato"); break;
      case 3: printf("%s", "espulso"); break;
      default: puts("error");
    }
  }
void stampaNome(int i){
  switch (i) {
    case 0: printf("%s", "ROSSO"); break;
    case 1: printf("%s", "BLU"); break;
    case 2: printf("%s", "NERO"); break;
    case 3: printf("%s", "VIOLA"); break;
    case 4: printf("%s", "VERDE"); break;
    case 5: printf("%s", "MARRONE"); break;
    case 6: printf("%s", "BIANCO"); break;
    case 7: printf("%s", "CELESTE"); break;
    case 8: printf("%s", "GRIGIO"); break;
    case 9: printf("%s", "ARANCIONE"); break;
    default: puts("error");
  }
}
void delay_n_msec(int n){
  int msec = 1, trigger = n;
  clock_t before = clock();
  int iterations=0;
  do{
    clock_t difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    iterations++;
  }while ( msec < trigger );

}


short int imposta_gioco(){
  short int n=0;

  do{
  puts("Quanti partecipanti? (da 4 a 10)");
  scanf("%hd", &n); getchar();

  if(n<4 || n>10) puts("Scegli tra 4 e 10 partecipanti!");
}while(n<4 || n>10);
do{
puts("Quante quest totali? (da 10 a 20)");
scanf("%d", &quest_totali); getchar();
if(quest_totali<10 || quest_totali>20) puts("Scegli tra 10 e 20 quest!");
}while(quest_totali<10 || quest_totali>20);
lim_quest=quest_totali; //ne ho bisogno per capire se sono state eseguite quest
  return n;
}
//
// inizio ad implementare gioca
//
int gioca(short int n){

  if(n==0){puts("imposta il gioco prima di giocare");return 2;}


  stanza_iniziale = (struct Stanza*)malloc(sizeof(struct Stanza));

  stanza_iniziale->tipoStanza = vuota;

  stanza_iniziale->emergenza_chiamata=0;

  stanza_iniziale->destra = NULL;
  stanza_iniziale->sinistra = NULL;
  stanza_iniziale->avanti = NULL;
  stanza_iniziale->precedente = NULL;






  time_t t;
  int max; //numero massimo impostori
  if(n<6) max=1;
  if(n<9) max=2;
  else max=3;
  short int fine=0;
  short int
  imp_max=max;

  //creazione stanza iniziale
  int i, j;
  for(i=0; i<10; i++){
    array_numeri[i]=rand()%10;
          for(j=0;j<i;j++) {
         if(array_numeri[i]==array_numeri[j]) {
                i--;
                break;
  }
}
}
  srand((unsigned)time(&t));
    short int app=20; //variabili di appoggio
    short int app2=0;
    for(int i=0; i<n; i++){
      array_giocatori[i].statoGiocatore=astronauta;
    }

    for(int c=0; c<max; c++){
      app=rand()%n;
      while(app==app2){
        app=rand()%n;
      }
      array_giocatori[app].statoGiocatore=impostore;
      app2=app;
    }

    printf("Ci sono %hd impostori tra voi... \nAttendi...\n", imp_max);

    invio_per_continuare();
    for(int k=0; k<n; k++){

      array_giocatori[k].nomeGiocatore=array_numeri[k];
      array_giocatori[k].stanza_attuale=stanza_iniziale;
      array_giocatori[k].voti=0;
      //stampaNome(array_giocatori[k].nomeGiocatore); printf("%s", " - " ); printf(" %d\n", k);

      //stampaStatoGiocatore(array_giocatori[k].statoGiocatore); printf("%s", "\n" );
    }

    while(fine!=1){

    int i=0;


    if(imp_max<=0){
      system("clear");
      puts("Non è rimasto nessun impostore, gli astronauti hanno vinto!");
      termina_gioco();
      fine=1;

      return 1;
    }
    while(i<n){
      if(quest_totali<=0) {
        system("clear");
        puts("Quest terminate, gli astronauti hanno vinto!");
        termina_gioco();
        fine=1;
        return 1;
      }

      int contr=0;
      for(int i=0; i<n; i++){
        if(array_giocatori[i].statoGiocatore==astronauta) contr=1;
      }
      if(contr==0){
        puts("Tutti gli astronauti sono stati uccisi, hanno vinto gli impostori!");
        termina_gioco();
        fine=1;
        return 1;
      }
      if(imp_max==0) {fine=1; continue;}

      int scelta=0;
      delay_n_msec(2000);
      system("clear"); //da rimettere
      //codice se il giocatore i risulta morto, non può fare scelta quindi passa il turno

      printf("Quest rimanenti: %d \n", quest_totali);
      for(int i=0; i<quest_totali; i++){
        printf("||");
      }
      printf("\n\n");

      printf("%s", "Turno del: " ); stampaNome(array_giocatori[i].nomeGiocatore); printf("%s",". Premere invio per cominciare.. " );invio_per_continuare();

      //controllo che stato ha il giocatore
      //se assassinato

      if(array_giocatori[i].statoGiocatore==assassinato){stampaNome(array_giocatori[i].nomeGiocatore);
        printf("%s"," sei stato assassinato. \n");
        i++;
        continue; }
      //se espulso
      else if(array_giocatori[i].statoGiocatore==espulso){stampaNome(array_giocatori[i].nomeGiocatore);
        printf("%s"," sei stato espulso. \n");
        i++;
        continue;
       }
      //stampa dei vari menu personalizzati per ogni tipo di giocatore e stanza
      //stampa caratteristiche stanza


      stampa_giocatori(i, n);

      printf("%s","Tipo stanza: " ); stampaTipoStanza(array_giocatori[i].stanza_attuale->tipoStanza);
      //chiamate di emergenza rimasta
      printf("%s","\nChiamate di emergenza rimaste: ");
      if(array_giocatori[i].stanza_attuale->emergenza_chiamata==1) printf("%s","0\n");
      else printf("%s", "1\n");

      //stampa del testo comune tra tutti i giocatori in gioco

      printf("\n%s", "Giocatore ");stampaNome(array_giocatori[i].nomeGiocatore); printf("%s", " sei un " ); stampaStatoGiocatore(array_giocatori[i].statoGiocatore);

      //controllo se astronauta e se la stanza è di tipo quest

      if(array_giocatori[i].statoGiocatore==astronauta && (array_giocatori[i].stanza_attuale->tipoStanza==quest_semplice || array_giocatori[i].stanza_attuale->tipoStanza==quest_complicata)){

      puts("\n1. Muoviti \n2. Fai quest \n3. Chiamata di emergenza \n4. Non fare niente\n");

      do{
        scanf("\n%d",  &scelta); getchar();
        if(scelta!=1  && scelta!=2 && scelta!=3 && scelta!=4) puts("Scelta non valida, riprova: ");
      }while(scelta!=1  && scelta!=2 && scelta!=3 && scelta!=4);

      switch (scelta) {

        case 1: avanza(i, n); break;
        case 2: fai_quest(i); break;
        case 3: chiamata_emergenza(i, n); break;

        case 4:
        {
        i++;
        puts("Premi invio per passare il turno");
        invio_per_continuare();
        puts("Cancellazione schermo");
        delay_n_msec(800); system("clear");
        continue;
        } break;
        default: break;
      }
      }

      //controllo se astronauta e se la stanza è di tipo botola o vuota, in entrambi i casi un astronauta ha lo stesso menu

      else if(array_giocatori[i].statoGiocatore==astronauta && (array_giocatori[i].stanza_attuale->tipoStanza==botola || array_giocatori[i].stanza_attuale->tipoStanza==vuota)){

      puts("\n1. Muoviti \n2. Chiamata di emergenza \n3. Non fare niente\n");

      do{
        scanf("\n%d",  &scelta); getchar();
        if(scelta!=1  && scelta!=2 && scelta!=3 ) puts("Scelta non valida, riprova: ");
      }while(scelta!=1  && scelta!=2 && scelta!=3);

      switch (scelta) {

        case 1: avanza(i, n); break;
        case 2: chiamata_emergenza(i, n); break;

        case 3:
        {
        i++;
        puts("Premi invio per passare il turno");
        invio_per_continuare();
        puts("Cancellazione schermo");
        delay_n_msec(800); system("clear");
        continue;
        } break;
        default: break;
      }
      }

      //controllo se impostore e se la stanza non è botola

      else if(array_giocatori[i].statoGiocatore==impostore){
        if(array_giocatori[i].stanza_attuale->tipoStanza!=botola){


        puts("\n1. Muoviti \n2. Uccidi \n3. Sabota \n4. Chiamata di emergenza \n5. Non fare niente \n");

        do{
          scanf("\n%d",  &scelta); getchar();
          if(scelta!=1 && scelta!=8 && scelta!=2 && scelta!=3 && scelta!=4 && scelta!=5) puts("Scelta non valida, riprova: ");
        }while(scelta!=1 && scelta!=2 && scelta!=3 && scelta!=4 && scelta!=5);

        switch (scelta) {

          case 1: avanza(i, n);break;
          case 2: uccidi(i, n);break;
          case 3: sabota();break;
          case 4: chiamata_emergenza(i, n);break;
          case 5: {i++; puts("Premi invio per passare il turno");
          invio_per_continuare();
          puts("Cancellazione schermo");
          delay_n_msec(800); system("clear");
          continue;} break;
          default: break;
        }

    }
    else if(array_giocatori[i].stanza_attuale->tipoStanza==botola){ //da modificare quando si sviluppa la gestione delle stanzaimposta_gioco

    puts("\n1. Muoviti \n2. Uccidi \n3. Sabota \n4. Chiamata di emergenza \n5. Usa botola \n6. Non fare niente");

    do{
      scanf("\n%d",  &scelta); getchar();
      if( scelta!=1 && scelta!=2 && scelta!=3 && scelta!=4 && scelta!=5 && scelta!=6) puts("Scelta non valida, riprova: ");
    }while(scelta!=1 && scelta!=2 && scelta!=3 && scelta!=4 && scelta!=5 && scelta!=6 );

    switch (scelta) {

      case 1: avanza(i, n); break;
      case 2: uccidi(i, n); break;
      case 3: sabota(); break;
      case 4: chiamata_emergenza(i, n);break;

      case 5: usa_botola(i, n, stanza_iniziale); break;
      case 6:
      {
        i++;
        puts("Premi invio per passare il turno");
        invio_per_continuare();
        puts("Cancellazione schermo");
        delay_n_msec(800); system("clear");
        continue;
      } break;
      default: puts("error"); break;
    }

}
  }

  i++;
  puts("Premi invio per passare il turno");
  invio_per_continuare();
  puts("Cancellazione schermo");

  delay_n_msec(800); system("clear");
  continue;
}

}

  return 0;}
//
// inizio ad implementare la funzione avanza
//
void avanza_avanti(int i, int n){
  if(array_giocatori[i].stanza_attuale->avanti==NULL){
    struct Stanza* stanza = (struct Stanza*)malloc(sizeof(struct Stanza));


    stanza->destra=NULL;
    stanza->sinistra=NULL;
    stanza->avanti=NULL;

    stanza->precedente=array_giocatori[i].stanza_attuale;
    stanza->tipoStanza=assegna_tipo_stanza(rand()%100);
    stanza->emergenza_chiamata=0;

    array_giocatori[i].stanza_attuale->avanti=stanza;

  }
  if(array_giocatori[i].stanza_attuale->avanti!=NULL){
    array_giocatori[i].stanza_attuale=array_giocatori[i].stanza_attuale->avanti;

    puts("Ti sei spostato avanti!");
      printf("%s","Tipo stanza: "); stampaTipoStanza(array_giocatori[i].stanza_attuale->tipoStanza);printf("%s","\n" );
    delay_n_msec(1000);
    stampa_giocatori(i,n);

  }
}
void avanza_destra(int i, int n){
  if(array_giocatori[i].stanza_attuale->destra==NULL){
    struct Stanza* stanza = (struct Stanza*)malloc(sizeof(struct Stanza));

    stanza->destra=NULL;
    stanza->sinistra=NULL;
    stanza->avanti=NULL;

    stanza->precedente=array_giocatori[i].stanza_attuale;
    stanza->tipoStanza=assegna_tipo_stanza(rand()%100);
    stanza->emergenza_chiamata=0;
    array_giocatori[i].stanza_attuale->destra=stanza;

  }
  if(array_giocatori[i].stanza_attuale->destra!=NULL){
    array_giocatori[i].stanza_attuale=array_giocatori[i].stanza_attuale->destra;

  puts("Ti sei spostato a destra!");
    printf("%s","Tipo stanza: "); stampaTipoStanza(array_giocatori[i].stanza_attuale->tipoStanza);printf("%s","\n" );
    delay_n_msec(800);
    stampa_giocatori(i,n);
  }
}
void avanza_sinistra(int i, int n){
  if(array_giocatori[i].stanza_attuale->sinistra==NULL){
    struct Stanza* stanza = (struct Stanza*)malloc(sizeof(struct Stanza));

    stanza->destra=NULL;
    stanza->sinistra=NULL;
    stanza->avanti=NULL;

    stanza->precedente=array_giocatori[i].stanza_attuale;
    stanza->tipoStanza=assegna_tipo_stanza(rand()%100);
    stanza->emergenza_chiamata=0;
    array_giocatori[i].stanza_attuale->sinistra=stanza;


  }
  if(array_giocatori[i].stanza_attuale->sinistra!=NULL){
    array_giocatori[i].stanza_attuale=array_giocatori[i].stanza_attuale->sinistra;

    puts("Ti sei spostato a sinistra!");
    printf("%s","Tipo stanza: "); stampaTipoStanza(array_giocatori[i].stanza_attuale->tipoStanza); printf("%s","\n" );
    delay_n_msec(1000);
    stampa_giocatori(i,n);

  }

}
void avanza(int i, int n){
  int scelta=0;
  puts("Dove ti vuoi muovere: \n 1. Avanti \n 2. Destra \n 3. Sinistra \n 4.Torna al menu' \n Scelta: "); //torna al menu da fare, non sara inserito per ora
  do{
  scanf("\n%d", &scelta); getchar();
}while(scelta!=1 && scelta!=8 && scelta!=2 && scelta!=3 && scelta!=4);
switch (scelta) {
  case 1: avanza_avanti(i, n); break;
  case 2: avanza_destra(i, n); break;
  case 3: avanza_sinistra(i, n); break;
  case 4: break;
  default: puts("bug");
}

}
void stampa_giocatori(int k, int n){
  int contr=0;
  puts("I giocatori nella tua stanza sono: ");
  for(int i=0; i<n; i++){
  if(array_giocatori[i].statoGiocatore==espulso){
    continue;
  }
  else if(array_giocatori[i].nomeGiocatore==array_giocatori[k].nomeGiocatore){
    continue;
  }
  else if(array_giocatori[k].stanza_attuale==array_giocatori[i].stanza_attuale) {
    printf(" - ");
    if(array_giocatori[i].statoGiocatore==assassinato){ printf("%s","Cadavere di " );} else{printf("%s"," ");}
    stampaNome(array_giocatori[i].nomeGiocatore); printf("%s", "\n" );
    contr=1;
  }
}
if(contr==0) puts("nessuno");
}

void uccidi(int k, int n){


  puts("Nella tua stanza ci sono: ");
  int c=0;
  int contr=0;
  for(int i=0; i<n; i++){
  if(array_giocatori[k].stanza_attuale==array_giocatori[i].stanza_attuale && array_giocatori[i].statoGiocatore==0 && array_giocatori[i].nomeGiocatore!=array_giocatori[k].nomeGiocatore) {

    printf("%d. ", array_giocatori[i].nomeGiocatore);stampaNome(array_giocatori[i].nomeGiocatore); printf("%s", "\n" );
    contr=1;
    c++;
  }
}
if(contr==0) {
  puts("Non puoi uccidere nessuno, la tua stanza è vuota");
  return;
}
int scelta2;
int controllo=0;
  do{

    printf("%s","Chi vuoi uccidere?");
    scanf("%d", &scelta2);
    for(int i=0; i<n; i++){

    if(array_giocatori[k].stanza_attuale==array_giocatori[i].stanza_attuale && array_giocatori[i].nomeGiocatore==scelta2 && array_giocatori[i].statoGiocatore!=1){
    array_giocatori[i].statoGiocatore=2;
    printf("%s ", "Hai ucciso il giocatore: "); stampaNome(scelta2);printf("%s", "\n" );printf("%s", "\n" );

    controllo=1;

    }

  }
  if(controllo==0){puts("Scelta errata, inserisci un numero valido!");}
}while(controllo==0);
}
short int chiamata_emergenza(int k, int n){

if(array_giocatori[k].stanza_attuale->emergenza_chiamata==1){puts("Chiamata di emergenza gia effettuata in questa stanza!");return 0;}
array_giocatori[k].stanza_attuale->emergenza_chiamata=1;
system("clear");
printf("Ci sono ancora %hd impostori. \n", imp_max);
for(int i=0; i<n; i++){
  if(array_giocatori[i].statoGiocatore==assassinato){
    printf("- "); stampaNome(array_giocatori[i].nomeGiocatore); printf(" - Morto\n");
  }
  if(array_giocatori[i].statoGiocatore==espulso){
    printf("- "); stampaNome(array_giocatori[i].nomeGiocatore); printf(" - Espulso\n");
  }
  if(array_giocatori[i].statoGiocatore==astronauta || array_giocatori[i].statoGiocatore==impostore){
  printf("- "); stampaNome(array_giocatori[i].nomeGiocatore); printf("\n");
}
}
printf("\n%s", "Il giocatore " ); stampaNome(array_giocatori[k].nomeGiocatore); printf("%s\n", " ha effettuato una chiamata di emergenza!" );
puts("Discutete e una volta presa una decisione premere invio e votate! \n");
invio_per_continuare();



for(int i=0; i<n; i++){
  system("clear");
  if(array_giocatori[i].statoGiocatore!=2 && array_giocatori[i].statoGiocatore!=3){
    printf("%s", "\n"); stampaNome(array_giocatori[i].nomeGiocatore); printf("%s"," chi vuoi espellere? Scrivi il numero corrispondente al giocatore che vuoi votare: \n" );
    for(int c=0; c<n; c++){
      if(array_giocatori[c].statoGiocatore!=2 && array_giocatori[c].statoGiocatore!=3){
        printf("%d. ", array_giocatori[c].nomeGiocatore); stampaNome(array_giocatori[c].nomeGiocatore); printf("%s", "\n");
      }

    }
    int scelta2;
    int controllo=0;
      do{

        scanf("%d", &scelta2);
        for(int i=0; i<n; i++){

        if(array_giocatori[i].statoGiocatore==0 || array_giocatori[i].statoGiocatore==1){
          controllo=1;
        }

      }

      if(controllo==0){puts("Scelta errata, inserisci un numero valido! ");}
      printf("%s ", "Hai votato il giocatore: "); stampaNome(scelta2);printf("%s", "\n" );printf("%s", "\n" );
    }while(controllo==0);

    for(int i=0; i<n; i++){
      if(array_giocatori[i].nomeGiocatore==scelta2) {  array_giocatori[i].voti++;}
    }


  }
}
int max2=-1;
int id_appoggio;
for(int o=0; o<n; o++){
  printf("Voti: %d per ",array_giocatori[o].voti); stampaNome(array_giocatori[o].nomeGiocatore); printf("%s", "\n" );
  if(array_giocatori[o].voti>max2){max2=array_giocatori[o].voti; id_appoggio=o;}
}
delay_n_msec(1000);
system("clear");
int imp=0;

if(array_giocatori[id_appoggio].statoGiocatore==impostore){ imp=1; }
if(array_giocatori[id_appoggio].statoGiocatore==astronauta){ imp=0; }

array_giocatori[id_appoggio].statoGiocatore=espulso;

printf("%s"," E' stato espulso: " ); stampaNome(array_giocatori[id_appoggio].nomeGiocatore); printf(" ed era un ");
if(imp==0){
  printf(" astronauta. \n");}
else{
printf(" impostore. \n");
imp_max--;
}
for(int i=0; i<n; i++){
  array_giocatori[i].voti=0;
}
invio_per_continuare();
return 1;
}
void fai_quest(int i){

  if(array_giocatori[i].stanza_attuale->tipoStanza==quest_semplice) {puts("Hai eseguito una quest semplice");
  quest_totali--;
 }
  if(array_giocatori[i].stanza_attuale->tipoStanza==quest_complicata) { puts("Hai eseguito una quest complicata");
  quest_totali=quest_totali-2;
}
array_giocatori[i].stanza_attuale->tipoStanza=vuota;
    printf("Quest rimanenti %d\n",  quest_totali);
}
void sabota(){
  if(quest_totali==lim_quest) puts("Non è stata eseguita alcuna quest, non puoi sabotare!");
  else {quest_totali++;
    puts("Hai sabotato una quest");
  }
}
//struct Stanza array_botole[n_botole];
//int n_botole=0;
void usa_botola(int k, int n, struct Stanza* inizio){


  //!!! algoritmo non permette di entrare in stanze tipo botola senza personaggi perchè l'aggancio alle stanze avviene tramite personaggio !!!

  int controll=0;
  puts("Cercando una stanza con botola...");
  for(int i=0; i<n; i++){
    if(array_giocatori[i].stanza_attuale->tipoStanza==botola && array_giocatori[k].stanza_attuale!=array_giocatori[i].stanza_attuale){
      if(rand()%10<5){ array_giocatori[k].stanza_attuale=array_giocatori[i].stanza_attuale;}
      controll=1;
    }

    if(controll==0){
      array_giocatori[k].stanza_attuale=array_giocatori[rand()%n].stanza_attuale;

    }

  }
  printf("Ti sei spostato nella stanza botola con: \n");
  stampa_giocatori(k, n);
  }


int assegna_tipo_stanza(int n){

  if(n<=30) return 0;
  if(n>30 && n<=60) return 1;
  if(n>60 && n<=75) return 2;
  else { return 3;}
}
void invio_per_continuare(){
char enter = 0;
while ( enter != '\r' && enter != '\n') { enter = getchar(); }
}
void termina_gioco(){
  free(stanza_iniziale);
  free(stanza_iniziale->destra);
  free(stanza_iniziale->sinistra);
  free(stanza_iniziale->avanti);
  free(stanza_iniziale->precedente);
}
