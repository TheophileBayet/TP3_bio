Avant de tenter de compiler, assurez-vous d'avoir téléchargé la bibliothèque armadillo .

Pour faire marcher le code :
 cd ./build
 cmake .
 make
 ./exe

 Vous aurez en sortie les matrices Q_ij et D_ij à l'état stationnaire atteint ; Il y a possibilité de modifier le code ( décommenter les dernières lignes ) pour afficher la matrice A et le vecteur P.
