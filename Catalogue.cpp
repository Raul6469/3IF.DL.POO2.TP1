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

# include <fstream>

# include <stdio.h>

# include <stdlib.h>

# include <string>

//------------------------------------------------------ Include personnel

# include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void affecter (char * chaine1, const char * chaine2)
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

bool equals (char * chaine1, const char * chaine2);
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
        
    if (listeTrajets.GetTrajet(0) == NULL)
    {
        cout << " La liste de trajets est vide" << endl;
    }
    else
    {
        cout << endl;
        
        listeTrajets.Afficher ();
    
        cout << endl;
    }
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

Trajet * lireTrajetSimple (string contenu, int * i, 
                           char * depart = NULL, char * arrivee = NULL)
{    
    Trajet * trajetSimple;
        
    string departLu = "";
    string arriveeLu = "";
    string transport = "";
    
    char indifferent[] = "i";
    
    while (contenu[*i] != ':')
    {
        *i = *i + 1;
    }
    
    *i = *i + 1;
    
    while (contenu[*i] != '|')
    {
        departLu = departLu + contenu[*i];
        
        *i = *i + 1;
    }
    
    *i = *i + 1;
    
    while (contenu[*i] != '|')
    {
        arriveeLu = arriveeLu + contenu[*i];
        
        *i = *i + 1;
    }
    
    *i = *i + 1;
    
    while (contenu[*i] != '|')
    {
        transport = transport + contenu[*i];
        
        *i = *i + 1;
    }

    *i = *i + 1;
    
    if ( ( depart == NULL || equals (depart, indifferent) || 
           equals (depart, departLu.c_str()) ) &&
         ( arrivee == NULL || equals (arrivee, indifferent) || 
           equals (arrivee, arriveeLu.c_str()) ) )
    {
        trajetSimple = new TrajetSimple (departLu.c_str(), arriveeLu.c_str(), transport.c_str());
    
        return trajetSimple;
    }
    
    return NULL;
}

Trajet * lireTrajet (string contenu, int * i, 
                     char * type, char * depart, char * arrivee, int niveau = 0)
{
    char simple[] = "s";
    char compose[] = "c";
    char indifferent[] = "i";
    
    // Trajet Compose
    if (contenu[*i] != '0' && !equals (type, simple))
    {
        niveau = niveau + 1;
        
        ListeTrajets * listeTrajetsFille;
        listeTrajetsFille = new ListeTrajets;
        
        Trajet * trajet;
        
        TrajetCompose * trajetCompose;
        
        int id = (int)contenu[*i];
        int newId = id;
        
        while (newId == id)
        {
            *i = *i + 2;
           
            trajet = lireTrajet (contenu, i, NULL, NULL, NULL, niveau);
            
            listeTrajetsFille->Ajouter (trajet);
            
            delete trajet;
            
            *i = *i + 2 * niveau;
            
            newId = (int)contenu[*i];
        }
        
        *i = *i - 2 * niveau;
        
        niveau = niveau - 1;
        
        trajetCompose = new TrajetCompose (listeTrajetsFille);
        
        delete listeTrajetsFille;
        
        if ( ( depart == NULL || equals (depart, indifferent) || 
               equals (depart, trajetCompose->GetDepart()) ) &&
             ( arrivee == NULL || equals (arrivee, indifferent) || 
               equals (arrivee, trajetCompose->GetArrivee()) ) )
        {    
            return trajetCompose;
        }
       
        return NULL;
    }
    // Trajet Simple
    else if (contenu[*i] == '0' && !equals (type, compose))
    {   
        return lireTrajetSimple (contenu, i, depart, arrivee);
    }
    else
    {
        while (contenu[*i] != '\n')
        {    
            *i = *i + 1;
        }
        
        *i = *i - 1;
        
        return NULL;
    }
}

void Catalogue::importer (string contenu, char * type, 
                          char * depart, char * arrivee, int debut, int fin)
{
    Trajet * trajet;
    
    int * i;
    
    i = new int;
    
    *i = 0;
    
    int nbTrajets = 0;
        
    while (contenu[*i] != '#' && nbTrajets < debut-1)
    {
        trajet = lireTrajet(contenu, i, type, depart, arrivee);
        
        delete trajet;
        
        nbTrajets = nbTrajets + 1;
        
        *i = *i + 2;
    }
    
    if (fin == 0)
    {
        while (contenu[*i] != '#')
        {       
            trajet = lireTrajet(contenu, i, type, depart, arrivee);
            
            if (trajet != NULL)
            {
                listeTrajets.Ajouter(trajet);
                
                delete trajet;

                nbTrajets = nbTrajets + 1;
            }
            
            *i = *i + 2;
        }
    }
    else
    {
        while (contenu[*i] != '#' && nbTrajets <= fin-1)
        {       
            trajet = lireTrajet(contenu, i, type, depart, arrivee);
            
            if (trajet != NULL)
            {
                listeTrajets.Ajouter(trajet);
                
                delete trajet;

                nbTrajets = nbTrajets + 1;
            }
            
            *i = *i + 2;
        }
    }
    
    delete i;
    
    cout << "     Fichier importe" << endl;
}

void Catalogue::exporter()
{
    #ifdef MAP
        cout << "Appel de la methode Catalogue::exporter" << endl;
    #endif
        
    string cheminFichier;
        
    cout << "     Chemin d'accès du fichier : ";
            
    cin >> cheminFichier;

    unsigned int i = 0;

    string line = "";
    
    string str = "";

    while(listeTrajets.GetTrajet(i) != NULL)
    {
        line = line + listeTrajets.GetTrajet(i)->exporterTrajet(i, str);
        
        i++;
    }

    ofstream fichier (cheminFichier.c_str());
    
    if (!fichier)
    {
        cout << "     Erreur d'ouverture du fichier d'export" << endl;
        
        return;
    }
    
    streambuf * oldCoutBuffer = cout.rdbuf(fichier.rdbuf());

    cout << line + "#";

    cout.rdbuf(oldCoutBuffer);
    fichier.close();
    
    cout << "     Fichier exporte" << endl;
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

bool equals (char * chaine1, const char * chaine2)
{
    if (chaine1 == NULL || chaine2 == NULL)
    {
        return false;
    }
    
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

Trajet * creerTrajet (int niveau = 0, char * departPrecedent = NULL)
{
    char lecture[100];
    char depart[100];
    char arrivee[100];
    char transport[100];
    
    char simple[] = "s";
    char compose[] = "c";
    char nouveau[] = "n";
      
    for (int i = 0; i < niveau; i = i + 1){cout << "    ";}
    cout << "     Simple : s / Compose : c : ";
            
    cin >> lecture;
    
    // Trajet Simple
    if ( equals (lecture, simple) == true )
    {
        Trajet * trajetSimple;
        
        for (int i = 0; i < niveau; i = i + 1){cout << "    ";}
        cout << "     Depart  : ";
        
        if ( departPrecedent == NULL )
        {
            cin >> depart;
        }
        else
        {
            cout << departPrecedent << endl;
            
            affecter (depart, departPrecedent);
        }
            
        for (int i = 0; i < niveau; i = i + 1){cout << "    ";}
        cout << "     Arrivee : ";
        
        cin >> arrivee;
        
        for (int i = 0; i < niveau; i = i + 1){cout << "    ";}
        cout << "     Transport : ";
        
        cin >> transport;
        
        trajetSimple = new TrajetSimple (depart, arrivee, transport);
        
        return trajetSimple;
    }
    // Trajet Compose
    else if ( equals (lecture, compose) == true )
    {
        niveau = niveau + 1;
        
        ListeTrajets * liste;
        liste = new ListeTrajets;
        
        Trajet * trajetCompose;
        
        Trajet * trajet;
        
        bool nouveauTrajet;
        
        int nbTrajets = 0;
        
        do
        {
            for (int i = 0; i < niveau-1; i = i + 1){cout << "    ";}
            cout << "     Trajet " << nbTrajets+1 << " : " << endl; 
            
            if (nbTrajets > 0)
            {
                trajet = creerTrajet(niveau, 
                                     liste->GetTrajet(nbTrajets-1)->GetArrivee());
            }
            else
            {
                trajet = creerTrajet(niveau);
            }
            
            liste->Ajouter(trajet);
                
            delete trajet;
            
            if (nbTrajets > 0)
            {
                for (int i = 0; i < niveau-1; i = i + 1){cout << "    ";}
                cout << "     Nouveau trajet : n / Fin : f : ";
                
                cin >> lecture;
                
                nouveauTrajet = false;
                
                if ( equals (lecture, nouveau) )
                {
                    nouveauTrajet = true;
                }
            }
            else
            {
                nouveauTrajet = true;
            }
            
            nbTrajets = nbTrajets + 1; 
        }
        while (nouveauTrajet);
        
        trajetCompose = new TrajetCompose (liste);
                
        delete liste;
        
        return trajetCompose;
    }
    else
    {
        return NULL;
    }
}

void run ()
{
    Catalogue catalogue;
    
    Trajet * trajet;
    
    char lecture[100];
    char depart[100];
    char arrivee[100];
    
    char * departImport;
    char * arriveeImport;
    char * type;
    
    string cheminFichier;
    
    char quit[] = "q";
    char ajouter[] = "a";
    char simple[] = "s";
    char compose[] = "c";
    char indifferent[] = "i";
    char afficher[] = "f";
    char rechercher[] = "r";
    char exporter[] = "e";
    char importer[] = "i";
    
    int debut;
    int fin;
    
    do 
    {
        cout << " Ajouter : a / aFficher : f / Rechercher : r /";
        cout << " Exporter : e / Importer : i / Quit : q : ";
        
        cin >> lecture;
        
        // Ajouter Trajet
        if ( equals (lecture, ajouter) == true )
        {
            trajet = creerTrajet();
            
            if (trajet != NULL)
            {
                catalogue.Ajouter(trajet);
            }
            
            delete trajet;
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
            
            if (listeResultats->GetTrajet(0) == NULL)
            {
                cout << " Aucun Trajet correspondant à la recherche" << endl;
            }
            
            delete listeResultats;
        }
        // Exporter
        else if ( equals (lecture, exporter) == true )
        {
            catalogue.exporter();
        }
        // Importer
        else if ( equals (lecture, importer) == true )
        {
            cout << "     Chemin d'accès du fichier : ";
            
            cin >> cheminFichier;
            
            
            
            ifstream saveFile;
    
            saveFile.open (cheminFichier.c_str());
            
            string contenu;
            string ligne;
            
            if (saveFile)
            {       
                while ( getline (saveFile, ligne) )
                {
                    contenu = contenu + ligne + "\r\n"; 
                }
                
                saveFile.close();
                
                cout << "     Restrictions : " << endl;
            
                type = new char;
                departImport = new char;
                arriveeImport = new char;
                affecter(type, indifferent);
                affecter(departImport, indifferent);
                affecter(arriveeImport, indifferent);
                
                debut = 0;
                fin = 0;
                
                cout << "         Simples : s / Composes : c (Indiferrent : i) : ";
                
                cin >> lecture;
                
                if ( equals (lecture, simple) == true || 
                    equals (lecture, compose) == true )
                {    
                    affecter(type, lecture);
                }
                
                cout << "         Depart (Indiferrent : i) : ";
                
                cin >> lecture;
                
                if ( !equals (lecture, indifferent))
                {
                    affecter (departImport, lecture);
                }
                    
                cout << "         Arrivee (Indiferrent : i) : ";
                
                cin >> lecture;
                
                if ( !equals (lecture, indifferent))
                {
                    affecter (arriveeImport, lecture);
                }
                
                cout << "         Borne inferieure (Indifferent : 0) : ";
                
                cin >> debut;
                
                cout << "         Borne superieure (Indifferent : 0) : ";
                
                cin >> fin;
                
                catalogue.importer (contenu, type, 
                                    departImport, arriveeImport, debut, fin);
                
                delete departImport;
                delete arriveeImport;
                delete type;
            }
            else
            {
                cout << "     Erreur d'ouverture du fichier d'import" << endl;
            }
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
