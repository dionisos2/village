#include<timer.h>


void Ttimer::departpause(int ldurer)
{
	dernieredate=GetTickCount();
	durer=ldurer;
};

void Ttimer::finpause(void)
{
	while((dernieredate+durer)>GetTickCount())
	{
		
	}

	tempperdu=GetTickCount()-(dernieredate+durer);
};

int Ttimer::gettempperdu(void)
{
	return tempperdu;
};

void Tdate::initdate(void)
{	
	long H;
  time(&H);

	annee=(H/31536000);
	jour=((H-(annee*31536000))/86400);
	heure=((H-(annee*31536000)-(jour*86400))/3600);
	min=((H-(annee*31536000)-(jour*86400)-(heure*3600))/60);
	seconde=(H-(annee*31536000)-(jour*86400)-(heure*3600)-(min*60));

	annee=annee+1970;
	jour=jour-8;
	heure=heure+1;
};