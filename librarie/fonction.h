/*#ifndef _fonction_
#define _fonction_*/


#include <iostream>
#include <math.h>
#include <windows.h>
#include <gl\gl.h>
#include <gl\glut.h>
#include <sstream>
#include <string>


using namespace std;

int randomentre(int *tab);
int randomentre(int a,int b);
bool randomentre(void);

double distances(double x1,double y1,double x2,double y2);
double distances(double x1,double y1);

int strtoint(string str);
string inttostr(int integer);
bool strtobool(string str);
string booltostr(bool boolean);

void Initaffichage(int argc, char *argv[ ]);
void Display();

/*#endif*/