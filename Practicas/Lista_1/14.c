#include <string.h>
#include <stdio.h>
#include <conio.h>
#define MAX 20
#define COMPV 1

typedef int TipoDato;

typedef struct alm{
	int numelm;
	TipoDato dato[MAX];
}Nodo;

void CrearOVaciarLista(Nodo* Lista);

void ImpresionLista(Nodo* Lista);

void ImprimirNelementos(Nodo *lista);

void InsertarFinal(Nodo* Lista, TipoDato elemento);

void InsertarInicio(Nodo* lista, TipoDato elemento);

TipoDato EliminarFinal(Nodo* lista);

TipoDato EliminarInicio(Nodo* lista);

void InsertarCPI(Nodo *lista, TipoDato elemento, int posicion);

TipoDato EliminarCPI(Nodo *lista, int posicion);

void ConcatenarListas(Nodo *plista, Nodo *slista);

void BuscarComunes(Nodo *plista, Nodo *slista);

void CambiarDato(Nodo *plista, Nodo *slista);

int main (void){
	Nodo LU, *Lista;
	Lista=&LU;
	CrearOVaciarLista(Lista);
	int posicion, opcion, nlista, nelista, ubicacion;
	TipoDato elemento, eliminado;
	
	do{
		system("cls");
		printf("\nBienvenido al programa de dos listas\n");
		printf("Insertar un elemento al inicio de la lista...................................[1]\n");
		printf("Insertar un elemento al final de la lista....................................[2]\n");
		printf("Insertar un elemento en un punto intermedio dentro del dominio de la lista...[3]\n");
		printf("Eliminar un elemento al inicio de la lista...................................[4]\n");
		printf("Eliminar un elemento al final de la lista....................................[5]\n");
		printf("Eliminar un elemento en un punto intermedio dentro del dominio de la lista...[6]\n");
		printf("Vaciar lista.................................................................[7]\n");
		printf("Salir del programa...........................................................[8]\n");
		
		printf("\nPrimer lista:\n");
		ImpresionLista(Lista);
		//ImprimirNelementos(Lista);
		
		printf("\nEl valor eliminado de la primera lista fue: %d\n", eliminado);
		
		printf("\nPor favor escoja una opcion del menu:\n");
		scanf("%d",&opcion);
		
		if(opcion==1){
				printf("Introduzca el dato de su preferencia\n");
				scanf("%d",&elemento);
				InsertarInicio(Lista,elemento);
		}
		else if(opcion==2){
			printf("Introduzca el dato de su preferencia\n");
			scanf("%d",&elemento);
			InsertarFinal(Lista,elemento);	
		}
		else if(opcion==3){
			printf("Introduzca el dato de su preferencia\n");
			scanf("%d",&elemento);
			printf("Introduzca la posicion de su preferencia\n");
			scanf("%d",&posicion);
			InsertarCPI(Lista,elemento,posicion);
		}
		else if(opcion==4){
			eliminado=EliminarInicio(Lista);
			nelista=nlista;
		}
		else if(opcion==5){
			eliminado=EliminarFinal(Lista);
			nelista=nlista;
		}
		else if(opcion==6){
			printf("Introduzca la posicion de su preferencia\n");
			scanf("%d",&posicion);
			eliminado=EliminarCPI(Lista,posicion);
			nelista=nlista;
		}
		else if(opcion==7){
			CrearOVaciarLista(Lista);
		}
		else if(opcion==8){
			printf("Nos vemos\n");
			printf("\n");
		}
		else
		printf("Opcion invalida\n");
		printf("\n");
	}while(opcion!=11);

	return 0;
}

void CrearOVaciarLista(Nodo* lista){
	int cont=0;
	do{
		lista->dato[cont]=COMPV;
		cont++;
	}while(cont!=MAX);
	lista->numelm=0;
	return;
}

void ImpresionLista(Nodo* lista){
	int cont=0;
	if(lista->numelm==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else
	do{
		printf("%d ",lista->dato[cont]);
		cont++;
	}while(cont!=lista->numelm);
	printf("\nNumero de elementos en tu lista: %d\n",lista->numelm);
	
	return;
}

void ImprimirNelementos(Nodo *lista){
	printf("\nNumero de elementos en tu lista: %d\n",lista->numelm);
	return;
}

void InsertarFinal(Nodo* lista, TipoDato elemento){
	if(lista->numelm==MAX){
		printf("Tu lista esta llena\n");
		return;
	}
	else
	lista->dato[lista->numelm]=elemento;
	lista->numelm++;
	return;
}

void InsertarInicio(Nodo* lista, TipoDato elemento){
	if(lista->numelm==MAX){
		printf("Tu lista esta llena\n");
		return;
	}
	else if(lista->numelm<1){
		InsertarFinal(lista,elemento);
		return;
	}
	int aux,apy;
	aux=lista->numelm;
	aux--;
	apy=lista->numelm;
	do{
		lista->dato[apy]=lista->dato[aux];
		apy--;
		aux--;
	}while(apy!=0);
	lista->dato[0]=elemento;
	lista->numelm++;
	return;
}

TipoDato EliminarFinal(Nodo* lista){
	if(lista->numelm==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	int aux;
	TipoDato rpd;
	aux=lista->numelm;
	aux--;
	rpd=lista->dato[aux];
	lista->dato[aux]=COMPV;
	lista->numelm--;
	return rpd;
}

TipoDato EliminarInicio(Nodo* lista){
	int aux=1, cont=0;
	TipoDato rpd;
	if(lista->numelm==cont){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(lista->numelm==aux){
		rpd=EliminarFinal(lista);
		return rpd;
	}
	rpd=lista->dato[0];
	do{
		lista->dato[cont]=lista->dato[aux];
		cont++;
		aux++;
	}while(aux!=lista->numelm);
	lista->numelm--;
	lista->dato[lista->numelm]=COMPV;
	
	return rpd;
}

void InsertarCPI(Nodo *lista, TipoDato elemento, int posicion){
	int aux, apy;
	if(lista->numelm==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(posicion<1){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al inicio de la lista\n");
		return;
	}
	else if(posicion>=lista->numelm){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al final de la lista\n");
		return;
	}
	else
	lista->numelm++;
	aux=lista->dato[posicion];
	lista->dato[posicion]=elemento;
	posicion++;
	do{
		apy=lista->dato[posicion];
		lista->dato[posicion]=aux;
		aux=apy;
		posicion++;
	}while(posicion!=lista->numelm);
	return;
}

TipoDato EliminarCPI(Nodo *lista, int posicion){
	int aux, cont;
	TipoDato rpd;
	if(lista->numelm==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(posicion<=1){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar al inicio de la lista\n");
		return;	
	}
	else if(posicion>=lista->numelm){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar al final de la lista\n");
		return;
	}
	else
	cont=posicion;
	posicion--;
	rpd=lista->dato[posicion];
	do{
		aux=lista->dato[cont];
		lista->dato[posicion]=aux;
		cont++;
		posicion++;
	}while(cont!=lista->numelm);
	lista->numelm--;
	return rpd;
}
