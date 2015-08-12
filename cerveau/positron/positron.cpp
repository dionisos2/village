#include <iostream>
#include <fvector.h>
#include "positron.h"
#define PAUSE system("pause")


/*D-Definition de la classe*/

int Tpositron::nbrpositron=0;


Tpositron::Tpositron(int nentre):
tabentre(1000,"tabentre"),
tabpoid(1000,"tabpoid"),
tabpentre(1000,"tabpentre"),
tabentrefixe(1000,"tabentrefixe"),
dejapasser(false),
vsortie(0)
{
	++nbrpositron;
	numpositron=nbrpositron;
	for(int i=0;i<nentre;++i)
	{
		tabpoid.push_back(new int(0));
	}
};

Tpositron::~Tpositron()
{
--nbrpositron;
};


void Tpositron::save(ofstream &fichier)
{
	int i;

	fichier<<"positron:"<<this->numpositron<<endl;
	
	/*seuil1 et son sens*/
	fichier<<this->seuil1<<endl;
	fichier<<booltostr(this->sens_du_seuil)<<endl;
	/*activer_seuil*/
	fichier<<booltostr(this->activerseuil)<<endl;
	/*diviseur de sortie*/
	fichier<<this->diviseur_de_sortie<<endl;
	/*sortie fixe*/
	fichier<<booltostr(this->sortie_fixe)<<endl;
	/*vsortie*/
	fichier<<this->vsortie<<endl;
	/*entrées*/
	fichier<<tabentre.size()<<endl;
	for(i=0;i<tabentre.size();++i)
    {
		fichier<<tabpentre.at(i)<<endl;
		fichier<<this->tabpoid.at(i)<<endl;
		fichier<<booltostr(this->tabentrefixe.at(i))<<endl;
	}
}

void Tpositron::load(ifstream &fichier)
{
int i,taille;
string ligne;
getline(fichier,ligne);

/*seuil1 et son sens*/
getline(fichier,ligne);
this->seuil1=strtoint(ligne);
getline(fichier,ligne);
this->sens_du_seuil=strtobool(ligne);
/*activer_seuil*/
getline(fichier,ligne);
this->activerseuil=strtobool(ligne);
/*diviseur de sortie*/
getline(fichier,ligne);
this->diviseur_de_sortie=strtoint(ligne);
/*sortie fixe*/
getline(fichier,ligne);
this->sortie_fixe=strtobool(ligne);
/*vsortie*/
getline(fichier,ligne);
this->vsortie=strtoint(ligne);
/*entrées*/
getline(fichier,ligne);
taille=strtoint(ligne);

for (i=0;i<taille;i++)
{
getline(fichier,ligne);
this->tabpentre.push_back(new int(strtoint(ligne)));
getline(fichier,ligne);
this->tabpoid.push_back(new int(strtoint(ligne)));
getline(fichier,ligne);
this->tabentrefixe.push_back(new bool(strtobool(ligne)));
}


}





void Tpositron::afficherliaison()
{
	cout<<"N"<<numpositron<<" @"<<(int)this<<":"<<endl;

	int i;
	for(i=0;i<tabentre.size();++i)
	{
		cout<<"N"<<tabentre.at(i)->numpositron<<" @"<<(int)tabentre.at(i);
		cout<<"/";
	}
	cout<<endl;
	
};



int Tpositron::sortie(int position)
{
	
	int somme;
	somme=0;
	int sommepoid;
	sommepoid=0;
	
	
	if((dejapasser==false)&&(sortie_fixe==false))
	{
		int i;
		for(i=0;i<tabentre.size();++i)
		{
			dejapasser=true;
			somme+=(tabentre.at(i)->sortie(position+1))*tabpoid.at(i);
		}
		
		if(diviseur_de_sortie!=0)
		{
			somme/=diviseur_de_sortie;
		}

		vsortie=somme;
	}



	if((((((vsortie>=seuil1)&&(sens_du_seuil==true))||((vsortie<=seuil1)&&(sens_du_seuil==false)))&&(vsortie<SEUIL_MAX)&&(vsortie>-SEUIL_MAX)))||(sortie_fixe==true))
	{
		//cout<<vsortie<<endl;
		return vsortie;

	}
	else
	{
		if(activerseuil==true)
		{
			return 0;
		}
		else
		{
			return vsortie;
		}
	}
};


/*F-Definition de la classe*/
