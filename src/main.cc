#include"laby.h"
#include <armadillo>
#include<iostream>
using namespace arma;


void integration(laby *D, laby *Q, double const alpha, double const  g, double const pas){
  for (int i = 0 ; i<23; i++){
      for (int j = 0 ; j<23 ; j++){
        D->set(i,j,D->getValue(i,j)+(alpha*(Q->getValue(i,j))-g*D->getValue(i,j))*pas);
      }
    }
}

void update_A(laby *A, laby *D, laby *L ){
  for (int i = 0 ; i<12; i++){
      for (int j = 0 ; j<12 ; j++){
        double lij = L->getValue(i,j);
        double dij = D->getValue(i,j);
        if (i!=j){
          if(lij==0){
            A->set(i,j,0);
            A->set(j,i,0);
          }else{
          A->set(i,j,-dij/lij);
          A->set(j,i,-dij/lij);
          }
        } else {
          double somme = 0;
          for (int k =0 ;  k<23 ; k++){
            if(L->getValue(i,k)!=0){
            somme += D->getValue(i,k) / L->getValue(i,k);}
          }
          A->set(i,j,somme);
        }
      }
  }
}

int main(int argc, char **argv)
{
  bool cond = true;
  //mat Arobase = randu<mat>(4,5);
  //std::cout << Arobase.t() << std::endl;
  laby *longueur = new laby(23);
  //lab->display();

  laby *conductivite = new laby(23);
  laby *labyrinthe = new laby(23);
  laby *A = new laby(23);
  double dInit = 1;
  double Q0 = 0.01;
  vec b= zeros<vec>(23);
  vec Pi;
  double alpha = 1;
  double g = 1;
  double pas_int = 0.00001;

  //initialisation des longueurs
  longueur->set(0,2 ,7);
  longueur->set(2,0,7);
  longueur->set(2,4,16.5);
  longueur->set(4,2,16.5);
  longueur->set(2,3,1);
  longueur->set(3,2,1);
  longueur->set(3,4,14.425);
  longueur->set(4,3,14.425);
  longueur->set(3,13,7);
  longueur->set(13,3,7);
  longueur->set(4,5,1);
  longueur->set(5,4,1);
  longueur->set(5,6,3);
  longueur->set(6,5,3);
  longueur->set(6,7,15.164);
  longueur->set(7,6,15.164);
  longueur->set(6,15,12);
  longueur->set(15,6,12);
  longueur->set(15,16,3);
  longueur->set(16,15,3);
  longueur->set(15,17,1);
  longueur->set(17,15,1);
  longueur->set(17,18,0.5);
  longueur->set(18,17,0.5);
  longueur->set(17,19,1);
  longueur->set(19,17,1);
  longueur->set(19,20,0.5);
  longueur->set(20,19,0.5);
  longueur->set(19,21,4);
  longueur->set(21,19,4);
  longueur->set(5,8,1.5);
  longueur->set(8,5,1.5);
  longueur->set(8,9,14.5);
  longueur->set(9,8,14.5);
  longueur->set(9,10,1.5);
  longueur->set(10,9,1.5);
  longueur->set(10,7,1.5);
  longueur->set(7,10,1.5);
  longueur->set(8,11,4);
  longueur->set(11,8,4);
  longueur->set(9,22,3);
  longueur->set(22,9,3);
  longueur->set(10,12,1);
  longueur->set(12,10,1);
  longueur->set(7,14,1.5);
  longueur->set(14,7,1.5);
  longueur->set(1,14,3);
  longueur->set(14,1,3);

/*
  // affichage des longueurs
  std::cout << "Les longueurs sont :" << std::endl;
  longueur->display();*/

  // initialisation de la conductivité
  conductivite->set(0,2 ,dInit);
  conductivite->set(2,0,dInit);
  conductivite->set(2,4,dInit);
  conductivite->set(4,2,dInit);
  conductivite->set(2,3,dInit);
  conductivite->set(3,2,dInit);
  conductivite->set(3,4,dInit);
  conductivite->set(4,3,dInit);
  conductivite->set(3,13,dInit);
  conductivite->set(13,3,dInit);
  conductivite->set(4,5,dInit);
  conductivite->set(5,4,dInit);
  conductivite->set(5,6,dInit);
  conductivite->set(6,5,dInit);
  conductivite->set(6,7,dInit);
  conductivite->set(7,6,dInit);
  conductivite->set(6,15,dInit);
  conductivite->set(15,6,dInit);
  conductivite->set(15,16,dInit);
  conductivite->set(16,15,dInit);
  conductivite->set(15,17,dInit);
  conductivite->set(17,15,dInit);
  conductivite->set(17,18,dInit);
  conductivite->set(18,17,dInit);
  conductivite->set(17,19,dInit);
  conductivite->set(19,17,dInit);
  conductivite->set(19,20,dInit);
  conductivite->set(20,19,dInit);
  conductivite->set(19,21,dInit);
  conductivite->set(21,19,dInit);
  conductivite->set(5,8,dInit);
  conductivite->set(8,5,dInit);
  conductivite->set(8,9,dInit);
  conductivite->set(9,8,dInit);
  conductivite->set(9,10,dInit);
  conductivite->set(10,9,dInit);
  conductivite->set(10,7,dInit);
  conductivite->set(7,10,dInit);
  conductivite->set(8,11,dInit);
  conductivite->set(11,8,dInit);
  conductivite->set(9,22,dInit);
  conductivite->set(22,9,dInit);
  conductivite->set(10,12,dInit);
  conductivite->set(12,10,dInit);
  conductivite->set(7,14,dInit);
  conductivite->set(14,7,dInit);
  conductivite->set(1,14,dInit);
  conductivite->set(14,1,dInit);

/*
  // affichage de la conductivite
    std::cout << "La conductivite est :" << std::endl;
  conductivite->display();
*/
  // initialisation du labyrinthe
  for (int i =0 ; i< 23; i++){
      for (int j =0; j<23; j++){
        if (longueur->getValue(i,j)==0){
          labyrinthe->set(i,j,0);
        } else {
          labyrinthe->set(i,j,conductivite->getValue(i,j)/longueur->getValue(i,j));
        }
      }
  }

/*
  // affichage du labyrinthe
  std::cout << "Le labyrinthe est :" << std::endl;
  labyrinthe->display();*/

  // initialisation de b
  b(0)=Q0;
  b(1)=0;
  /*
  for (int i =2; i<23; i++){
    b[i]=0;
  }*/

  //affichage de b
  std::cout << "Le vecteur b est : [" ;
  for (int i =0 ; i<23; i++){
    std::cout << b[i]<<"|" ;
  }
  std::cout << " ]" << std::endl;

  //initialisation de A
  for (int i = 0 ; i<23; i++){
      for (int j = 0 ; j<23 ; j++){
        if(i==1){// On est sur p2, la sortie
          if(j!=1){A->set(i,j,0);}else{A->set(i,j,1);}
        }else{
        if (i!=j){
          A->set(i,j,-labyrinthe->getValue(i,j));
        } else {
          double somme = 0;
          for (int k =0 ;  k<23 ; k++){
            somme += labyrinthe->getValue(i,k);
          }
          A->set(i,j,somme);
        }
      }
    }
  }


  // affichage de A
  std::cout << "La matrcie A est :" << std::endl;
  A->display();
  std::cout << " Rang de A : " << rank(A->getMat())<<std::endl;
/*
// TEST DU SOLVE DE ARMADILLO
  mat test_A(3,3,fill::eye);
  vec test_b(3);
  test_b.fill(1);
  std::cout << " mat b " << test_b.t()<< std::endl;
  vec test_sol = solve(test_A,test_b);
  std::cout << "TEST DU SOLVE : TEST SIMPLE " << std::endl;
  std::cout<< "matrice A : " <<std::endl<< test_A.t()<<std::endl;
  std::cout<< "matrice b : " <<std::endl<< test_b.t()<<std::endl;
  std::cout<<"matrice solv : " << test_sol.t()<<std::endl;*/

  int count=0;
  while(cond){
    Pi=solve(A->getMat(),b);
    // Calcul des Qij selon les pij :
      for (int i = 0 ; i<23; i++){
        for (int j = 0 ; j<23 ; j++){
          if (longueur->getValue(i,j)==0){
            labyrinthe->set(i,j,0);
          } else {
            labyrinthe->set(i,j,(conductivite->getValue(i,j)/longueur->getValue(i,j))*(Pi[i]-Pi[j]));
          }
        }
      }
    //  quelques pas d'intégration suivant (3)
    mat D = conductivite->getMat();
    mat copie = mat(D);
    integration(conductivite,labyrinthe,alpha,g,pas_int);
    copie = copie - conductivite->getMat();
    //std::cout<<"copie : " << copie.t()<<std::endl;
    if(approx_equal(copie,conductivite->getMat(),"absdiff",0)){
      std::cout<<" condition à false"<<std::endl;
      cond=false;
    }
    count++;
    //Mettre A à jour :
    update_A(A,conductivite,longueur);
   if(count==20000) cond = false;
  }
std::cout<<count<<std::endl;
std::cout<< "matrice A : " <<std::endl<< A->getMat().t()<<std::endl;
std::cout<< "matrice Q : " <<std::endl<< labyrinthe->getMat().t()<<std::endl;
std::cout<< "matrice P : " <<std::endl<< Pi.t()<<std::endl;
return 0;
}
