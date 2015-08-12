#include"robot.h"

int Trobot::robot_total=0;


Trobot::Trobot():
sortiemonde(5000,"sortiemonde"),
psortiemonde(5000,"psortiemonde"),
entremonde(5000,"entremonde"),
ppositronmonde(5000,"ppositronmonde"),
pentremonde(5000,"pentremonde"),
memoire(5000,"memoire"),
pmemoire(5000,"pmemoire"),
bouffe_a_placer(0)
{
	numrobot=robot_total;
	robot_total++;	
};

void Trobot::vider()
{
	ppositronmonde.clear();
	pentremonde.clear();
	memoire.clear();
	pmemoire.clear();
	Tcerveau::vider();
};

void Trobot::init(Trobot &robotparent,string adresse_fichier)
{
	this->points=0;
	robotparent.save(adresse_fichier);
	this->vider();
	this->load(adresse_fichier);
	

	ame.delaymax+=randomentre(ame.minitdelaymax);
	ame.maxnonamelioration+=randomentre(ame.minitmaxnonamelioration);
	ame.vchangement_poids+=randomentre(ame.minitvchangement_poids);
	ame.vchangement_seuil+=randomentre(ame.minitvchangement_seuil);
	ame.vchangement_diviseur+=randomentre(ame.minitvchangement_diviseur);
	ame.vchangement_sortie+=randomentre(ame.minitvchangement_sortie);

	if(ame.delaymax<=0)
	{
		ame.delaymax=1;
	}

	if(ame.maxnonamelioration<=0)
	{
		ame.maxnonamelioration=1;
	}

	if(ame.vchangement_poids<=0)
	{
		ame.vchangement_poids=1;
	}


	if(ame.vchangement_seuil<=0)
	{
		ame.vchangement_seuil=1;
	}


	if(ame.vchangement_diviseur<=0)
	{
		ame.vchangement_diviseur=1;
	}

	if(ame.vchangement_sortie<=0)
	{
		ame.vchangement_sortie=1;
	}
	
};

void Trobot::load(string nfichier)
{

	int i,i2;
	ifstream fichier( nfichier.c_str());

    if ( fichier )
    {
        
		string ligne;
		int compteur,taille;

        
		/*passe deux ligne*/
		getline(fichier,ligne);
		getline(fichier,ligne);

		/*chargement de la mémoire*/
		getline(fichier,ligne);
		taille=strtoint(ligne);
		
		for(compteur=0;compteur<taille;++compteur)
		{
			getline(fichier,ligne);
			
			this->pmemoire.push_back(new int(strtoint(ligne)));	
		}
	
		/*Chargement d'entremonde*/
		getline(fichier,ligne);	
		getline(fichier,ligne);
		taille=strtoint(ligne);

    for(compteur=0;compteur<taille;++compteur)
		{
			getline(fichier,ligne);
			this->ppositronmonde.push_back(new int(strtoint(ligne)));
			getline(fichier,ligne);
			this->pentremonde.push_back(new int(strtoint(ligne)));
		}

		/*Chargement des sorties*/
		getline(fichier,ligne);
		getline(fichier,ligne);
		taille=strtoint(ligne);

    for(compteur=0;compteur<taille;++compteur)
		{
			getline(fichier,ligne);
			this->psortiemonde.at(compteur)=strtoint(ligne);
		}

		Tcerveau::load(fichier);
    }

	
		
	

	for(i=0;i<Tcerveau::Tabpositrons.size();++i)
	{
		if(Tcerveau::Tabpositrons.at(i).tabentre.size()!=0)
		{
			cout<<"prout 2"<<endl;
			system("pause");
		}

		for(i2=0;i2<Tcerveau::Tabpositrons.at(i).tabpentre.size();++i2)
		{
			Tcerveau::Tabpositrons.at(i).tabentre.push_back(new Tpositron*(&(Tabpositrons.at(Tcerveau::Tabpositrons.at(i).tabpentre.at(i2)))));
		}
	
	}

	for(i=0;i<NBRENTRE;++i)
	{
		Tabpositrons.at(ppositronmonde.at(i)).tabentre.at(pentremonde.at(i))=&(this->entremonde.at(i));
	}


	if(memoire.size()!=0)
	{
		cout<<"prout 3"<<endl;
		system("pause");
	}
	for(i=0;i<memoire.size();++i)
	{
		memoire.push_back(new Tpositron*(&(Tabpositrons.at(pmemoire.at(i)))));
	}

	for(i=0;i<NBRSORTIE;i++)
	{
		sortiemonde.at(i)=&(Tabpositrons.at(psortiemonde.at(i)));
	}

	x=500;
	y=500;
	this->ame.changerdepositron();
	fichier.close();
}


void Trobot::reinit()
{	

	Tcerveau::reinit();
	

	memorise();
	
};



void Trobot::afficherliaison()
{
	int i;
	Tcerveau::afficherliaison();

	cout<<endl<<"entremonde:"<<endl<<endl;

	for(i=0;i<NBRENTRE;++i)
	{
		entremonde.at(i).afficherliaison();
		cout<<endl;
	}
};



void Trobot::memorise()
{

	static int i;
	for(i=resultdecalage;i<memoire.size();++i)
	{
		memoire.at(i)->dejapasser=true;
	}


	static int i2;

	for(i2=memoire.size()-1-resultdecalage;i2>0;--i2)
	{

		memoire.at(i2+resultdecalage)=memoire.at(i2);

	}


};


void Trobot::init()
{
	static int i;
	for(i=0;i<NBRSORTIE;++i)
	{

		sortiemonde.push_back(new Tpositron*);	
		psortiemonde.push_back(new int);	
	}

	Tcerveau::init();
	static int resultmemoire;
	static int position;
	resultmemoire=randomentre(initmemoire);

	resultdecalage=randomentre(initdecalage);

	Tpositron *choix;

	
	for(i=0;i<resultmemoire;++i)
	{
		position=randomentre(0,Tabpositrons.size()-1);
		memoire.push_back(new Tpositron*(&(Tabpositrons.at(position))));
		pmemoire.push_back(new int(position));

	}
	
	for(i=0;i<NBRENTRE;++i)
	{
		entremonde.push_back(new Tpositron(0));
		entremonde.at(i).seuil1=-500000;
		entremonde.at(i).sens_du_seuil=true;
	}

		
	for(i=0;i<NBRSORTIE;++i)
	{
		position=randomentre(0,Tabpositrons.size()-1);
		sortiemonde.at(i)=&Tabpositrons.at(position);
		psortiemonde.at(i)=position;
	}

	

	for(i=0;i<NBRENTRE;++i)
	{
		position=randomentre(0,Tabpositrons.size()-1);

		choix=&Tabpositrons.at(position);
		ppositronmonde.push_back(new int(position));
		
		position=randomentre(0,choix->tabentre.size()-1);

		pentremonde.push_back(new int(position));
		choix->tabentre.at(position)=&entremonde.at(i);
		choix->tabentrefixe.at(position)=true;
		entremonde.at(i).dejapasser=true;

	}



};

void Trobot::save(string nfichier)
{
	ofstream fichier(nfichier.c_str(),ios :: trunc); 
	int i;

	if ( !fichier )
	{ 
		cerr << "Erreur de creation du fichier" << endl; 
		exit(1); 
	}

	fichier<<"ROBOT"<<endl;

	fichier<<"memoire"<<endl;
	fichier<<pmemoire.size()<<endl;
	for(i=0;i<this->pmemoire.size();++i)
	{	
		fichier<<pmemoire.at(i)<<endl;
	}
	
	fichier<<"entrer monde"<<endl;
	fichier<<ppositronmonde.size()<<endl;
	for(i=0;i<this->ppositronmonde.size();++i)
	{
		fichier<<this->ppositronmonde.at(i)<<endl;
		fichier<<this->pentremonde.at(i)<<endl;
	}
	
	fichier<<"sortie monde"<<endl;
	fichier<<NBRSORTIE<<endl;
	for(i=0;i<NBRSORTIE;++i)
	{
		fichier<<this->psortiemonde.at(i)<<endl;
	}
	
	
	Tcerveau::save(fichier);
	fichier.close();
};

