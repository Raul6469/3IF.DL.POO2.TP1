/*************************************************************************
                           Trajet  -  description
                           ----------------------
    debut                : 2016
    copyright            : (C) 2016 Etienne Raquin & Victor Borg
*************************************************************************/

//---------- Interface de la classe Trajet (fichier Trajet.h) ------------

# if ! defined ( TRAJET_H )
# define TRAJET_H

//--------------------------------------------------- Interfaces utilisees

# include <string>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

// Forward decaration
struct ListeTrajets;

//------------------------------------------------------------------------ 
// Role de la classe Trajet
    // Cette classe généralise la défintion des objets TrajetSimple et TrajetCompose
    // Elle contient des méthodes virtuelles pures qui sont redéfinies dans les classes
    // qui héritent de Trajet : TrajetSimple et TrajetCompose.
//------------------------------------------------------------------------ 

class Trajet
{

//----------------------------------------------------------------- PUBLIC

    public:
    
//----------------------------------------------------- Methodes publiques
    
        virtual char * GetDepart() = 0;
        // Mode d'emploi :
            // Action : Permet d'obtenir la ville de départ du trajet passé en paramètre
        // Contrat :
            // Cohérence :Trajet valide et trajet non modifié

        virtual char * GetArrivee() = 0;
        // Mode d'emploi :
            // Action : Permet d'obtenir la ville d'arrivée du trajet passé en paramètre
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
        
        virtual ListeTrajets * GetListe () = 0;
        // Mode d'emploi :
            // Action : Permet d'obtenir la liste de trajets contenue dans l'objet ayant appelé la méthode
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Renvoie un pointeur sur la liste de trajets

        virtual void Afficher (int indentation) = 0;
        // Mode d'emploi :
            // Action : Permet d'afficher les caractéristiques du trajet courant
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
        
        virtual Trajet * Clone() = 0;
        // Mode d'emploi :
            // Action : Permet d'appeler le constructeur de copie correspondant au type de trajet ayant appellé la méthode
        // Contrat :
            // Cohérence : objet appelant la méthode valide
            // Performance : objet créé valide

        virtual string exporterTrajet(unsigned int numero) = 0;
        // Mode d'emploi :
            // Action : Permet d'écrire dans le fichier de sauvegarde le trajet ayant appelé la méthode
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Enregistre le trajet dans le fichier

//-------------------------------------------- Constructeurs - destructeur

        Trajet ();
        // Mode d'emploi : constructeur par défaut
            // Action : Crée un trajet vide
        // Contrat :
            // Performance : objet créé valide 
        
        Trajet (const Trajet & trajet);  
        // Mode d'emploi : constructeur de copie
            // Action : Créé une copie du trejet passé en référence
        // Contrat :
            // Cohérence : référence vers un objet Trajet valide
            // Performance : objet créé valide

        virtual ~Trajet ();
        // Mode d'emploi : destructeur
            // Action : Libère les espaces mémoires utilisés par le trajet ayant invoqué la méthode
        // Contrat :
            // Performance : libération des espaces mémoire correspondants

//------------------------------------------------------------------ PRIVE 

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

//----------------------------------------------------- Attributs proteges

//------------------------------------------------------- Attributs prives

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Trajet>

# endif // TRAJET_H
