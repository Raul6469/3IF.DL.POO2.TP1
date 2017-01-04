/*************************************************************************
                           TrajetSimple  -  description
                           ----------------------------
    début                : 2016
    copyright            : (C) 2016 par Etienne Raquin et Victor Borg
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

#include <iostream>

#include <string>

//------------------------------------------------------ Include personnel

# include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

char * TrajetSimple::GetDepart()
// Algorithme :
	// Renvoie le nom de la ville de départ du trajet simple
{
    #ifdef MAP
        cout << "Appel de la methode TrajetSimple::GetDepart" << endl;
    #endif
    
    return depart;
} //----- Fin de Méthode

char * TrajetSimple::GetArrivee()
// Algorithme :
	// Renvoie le nom de la ville d'arrivée du trajet simple
{
    #ifdef MAP
        cout << "Appel de la methode TrajetSimple::GetArrivee" << endl;
    #endif
    
    return arrivee;
} //----- Fin de Méthode

ListeTrajets * TrajetSimple::GetListe ()
{
    #ifdef MAP
        cout << "Appel de la methode TrajetSimple::GetListe" << endl;
    #endif
    
    return NULL;
}

void TrajetSimple::Afficher(int indentation)
// Algorithme :
	// Affiche la ville de départ et d'arrivée du TrajetSimple ayant appelé la méthode
{
    #ifdef MAP
        cout << "Appel de la methode TrajetSimple::Afficher" << endl;
    #endif
    
    for (int j = 0; j < indentation; j = j + 1)
    {
        cout << "    ";
    }
    
    //cout << depart << " -> " << arrivee << endl;
    
    cout << "Départ : " << depart << endl;
    
    for (int j = 0; j < indentation; j = j + 1)
    {
        cout << "    ";
    }
    
    cout << "Arrivée : " << arrivee << endl;
    
    for (int j = 0; j < indentation; j = j + 1)
    {
        cout << "    ";
    }
    
    cout << "Transport : " << transport << "\r\n";
}

Trajet * TrajetSimple::Clone()
{
    #ifdef MAP
        cout << "Appel de la methode TrajetSimple::Clone" << endl;
    #endif
    
    Trajet * clone;
    
    clone = new TrajetSimple(*this);
    
    return clone;
}

string TrajetSimple::exporterTrajet(unsigned int numero)
// Algorithme :
	// Construit la chaine de caractères correspondante au trajet à
    // écrire dans le fichier de sauvegarde
{

    #ifdef MAP
        cout << "Appel de la methode TrajetSimple::exporterTrajet" << endl;
    #endif

    string line = "";

    string DepartS = string(depart);
    string ArriveeS = string(arrivee);
    string TransportS = string(transport);

    line = "0:" + DepartS + "|" + ArriveeS + "|" + TransportS + "|" + "\r\n";

    return line;

}

//-------------------------------------------- Constructeurs - destructeur

void affecter (char * chaine1, char * chaine2);

TrajetSimple::TrajetSimple (char* dep, char* ar, char* trans)
// Algorithme :
	// Constructeur de TrajetSimple
// Prend en paramètre les noms des villes de départ et d'arrivée, ainsi que le nom
	// du mode de transport utlisé
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif

    depart = new char[10];
    
    arrivee = new char[10];
    
    transport = new char[10];
    
    affecter (depart, dep);
    affecter (arrivee, ar);
    affecter (transport, trans);
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple (TrajetSimple & trajetSimple)
// Algorithme :
	// Constructeur de copie de TrajetSimple
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif
    
    depart = new char[10];
    
    arrivee = new char[10];
    
    transport = new char[10];
    
    affecter (depart, trajetSimple.depart);
    affecter (arrivee, trajetSimple.arrivee);
    affecter (transport, trajetSimple.transport);
} // Fin du constructeur de copie de TrajetSimple

TrajetSimple::~TrajetSimple ( )
// Algorithme :
	// Destrcucteur de la classe TrajetSimple
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif

    delete[] depart;
    delete[] arrivee;
    delete[] transport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées