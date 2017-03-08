#ifndef LABY
#define LABY

#include"noeud.h"
#include"arrete.h"

class laby{

public :
//constructors
laby();
//destructor
~laby();
// add a node
void addNode(noeud i);
// add a link
void addLink(noeud i,noeud j,int q, int l, int d );


};
#endif
