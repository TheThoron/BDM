
#include <vector>
#include <titre.h>
/* stdlib pour exit(), et stdio pour puts() */

using namespace std;

int main(void)
{
    char* chemin ="//adhome//c//cf//cfellah//Documents//BDM//Music//music//test";
    vector <char*>music;
    Titre titre;
    titre.ouvrir(chemin);
    music=titre.remplire();
    titre.fermeture();

    for_each(music.begin(), music.end(),print);


    return 0;
}
