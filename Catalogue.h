/*************************************************************************
                           Catalogue  -  description
                           -------------------------
    début                : 2016
    copyright            : (C) 2016 par Etienne Raquin et Victor Borg
*************************************************************************/

//---------- Interface de la classe Catalogue (fichier Catalogue.h) ------

# if ! defined ( CATALOGUE_H )
# define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

# include "ListeTrajets.h"

# include "TrajetSimple.h"

# include "TrajetCompose.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe Catalogue :
    // Gérer une liste de trajets, simples ou composés :
    // Ajout de trajets, affichage des trajets, et recherche
//------------------------------------------------------------------------ 

class Catalogue
{
    
//----------------------------------------------------------------- PUBLIC

    public:

//----------------------------------------------------- Méthodes publiques
    
        void Ajouter (Trajet * trajet);
        // Mode d'emploi :
            // Paramètres : Pointeur sur le trajet à ajouter
            // Action : Ajoute le trajet pointé au catalogue
        // Contrat :
            // Cohérence : Pointeur de trajet passé en paramètre valide
            // Performance : Catalogue valide

        void Afficher ();
        // Mode d'emploi :
            // Action : Affiche les trajets du catalogue
        
        ListeTrajets * GetListe ();
        // Mode d'emploi :
            // Action : Renvoie un pointeur sur la liste de trajets du catalogue
        
        void Rechercher (ListeTrajets * listeResultats, char * depart, 
                         char * arrivee, int * nbVisites, char * villesVisitees[]);
        // Mode d'emploi :
            // Paramètres : Liste de trajets vide pour stocker les résultats,
                // villes de départ et d'arrivée, nombre de villes visitées,
                // tableau des villes visitées
            // Action : Recherche des trajets ou des compositions de trajets 
                // qui permettent de relier la ville de départ à la ville d'arrivée
        // Contrat :
            // Cohérence : Liste vide, chaines et tableaux valides

        void exporter();

        void importer (string cheminFichier, char * type, 
                       char * depart, char * arrivee, int debut, int fin);
        // Mode d'emploi :
            // Action : Ajoute les trajets du fichier d'export au catalogue
        // Contrat :
            // Cohérence : Trajets du fichier valides

//-------------------------------------------- Constructeurs - destructeur
    
        Catalogue ();
        // Mode d'emploi : Constructeur par defaut
            // Action : Créé un catalogue vide
        
        Catalogue (Catalogue const & catalogue);
        // Mode d'emploi : Constructeur de copie
            // Paramètres : Référence vers un catalogue
            // Action : Créé une copie du catalogue
        // Contrat :
            // Cohérence : Catalogue valide
            // Performance : Catalogue valide
        
        virtual ~Catalogue ();
        // Mode d'emploi : destructeur
            // Action : Libération de la mémoire allouée dynamiquement pour le catalogue
        
//------------------------------------------------------------------ PRIVE 

    private :

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

//----------------------------------------------------- Attributs proteges

//------------------------------------------------------- Attributs prives

        ListeTrajets listeTrajets;
        // Liste des trajets du catalogue

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dépendants de Catalogue

# endif // CATALOGUE_H
