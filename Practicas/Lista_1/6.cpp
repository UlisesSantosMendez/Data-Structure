#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void Pedir_expresion (char e[30])
{
	cout<<"Ingresa la expresion:"<<endl;
	cin>>e;
}

void Evaluar_delimitadores (char e[30])
{
	char delimitadores[6] = {'(', ')', '{' , '}', '[', ']'};
	int n = strlen(e);
	int i;
	int c_p[2];
	c_p[0] = 0;
	int c_c[2];
	c_c[0] = 0;
	int c_ll[2];
	c_ll[0] = 0;
	for (i = 0; i<n; i++)
	{
		switch(e[i])
		{
			case '(':
				c_p[0]++;
				c_p[1] = i+1;
			break;
			case ')':
				c_p[0]--;
			break;
			case '[':
				c_c[0]++;
				c_c[1] = i+1;
			break;
			case ']':
				c_c[0]--;
			break;
			case '{':
				c_ll[0]++;
				c_ll[1] = i+1;
			break;
			case '}':
				c_ll[0]--;
			break;
		}

	}
	system("cls");
	cout<<e<<endl;
	if (c_p[0] == 0 && c_c[0] == 0 && c_ll[0] == 0)
	{
		cout<<"La expresion no tiene errores"<<endl;
	}
	else
	{
		if (c_p[0] > 0)
		{
			for (i = 0; i<c_p[1]-1; i++)
			{
				cout<<" ";
			}
			cout<<"^"<<endl;
			cout<<"No se cerro este parentesis";
		}
		else if(c_c[0] > 0)
		{
			for (i = 0; i<c_c[1]-1; i++)
			{
				cout<<" ";
			}
			cout<<"^"<<endl;
			cout<<"No se cerro este corchete";
		}
		else if(c_ll[0] > 0)
		{
			for (i = 0; i<c_ll[1]-1; i++)
			{
				cout<<" ";
			}
			cout<<"^"<<endl;
			cout<<"No se cerro esta llave";
		}
	}
	
}

int main()
{
	char r;
	do
	{
	system("cls");
	char expresion[30];
	Pedir_expresion(expresion);
	Evaluar_delimitadores(expresion);
	cout<<endl;
	cout<<endl;
	cout<<"¿Deseas evaluar otra expresion? (s/n)"<<endl;
	cin>>r;
	}while(r == 's');
	getch();
	return 0;
}
