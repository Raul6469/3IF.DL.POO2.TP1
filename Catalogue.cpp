/*************************************************************************
                            Catalogue  -  realisation
                            -------------------------
    début                : 2016
    copyright            : (C) 2016 par Etienne Raquin et Victor Borg
*************************************************************************/

//----- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

# include <iostream>

# include <stdio.h>

# include <stdlib.h>

//------------------------------------------------------ Include personnel

# include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void affecter (char * chaine1, char * chaine2)
// Mode d'emploi :
    // Paramètres : 2 chaines de caratères
    // Action : Rend chaine1 identique à chaine 2
// Contrat :
    // Cohérence : Chaines de caractères valides
    // Performance : Chaines de caractères valides
{
    int i = 0;
    
    while (chaine2[i] != '\0')
    {
        chaine1[i] = chaine2[i];
        
        i = i + 1;
    }
    
    chaine1[i] = chaine2[i];
}

bool equals (char * chaine1, char * chaine2);
// Mode d'emploi :
    // Paramètres : Deux pointeur sur char
    // Action : Teste l'égalité entre les deux chaines
// Contrat :
    // Cohérence : Chaines valides

bool dejaVisite (char * ville, int nbVisites, char * villesVisitees[])
// Mode d'emploi :
    // Paramètres ; Ville a teser, nombre de villes visitées, tableau des villes visitées
    // Action : Teste si la ville a déjà été visité par la méthode Rechercher
// Contrat :
    // Cohérence : Chaines valides
{
    for (int i = 0; i < nbVisites; i = i + 1)
    {
        if ( equals (ville, villesVisitees[i]))
        {
            return true;
        }
    }
    
    return false;
}

void Catalogue::Ajouter (Trajet * trajet)
{
    # ifdef MAP
        cout << "Appel de la methode Catalogue::Ajouter" << endl;
    # endif
    
    listeTrajets.Ajouter (trajet);
}

void Catalogue::Afficher ()
{
    # ifdef MAP
        cout << "Appel de la methode Catalogue::Afficher" << endl;
    # endif
        
    listeTrajets.Afficher ();
}

ListeTrajets * Catalogue::GetListe ()
{
    # ifdef MAP
        cout << "Appel de la methode Catalogue::GetListe" << endl;
    # endif
    
    return &listeTrajets;
}

void Catalogue::Rechercher (ListeTrajets * listeResultats, char * depart, 
                            char * arrivee, int * nbVisites, char * villesVisitees[])
// Algorithme : Récursivité
    // Parcours de la liste de trajets du catalogue,
    // Si un trajet correspond à celui recherché, il est ajouté à la liste des résultats
    // Si le départ d'un trajet correspond au départ du trajet recherché,
    // Et que cette ville n'a pas déjà été visitée :
        // Récursivité : Appel de la méthode Rechercher avec comme départ l'arrivée du trajet
{
    # ifdef MAP
        cout << "Appel de la methode Catalogue::Rechercher" << endl;
    # endif
        
    unsigned int i = 0;
    
    while (this->GetListe()->GetTrajet(i) != NULL)
    {        
        // Si le trajet correspond à celui recherché
        
        if ( equals (this->GetListe()->GetTrajet(i)->GetDepart(), depart) &&
             equals (this->GetListe()->GetTrajet(i)->GetArrivee(), arrivee) )
        {
            listeResultats->Ajouter(this->GetListe()->GetTrajet(i));
        }
        
        // Sinon, si le départ d'un trajet correspond au départ du trajet recherché,
        // Et que cette ville n'a pas déjà été visitée
        
        else if ( equals (this->GetListe()->GetTrajet(i)->GetDepart(), depart) &&
                  !dejaVisite (this->GetListe()->GetTrajet(i)->GetArrivee(), *nbVisites, villesVisitees) )
        {
            villesVisitees[*nbVisites] = new char [100];
            
            affecter (villesVisitees[*nbVisites], this->GetListe()->GetTrajet(i)->GetDepart());
            
            *nbVisites = *nbVisites + 1;
            
            ListeTrajets * listeResultatsFille;
            listeResultatsFille = new ListeTrajets();
            
            listeResultatsFille->Ajouter(this->GetListe()->GetTrajet(i));
            
            // Appel de la méthode Rechercher avec comme départ l'arrivée du trajet
            
            Rechercher (listeResultatsFille, this->GetListe()->GetTrajet(i)->GetArrivee(), 
                        arrivee, nbVisites, villesVisitees) ;
            
            TrajetCompose * trajetCompose;
            trajetCompose = new TrajetCompose(listeResultatsFille);
            
            delete listeResultatsFille;
            
            if ( equals (trajetCompose->GetArrivee(), arrivee))
            {
                listeResultats->Ajouter(trajetCompose);
            }
            
            delete trajetCompose;   
        }
        
        i = i + 1;
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ()
{
    # ifdef MAP
        cout << "Appel au constructeur par defaut de <Catalogue>" << endl;
    # endif
}

Catalogue::~Catalogue ()
{
    # ifdef MAP
        cout << "Appel au destructeur de <Catalogue>" << endl;
    # endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool equals (char * chaine1, char * chaine2)
{
    int i = 0;
    
    while (chaine1[i] == chaine2[i] && chaine1[i] != '\0' && 
           chaine2[i] != '\0' && i < 100)
    {
        i = i + 1;
    }
    
    if (chaine1[i] != chaine2[i] || i >= 100)
    {
        return false;
    }
    
    return true;
}

void run ()
{
    Catalogue catalogue;
    
    char lecture[100];
    char depart[100];
    char arrivee[100];
    char transport[100];
    
    char quit[] = "q";
    char ajouter[] = "a";
    char simple[] = "s";
    char compose[] = "c";
    char afficher[] = "f";
    char rechercher[] = "r";
    
    int nbTrajets;
    int i;
    
    TrajetSimple * trajetSimple;
    TrajetCompose * trajetCompose;
    
    ListeTrajets * liste;
    
    do 
    {
        cout << " ajouter : a / afficher : f / rechercher : r / quit : q :";
        
        cin >> lecture;
        
        // Ajouter Trajet
        if ( equals (lecture, ajouter) == true )
        {
            cout << "    simple : s / compose : c : ";
            
            cin >> lecture;
            
            // Trajet Simple
            if ( equals (lecture, simple) == true )
            {
                cout << "       Depart  : ";
                
                cin >> depart;
                
                cout << "       Arrivee : ";
                
                cin >> arrivee;
                
                cout << "       Transport : ";
                
                cin >> transport;
                
                trajetSimple = new TrajetSimple (depart, arrivee, transport);
                
                catalogue.Ajouter (trajetSimple);
                
                delete trajetSimple;
            }
            // Trajet Compose
            else if ( equals (lecture, compose) == true )
            {
                cout << "       Nombre Trajets : ";
                
                cin >> nbTrajets;
                
                liste = new ListeTrajets;
                
                for (i = 0; i < nbTrajets; i = i + 1)
                {
                    cout << "       Trajet " << i+1 << " : " << endl; 
                    
                    cout << "           Depart  : ";
                    
                    if (i == 0)
                    {
                        cin >> depart;
                    }
                    else
                    {
                        affecter(depart, arrivee);
                        
                        cout << depart << endl;
                    }
                    
                    cout << "           Arrivee : ";
                    
                    cin >> arrivee;
                    
                    cout << "           Transport : ";
                    
                    cin >> transport;
                    
                    trajetSimple = new TrajetSimple (depart, arrivee, transport);
                    
                    liste->Ajouter (trajetSimple);
                    
                    delete trajetSimple;
                }
                
                trajetCompose = new TrajetCompose (liste);
                    
                delete liste;
              
                catalogue.Ajouter (trajetCompose);
                
                delete trajetCompose;
            }
        }
        // Afficher
        else if ( equals (lecture, afficher) == true )
        {
            catalogue.Afficher ();
        }
        // Rechercher
        else if ( equals (lecture, rechercher) == true )
        {
            cout << "    Depart  : ";
                    
            cin >> depart;
            
            cout << "    Arrivee : ";
            
            cin >> arrivee;
            
            char ** villesVisitees;
            villesVisitees = new char*[100];
    
            int * nbVisites = new int;
            *nbVisites = 0;
            
            ListeTrajets * listeResultats;
            listeResultats = new ListeTrajets();
            
            // Appel de la méthode Rechercher sur le catalogue,
            // Avec le départ et l'arrivée souhaités,
            // En initialisant qu'aucune ville n'a déjà été visitée
            
            catalogue.Rechercher (listeResultats, depart, arrivee, nbVisites,
                                  villesVisitees);
            
            for (int i = 0; i < *nbVisites; i = i + 1)
            {
                delete[] villesVisitees[i]; 
            }
            
            delete[] villesVisitees;
            delete nbVisites;
            
            listeResultats->Afficher(0);
            
            delete listeResultats;
        }
        
    }
    // Quitter
    while ( equals (lecture, quit) == false );
}

int main ()
{
    run ();
    
    return 0;
}
