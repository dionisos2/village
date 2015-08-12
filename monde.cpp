#include"monde.h"

Tmonde::Tmonde(vector<Trobot>* Tabprobotsloc)
{
	Tabprobots=Tabprobotsloc;
};

void Tanimaux::move(void)
{
	static int entreT;
	entreT=0;

	static int i;

	/*entremonde.at(entreT).vsortie=randomentre(-500,500);
	++entreT;*/
	for(i=0;i<monde->Tabprobots->size();++i)
	{
		entremonde.at(entreT).vsortie=monde->Tabprobots->at(i).x-x;
		++entreT;
		entremonde.at(entreT).vsortie=monde->Tabprobots->at(i).y-y;
		++entreT;
	}
		
	
	
	for(i=entreT;i<NBRENTRE;i++)
	{
		entremonde.at(i).vsortie=0;
	}
	

	static int xmem;
	static int ymem;
	static int vitessecourante;
	static double rapport;

	
	xmem=sortiemonde.at(0)->sortie();
	ymem=sortiemonde.at(1)->sortie();


	vitessecourante=distances(xmem,ymem);
	if(vitessecourante<=Vmax)
	{
		x+=xmem;
		y+=ymem;
	}
	else
	{	 
		x+=(int)((xmem*Vmax)/vitessecourante);
		y+=(int)((ymem*Vmax)/vitessecourante);
	}
	
	// mur
	/*if(((250<x)&&(x<280))&&((500<y)&&(y<999)))
	{
	x=250;
	};
	if(((280<x)&&(x<300))&&((500<y)&&(y<999)))
	{
	x=300;
	};*/

	


	if(x<0)
	{
		x=0;
	};

	if(x>999)
	{
		x=999;
	};

	if(y<0)
	{
		y=0;
	};

	if(y>999)
	{
		y=999;
	};

}

void Tproie::action(void)
{
	for(int i=0;i<monde->Tabprobots->size();++i)
	{
		if(monde->Tabprobots->at(i).type=="predateur")
		{
			if(distances(x-monde->Tabprobots->at(i).x,y-monde->Tabprobots->at(i).y)<30)
			{
				x=randomentre(100,500);
				y=randomentre(100,500);
			}
			else
			{
				points++;
			}
		}
	}
}



void Tproie::depart(bool remise_a_zero)
{
	x=250;
	y=500;
	if(remise_a_zero)
	{
		points=0;
	}
}


void Tpredateur::depart(bool remise_a_zero)
{
	x=750;
	y=500;
	if(remise_a_zero)
	{
		points=0;
	}
}



void Tpredateur::action(void)
{
	for(int i=0;i<monde->Tabprobots->size();++i)
	{
		if(monde->Tabprobots->at(i).type=="proie")
		{
			if(distances(x-monde->Tabprobots->at(i).x,y-monde->Tabprobots->at(i).y)<30)
			{
				points++;
			}
		}
	}
};

Tpredateur::Tpredateur(void)
{
	type="predateur";
}

Tproie::Tproie(void)
{
	type="proie";
}
