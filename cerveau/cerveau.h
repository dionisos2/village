#ifndef _cerveau_
#define _cerveau_

#include <iostream>
#include <fvector.h>
#include <ctime>
#include "positron/positron.h"
#include <fonction.h>
#include "ame/ame.h"
#include <fstream>
#include <string>
using namespace std;

class Tcerveau
{
	public:

	
	void init();
	void reinit();
	void afficherliaison();
	void save(ofstream &fichier);
	void load(ifstream &fichier);
	void vider();
	Tcerveau(void);

	vector<Tpositron> Tabpositrons;
	

	
	static int initpoid[2],initseuil1[2],initentrer[2],initpositron[2],initdiviseur_de_sortie[2];
	static int minitseuil1[2],minitentrer[2],minitpositron[2],minitliaison[2],minitdiviseur_de_sortie[2];

	Tame ame;
	int points;
};

#endif