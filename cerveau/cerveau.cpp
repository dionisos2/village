#include <iostream>
#include <fvector.h>
#include <ctime>
#include <fonction.h>
#include "cerveau.h"





Tcerveau::Tcerveau(void):
Tabpositrons(5000,"Tabpositrons")
{
};

void Tcerveau::vider()
{

	int i;
	for (i=0;i<Tabpositrons.size();++i)
	{
		Tabpositrons.at(i).tabentre.clear();
		Tabpositrons.at(i).tabpoid.clear();
		Tabpositrons.at(i).tabpentre.clear();

	}

	
	Tabpositrons.clear();
	ame.vider();

};

void Tcerveau::save(ofstream &fichier)
{	
	 
	static int compteur;

	fichier<<"cerveaux"<<endl;

	this->ame.save(fichier);

	fichier<<Tabpositrons.size()<<endl;
	for (compteur=0;compteur<this->Tabpositrons.size();++compteur)
	{
		Tabpositrons.at(compteur).save(fichier);
	}
};

void Tcerveau::load(ifstream &fichier)
{
	string ligne;
	int taille,i;

	/*passe deux lignes*/	
	getline(fichier,ligne);
	getline(fichier,ligne);
	this->ame.load(fichier);

	/*Chargement des positrons*/
	getline(fichier,ligne);
	taille=strtoint(ligne);

	if(Tabpositrons.size()!=0)
	{
		cout<<"prout 1"<<Tabpositrons.size()<<endl;
		system("pause");
	}
	for (i=0;i<taille;++i)
	{
		this->Tabpositrons.push_back((new Tpositron));
		this->Tabpositrons.at(i).load(fichier);

	}


}		
		  

void Tcerveau::init()
{
	static int resultseuil1;
	static int resultseuil2;
	static int resultnentrer;
	static int resultnpositron;
	static int position;
	resultnpositron=randomentre(Tcerveau::initpositron);
		

	points=0;

	static int i;

	if(Tabpositrons.size()!=0)
	{
		cout<<"Tcerveau->couille"<<endl;
		system("pause");
	}

	for (i=0;i<resultnpositron;++i)
	{
		resultseuil1=randomentre(Tcerveau::initseuil1);
		resultnentrer=randomentre(Tcerveau::initentrer);
		Tabpositrons.push_back((new Tpositron(resultnentrer)));
		Tabpositrons.at(i).seuil1=resultseuil1;
		Tabpositrons.at(i).sens_du_seuil=randomentre();
		Tabpositrons.at(i).sortie_fixe=false;
		Tabpositrons.at(i).diviseur_de_sortie=randomentre(Tcerveau::initdiviseur_de_sortie);	
		
	}

	
	for (i=0;i<resultnpositron;++i)
	{
		static int i2;
		for(i2=0;i2<Tabpositrons.at(i).tabpoid.size();++i2)
		{
			position=(rand()%resultnpositron);
			Tabpositrons.at(i).tabentre.push_back(new Tpositron*(&Tabpositrons.at(position)));
			Tabpositrons.at(i).tabpentre.push_back(new int(position));
			Tabpositrons.at(i).tabpoid.at(i2)=randomentre(Tcerveau::initpoid);
			Tabpositrons.at(i).tabentrefixe.push_back(new bool(false));
		}

	}

	ame.cerveau=this;
	ame.init();

};






void Tcerveau::reinit()
{
	static int i;
	for(i=0;i<Tabpositrons.size();i++)
	{
		Tabpositrons.at(i).dejapasser=false;
	}

}


void Tcerveau::afficherliaison()
{
	int i;

	cout<<"cerveaux:"<<(int)this<<endl<<endl;
	for(i=0;i<Tabpositrons.size();++i)
	{
		Tabpositrons.at(i).afficherliaison();
		cout<<endl;
	}
};
