#include"laby.h"

int main(int argc, char **argv)
{
  laby *longueur = new laby(23);
  //lab->display();
  laby *conductivite = new laby(23);
  laby *labyrinthe = new laby(23);

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

  longueur->display();
return 0;
}
