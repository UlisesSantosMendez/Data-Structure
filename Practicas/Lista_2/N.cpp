#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
typedef int TipoDato;
struct Nodo
{
	TipoDato Dato = 0;
	struct Nodo *hijo_izquierdo;
	struct Nodo *hijo_derecho;	
};
Nodo* CrearNodo(TipoDato d)
{
	Nodo *a;
	a = (Nodo*)malloc(sizeof(Nodo));
	a->Dato = d;
	a->hijo_derecho = NULL;
	a->hijo_izquierdo = NULL;
	return a;
}
void Insertar(Nodo *&arbol, int d)
{
	char opc = 0;
	if(arbol == NULL)
	{
		Nodo *nuevo;
		nuevo = CrearNodo(d);
		arbol = nuevo;
	}
	else
	{
		cout<<"¿A cual hijo deseas insertar? (i/d)"<<endl;
		cin>>opc;
		if (opc == 'i')
		{
			Insertar(arbol->hijo_izquierdo, d);
		}
		else
		{
			Insertar(arbol->hijo_derecho, d);
		}
	}
}
void Eliminar(Nodo *&arbol)
{
	char opc = 0;
	if(arbol == NULL)
	{
		cout<<"El arbol no tiene elementos"<<endl;
	}
	else
	{
		cout<<"¿Cual elemento deseas eliminar? (i/d)"<<endl;
		cin>>opc;
		if(opc == 'i')
		{
			if(arbol->hijo_izquierdo == NULL)
			{
				cout<<"No hay elemento en la izquierda"<<endl;
			}
			else
			{
			arbol->hijo_derecho = NULL;
			cout<<"Se elimino el hijo izquierdo"<<endl;
			}
		}
		else
		{
			if(arbol->hijo_derecho == NULL)
			{
				cout<<"No hay elemento en la derecha"<<endl;
			}
			else
			{
			arbol->hijo_derecho = NULL;
			cout<<"Se elimino el hijo derecho"<<endl;
			}
		}
	}
}
void Buscar(Nodo *arbol, int e)
{
	if(arbol == NULL)
	{
		return;
	}
	else
	{
		if(arbol->hijo_derecho->Dato == e || arbol->hijo_izquierdo->Dato == e)
		{
			cout<<"El Padre es:"<<endl;
			cout<<arbol->Dato<<endl;
		}
	}
}
void Mostrar(Nodo *arbol, int contador, char r)
{
	if(contador == 0)
	{	
	cout<<"El padre es la raiz"<<endl;
	}
	else
	{
		if(r == 'd')
		{
		int cont = 0;
		for(int i = 0; i<contador; i++)
		{
			cont++;
			Mostrar(arbol->hijo_derecho, cont, r);
		}
		cout<<arbol->Dato<<endl;
		}
	}
}
void Padre(Nodo *arbol, int e)
{
	int c = 0;
	if(arbol == NULL)
	{
		cout<<"El arbol no tiene elementos"<<endl;
	}
	else
	{
		Buscar(arbol, e);
	}
}


void menu(Nodo *&arbol)
{
	int opc = 0;
	int dato = 0;
	cout<<"¿Que operacion quieres realizar?"<<endl;
	cout<<"1. Insertar Elemento"<<endl;
	cout<<"2. Eliminar Elemento"<<endl;
	cout<<"3. Padre"<<endl;
	cout<<"4. Hijo Izquierdo"<<endl;
	cout<<"5. Hijo Derecho"<<endl;
	cin>>opc;
	
	switch(opc)
	{
		case 1:
			cout<<"Ingresa el dato a insertar: "<<endl;
			cin>>dato;
			Insertar(arbol, dato);
			break;
		case 2:
			Eliminar(arbol);
			break;
		case 3:
			cout<<"¿De cual dat quieres conocer el padre?"<<endl;
			cin>>dato;
			Padre(arbol, dato);
			break;
		case 4:
			cout<<"El hijo izquierdo es:"<<endl;
			cout<<arbol->hijo_izquierdo->Dato<<endl;
			break;
		case 5:
			cout<<"El hijo derecho es:"<<endl;
			cout<<arbol->hijo_derecho->Dato<<endl;
	}
}

int main()
{
	char r;
	Nodo *arbol = NULL;
	do
	{
		system("cls");
	menu(arbol);
	cout<<"¿Quieres realizar otra operacion? (s/n)"<<endl;
	cin>>r;
	}while(r == 's');
	getch();
	return 0;
}

