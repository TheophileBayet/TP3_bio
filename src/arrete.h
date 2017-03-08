#ifndef ARRETE
#define ARRETE

#include"noeuh.h"

class arrete{

private :
  noeud i;
  noeud j;

public :
//constructors
arrete();
arrete(i,j);
//destructor
~arrete();
// set the nodes
void setI(noeud i);
void setJ(noeud j);
// accessors for the nodes
int getI();
int getJ();


};
#endif
