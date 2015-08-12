#include "fondation.h"


	/*D-Initialisation du robot*/
	int Trobot::initdecalage[2];
	int Trobot::initentrer[2]; 
	int Trobot::initmemoire[2];
	int Trobot::initpoid[2];
	int Trobot::initpositron[2];
	int Trobot::initseuil1[2];
	int Trobot::initdiviseur_de_sortie[2];
	
	int Trobot::minitdecalage[2];
	int Trobot::minitentrer[2];
	int Trobot::minitmemoire[2];
	int Trobot::minitpositron[2];
	int Trobot::minitseuil1[2];
	int Trobot::minitdiviseur_de_sortie[2];


	int Trobot::rayonvue=1000;
	int Trobot::Vmax=20;
	int Trobot::rayonmange=30;

	int Tame::initdelaymax[2];
	int Tame::initmaxnonamelioration[2];
	
	int Tame::initvchangement_poids[2];
	int Tame::initvchangement_seuil[2];
	int Tame::initvchangement_diviseur[2];
	int Tame::initvchangement_sortie[2];

	int Tame::minitdelaymax[2];
	int Tame::minitmaxnonamelioration[2];
	
	int Tame::minitvchangement_poids[2];
	int Tame::minitvchangement_seuil[2];
	int Tame::minitvchangement_diviseur[2];
	int Tame::minitvchangement_sortie[2];
	/*F-Initialisation du robot*/

void Tfondation::caract_robot_default(void)
{
		Trobot::initdecalage[0]=0;
		Trobot::initdecalage[1]=0;
		Trobot::initentrer[0]=1; 
		Trobot::initentrer[1]=5;
		Trobot::initmemoire[0]=0;
		Trobot::initmemoire[1]=0;
		Trobot::initpoid[0]=-10;
		Trobot::initpoid[1]=10;
		Trobot::initpositron[0]=20;
		Trobot::initpositron[1]=20;
		Trobot::initseuil1[0]=-500;
		Trobot::initseuil1[1]=500;
		Trobot::initdiviseur_de_sortie[0]=-100;
		Trobot::initdiviseur_de_sortie[1]=100;

		
		Trobot::minitdecalage[0]=0;
		Trobot::minitdecalage[1]=0;
		Trobot::minitentrer[0]=1;
		Trobot::minitentrer[1]=1;
		Trobot::minitmemoire[0]=3;
		Trobot::minitmemoire[1]=3;
		Trobot::minitpositron[0]=5;
		Trobot::minitpositron[1]=5;
		Trobot::minitseuil1[0]=2;
		Trobot::minitseuil1[1]=2;
		Trobot::minitdiviseur_de_sortie[0]=-5;
		Trobot::minitdiviseur_de_sortie[1]=5;


		Tame::initdelaymax[0]=20000;
		Tame::initdelaymax[1]=20000;
		Tame::initmaxnonamelioration[0]=3;
		Tame::initmaxnonamelioration[1]=3;
		
		Tame::initvchangement_poids[0]=1;
		Tame::initvchangement_poids[1]=10;
		Tame::initvchangement_seuil[0]=1;
		Tame::initvchangement_seuil[1]=100;
		Tame::initvchangement_diviseur[0]=1;
		Tame::initvchangement_diviseur[1]=50;
		Tame::initvchangement_sortie[0]=1;
		Tame::initvchangement_sortie[1]=10;


		Tame::minitdelaymax[0]=-1000;
		Tame::minitdelaymax[1]=1000;
		Tame::minitmaxnonamelioration[0]=-5;
		Tame::minitmaxnonamelioration[1]=5;
		
		Tame::minitvchangement_poids[0]=-1;
		Tame::minitvchangement_poids[1]=1;
		Tame::minitvchangement_seuil[0]=-4;
		Tame::minitvchangement_seuil[1]=4;
		Tame::minitvchangement_diviseur[0]=-2;
		Tame::minitvchangement_diviseur[1]=2;
		Tame::minitvchangement_sortie[0]=-10;
		Tame::minitvchangement_sortie[1]=10;
}


void Tfondation::muterrobot(int nombredeparent)
{
	static vector<Trobot*> tabmeilleurrobot(1000,"tabmeilleurrobot");
	static Tmax<int> tabmeilleurpoints;
	static Tmin<int> meilleurpoints;
	static parentencour;
	
	parentencour=0;
	tabmeilleurpoints.init(nombredeparent);
	meilleurpoints.init(1);
	tabmeilleurrobot.clear();

	static int i;
	for(i=0;i<nombredeparent;++i)
	{
		tabmeilleurrobot.push_back(new Trobot*(NULL));
	}
	
	for(i=0;i<Tabrobots.size();++i)
	{
		tabmeilleurpoints.ajoute(Tabrobots.at(i).points);
	}

	for(i=0;i<nombredeparent;++i)
	{
		meilleurpoints.ajoute(tabmeilleurpoints.tabmax.at(i));
	}

	for(i=0;i<nombredeparent;++i)
	{
		tabmeilleurrobot.at(i)=&Tabrobots.at(tabmeilleurpoints.tabpmax.at(i));
	}

	for(i=0;i<Tabrobots.size()-1;++i)
	{
		if(Tabrobots.at(i).points<=meilleurpoints.tabmin.at(0))
		{
			cout<<"robot muter:"<<i<<endl;
			Tabrobots.at(i).init(*tabmeilleurrobot.at(parentencour),"parent"+inttostr(parentencour));
			parentencour++;
		}
		
		
		if(parentencour>=nombredeparent)
		{
			parentencour=0;
		}
	}

};


void Tfondation::deplacerrobot(int temps_restant,bool phase)
{

	static int i;
	static int i2;
	for(i=0;i<Tabrobots.size();i++)
	{

		
		Tabrobots.at(i).reinit();

		Tabrobots.at(i).move();
	
		Tabrobots.at(i).action();
	
		if((Tabrobots.at(i).type=="predateur")&&(phase==true))
		{
		Tabrobots.at(i).ame.action(temps_restant);
		}
		if((Tabrobots.at(i).type=="proie")&&(phase==false))
		{
		Tabrobots.at(i).ame.action(temps_restant);
		}
		
	
	}


};

Tfondation::Tfondation(bool monde_communloc):
Tabmondes(1000,"Tabmondes"),
Tabrobots(1000,"Tabrobots")
{
	monde_commun=monde_communloc;
	if(monde_commun==true)
	{
		Tabmondes.push_back(new Tmonde(&Tabrobots));
	}
}


Tfondation::~Tfondation(void)
{
}

void Tfondation::creer_robot(void)
{
	if(monde_commun==true)
	{
		Tabrobots.at(Tabrobots.size()-1).monde=&(Tabmondes.at(0));
	}
	else
	{
		Tabmondes.push_back(new Tmonde(&Tabrobots));
		Tabrobots.at(Tabrobots.size()-1).monde=&(Tabmondes.at(Tabmondes.size()-1));
	}
}


void Tfondation::detruire_robot(void)
{
	if(monde_commun==false)
	{
		Tabmondes.erase(Tabmondes.size()-1);
		Tabmondes.taille=Tabmondes.taille-1;
	}
}