#include"arrete.h"

arrete::arrete(){
  i= new noeud();
  j= new noeud();
  q=0;
  l=0;
  d=0;
}
arrete::arrete(noeud i,noeud j,int q, int l, int d){
  i=i;
  j=j;
  q=q;
  l=l;
  d=d;
}
//destructor
arrete::~arrete(){

}
// setters for the node
void arrete::setI(noeud i){
  i=i;
}
void arrete::setJ(noeud j){
  j=j;
}
void arrete::setQ(int q){
  q=q;
}
void arrete::setL(int l){
  l=l;
}
void arrete::setD(int d){
  d=d;
}
// accessors for the nodes
noeud arrete::getI(){
  return i;
}
noeud arrete::getJ(){
  return j;
}
int arrete::getQ(){
  return q;
}
int arrete::getL(){
  return l;
}
int arrete::getD(){
  return d;
}
