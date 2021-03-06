/*************************************************************************
                           TrajetCompose  -  description
                           -----------------------------
    début                : 2016
    copyright            : (C) 2016 par Etienne Raquin et Victor Borg
*************************************************************************/

//- Realisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme

using namespace std;

#include <iostream>

#include <string>

#include <sstream>

//------------------------------------------------------ Include personnel

# include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

char * TrajetCompose::GetDepart()
// Algorithme :
    // Renvoie le nom de la ville de départ du premier trajet du TrajetCompose ayant appelé la méthode
{
    #ifdef MAP
        cout << "Appel de la methode TrajetCompose::GetDepart" << endl;
    #endif
    
    return listeTrajets->GetDebut()->GetDepart();
} //----- Fin de getDepart

char * TrajetCompose::GetArrivee()
// Algorithme :
    // Renvoie la ville d'arrivée du dernier trajet du TrajetCompose ayant appelé la méthode
{
    #ifdef MAP
        cout << "Appel de la methode TrajetCompose::GetArrivee" << endl;
    #endif
    
    return listeTrajets->GetFin()->GetArrivee();
}

ListeTrajets * TrajetCompose::GetListe ()
{
    #ifdef MAP
        cout << "Appel de la methode TrajetCompose::GetListe" << endl;
    #endif
    
    return listeTrajets;
}

void TrajetCompose::Afficher(int indentation)
// Algorithme :
    // Affiche tous les trajets du TrajetCompose ayant appelé la méthode
{
    #ifdef MAP
        cout << "Appel de la methode TrajetCompose::Afficher" << endl;
    #endif
    
    listeTrajets->Afficher(indentation);
}

string TrajetCompose::exporterTrajet(unsigned int numero, string aEcrire)
// Algorithme :
	// Construit la chaine de caractères correspondante au trajet à
    // écrire dans le fichier de sauvegarde
{

    #ifdef MAP
        cout << "Appel de la methode TrajetCompose::exporterTrajet" << endl;
    #endif

    stringstream ss1;
    if (numero >= 9)
    {
		numero = 1;
	}
    ss1 << numero+1;
    string numeroS = ss1.str();

    string line = "";
    
    string newAEcrire = aEcrire + numeroS + "|";

    unsigned int i = 0;

    while(listeTrajets->GetTrajet(i) != NULL)
    {
        line = line + listeTrajets->GetTrajet(i)->exporterTrajet(i, newAEcrire);
        
        i++;
    }

    return line;

}

Trajet * TrajetCompose::Clone()
{
    #ifdef MAP
        cout << "Appel de la methode TrajetCompose::Clone" << endl;
    #endif
    
    Trajet * clone;
    
    clone = new TrajetCompose(*this);
    
    return clone;
}

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose (const TrajetCompose & trajetCompose)
// Algorithme :
// Constrcuteur de copie de la classe TrajetCompose
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
    #endif
        
    listeTrajets = new ListeTrajets;
    
    int i = 0;
    
    while (trajetCompose.listeTrajets->GetTrajet(i) != NULL)
    {
        listeTrajets->Ajouter(trajetCompose.listeTrajets->GetTrajet(i));
        
        i = i + 1;
    }
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose (ListeTrajets * liste)
// Algorithme :
// Initialise un trajet composé avec en paramètre une liste de Trajets
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif

    listeTrajets = new ListeTrajets;
    
    int i = 0;
    
    while (liste->GetTrajet(i) != NULL)
    {
        listeTrajets->Ajouter(liste->GetTrajet(i));
        
        i = i + 1;
    }

} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
// Algorithme :
// Destructeur de la classe TrajetCompose
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
        
    delete listeTrajets;
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees
