#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#define tam 10
using namespace std;
struct Pila
{
	char dato[tam];
	int tope = -1;
	int precedencia[tam];
};

void PedirExpresion (char c[30])
{
	system("cls");
	cout<<"Ingresa la expresion infija"<<endl;
	cin>>c;

}

void Push (Pila *p, char aux)
{
	if (p->tope == tam-1)
	{
		cout<<"La pila esta llena"<<endl;
	}
	else 
	{
		p->tope = p->tope + 1;
		p->dato[p->tope] = aux;
	}
	
}

void Pop (Pila *p)
{
	if (p->tope == -1)
	{
		cout<<"La pila esta vacia"<<endl;
	}
	else
	{
		cout<< p->dato[p->tope]<<endl;
		p->tope = p->tope - 1;
	}
}

void Precedencia (Pila *p, char c)
{
	switch (c)
	{
		case '+':
			p->precedencia[p->tope] = 1;
		break;
		case '-':
			p->precedencia[p->tope] = 1;
		break;
		case '*':
			p->precedencia[p->tope] = 2;
		break;
		case '/':
			p->precedencia[p->tope] = 2;
		break;
		case 'e':
			p->precedencia[p->tope] = 3;
		break;
	}

}
void Conversor (char c[30], int *l)
{
	Pila p1;
	char operadores [4] = {'+', '-', '/', '*'};
	char aux;
	int i;
	cout<<endl;
	cout<<"La expresion posfija es: "<<endl;
	for (i = 0 ; i<*l ; i++)
	{
		for (int j = 0 ; j<4 ; j++)
		{
			if (c[i] == operadores[j])
			{
				aux = c[i];
				i++;
				Push(&p1, aux);
				Precedencia(&p1, aux);
			}
			else if (c[i] == 'e' && c[i+1] == 'x' && c[i+2] == 'p')
			{
				aux = c[i];
				i = i+3;
				Push(&p1, aux);
				Precedencia(&p1, aux);
			}

		}
		if (p1.tope >= 1)
		{
			if (p1.precedencia[p1.tope] < p1.precedencia[p1.tope-1])
			{
				if (p1.dato[p1.tope-1] == 'e')
				{
					cout<<"exp";
					p1.dato[p1.tope-1] = p1.dato[p1.tope];
					p1.precedencia[p1.tope-1] = p1.precedencia[p1.tope];
					p1.tope--;
				}
				else
				{
				cout<<p1.dato[p1.tope-1];
				p1.dato[p1.tope-1] = p1.dato[p1.tope];
				p1.precedencia[p1.tope-1] = p1.precedencia[p1.tope];
				p1.tope--;
				}
			}
		}
		cout<<c[i];
		
	}
	for (i = p1.tope; i >= 0; i--)
	{
		if (p1.dato[i] == 'e')
		{
			cout<<"exp";
		}
		else
		{
		cout<<p1.dato[i];
		}
	}
	cout<<endl;
}
int main ()
{
	char r;
	do
	{
	system("cls");
	char expresion[30];
	int lon = 0;
	PedirExpresion(expresion);
	lon = strlen (expresion);
	Conversor(expresion, &lon);
	cout<<endl;
	cout<<"¿Quieres convertir otra expresion? (s/n)"<<endl;
	cin>>r;
	}while(r == 's');
	getch();
	return 0;
}
