#ifndef _robot_
#define _robot_

#include<iostream>
#include<math.h>
#include "cerveau/cerveau.h"
#include<string>
#include<fvector.h>



#define PAUSE system("pause")
#define NBRSORTIE 2
#define NBRENTRE 10
#define sqr(x) ((x)*(x))
class Tmonde;

class Trobot;
class Trobot:public Tcerveau
{
	public:

	static int rayonvue;
	static int Vmax;
	static int rayonmange;	
	static int robot_total;

	int numrobot;
	int bouffe_a_placer;
	string type;
	Tmonde *monde;

	
	vector<Tpositron*> sortiemonde;
	vector<int> psortiemonde;

	vector<Tpositron> entremonde;
	vector<int> ppositronmonde;
	vector<int> pentremonde;

	static int initdecalage[2],initmemoire[2];
	static int minitdecalage[2],minitmemoire[2];

	
	int resultdecalage,x,y;

	vector<Tpositron*> memoire;
	vector<int> pmemoire;
	
	Trobot();
	void init();
	void memorise();	
	void afficherliaison();
	void reinit();	
	void save(string nfichier);
	void load(string nfichier);
	void vider();
	void init(Trobot &robotparent,string adresse_fichier);

	virtual void depart(bool remise_a_zero)=0;
	virtual void action()=0;
	virtual void move()=0;

};

#endif