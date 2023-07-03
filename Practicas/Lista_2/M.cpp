#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;

void Pedir_datos(int *n)
{
	cout<<"¿Cuantos niveles quieres en tu arbol binario?"<<endl;
	cin>>*n;
}
int crear_arbol (int n)
{
	int total_n = 0;
	 if (n == 0)
	 {
	 	total_n = total_n+1;
	 }
	 else
	 {
	 total_n = pow(2, n) + crear_arbol(n-1);		
	 }
	 return total_n;
}
void menu (int *opc)
{
	cout<<"Que operacion deseas realizar?"<<endl;
	cout<<"1. Ingresar valores"<<endl;
	cout<<"2. Hijo izquierdo"<<endl;
	cout<<"3. Hijo derecho"<<endl;
	cin>>*opc;
}
void Ingresar_valores (int a[], int *n)
{
	for(int i = 0; i<*n ; i++)
	{
	cout<<"Ingresa el valor del nodo "<<i+1<<":" <<endl;
	cin>>a[i];
	}
}
void Hijo_i (int a[])
{
	int n = 0;
	cout<<"¿Cual nodo quieres inspeccionar?"<<endl;
	cin>>n;
	cout<<"El hijo izquierdo del nodo "<<n<<" es el nodo "<< 2*n;
	cout<<" con valor: "<<a[(2*n)-1];

}
void Hijo_d (int a[])
{
	int n = 0;
	cout<<"¿Cual nodo quieres inspeccionar?"<<endl;
	cin>>n;
	cout<<"El hijo izquierdo del nodo "<<n<<" es el nodo "<< (2*n)+1;
	cout<<" con valor: "<<a[(2*n)];

}
int main ()
{
	int nivel = 0;
	int opc = 0;
	char r;
	Pedir_datos(&nivel);
	int numero_nodos = crear_arbol(nivel);
	int arbol[numero_nodos];
	do{
	menu(&opc);
	switch (opc)
	{
	case 1:
		Ingresar_valores(arbol, &numero_nodos);
		break;
	case 2:
		Hijo_i(arbol);
		break;
	case 3:
		Hijo_d(arbol);
		break;
	}
	cout<<endl<<"¿Quieres realizar otra operacion? (s/n)"<<endl;
	cin>>r;
	system("cls");
	}while(r == 's');

	getch();
	return 0;
}
