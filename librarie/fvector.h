#ifndef _fvector_
#define _fvector_

#include<iostream>
#include<string>

using namespace std;

class Tpositron;

template<class T>
class vector
{
  public:
    T **tab;
	  mutable string nom;
	  int taille,reserve;
    bool tabdim_init,prevenir_quand_realloc,informer_erreur_alloc,informer_depassement_de_tab,prevenir_quand_deja_erase;
    int tabdim_vinit;

    vector(int areserve,string anom);
		~vector(void);
    //vector(string anom="inconnue",int areserve=0);
	  int tabdim(int areserve);
    void mode(string choix);
    int push_back(T *element);
    T& at(int position);
    void clear(void);
    void erase(int position);
    void afficher(bool avec_reserve=true);
    int size(void);
    void init(int areserve,string anom);
		void add(int position,T *element);
};  

template <class T>
void vector<T>::add(int position,T *element)
{
	if(reserve>position)
  {
    tab[position]=element;
  }
	else
	{
		cout<<"pas beau"<<endl;
		system("pause");
	}
}


template <class T>
vector<T>::~vector(void)
{
	clear();
	free(tab);
}


template <class T>
int vector<T>::size(void)
{
  return taille;
}

template <class T>
void vector<T>::afficher(bool avec_reserve)
{
  int i;
  cout<<nom<<endl;
  cout<<"taille:"<<taille<<endl;
  cout<<"reserve:"<<reserve<<endl;
  for(i=0;i<taille;++i)
  {
    if(tab[i]!=NULL)
    {
      //cout<<this->at(i)<<"/";
      cout<<"+"<<"/";
    }
    else
    {
      cout<<"#"<<"/";
    }
  }

  if(avec_reserve)
  {
    for(;i<reserve;++i)
    {
      cout<<"#"<<"/";
    }
  }
};

template <class T>
void vector<T>::clear(void)
{
  for(int i=0;i<taille;++i)
  {
    if(tab[i]!=NULL)
    {
      erase(i);
    }
  }
  taille=0;
	
};

template <class T>
T& vector<T>::at(int position)
{
  if(position<taille)
  {
    if(tab[position]!=NULL)
    {
      return (*tab[position]);
    }
    else
    {
      cout<<nom<<".at("<<position<<") est vide"<<endl;
      system("pause");
    }
  }
  else
  {
    if(informer_depassement_de_tab)
    {
      cout<<nom<<".at("<<position<<") depasse du tableau"<<endl;
      system("pause");
    }
  }
  return *tab[0];
}

template <class T>
void vector<T>::erase(int position)
{
  if(position<taille)
  {
    if(tab[position]!=NULL)
    {
			//cout<<nom<<".erase("<<position<<")"<<endl;
      delete tab[position];
			//cout<<"delete"<<endl;
      tab[position]=NULL;
			//cout<<"NULL"<<endl;
			
    }
    else
    {
      if(prevenir_quand_deja_erase)
      {
        cout<<nom<<".erase("<<position<<") est deja erase"<<endl;
        system("pause");
      }
    }
  }
  else
  {
    if(informer_depassement_de_tab)
    {
      cout<<nom<<".erase("<<position<<") depasse du tableau"<<endl;
      system("pause");
    }
  }
}


template <class T>
void vector<T>::init(int areserve,string anom)
{
  mode("debug");
  tabdim(areserve);  
};

template <class T>
vector<T>::vector(int areserve,string anom):
nom(anom),
tab(NULL),
taille(0),
reserve(0)
{	
	//cout<<nom<<".create("<<areserve<<")"<<endl;
  init(areserve,anom);
};

/*template <class T>
vector<T>::vector(string anom,int ataille):
nom(anom),
tab(NULL),
taille(0),
reserve(0)
{
  init(ataille,anom);
};*/

template <class T>
int vector<T>::push_back(T *element)
{
  int test;
  if(reserve>taille)
  {
    tab[taille]=element;
  }
  else
  {
    test=tabdim(taille+10);
    tab[taille]=element;
		cout<<nom<<":depassement de la reserve"<<endl;
		system("pause");
  }
  ++taille;
  return test;
}

template <class T>
int vector<T>::tabdim(int areserve)
{
  if(tab==NULL)
  {
	  tab = (T**)malloc(areserve * sizeof(T*));
  }
  else
  {
    /*T **newtab;
    newtab=(T**)realloc(tab,areserve);
    if(newtab!=tab)
    {
      if(prevenir_quand_realloc)
      {
        cout<<nom<<" a changer d'emplacement memoire"<<endl;
        system("pause");
      }
    }
    tab=newtab;*/
		cout<<nom<<": tentative de reallocation"<<endl;
		system("pause");
  }
  
  if(tab==NULL)
  {
    if(informer_erreur_alloc)
    {
      cout<<nom<<" n'a pas reussi a s'allouer correctement a cause d'un manque de memoire"<<endl;
      system("pause");
    }
    return (-1);
  }
  else
  {
    reserve=areserve;
  }

  if(tabdim_init)
  {
    //memset(tab+(taille)*sizeof(T),tabdim_vinit,ataille * sizeof(T*));
  }
  
  return 0;
};

template <class T>
void vector<T>::mode(string choix)
{
  if(choix=="propre")
  {
    prevenir_quand_realloc=false;
    tabdim_init=true;
    tabdim_vinit=0;
    informer_erreur_alloc=false;
    prevenir_quand_deja_erase=false;
  }

  if(choix=="performant")
  {
    prevenir_quand_realloc=false;
    tabdim_init=false;
    prevenir_quand_realloc=false;
    informer_erreur_alloc=false;
    prevenir_quand_deja_erase=false;
  }
  
  if(choix=="debug")
  {
    prevenir_quand_realloc=true;
    tabdim_init=true;
    tabdim_vinit=0;
    informer_erreur_alloc=true;
    informer_depassement_de_tab=true;
    prevenir_quand_deja_erase=true;
  }
}


#endif