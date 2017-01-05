/*************************************************************************
                           TrajetCompose  -  description
                           -----------------------------
    debut                : 2016
    copyright            : (C) 2016 Etienne Raquin & Victor Borg
*************************************************************************/

//---- Interface de la classe TrajetCompose (fichier TrajetCompose.h) ----

# if ! defined ( TRAJETCOMPOSE_H )
# define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisees

# include "ListeTrajets.h"

# include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe TrajetCompose :
    // Définit l'objet TrajetCompose, qui est un composition de TrajetsSimples
    // ou d'autres TrajetsComposes. Cette classe hérite de Trajet. 
    // Cette composition se traduit par l'utilisation d'une liste chainee
    // qui est un attribut de cette classe.
    // Cette classe contient des méthodes de manipulation de cette liste
    // (accès aux villes de départ, d'arrivée), ainsi que d'affichage.
//------------------------------------------------------------------------ 

class TrajetCompose : public Trajet
{

//----------------------------------------------------------------- PUBLIC

    public:

//----------------------------------------------------- Methodes publiques

        virtual char * GetDepart ();
        // Mode d'emploi :
            // Action : Permet d'obtenir la ville de départ du trajet passé en paramètre
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Renvoie un pointeur sur la ville de départ

        virtual char * GetArrivee ();
        // Mode d'emploi :
            // Action : Permet d'obtenir la ville d'arrivée du trajet passé en paramètre
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Renvoie un pointeur sur la ville d'arrivée
        
        ListeTrajets * GetListe ();
        // Mode d'emploi :
            // Action : Permet d'obtenir la ville d'arrivée du trajet passé en paramètre
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Renvoie un pointeur sur la ville d'arrivée

        string exporterTrajet(unsigned int numero, string aEcrire);
        // Mode d'emploi :
            // Action : Permet d'écrire dans le fichier de sauvegarde le trajet ayant appelé la méthode
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Enregistre le trajet dans le fichier

        virtual void Afficher (int indentation);
        // Mode d'emploi :
            // Action : Permet d'afficher les paramètres du trajet courant, avec un niveau de hiérachie égal à la valeur de indentation
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié, et identation entier valide supérieur ou égal à 0
            // Performance : Affiche l'ensemble des trajets contenus dans le TrajetCompose ayant appelé la méthode
        
        virtual Trajet * Clone ();
        // Mode d'emploi :
            // Action : Permet d'appeler le constructeur de copie correspondant à l'objet qui a appelé la méthode
        // Contrat :
            // Cohérence : Trajet valide et trajet non modifié
            // Performance : Renvoie un pointeur sur le Trajet créé par le constructeur de copie

//-------------------------------------------- Constructeurs - destructeur
    
        TrajetCompose ();
        // Mode d'emploi : constructeur par défaut
            // Action : Crée un trajet composé vide, c'est-à-dire avec une liste de trajets initialisée vide
        // Contrat :
            // Performance : objet créé valide    

        TrajetCompose (const TrajetCompose & trajetCompose);
        // Mode d'emploi : constructeur de copie
            // Action : Créé une copie du trejet passé en référence
        // Contrat :
            // Cohérence : référence vers un objet TrajetCompose valide
            // Performance : objet créé valide
        
        TrajetCompose (ListeTrajets * listeTrajets);
        // Mode d'emploi :
            // Action : créé un nouveau TrajetCompose contenant la liste de trajets passée en paramètre
        // Contrat :
            // Cohérence : Liste de trajets valide
            // Performance : objet créé valide

        virtual ~TrajetCompose ();
        // Mode d'emploi : Destructeur de TrajetCompose
            // Action : Libère les espace mémoire occupés par le trajet composé ayant invoqué la méthode
        // Contrat :
            // Cohérence : Trajet valide
            // Performance : Libération de tous les espaces mémoire occupés par le trajet composé concerné
		
//------------------------------------------------------------------ PRIVE 

    private :
	
//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

//----------------------------------------------------- Attributs proteges

//------------------------------------------------------- Attributs prives

        // Contient la liste de Trajets qui forme le trajet composé
        ListeTrajets * listeTrajets;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dpendants de <${file_base}>

# endif // TRAJETCOMPOSE_H
