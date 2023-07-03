#include<iostream>
#include<conio.h>
#include<stdio.h>
#define tam 10
using namespace std;
struct Pila
{
	int dato[tam];
	int tope = -1;
};

void menu (int *opc)
{
	do
	{
	system("cls");
	cout<<"¿Que operacion deseas realizar?:"<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Mostrar pila"<<endl;
	cin>> *opc;
	}while(*opc<1 || *opc>3);
}

void Push (Pila *p)
{
	if (p->tope == tam-1)
	{
		cout<<"La pila esta llena"<<endl;
	}
	else 
	{
		p->tope = p->tope + 1;
		cout<<"Introduce un dato"<<endl;
		cin>> p->dato[p->tope];

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
		system("cls");
		cout<<"Se saco el valor: "<<endl;
		cout<< p->dato[p->tope]<<endl;
		p->tope = p->tope - 1;
	}
}

void Mostrar (Pila *p)
{
	int aux = 0;
	aux = p->tope; 
	if (p->tope == -1)
	{
		cout<<"La pila esta vacia"<<endl;
	}
	else
	{
	for (int i = aux; i>=0; i--)
	{
		cout<<"|"<<p->dato[i]<<"|"<<endl;
	}
	cout<<"|_|"<<endl;
	}
}

int main ()
{
	Pila p1;
	int opc = 0;
	char r;
	do
	{
	system ("cls");
	menu(&opc);
	switch(opc)
	{
		case 1:
			Push(&p1);
			break;
		case 2:
			Pop(&p1);
			break;
		case 3:
			Mostrar(&p1);
			break;
	}
	cout<<"¿Quieres realizar otra operacion? (s/n)"<<endl;
	cin>>r;
	}while(r == 's');
	getch();
	return 0;
}
