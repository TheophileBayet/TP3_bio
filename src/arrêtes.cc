#ifndef ARRETES
#define ARRETES

class noeud{

private :
  int num;

public :
//constructors
noeud();
noeud(int n);
//destructor
~noeud();
// set a number for a node
void setNum(int n);
// accessor for the number
int getNum(int n);

};


#endif
