#include <iostream>
#include <conio.h>
using namespace std;
struct Vector
{
	int i = 0;
	int j = 0;
	int k = 0;
};
void menu (int *opc)
{
	do
	{
	system ("cls");
	cout<<"¿Que operacion deseas realizar?"<<endl;
	cout<<"1. Suma"<<endl;
	cout<<"2. Resta"<<endl;
	cout<<"3. Producto Punto"<<endl;
	cout<<"4. Producto Cruz"<<endl;
	cin>>*opc;
	}while (*opc > 4 || *opc < 1);
}
void Pedir_vec (Vector *v1, Vector *v2)
{
	
	cout<<"Introduce el valor i del vector 1"<<endl;
	cin>>v1->i;

	cout<<"Introduce el valor j del vector 1"<<endl;
	cin>>v1->j;
	cout<<"Introduce el valor k del vector 1"<<endl;
	cin>>v1->k;
	system("cls");
	cout<<"Introduce el valor i del vector 2"<<endl;
	cin>>v2->i;
	cout<<"Introduce el valor j del vector 2"<<endl;
	cin>>v2->j;
	cout<<"Introduce el valor k del vector 2"<<endl;
	cin>>v2->k;
	
}
void Operacion (Vector *v1, Vector *v2, int *opc)
{
	Vector res;
	int aux;
		switch (*opc)
	{
		case 1:
			res.i = v1->i + v2->i;
			res.j = v1->j + v2->j;
			res.k = v1->k + v2->k;
			cout<<"El resultado de la suma es: "<<endl;
			cout<<"("<<res.i<<","<<res.j<<","<<res.k<<")"<<endl;
			break;
		case 2:
			res.i = v1->i - v2->i;
			res.j = v1->j - v2->j;
			res.k = v1->k - v2->k;
			cout<<"El resultado de la resta es: "<<endl;
			cout<<"("<<res.i<<","<<res.j<<","<<res.k<<")"<<endl;
			break;
		case 3:
			res.i = v1->i * v2->i;
			res.j = v1->j * v2->j;
			res.k = v1->k * v2->k;
			aux = res.i + res.j + res.k;
			cout<<"El resultado del producto punto es: "<<endl;
			cout<<aux;
			break;
		case 4:
			res.i = (v1->j * v2->k) - (v1->k * v2->j);
			res.j = (v1->i * v2->k) - (v1->k * v2->i);
			res.j = res.j * (-1);
			res.k = (v1->i * v2->j) - (v1->j * v1->i);
			cout<<"El resultado del producto cruz es: "<<endl;
			cout<<"("<<res.i<<","<<res.j<<","<<res.k<<")"<<endl;
			break;
				
	}
}
int main()
{
	int opc = 0;
	char r;
	Vector v1;
	Vector v2;
	do
	{
	menu(&opc);
	system("cls");
	Pedir_vec (&v1, &v2);
	system("cls");
	Operacion (&v1, &v2, &opc);
	cout<<endl;
	cout<<"¿Quieres realizar otra operacion? (s/n)"<<endl;
	cin>>r;
	}while (r == 's');
	getch();
	return 0;
}
