#include"noeud.h"





noeud::noeud(){
  num = 0;
  p=0;
}
noeud::noeud(int n,int p){
  num = n;
  this->p=p;
}
//destructor
noeud::~noeud(){

}
// set a number for a node
void noeud::setNum(int n){
  num=n;
}
// accessor for the number
int noeud::getNum(){
  return num;
}
// set a pression for the node
void noeud::setP(int p){
  p=p;
}
// get the node's presssion
int noeud::getP(){
  return p;
}
