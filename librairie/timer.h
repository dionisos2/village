#include<iostream>
#include<windows.h>
#include<winbase.h>
#include<fvector.h>
#include<time.h>


using namespace std;


class Ttimer
{
	public:
	void departpause(int ldurer);
	void finpause(void);
	int gettempperdu(void);

	private:
	int dernieredate;
	int durer,tempperdu;
};



class Tdate
{
	public:
	void initdate(void);

	int annee,jour,heure,min,seconde;
};




template <class T>
class Tmax
{
	public:
	void init(int taille);
	void ajoute(const T valeur);
	Tmax(void);

	vector<T> tabmax;
	vector<int> tabpmax;
	int encour;
};


template <class T>
Tmax<T>::Tmax(void):
tabmax(1000,"tabmax"),
tabpmax(1000,"tabpmax")
{
};

template <class T>
void Tmax<T>::init(int taille)
{	
	static int i;
	tabmax.clear();
	tabpmax.clear();

	for(i=0;i<taille;++i)
	{
		tabmax.push_back((new T(0)));
		tabpmax.push_back((new int(0)));
	}

	encour=0;
};


template <class T>
void Tmax<T>::ajoute(const T valeur)
{
	static int i,pmin;
	
	if(encour<tabmax.size())
	{
		tabmax.at(encour)=valeur;
		tabpmax.at(encour)=encour;
	}
	else
	{
		pmin=0;

		for(i=1;i<tabmax.size();++i)
		{
			if(tabmax.at(i)<tabmax.at(pmin))
			{
				pmin=i;
			}
		}

		if(tabmax.at(pmin)<valeur)
		{
			tabmax.at(pmin)=valeur;
			tabpmax.at(pmin)=encour;
		}
	}

	encour++;
};







template <class T>
class Tmin
{
	public:
	void init(int taille);
	void ajoute(const T valeur);
	Tmin(void);

	vector<T> tabmin;
	vector<int> tabpmin;
	int encour;
};


template <class T>
Tmin<T>::Tmin(void):
tabmin(1000,"tabmin"),
tabpmin(1000,"tabpmin")
{
};


template <class T>
void Tmin<T>::init(int taille)
{	
	static int i;
	tabmin.clear();
	tabpmin.clear();

	for(i=0;i<taille;++i)
	{
		tabmin.push_back((new T(0)));
		tabpmin.push_back((new int(0)));
	}

	encour=0;
};


template <class T>
void Tmin<T>::ajoute(const T valeur)
{
	static int i,pmax;
	
	if(encour<tabmin.size())
	{
		tabmin.at(encour)=valeur;
		tabpmin.at(encour)=encour;
	}
	else
	{
		pmax=0;

		for(i=1;i<tabmin.size();++i)
		{
			if(tabmin.at(i)>tabmin.at(pmax))
			{
				pmax=i;
			}
		}

		if(tabmin.at(pmax)>valeur)
		{
			tabmin.at(pmax)=valeur;
			tabpmin.at(pmax)=encour;
		}
	}

	encour++;
};