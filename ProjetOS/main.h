#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <time.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdbool.h>
#include <printf.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

//Structure d'une voiture. Sera manipulée par les processus fils.
struct Voiture{
  int numero;
  int pit;
  int out;
  double best[4];
  double nbTour;;
};

//Structure de la mémoire partagée.
struct MemoirePartagee{
  struct Voiture tableauV[20];
  struct Voiture courseFinale[20];
  int nbVoituresFini;
  int nbTourAFaire;
};

// Process pour un tour
//renvoie le temps du tour
double calculTour(struct Voiture *v);

//Fonction qui gère la course Finale
void courseFinale(struct MemoirePartagee *tabVoitures, int i);

//Fonction qui gère les essais et les qualifications
void essaisEtQualifications(struct MemoirePartagee *tabVoitures, int i, double tempsTotal);

//Fonction qui permet d'afficher ce qu'il se passe
void afficheTab(struct MemoirePartagee *tabVoitures, int choix);

//Fonction qui permet de trier le tableau des voitures après chaque qualification
void triQualifications(struct MemoirePartagee *tabVoitures, int choix);

//Fonction qui gère l'affichage, les tris et la création des fichiers
void fonctionPere(struct MemoirePartagee *tabVoitures, int choix);
