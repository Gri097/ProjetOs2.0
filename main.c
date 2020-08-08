#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <time.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdbool.h>
#include <printf.h>

//typedef struct Voiture Voiture;
struct Voiture{
int id;
int numero;
double s1;
double s2;
double s3;
double tour;
int pit;
bool out;
double best_s1;
double best_s2;
double best_s3;
double best_tour;
};

//Renvoie un entier random entre min et min + max
double randomInt(int max, int min){
    srand(clock());
    return (rand() % max) + min;
}

//Renvoie un temps double au centième
double randomTime(int min, int max){
    srand(clock());
    double pEntiere = randomInt(min, max);
    double pDecimale = randomInt(999, 0);
    pDecimale /= 1000;
    return pEntiere + pDecimale;
}

double calculSection(){
  return randomTime(15, 35);
}

double meilleurTemps(double t1, double t2)
{
  double meilleur;
  if (t1 < t2) {
    meilleur = t1;
  }
  else{
    meilleur = t2;
  }
  return meilleur;
}

double stand(){
  double tempsAdditionnel = 0.0;
  if (randomInt(1000,0) >= 998) {
    tempsAdditionnel = randomTime(10, 10);
  }
  return tempsAdditionnel;
}

bool out(){
  bool resultat = false;
  if (randomInt(10000,0) >= 9997) {
    resultat = true;
  }
  return resultat;
}

int calculP1(struct Voiture *v){
  clock();
  double tempsTotal = 54000; //Ce temps est le temps en seconde de essai 1 (1H30)
  double tempsEnCours = 0, tempsPit;
  v->best_s1 = 51;
  v->best_s2 = 51;
  v->best_s3 = 51;
  v->best_tour = 151;
  //Boucle course
  while (tempsEnCours < tempsTotal) {
    if (out()) {
      v->out = true;
      break;
    }
    else{
      v->s1 = calculSection();
      v->s2 = calculSection();
      v->s3 = calculSection();
      tempsPit = stand();
      if (tempsPit > 0) {
        v->pit += 1;
      }
      v->tour = v->s1 + v->s2 + v->s3 + tempsPit;
      v->best_s1 = meilleurTemps(v->best_s1, v->s1);
      v->best_s2 = meilleurTemps(v->best_s2, v->s2);
      v->best_s3 = meilleurTemps(v->best_s3, v->s3);
      v->best_tour = meilleurTemps(v->best_tour, v->tour);
    }
    tempsEnCours += v->tour;
  }
  return 0;
}

int boolean(bool b){
    int i = 0;
    if(b){
       i = 1;
    }
    return i;
}

int main(int argc, char *argv[]){
  struct Voiture *voitures;

  int shmid = shmget(1009, sizeof(voitures) * 20, IPC_CREAT | 0666);
  voitures = shmat(shmid, NULL, 0);

  int numVoitures[20] = {7,99,5,16,8,20,4,55,10,26,44,77,11,18,23,33,3,27,6,85};

  for(int i = 0; i < 20; i++){
    voitures[i].id = i;
    voitures[i].numero = numVoitures[i];
    calculP1(&voitures[i]);
  }


  printf("_______________________________________________________________________\n");
  printf("|                     Simulation Grand Prix de F1                     |\n");
  printf("|_____________________________________________________________________|\n");
  printf("| Voiture | Section 1 | Section 2 | Section 3 |Temps Total| Pit | Out |\n");
  printf("|---------|-----------|-----------|-----------|-----------|-----|-----|\n");
  for(int i = 0; i < 20; i++){
    printf("|   %d    |   %.3f\"  |  %.3f\"  |  %.3f\" |   %.3f\"  |  %d  |  %d  |\n", voitures[i].numero, voitures[i].best_s1 , voitures[i].best_s2, voitures[i].best_s3, voitures[i].best_tour, voitures[i].pit, boolean(voitures[i].out));
    printf("|---------|-----------|-----------|-----------|-----------|-----|-----|\n");
  }
}
