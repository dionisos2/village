#ifndef _ame_
#define _ame_

#include <iostream>
#include<fonction.h>
#include<fvector.h>


using namespace std;
class Tcerveau;
class Tpositron;


class Tame
{
public:

Tcerveau *cerveau;

void action(int temps_restant);
void init(void);
void changerdepositron(void);
void save(ofstream &fichier);
void load(ifstream &fichier);
void enregistrer_meilleur(int aselection);
void charger_meilleur(int aselection);
void changer(int aselection);
void changer_selection(void);
void rafraichir_tabpositronsfixes(void);
void vider(void);
Tame(void);

static int initdelaymax[2],initmaxnonamelioration[2];
static int initvchangement_poids[2],initvchangement_seuil[2],initvchangement_diviseur[2],initvchangement_sortie[2];

static int minitdelaymax[2],minitmaxnonamelioration[2];
static int minitvchangement_poids[2],minitvchangement_seuil[2],minitvchangement_diviseur[2],minitvchangement_sortie[2];

int meilleuramelioration,dernierpoints;
int delaymax,maxnonamelioration,vchangement_poids,vchangement_seuil,vchangement_diviseur,vchangement_sortie;
int delay,amelioration,nonamelioration;
bool modif;



Tpositron **pointeurentre;
int positionpositron;


int *pointeurpoid,meilleurpoid;
int *pointeurpentre,meilleurliaison;
int *pointeurseuil,meilleurseuil;
int *pointeurdiviseur,meilleurdiviseur;
int *pointeursortie,meilleursortie;
bool *pointeursortie_fixe,meilleursortie_fixe;
bool *pointeur_activerseuil,meilleuractiverseuil;	


int selection;
int tabchance[10];
vector<Tpositron*> tabpositronsfixes;  
};

#endif