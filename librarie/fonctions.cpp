#include<fonction.h>
#define sqr(x) ((x)*(x))


int randomentre(int *tab)
{
	return (rand()%(abs(tab[1]-tab[0])+1)+tab[0]);
};

int randomentre(int a,int b)
{
	return (rand()%(abs(b-a)+1)+a);
};

bool randomentre()
{
	if(rand()%2==0)
	{
		return true;
	}
	else
	{
		return false;
	}
};


double distances(double x1,double y1,double x2,double y2)
{
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
};

double distances(double x1,double y1)
{
	return sqrt(sqr(x1)+sqr(y1));
};



int strtoint(string str)
{
	int temp;
	istringstream istr(str);
	istr>>temp;
	return temp;
};


string inttostr(int integer)
{
	ostringstream ostr;
	ostr<<integer;
	return ostr.str();
};


bool strtobool(string str)
{
	if(str=="true")
	{
		return true;	
	}
	else
	{
		return false;
	}
};

string booltostr(bool boolean)
{
	string inter;

	if(boolean)
	{
		inter="true";
		return inter;	
	}
	else
	{	
		inter="false";
		return inter;
	}
};


////////////////////////////////////////////////////////////////////////////
void Initaffichage(int argc, char *argv[ ])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

  glutInitWindowSize(640,480);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Virtual Village");

	gluOrtho2D(0,1000,0,1000);
};
