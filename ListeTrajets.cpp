/*************************************************************************
                           ListeTrajets  -  realisation
                           ----------------------------
    début                : 2016
    copyright            : (C) 2016 par Etienne Raquin et Victor Borg
*************************************************************************/

//-- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

# include <iostream>

//------------------------------------------------------ Include personnel

# include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeTrajets::Ajouter(Trajet * trajet)
// Algorithme :
    // Créé un nouvel élement de liste de trajets avec le trajet pointé
    // Ajoute cet élément à la fin de la liste de trajets
    // Actualise le pointeur sur le dernier élément de la liste de trajets
{
    # ifdef MAP
        cout << "Appel de la méthode ListeTrajets::Ajouter" << endl;
	
        trajet->Afficher(0);
    # endif

    // Création du trajet
        
    Trajet * newTrajet;
    newTrajet = (*trajet).Clone();
    
    // Création du nouvel élement
    
    ElementTrajet * newElement;
    newElement = new ElementTrajet;
    
    newElement->trajet = newTrajet;
    newElement->suivant = NULL;
    
    // Cas de la liste de trajets vide
    
    if(debut == NULL)
    {
        delete debut;
        
        debut = newElement;
        fin = newElement;
        
        return;
    }

    // Cas général
    
    fin->suivant = newElement;
    fin = newElement;
}

Trajet * ListeTrajets::GetDebut ()
{
    # ifdef MAP
        cout << "Appel de la méthode ListeTrajets::GetDebut" << endl;
    # endif
    
    return debut->trajet;
}

Trajet * ListeTrajets::GetFin ()
{
    # ifdef MAP
        cout << "Appel de la méthode ListeTrajets::GetFin" << endl;
    # endif
    
    return fin->trajet;
}

Trajet * ListeTrajets::GetTrajet(unsigned int i)
{
    # ifdef MAP
        cout << "Appel de la méthode ListeTrajets::GetTrajet" << endl;
    # endif
    
    ElementTrajet * element;

    element = debut;

    unsigned int j = 0;
    
    while (element != NULL and j < i)
    {
        element = element->suivant;	
        
        j = j + 1;
    }
   
    if (element == NULL)
    {
        return NULL;
    }

    return (element->trajet);
}

void ListeTrajets::Afficher(int niveau)
{
    # ifdef MAP
        cout << "Appel de la méthode ListeTrajets::Afficher" << endl;
    # endif
            
    int i = 0;
        
    ElementTrajet * element;
    
    element = debut;
    
    // Parcours des éléments de la liste de trajets
    
    while(element != NULL)
    {
        for (int j = 0; j < niveau; j = j + 1)
        {
            cout << "    ";
        }
        
        // Affichage condensé du trajet de l'élément actuel
        
        cout << "Trajet " << i+1 << " : ";
        cout << element->trajet->GetDepart() << " -> ";
        cout << element->trajet->GetArrivee() << endl;
        
        // Appel de la méthode Afficher sur l'élément actuel
        // Avec un niveau de hierarchie suivant
        
        element->trajet->Afficher(niveau + 1);
        
        element = element->suivant;
        
        i = i + 1;
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

ListeTrajets::ListeTrajets()
// Algorithme : 
    // Le pointeur sur le premier élément de la liste de trajets est nul
{
    # ifdef MAP
        cout << "Appel au constructeur par defaut de <ListeTrajets>" << endl;
    # endif
  
    debut = NULL;
}

ListeTrajets::~ListeTrajets()
// Algorithme :
    // Parcours de tous les elements de la liste de trajets,
    // Pour chaque élément, suppression des pointeur de l'élément précédent
{
    # ifdef MAP
        cout << "Appel au destructeur de <ListeTrajets>" << endl; 
    # endif
        
    ElementTrajet * element;
    ElementTrajet * ancien;
    
    if (debut == NULL)
    {
        delete debut;
        
        return;
    }
    
    element = debut->suivant;
    ancien = debut;

    while (element != NULL)
    {
        delete (ancien->trajet);
        delete ancien;	

        ancien = element;
        element = element->suivant;
    }
    
    delete (ancien->trajet);
    delete ancien;
}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées
