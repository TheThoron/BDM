#ifndef TITRE_H
#define TITRE_H
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <dirent.h>     /* Pour l'utilisation des dossiers */

#ifndef WIN32
    #include <sys/types.h>
#endif
using namespace std;



class Titre
{
private:
    vector <char*> music_;  //contient les titres
    DIR* repertoire_;


public :
void ouvrir(char* chemin);

vector <char*> remplire();

void fermeture();



};

void print(char* t);


#endif // TITRE_H
