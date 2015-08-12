#ifndef _positron_
#define _positron_

/*D-délaration de la classe Tpositron*/

#include <iostream>
#include <fstream>
#include <fvector.h>
#include <string>
#include <fonction.h>
#define SEUIL_MAX 500000

using namespace std;


class Tpositron;

class Tpositron
{
  public:

	static int nbrpositron;
    /*constructeurs*/
	Tpositron(int nentre=0);
	~Tpositron();
    

    /*Méthodes*/
    int sortie(int position=0);
	void afficherliaison();
	void save(ofstream &fichier);
	void load(ifstream &fichier);


    /*tableaux*/
	
    vector<Tpositron*> tabentre;
    vector<int> tabpoid;
	vector<int> tabpentre;
	vector<bool> tabentrefixe;

    /*propriétées*/
    bool dejapasser,sens_du_seuil,sortie_fixe,activerseuil;
    int vsortie,seuil1,diviseur_de_sortie;
	int numpositron;


};

/*F-délaration de la classe Tpositron*/

#endif