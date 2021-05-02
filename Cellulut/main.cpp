#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    //Manipulation de la bibliothèque
    Model* model1 = new Model("model1"); //Initialisation de 3 modèles
    Model* model2 = new Model("model2");
    Model* model3 = new Model("model3");
    Library::getInstance()->add_Model(model1); //Ajout des 3 modèles à la bibliothèque
    Library::getInstance()->add_Model(model2);
    Library::getInstance()->add_Model(model3);
    try{
    Library::getInstance()->add_Model(model1); //Ajout redondant
    }
    catch(exception const& except)
    {
        cerr<<"ERREUR : "<<except.what()<<endl;
    }
    cout<<Library::getInstance()->getListModels()->size()<<endl;             //Taille de la biblio
    cout<<Library::getInstance()->getListModels()->at(2)->getName()<<endl;  //Nom du troisieme modele
    Library::getInstance()->del_Model(model1);                             //Suppression du modele 1
    cout<<Library::getInstance()->getListModels()->at(0)->getName()<<endl;//Nom du premier modele

    cout<<"\nDone"<<endl;
    //system("pause");
    return 0;
}
