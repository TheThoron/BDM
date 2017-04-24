#include <titre.h>


void Titre::ouvrir(char* chemin)
{
    repertoire_ = opendir(chemin);    ///* Ouverture d'un dossier */
    if (repertoire_ == NULL)          /// Si le dossier n'a pas pu être ouvert */
        perror("");
}



vector<char *> Titre::remplire()
{
    struct dirent* fichier=NULL;      ///contient le nom des fichiers

    while ((fichier=readdir(repertoire_))!= NULL)
    {
        music_.push_back(fichier->d_name);
    }

    return music_;
}



void Titre::fermeture()
{
    if (closedir(repertoire_) == -1)      ///en cas de fermeture incorrect
        exit(-1);
}


void print(char* t)
{
    std::cout<<t<<std::endl;
}
