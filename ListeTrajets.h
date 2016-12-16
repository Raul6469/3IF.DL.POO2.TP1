/*************************************************************************
                           ListeTrajets  -  description
                           ----------------------------
    début                : 2016
    copyright            : (C) 2016 par Etienne Raquin et Victor Borg
*************************************************************************/

//---- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----

# if ! defined ( LISTETRAJETS_H )
# define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées

# include "Trajet.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

typedef struct ElementTrajet ElementTrajet;

struct ElementTrajet
{
    Trajet * trajet;
    struct ElementTrajet * suivant;
};
// Element de la liste de trajets :
    // Pointeur sur trajet
    // Pointeur sur l'élément suivant de la liste

//------------------------------------------------------------------------ 
// Rôle de la classe <ListeTrajets>
    // Stocker, ajouter et afficher des trajets,
    // Permet un accès aux trajets,
    // Implémente une liste chaînée
//------------------------------------------------------------------------ 

class ListeTrajets
{
//----------------------------------------------------------------- PUBLIC

    public:

//----------------------------------------------------- Méthodes publiques
            
        void Ajouter (Trajet * trajet);
        // Mode d'emploi :
            // Paramètres : Pointeur sur trajet
            // Action : Ajoute le trajet pointé à fin de la liste
        // Contrat :
            // Cohérence : Trajet pointé valide
            // Performance : ListeTrajets valide

        Trajet * GetDebut ();
        // Mode d'emploi :
            // Action : Renvoie un pointeur sur le premier trajet de la liste
        // Contrat :
            // Performance : Pointeur sur trajet valide
        
        Trajet * GetFin ();
        // Mode d'emploi :
            // Action : Renvoie un pointeur sur le dernier trajet de la liste
        // Contrat :
            // Performance : Pointeur sur trajet valide
        
	Trajet * GetTrajet (unsigned int i);
	// Mode d'emploi :
            // Paramètres : Indice du trajet à renvoyer
            // Action : Renvoie le Trajet numero i de la liste de trajets
	// Contrat :
            // Cohérence : Indice valide	
            // Performance : Pointeur sur trajet valide

	void Afficher (int niveau = 0);    
        // Mode d'emploi :
            // Paramètres : Niveau de hierarchie du trajet, pour affichage indenté
            // Action : Affiche la liste des trajets
    
//-------------------------------------------- Constructeurs - destructeur
    
	ListeTrajets ();
	// Mode d'emploi : constructeur par défaut
            // Action : Créé une liste de trajets vide
        
        ListeTrajets (ListeTrajets const & listeTrajets);
        // Mode d'emploi : constructeur de copie
            // Paramètres : Référence vers une liste de trajets
            // Action : Créé une copie de la liste de trajets
        // Contrat :    
            // Cohérence : Liste de trajets valide
            // Performance : Liste de trajets valide

	virtual ~ListeTrajets ();
	// Mode d'emploi : destructeur
            // Action : Libération de la mémoire allouée dynamiquement pour la liste de Trajets

//------------------------------------------------------------------ PRIVE 

    private :

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

//----------------------------------------------------- Attributs proteges

//------------------------------------------------------- Attributs prives

        ElementTrajet * debut;
        // Pointeur sur le premier élément de la liste de trajets
        ElementTrajet * fin;
        // Pointeur sur le dernier élément de la liste de trajets

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//------------------------------------- Types dépendants de <ListeTrajets>

# endif // LISTETRAJETS_H
