#ifndef _monde_
#define _monde_

#include <iostream>
#include<fonction.h>
#include<fvector.h>
#include"robot.h"

class Tmonde
{
	public:
	Tmonde(vector<Trobot>* Tabprobotsloc);

	vector<Trobot>* Tabprobots;

};

class Tanimaux:public Trobot
{
	public:
	void move(void);
};

class Tpredateur:public Tanimaux
{
	public:
	void action(void);
	void depart(bool remise_a_zero);
	Tpredateur(void);
};

class Tproie:public Tanimaux
{
	public:
	void action(void);
	void depart(bool remise_a_zero);
	Tproie(void);
};

#endif