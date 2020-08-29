const int NB_KM = 310;

//Calcule le nombre de tour d'une course
int calculNbTour(int tailleCircuit);

//Fonction qui permet de faire un sleep en millisecondes
int msleep(long tms);

//Fonction qui intervertit les 2 pointeurs en paramètre
void swap(struct Voiture *x, struct Voiture *y);

//Fonction qui trie un tableau entré en paramètre
void triVoiture(struct Voiture *voitures, int choix);

//Renvoie un entier random entre min et min + max
double randomInt(int max, int min);

//Renvoie un temps double au centième
double randomTime(int min, int max);

//Fonction qui génère un temps de section en double au millième près
double calculSection();

//Fonction qui calcule le meilleur temps entre 2 temps passés en paramètres
double meilleurTemps(double t1, double t2);

//Fonction qui permet de savoir si une voiture est allé au stand
//et si elle est y est allé, renvoie le temps qu'elle a mit pour y aller
double stand();

//Fonction qui permet de savoir si une voiture est out ou pas
//Renvoie 1 si elle est out
int out();

//Fonction qui initialise la voiture passée en paramètre
void initVarVoiture(struct Voiture *v);

//Fonction qui initialise les voitures
struct Voiture init_voiture(int i);

//Fonction qui permet de créer le fichier de résultat d'une course
void docRecap(struct MemoirePartagee *tabVoitures, int choix);
