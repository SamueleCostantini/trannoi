#include <stdio.h>
#define N 10
enum Stato_giocatore{astronauta, impostore, assassinato, espulso=3};
enum Nome_giocatore{rosso, blu, nero, viola, verde, marrone, bianco, celeste, grigio, arancione=9};
enum Tipo_stanza{vuota, quest_semplice, quest_complicata, botola=3};
struct Giocatore{
  struct Stanza* stanza_attuale;
  enum Stato_giocatore statoGiocatore;
  enum Nome_giocatore nomeGiocatore;
  int voti; //attributo aggiunto per gestire la votazione per l'espulsione di un player

} Player;

struct Stanza{
  struct Stanza* destra;
  struct Stanza* sinistra;
  struct Stanza* avanti;
  struct Stanza* precedente;

  enum Tipo_stanza tipoStanza;

  int emergenza_chiamata;

} Room;


struct Giocatore array_giocatori[N];
struct Stanza* stanza_iniziale;




int controllo_morti;
int quest_totali;
int lim_quest;
short int imp_max; //impostori totali
char enter;
int array_numeri[10];
void termina_gioco();
 void invio_per_continuare();
 void stampaTipoStanza(int);
 void stampaStatoGiocatore(int);
 void stampaNome(int);
//void presentazione();
 int assegna_tipo_stanza(int);
 void delay_n_msec(int);
 void muoviti();
short int imposta_gioco();
 void stampa_giocatori(int, int);
 void inizia_gioco();
int gioca(short int);
   void avanza(int, int);
     void avanza_avanti(int, int);
     void avanza_destra(int, int);
     void avanza_sinistra(int, int);
 void fai_quest(int);
 short int chiamata_emergenza(int, int);
 void uccidi(int, int);
 void usa_botola(int, int, struct Stanza*);
 void sabota();
