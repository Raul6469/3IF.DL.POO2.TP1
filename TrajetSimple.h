/*************************************************************************
                           TrajetSimple  -  description
                           ----------------------------
    debut                : 2016
    copyright            : (C) 2016 Etienne Raquin & Victor Borg
*************************************************************************/

//----- Interface de la classe TrajetSimple (fichier TrajetSimple.h) -----

# if ! defined ( TRAJETSIMPLE_H )
# define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisees

# include "ListeTrajets.h"

# include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rele de la classe TrajetSimple
    // Définit l'objet TrajetSimple, qui hérite de Trajet. Elle a pour attributs
    // une ville de départ, une ville d'arrivée, ainsi qu'un mode de transport, qui
    // se traduisent par des chaînes de caractères. Elle contient des méthodes permettant
    // d'accéder à ces attributs.
//------------------------------------------------------------------------ 

class TrajetSimple : public Trajet
{

//----------------------------------------------------------------- PUBLIC

    public:

//----------------------------------------------------- Methodes publiques
    
        virtual char * GetDepart ();
        // Mode d'emploi :
            // Action : Permet d'obtenir la ville de départ du trajet passé en paramètre
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : renvoie un pointeur sur la liste de caractères correspondant à la ville de départ

        virtual char * GetArrivee ();
        // Mode d'emploi :
            // Action : Permet d'obtenir la ville d'arrivée du trajet passé en paramètre
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : renvoie un pointeur sur la liste de caractères correspondant à la ville de départ

        ListeTrajets * GetListe ();
        // Mode d'emploi :
            // Action : Permet d'obtenir la liste de trajets du trajet qui a appelé la méthode
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : renvoie un pointeur sur la liste de trajets

        string exporterTrajet(unsigned int numero);
        // Mode d'emploi :
            // Action : Permet d'écrire dans le fichier de sauvegarde le trajet ayant appelé la méthode
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Enregistre le trajet dans le fichier
        
        virtual void Afficher (int indentation);
        // Mode d'emploi :
            // Action : Permet d'afficher les paramètres du trajet courant
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Affiche sur la sortie standard le trajet ayant appelé la méthode

        virtual Trajet * Clone ();
        // Mode d'emploi :
            // Action : Permet d'appeler le constructeur de copie correspondant à l'objet qui a appelé la méthode
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Renvoie un pointeur sur le Trajet créé par le constructeur de copie

//-------------------------------------------- Constructeurs - destructeur
        
        TrajetSimple ();
         // Mode d'emploi : constructeur par défaut
            // Action : Crée un trajet simple vide
        // Contrat :
            // Performance : objet créé valide    
        
        TrajetSimple (TrajetSimple & trajetSimple);
        // Mode d'emploi : constructeur de copie
            // Action : Créé une copie du trejet passé en référence
        // Contrat :
            // Cohérence : référence vers un objet TrajetSimple valide
            // Performance : objet créé valide
        
        TrajetSimple (char * ar, char * dep, char * trans);
        // Mode d'emploi : constructeur de TrajetSimple
            // Action : créé un TrajetSimple initialisés avec un ville de départ, d'arrivée et un mode de transport
            // passés en paramètre
        // Contrat :
            // Cohérence : Les chaines de caractères données en paramètre sont valides
            // Performance : objet créé valide
        
        virtual ~TrajetSimple ();
        // Mode d'emploi : Destructeur de TrajetSimple
            // Action : Libère les espace mémoire occupés par le trajet simple ayant invoqué la méthode
        // Contrat :
            // Cohérence : Trajet valide
            // Performance : Libération de tous les espaces mémoire occupés par le trajet simple concerné

//------------------------------------------------------------------ PRIVE 

    private :

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees
    
//----------------------------------------------------- Attributs proteges

        // Ville de départ
        char * depart;

        // Ville d'arrivée
        char * arrivee; 

        // Mode de transport
        char * transport;

//------------------------------------------------------- Attributs prives

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------- Types dependants de <TrajetSimple.h>

# endif // TRAJETSIMPLE_H
