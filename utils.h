#ifndef _UTILS_H
#define _UTILS_H

typedef struct Voiture Voiture;
struct Voiture
{
int id;
float s1;
float s2;
float s3;
float tempsTotal;
int p;
int boolean_out;
float best_s1;
float best_s2;
float best_s3;
float best_total;
};

Voiture Voiture1, Voiture2;

#endif
