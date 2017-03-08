#ifndef ARRETE
#define ARRETE

#include"noeud.h"

class arrete{

private :

  noeud* i;
  noeud* j;
  int q; //flux
  int l; // longueur
  int d; // conducivité

public :
//constructors
arrete();
arrete(noeud i,noeud j,int q, int l, int d);
//destructor
~arrete();
// setters for the node
void setI(noeud i);
void setJ(noeud j);
void setQ(int q);
void setL(int l);
void setD(int d);
// accessors for the nodes
noeud getI();
noeud getJ();
int getQ();
int getL();
int getD();

};
#endif
