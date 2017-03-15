#ifndef LABY
#define LABY

#include"noeud.h"
#include"arrete.h"

class laby{
private :
  // la matrice des longueur entre les points
  double **matrice;
  int nbNoeud;

public :
//constructors
laby();

laby(int nbNoeud);
//destructor
~laby();
// add a node
// void addNode(noeud i);
// add a link
// void addLink(noeud i,noeud j,int q, int l, int d );
// display the matrix
void display();
// return true if adresse
bool isArrete(int i,int j);
// initialise une valeur dans la matrice
void set(int i , int j , double val);
// return the value in the laby
double getValue(int i , int j);
};
#endif
