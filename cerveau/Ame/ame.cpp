#include "ame.h"
#include "E:\projet\programmation\c++\proie-predateur\cerveau\cerveau.h"
#include<fonction.h>


Tame::Tame():
tabpositronsfixes(5000,"tabpositronsfixes")
{
};


void Tame::vider()
{
	tabpositronsfixes.clear();
}



void Tame::rafraichir_tabpositronsfixes()
{
	tabpositronsfixes.clear();
	for(int i=0;i<cerveau->Tabpositrons.size();++i)
	{
		
		
		if(cerveau->Tabpositrons.at(i).sortie_fixe==true)
		{
			tabpositronsfixes.push_back(new Tpositron*(&(cerveau->Tabpositrons.at(i))));
			
			
		}
	}
}

void Tame::save(ofstream &fichier)
{
	fichier<<"ame"<<endl;
	fichier<<this->delaymax<<endl;
	fichier<<this->maxnonamelioration<<endl;

	fichier<<this->vchangement_poids<<endl;
	fichier<<this->vchangement_seuil<<endl;
	fichier<<this->vchangement_diviseur<<endl;
	fichier<<this->vchangement_sortie<<endl;

}

void Tame::load(ifstream &fichier)
{
	string ligne;
	getline(fichier,ligne);
	this->delaymax=strtoint(ligne);
	getline(fichier,ligne);
	this->maxnonamelioration=strtoint(ligne);
	
	getline(fichier,ligne);
	this->vchangement_poids=strtoint(ligne);
	getline(fichier,ligne);
	this->vchangement_seuil=strtoint(ligne);
	getline(fichier,ligne);
	this->vchangement_diviseur=strtoint(ligne);
	getline(fichier,ligne);
	this->vchangement_sortie=strtoint(ligne);

}

void Tame::init()
{
	delaymax=randomentre(initdelaymax);
	maxnonamelioration=randomentre(initmaxnonamelioration);

	vchangement_poids=randomentre(initvchangement_poids);
	vchangement_seuil=randomentre(initvchangement_seuil);
	vchangement_diviseur=randomentre(initvchangement_diviseur);
	vchangement_sortie=randomentre(initvchangement_sortie);

	pointeurpoid=NULL;
	pointeurentre=NULL;
	pointeurpentre=NULL;
	pointeurseuil=NULL;
	
	selection=0;
	changerdepositron();
	meilleuramelioration=-50000;
	dernierpoints=cerveau->points;
	delay=0;
};



void Tame::changer_selection()
{
	int chancetotal,choix,nbrselection,total;
	
	nbrselection=7;

	chancetotal=0;
	tabchance[0]=70;
	tabchance[1]=70;
	tabchance[2]=50;
	tabchance[3]=50;
	tabchance[4]=50;
	tabchance[5]=50;
	tabchance[6]=50;

	for(int i=0;i<nbrselection;++i)
	{
		chancetotal+=tabchance[i];
	}

	choix=randomentre(0,chancetotal);

	if((choix>=0)&&(choix<tabchance[0]))
	{
		selection=0;
	}

	for(i=1;i<nbrselection;++i)
	{
		total=0;
		for(int i2=0;i2<i;++i2)
		{
		total+=tabchance[i2];
		}

		if((choix>=total)&&(choix<(total+tabchance[i])))
		{
			selection=i;
		}
	}

	changerdepositron();

};

void Tame::action(int temps_restant)
{
	
	delay++;
	modif=false;
	
	
	if (temps_restant>0)
	{	

		if(delay>=delaymax)
		{
				
			amelioration=cerveau->points-dernierpoints;
			if(meilleuramelioration>=amelioration)
			{
				nonamelioration++;
				cout<<"pas d'amelioration:"<<nonamelioration<<endl;
			}
			else
			{

				enregistrer_meilleur(selection);

			}
			
			if(nonamelioration>=maxnonamelioration)
			{
				cout<<"selectionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn(debut)"<<selection<<endl;
				charger_meilleur(selection);
				changer_selection();
				cout<<"selectionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn(fin)"<<selection<<endl;				

			}
			else
			{		
				changer(selection);
			}
			
			
			delay=0;
			dernierpoints=cerveau->points;
		}
	}



if (temps_restant==0)
{
	if(selection==0)/*poids*/ 
	{
		cout<<"redonne meilleur poids:"<<meilleurpoid<<endl;
		*(pointeurpoid)=meilleurpoid;		
	}
	
	if(selection==1)/*liaison*/ 
	{
		cout<<"redonne meilleur liaison:"<<meilleurliaison<<endl;
		positionpositron=meilleurliaison;
		*(pointeurentre)=&(cerveau->Tabpositrons.at(positionpositron));
		*(pointeurpentre)=positionpositron;
	}

	if(selection==2)/*seuil*/ 
	{
		cout<<"redonne meilleur seuil:"<<meilleurseuil<<endl;
		*(pointeurseuil)=meilleurseuil;
	}

	if(selection==3)/*diviseur*/ 
	{
		cout<<"redonne meilleur diviseur:"<<meilleurdiviseur<<endl;
		*(pointeurdiviseur)=meilleurdiviseur;
	}
	
	if(selection==4)/*sortie_fixe*/ 
	{
		cout<<"redonne meilleur etat:"<<meilleursortie_fixe<<endl;
		*(pointeursortie_fixe)=meilleursortie_fixe;
	}

	if(selection==5)/*sortie*/ 
	{
		cout<<"redonne meilleur sortie:"<<meilleursortie<<endl;
		*(pointeursortie)=meilleursortie;
	}

	if(selection==6)/*activer_seuil*/ 
	{
		cout<<"redonne une meilleur activation du seuil:"<<meilleuractiverseuil<<endl;
		*(pointeur_activerseuil)=meilleuractiverseuil;
	}

}



};

  



void Tame::changerdepositron()
{
	int position;
		
	nonamelioration=0;
	static Tpositron *positron;
	positron=&(cerveau->Tabpositrons.at(randomentre(0,cerveau->Tabpositrons.size()-1)));
	
		

	cout<<"changement de positron:"<<selection<<endl;
	
	
	if (selection==0)/*poids*/ 
	{
		position=randomentre(0,positron->tabpoid.size()-1);
		pointeurpoid=&(positron->tabpoid.at(position));
		meilleurpoid=*(pointeurpoid);
		cout<<"le poids selectione par l'ame a changer:("<<positron->numpositron<<";"<<position<<")"<<endl;
	}
	
	
	if (selection==1)/*liaison*/ 
	{
		positionpositron=randomentre(0,positron->tabpentre.size()-1);
		pointeurentre=&(positron->tabentre.at(positionpositron));
		pointeurpentre=&(positron->tabpentre.at(positionpositron));

		

		if((*positron).tabentrefixe.at(positionpositron)==false)
		{
			meilleurliaison=positionpositron;
			cout<<"la liaison selectione par l'ame a changer:("<<positron->numpositron<<";"<<positionpositron<<")"<<endl;
		}
		else
		{
			changer_selection();
		}
		
	}
	
	if (selection==2)/*seuil*/ 
	{
		pointeurseuil=&(positron->seuil1);		
		meilleurseuil=*(pointeurseuil);
		cout<<"le seuil selectione par l'ame a changer:"<<positron->numpositron<<endl;
	}

	if (selection==3)/*diviseur*/ 
	{
		pointeurdiviseur=&(positron->diviseur_de_sortie);		
		meilleurdiviseur=*(pointeurdiviseur);
		cout<<"le diviseur selectione par l'ame a changer:"<<positron->numpositron<<endl;
	}

	if (selection==4)/*sortie_fixe*/ 
	{	
		pointeursortie_fixe=&(positron->sortie_fixe);		
		meilleursortie_fixe=*(pointeursortie_fixe);
		cout<<"l'etat selectione par l'ame a changer:"<<positron->numpositron<<endl;
	}
	
	if (selection==5)/*sortie*/ 
	{
		rafraichir_tabpositronsfixes();
	

		
		if(tabpositronsfixes.size()==0)
		{
			changer_selection();
		}
		else
		{
			positron=(tabpositronsfixes.at(randomentre(0,tabpositronsfixes.size()-1)));
			pointeursortie=&(positron->vsortie);		
			meilleursortie=*(pointeursortie);
			cout<<"la sortie selectione par l'ame a changer:"<<positron->numpositron<<endl;
		}
	}



	if (selection==6)/*activer seuil*/ 
	{
		pointeur_activerseuil=&(positron->activerseuil);		
		meilleuractiverseuil=*(pointeur_activerseuil);
		cout<<"l'activation du seuil selectione par l'ame a changer:"<<positron->numpositron<<endl;
	}





}




void Tame::enregistrer_meilleur(int aselection)
{


	if(selection==0)/*poids*/ 
	{
		cout<<"nouvelle amelioration de poids:"<<meilleuramelioration<<"->"<<amelioration<<endl;
		nonamelioration=0;
		meilleuramelioration=amelioration;
		meilleurpoid=*(pointeurpoid);
		cout<<"meilleur poids:"<<meilleurpoid<<"->"<<*(pointeurpoid)<<endl;
	}

	if(selection==1)/*liaison*/ 
	{
		cout<<"nouvelle amelioration de liaison:"<<meilleuramelioration<<"->"<<amelioration<<endl;		
		nonamelioration=0;
		meilleuramelioration=amelioration;
		meilleurliaison=positionpositron;
		cout<<"meilleur liaison:"<<meilleurliaison<<"->"<<positionpositron<<endl;
	}

	if(selection==2)/*seuil*/ 
	{
		cout<<"nouvelle amelioration de seuil:"<<meilleuramelioration<<"->"<<amelioration<<endl;		
		nonamelioration=0;
		meilleuramelioration=amelioration;
		meilleurseuil=*(pointeurseuil);
		cout<<"meilleur seuil:"<<meilleurseuil<<"->"<<positionpositron<<endl;
	}

	if(selection==3)/*diviseur*/ 
	{
		cout<<"nouvelle amelioration de diviseur:"<<meilleuramelioration<<"->"<<amelioration<<endl;		
		nonamelioration=0;
		meilleuramelioration=amelioration;
		meilleurdiviseur=*(pointeurdiviseur);
		cout<<"meilleur diviseur:"<<meilleurdiviseur<<"->"<<positionpositron<<endl;
	}

	if(selection==4)/*sortie_fixe*/ 
	{
		cout<<"nouvelle amelioration de l'etat:"<<meilleuramelioration<<"->"<<amelioration<<endl;		
		nonamelioration=0;
		meilleuramelioration=amelioration;
		meilleursortie_fixe=*(pointeursortie_fixe);
		cout<<"meilleur etat:"<<meilleursortie_fixe<<"->"<<positionpositron<<endl;
	}

	

	if(selection==5)/*sortie*/ 
	{
		cout<<"nouvelle amelioration de la sortie:"<<meilleuramelioration<<"->"<<amelioration<<endl;		
		nonamelioration=0;
		meilleuramelioration=amelioration;
		meilleursortie=*(pointeursortie);
		cout<<"meilleur sortie:"<<meilleursortie<<"->"<<positionpositron<<endl;
	}

	
	if(selection==6)/*activer seuil*/ 
	{
		cout<<"nouvelle amelioration de l'activation du seuil:"<<meilleuramelioration<<"->"<<amelioration<<endl;		
		nonamelioration=0;
		meilleuramelioration=amelioration;
		meilleuractiverseuil=*(pointeur_activerseuil);
		cout<<"meilleur activation du seuil:"<<meilleuractiverseuil<<"->"<<positionpositron<<endl;
	}






};


void Tame::charger_meilleur(int aselection)
{
	if(selection==0)/*poids*/ 
	{
		*(pointeurpoid)=meilleurpoid;
		
	}

	if(selection==1)/*liaison*/ 
	{
		positionpositron=meilleurliaison;
		*(pointeurentre)=&(cerveau->Tabpositrons.at(positionpositron));
		*(pointeurpentre)=positionpositron;
	
	}

	if(selection==2)/*seuil*/ 
	{
		*(pointeurseuil)=meilleurseuil;
		
	}

	if(selection==3)/*diviseur*/ 
	{
		*(pointeurdiviseur)=meilleurdiviseur;
	}

	if(selection==4)/*sortie_fixe*/ 
	{
		*(pointeursortie_fixe)=meilleursortie_fixe;
	}

	if(selection==5)/*sortie*/ 
	{
		*(pointeursortie)=meilleursortie;
	}

	if(selection==6)/*activer_seuil*/ 
	{
		*(pointeur_activerseuil)=meilleuractiverseuil;
	}
};


void Tame::changer(int aselection)
{

	if(selection==0)/*poids*/ 
	{
		*(pointeurpoid)+=randomentre(-vchangement_poids,vchangement_poids);
		cout<<"changer poid:"<<*(pointeurpoid)<<endl;
	}

	if(selection==1)/*liaison*/ 
	{
		int position;
		position=randomentre(0,cerveau->Tabpositrons.size()-1);
		*(pointeurentre)=&cerveau->Tabpositrons.at(position);
		*(pointeurpentre)=position;
		cout<<"changer liaison:"<<position<<endl;
	}

	if(selection==2)/*seuil*/ 
	{
		*(pointeurseuil)+=randomentre(-vchangement_seuil,vchangement_seuil);
		cout<<"changer seuil:"<<*(pointeurseuil)<<endl;
	}

	if(selection==3)/*diviseur*/ 
	{
		*(pointeurdiviseur)+=randomentre(-vchangement_diviseur,vchangement_diviseur);
		cout<<"changer diviseur:"<<*(pointeurdiviseur)<<endl;
	}

	if(selection==4)/*sortie_fixe*/ 
	{
		*(pointeursortie_fixe)=!(*(pointeursortie_fixe));
		cout<<"changer d'état"<<*(pointeursortie_fixe)<<endl;
	}

	if(selection==5)/*sortie*/ 
	{
		*(pointeursortie)+=randomentre(-vchangement_sortie,vchangement_sortie);
		cout<<"changer sortie"<<*(pointeursortie)<<endl;
	}

	if(selection==6)/*activer_seuil*/ 
	{
		*(pointeur_activerseuil)=!(*(pointeur_activerseuil));
		cout<<"changer d'activation du seuil"<<*(pointeur_activerseuil)<<endl;
	}


};



