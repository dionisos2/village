#include<iostream>
#include<timer.h>
#include<math.h>
#include<string>
#include<fvector.h>
#include<fonction.h>
#include "fondation.h"
#include"monde.h"


void rafraichir(void);
void mainglut(void);
void depart();
void sauver_resultat();

typedef vector<int> vector_int;
typedef vector<bool> vector_bool;

ofstream fichier_resultat("resultat.txt",ios :: trunc);
int total_points_predateur,total_points_proie;


Tfondation fondation(true);




void sauver_resultat()
{
	
	if ( !fichier_resultat )
	{ 
		cerr << "Erreur de creation du fichier" << endl;
		exit(1); 
	}
	
	fichier_resultat<<"points predateurs:"<<total_points_predateur<<endl;
	fichier_resultat<<"points proie:"<<total_points_proie<<endl;
	
}




void depart()
{
	static int i;

	for(i=0;i<fondation.Tabrobots.size();i++)
	{
		fondation.Tabrobots.at(i).depart(true);
	}


};




void rafraichir()
{	
	static int rx;
	static int ry;
	
	glClearColor(0,0,0,0); // selectionne la couleur noire (qui est celle par défaut)
	glClear(GL_COLOR_BUFFER_BIT); // efface le frame buffer
	
	total_points_proie=0;
	total_points_predateur=0;
	static int i;

	
	if(fondation.monde_commun==false)
	{	
		rx=fondation.Tabrobots.at(0).x;
		ry=fondation.Tabrobots.at(0).y;
		
			if (fondation.Tabrobots.at(i).type=="proie")
			{
			glColor3d(0,5,0); 
			rx=fondation.Tabrobots.at(i).x;
			ry=fondation.Tabrobots.at(i).y;
	
			glBegin(GL_QUADS);
			glVertex2i(rx-10,ry-10); 
			glVertex2i(rx+10,ry-10); 
			glVertex2i(rx+10,ry+10); 
			glVertex2i(rx-10,ry+10);
			glEnd();
			
			}
		

			if (fondation.Tabrobots.at(i).type=="predateur")
			{
			glColor3d(5,0,0); 
			
			rx=fondation.Tabrobots.at(i).x;
			ry=fondation.Tabrobots.at(i).y;
	
			glBegin(GL_QUADS);
			glVertex2i(rx-10,ry-10); 
			glVertex2i(rx+10,ry-10); 
			glVertex2i(rx+10,ry+10); 
			glVertex2i(rx-10,ry+10);
			glEnd();
		
			}
	}
	else
	{

		for(i=0;i<fondation.Tabrobots.size();i++)
		{
			if (fondation.Tabrobots.at(i).type=="proie")
			{
			glColor3d(0,5,0); 
			rx=fondation.Tabrobots.at(i).x;
			ry=fondation.Tabrobots.at(i).y;
	
			glBegin(GL_QUADS);
			glVertex2i(rx-10,ry-10); 
			glVertex2i(rx+10,ry-10); 
			glVertex2i(rx+10,ry+10); 
			glVertex2i(rx-10,ry+10);
			glEnd();
			
			}
		

			if (fondation.Tabrobots.at(i).type=="predateur")
			{
			glColor3d(5,0,0); 
			
			rx=fondation.Tabrobots.at(i).x;
			ry=fondation.Tabrobots.at(i).y;
	
			glBegin(GL_QUADS);
			glVertex2i(rx-10,ry-10); 
			glVertex2i(rx+10,ry-10); 
			glVertex2i(rx+10,ry+10); 
			glVertex2i(rx-10,ry+10);
			glEnd();
		
			}
			
		}
	}
	/*glBegin(GL_QUADS);
	glVertex2i(250,500); 
	glVertex2i(300,500); 
	glVertex2i(300,999); 
	glVertex2i(250,999);
	glEnd();*/
    

	for(i=0;i<fondation.Tabrobots.size();i++)
	{	
		rx=fondation.Tabrobots.at(i).x;
		ry=fondation.Tabrobots.at(i).y;
		cout<<i<<": "<<rx<<"/"<<ry<<"->"<<fondation.Tabrobots.at(i).points<<endl;
		if(fondation.Tabrobots.at(i).type=="proie")
		{
			total_points_proie+=fondation.Tabrobots.at(i).points;		
		}

		if(fondation.Tabrobots.at(i).type=="predateur")
		{
			total_points_predateur+=fondation.Tabrobots.at(i).points;		
		}
	}


	cout<<"points total recolte (predateur):"<<total_points_predateur<<endl;
	cout<<"points total recolte (proie):"<<total_points_proie<<endl;
	

	glFinish();
	 // affichage de la scène
	

};




void main(int argc, char *argv[ ])
{
	
	srand(unsigned(time(NULL)));
	

	Initaffichage(argc,argv);
	glutDisplayFunc(mainglut);

	glutMainLoop();

	fichier_resultat.close();
}



void mainglut()
{
	static bool initialisation=true,phase=true;

	static int Npredateurs=0,Nproies=0;
	static int Ngeneration=0,generation=0,durergeneration,durerpause;
	static int bouffedepart,nombredeparent,temp_blocage_max,temp_blocage,ancien_bouffe,durer_choix_robot,temp_avec_obs;
	static Ttimer timer1;
	static int choix,choixrobot;
	string fichier;
	if(initialisation==true)
	{
		initialisation=false;	
	
		/*D-creer robot*/
		fondation.caract_robot_default();

		cout<<"Combien de predateurs desirez vous creer"<<endl;
		cin>>Npredateurs;
		cout<<"Combien de proies desirez vous creer"<<endl;
		cin>>Nproies;
	

		int i;
		for(i=0;i<Npredateurs;++i)
		{
			fondation.Tabrobots.push_back(new Tpredateur());		
			fondation.creer_robot();		
		}	

		for(i=0;i<Nproies;++i)
		{
			fondation.Tabrobots.push_back(new Tproie());		
			fondation.creer_robot();		
		}	
		
		/*F-creer robot*/
		for(i=0;i<(Nproies+Npredateurs);++i)
		{
			fondation.Tabrobots.at(i).init();
		}
		
		for(i=0;i<(Nproies+Npredateurs);++i)
		{
			fondation.Tabrobots.at(i).afficherliaison();
		}


		cout<<"Combien de temps par generation desirez vous ??"<<endl;
		/*cin>>durergeneration;*/
		durergeneration=50000;
		fichier_resultat<<"temps par generation:"<<endl;
		fichier_resultat<<durergeneration<<endl;

		cout<<"Combien de bouffe au depart desirez vous ??"<<endl;
		/*cin>>bouffedepart;*/
		bouffedepart=10;
		fichier_resultat<<"bouffe au depart:"<<endl;
		fichier_resultat<<bouffedepart<<endl;		
		
	

		cout<<"Combien de parent par generation desirez vous ??"<<endl;
		/*cin>>nombredeparent;*/
		nombredeparent=4;
		fichier_resultat<<"parent par generation"<<endl;
		fichier_resultat<<nombredeparent<<endl;

		cout<<"qu'elle durer de blocage avant un changement de generation desirez vous ??"<<endl;
		/*cin>>temp_blocage_max;*/
		temp_blocage_max=50000;
		fichier_resultat<<"temps blocage max"<<endl;
		fichier_resultat<<temp_blocage_max<<endl;

		cout<<"durer d'evaluation des parent ??"<<endl;
		/*cin>>temp_blocage_max;*/
		durer_choix_robot=10000;
		fichier_resultat<<"temps evaluation parent"<<endl;
		fichier_resultat<<durer_choix_robot<<endl;

		fichier_resultat<<"bouffe:"<<endl;

		depart();
		
		
	}

/*D-boucle de générations*/
	static int heure=0;
	

	if(heure>=durergeneration)
	{
		/*if(total_points_predateur>=40000)
		{
			Ngeneration=generation+1;
			cout<<"prout"<<endl;
			PAUSE;
		}*/
		++generation;
		cout<<"generation->"<<generation<<endl;
		sauver_resultat();

		depart();
		
		heure=0;
		//phase=!phase;
	}

	heure++;

	

	if(generation>=Ngeneration)
	{
		Ngeneration=0;
		cout<<"vous etes a la generation "<<generation<<endl;
		

		/*D-enregistrement d'un robot*/
		/*cout<<"vouler vous enregistrer un robot non:0 oui:1"<<endl;
		cin>>choix;
				
		while(choix==1)
		{
			

			cout<<"dans quel ficher?"<<endl;
			cin>>fichier;

			cout<<"choisir le robot a enregistrer"<<endl;
			cin>>choixrobot;

			Tabrobots[choixrobot].save(fichier);
			

			

			cout<<"vouler vous enregistrer un autre robot? non:0 oui:1"<<endl;
			cin>>choix;

			
		}
		choix=0;*/
		/*F-enregistrement d'un robot*/

		
		/*D-chargement d'un robot*/
		cout<<"vouler vous charger un robot non:0 oui:1"<<endl;
		cin>>choix;

			while(choix==1)
			{
			

				cout<<"A partir de quel ficher?"<<endl;
				cin>>fichier;

				cout<<"choisir le robot a charger"<<endl;
				cin>>choixrobot;
			
				
				
				fondation.Tabrobots.at(choixrobot).vider();
				fondation.Tabrobots.at(choixrobot).load(fichier);
			

			

				cout<<"vouler vous charger un autre robot? non:0 oui:1"<<endl;
				cin>>choix;

			
			}

		/*F-chargement d'un robot*/
	
		cout<<"combien de generation vouler vous attendre ??"<<endl;
		cin>>Ngeneration;
		Ngeneration+=generation;
			
		cout<<"quel durer en milliseconde vouler vous attendre par unitées de temp"<<endl;
		cin>>durerpause;
		
		if(durerpause>0)
		{
		cout<<"pendant combien de temp vouler vous observer?"<<endl;
		cin>>temp_avec_obs;
		}
			
	}

	if(temp_avec_obs<=0)
	{
		durerpause=0;
	}
	temp_avec_obs--;

	timer1.departpause(durerpause);

	
	fondation.deplacerrobot(durergeneration-heure-durer_choix_robot,phase);
	

	

	glFinish();
	glutPostRedisplay();
	
	

		
	if(durerpause>0)
	{
		cout<<generation<<"/"<<heure<<endl;
		rafraichir();
		timer1.finpause();
	}			
	
	total_points_predateur=0;
	total_points_proie=0;

	if(heure==durergeneration-durer_choix_robot)
	{
		depart();
	}

	for(int i=0;i<fondation.Tabrobots.size();i++)
	{	
		if(fondation.Tabrobots.at(i).type=="proie")
		{
			total_points_proie+=fondation.Tabrobots.at(i).points;		
		}

		if(fondation.Tabrobots.at(i).type=="predateur")
		{
			total_points_predateur+=fondation.Tabrobots.at(i).points;		
		}
		
		if (((heure%fondation.Tabrobots.at(i).ame.delaymax)==0)&&(heure<=durergeneration-durer_choix_robot))
		{

			fondation.Tabrobots.at(i).depart(false);			

		}

	}
	
	
	
	
	
	
	
	if((total_points_predateur+total_points_proie)==ancien_bouffe)
	{
		temp_blocage++;

		if((temp_blocage==temp_blocage_max)&&(heure>=durergeneration-durer_choix_robot))
		{

			for(i=0;i<fondation.Tabrobots.size();i++)
			{
				fondation.Tabrobots.at(i).depart(false);
			}

		}




		
	}
	else
	{
		temp_blocage=0;
		ancien_bouffe=total_points_predateur+total_points_proie;
	}


	if ((heure%10000)==0)
	{
		cout<<heure<<endl;
	}

/*F-boucle de générations*/

};
