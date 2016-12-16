/*************************************************************************
                           Trajet  -  description
                           ----------------------
    début                : 2016
    copyright            : (C) 2016 par Etienne Raquin et Victor
*************************************************************************/

//-------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

#include <iostream>

//------------------------------------------------------ Include personnel

# include "Trajet.h"

// # include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques 

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ()
// Algorithme :
    // Implémenté dans les classes TrajetSimple et TrajetCompose
{
    #ifdef MAP
        cout << "Appel au constructeur par defaut de <Trajet>" << endl;
    #endif
} //----- Fin de Trajet (constructeur par défaut)

Trajet::~Trajet ()
// Algorithme :
    // destructeur de Trajet
{
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
