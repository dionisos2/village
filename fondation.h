#ifndef _fondation_
#define _fondation_

#include<iostream>
#include "cerveau/cerveau.h"
#include<fonction.h>
#include<fvector.h>
#include "robot.h"
#include<timer.h>
#include"monde.h"

using namespace std;


class Tfondation
{
	public:
	void muterrobot(int nombredeparent);
	void deplacerrobot(int temps_restant,bool phase);
	void caract_robot_default(void);
	void creer_robot(void);
	void detruire_robot(void);
	Tfondation(bool monde_communloc);
	~Tfondation(void);
	
	vector<Tmonde> Tabmondes;
	vector<Trobot> Tabrobots;
	
	
	bool monde_commun;
};

#endif