#ifndef NOEUD
#define NOEUD

class noeud{

private :
  int num;
  int p;

public :
//constructors
noeud();
noeud(int n,int p);
//destructor
~noeud();
// set a number for a node
void setNum(int n);
// accessor for the number
int getNum();
// set a pression for the node
void setP(int p);
// get the node's presssion
int getP();
};
#endif
