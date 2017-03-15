#include"laby.h"
#include<stdlib.h>
#include<iostream>

laby::laby(){
  matrice = NULL;
  nbNoeud = 0;
}

laby::laby(int nbN){
  matrice = new double*[nbN];
  for (int i = 0; i<nbN; i++){
      matrice[i]=new double[nbN];
  }
  nbNoeud = nbN;
}

laby::~laby(){
  for (int i = 0;i<nbNoeud;i++){
      delete [] matrice[i];
  }
  delete [] matrice;
}

/*
void laby::addLink(noeud i, noeud j, int q, int l, int d){
  if ((!(i.getNum()<nbNoeud)) || (!(j.getNum()<nbNoeud) || (i.getNum()<0) || (j.getNum()<0))){
  std::cout << "Les noeuds demandés ne sont pas corrects." << std::endl;
  }
  if (matrice == NULL){
    std::cout << "Problème, la matrice est nulle." << std::endl;
  }
     matrice[i.getNum()][j.getNum()] = arrete(i,j,q,l,d) ;
}
*/

void laby::display(){
  std::cout << "Le nombre de noeud du labyrinthe est de : " <<nbNoeud << "."<< std::endl;
  std::cout << "AFFICHAGE DE LA MATRICE" << std::endl;
  for (int i =0 ; i<nbNoeud; i++){
    std::cout << "[";
    for ( int j =0; j<nbNoeud; j++){
      std::cout<<matrice[i][j]<<'|';
    }
    std::cout << "]" << std::endl;
  }
}

bool laby::isArrete(int i , int j){
  double cour = matrice[i][j];
  return (cour!=0);
}

void laby::set(int i, int j, double val){
  if (!((i<nbNoeud) && (i>=0) && (j>=0) &&(j<nbNoeud))){
    std::cout << "Les indices dans la matrice ne correspondent pas." << std::endl;
  } else {
      matrice[i][j]=val;
    }
}
