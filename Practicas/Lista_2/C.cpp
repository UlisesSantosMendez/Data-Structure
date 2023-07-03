#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

typedef int TipoDato;

typedef struct DPST{
	TipoDato dato;
	int posicion;
	int movimientos;
	struct DPST *next;
}Nodo;

typedef struct INL{
	int nelementos;
	struct DPST *PN;
}Indicador;

///////////////////////////////////////////////////////////////////////

Indicador* CrearLista(Indicador *lista);

Nodo* CrearNodo(TipoDato elemento);

void InsertarInicio(Indicador *lista, TipoDato elemento);

void InsertarFinal(Indicador *lista, TipoDato elemento);

void InsertarCPI(Indicador *lista, TipoDato elemento, int PP);

TipoDato EliminarInicio(Indicador *lista);

TipoDato EliminarFinal(Indicador *lista);

TipoDato EliminarCPI(Indicador *lista, int PP);

Nodo* BusquedaST(Indicador *lista, TipoDato elemento);

void ImprimirLista(Indicador *lista);

void ImprimirPosiciones(Indicador *lista);

void ImprimirNelementos(Indicador *lista);

////////////////////////////////////////////////////////////////////

int main(void){
	Indicador *Lista;
	Lista=NULL;
	Lista=CrearLista(Lista);
	Nodo *busqueda;
	busqueda=NULL;
	int elemento, posicion, opcion, indicador;
	TipoDato eliminado;
	
	do{
		system("cls");
		printf("\nBienvenido al programa de lista\n");
		printf("Insertar un elemento al inicio de la lista...................................[1]\n");
		printf("Insertar un elemento al final de la lista....................................[2]\n");
		printf("Insertar un elemento en un punto intermedio dentro del dominio de la lista...[3]\n");
		printf("Eliminar un elemento al inicio de la lista...................................[4]\n");
		printf("Eliminar un elemento al final de la lista....................................[5]\n");
		printf("Eliminar un elemento en un punto intermedio dentro del dominio de la lista...[6]\n");
		printf("Busqueda secuencial con transposicion........................................[7]\n");
		printf("Salir del programa...........................................................[8]\n");
		
		printf("\nTu lista:\n");
		ImprimirLista(Lista);
		printf("\nPosiciones:\n");
		ImprimirPosiciones(Lista);
		ImprimirNelementos(Lista);
		if(busqueda!=NULL){
			printf("\nEl valor que buscaste fue: %d\n", busqueda->dato);
		}
		printf("\nEl valor eliminado fue: %d\n", eliminado);
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
		}
		else if(opcion==5){
			eliminado=EliminarFinal(Lista);
		}
		else if(opcion==6){
			printf("Introduzca la posicion de su preferencia\n");
			scanf("%d",&posicion);
			eliminado=EliminarCPI(Lista,posicion);
		}
		else if(opcion==7){
			printf("Introduzca el valor a buscar\n");
			scanf("%d",&elemento);
			busqueda=BusquedaST(Lista,elemento);
		}
		else if(opcion==8){
			printf("Nos vemos\n");
			printf("\n");
		}
		else
		printf("Opcion invalida\n");
		printf("\n");	
	}while(opcion!=8);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

Indicador* CrearLista(Indicador *lista){
	lista=(Indicador*)malloc(sizeof(Indicador));
	lista->nelementos=0;
	lista->PN=NULL;
	return lista;
}

Nodo* CrearNodo(TipoDato elemento){
	Nodo *New;
	New=(Nodo*)malloc(sizeof(Nodo));
	New->dato=elemento;
	New->movimientos=0;
	New->next=NULL;
	return New;
}

void InsertarInicio(Indicador *lista, TipoDato elemento){
	if(lista->nelementos==0){
		lista->PN=CrearNodo(elemento);
		lista->nelementos++;
		(lista->PN)->posicion=lista->nelementos;
	}
	else{
		Nodo *New;
		New=CrearNodo(elemento);
		New->next=lista->PN;
		lista->PN=New;
		New->posicion=(New->next)->posicion;
		lista->nelementos++;
		while(New->next!=NULL){
			New=New->next;
			New->posicion++;
		}
	}
	return;
}

void InsertarFinal(Indicador *lista, TipoDato elemento){
	if(lista->nelementos==0){
		lista->PN=CrearNodo(elemento);
		lista->nelementos++;
		(lista->PN)->posicion=lista->nelementos;
	}
	else{
		Nodo *New, *Aux;
		New=CrearNodo(elemento);
		Aux=lista->PN;
		while(Aux->posicion!=lista->nelementos){
			Aux=Aux->next;
		}
		lista->nelementos++;
		Aux->next=New;
		New->posicion=lista->nelementos;
	}
	return;
}

void InsertarCPI(Indicador *lista, TipoDato elemento, int PP){
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
	}
	else if(PP<1){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al inicio de la lista\n");
	}
	else if(PP>=lista->nelementos){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al final de la lista\n");
	}
	else{
		Nodo *New, *Aux;
		New=CrearNodo(elemento);
		Aux=lista->PN;
		while(Aux->posicion!=PP){
			Aux=Aux->next;
		}
		New->next=Aux->next;
		Aux->next=New;
		New->posicion=Aux->posicion;
		do{
			New->posicion++;
			New=New->next;
		}while(New!=NULL);
		lista->nelementos++;
	}
	return;
}

TipoDato EliminarInicio(Indicador *lista){
	TipoDato eliminado;
	Nodo *Aux;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
	}
	else
	Aux=lista->PN;
	do{
		Aux->posicion--;
		Aux=Aux->next;
	}while(Aux!=NULL);
	lista->nelementos--;
	Aux=lista->PN;
	lista->PN=Aux->next;
	eliminado=Aux->dato;
	free(Aux);
	return eliminado;
}

TipoDato EliminarFinal(Indicador *lista){
	TipoDato eliminado;
	Nodo *Aux, *Ult;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
	}
	else if(lista->nelementos==1){
		Nodo *Aux;
		TipoDato eliminado;
		Aux=lista->PN;
		lista->PN=NULL;
		eliminado=Aux->dato;
		free(Aux);
		lista->nelementos=0;
		return eliminado;
	}
	else
	Aux=lista->PN;
	while((Aux->next)->posicion!=lista->nelementos){
		Aux=Aux->next;
	}
	Ult=Aux->next;
	Aux->next=NULL;
	eliminado=Ult->dato;
	free(Ult);
	lista->nelementos--;
	return eliminado;
}

TipoDato EliminarCPI(Indicador *lista, int PP){
	TipoDato eliminado;
	Nodo *Aux, *Hlp;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
	}
	else if(PP<=1){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar al inicio de la lista\n");
	}
	else if(PP>=lista->nelementos){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar al final de la lista\n");
	}
	else
	Aux=lista->PN;
	PP--;
	while(Aux->posicion!=PP){
		Aux=Aux->next;
	}
	Hlp=Aux->next;
	do{
		Hlp->posicion--;
		Hlp=Hlp->next;
	}while(Hlp!=NULL);
	Hlp=Aux->next;
	Aux->next=Hlp->next;
	eliminado=Hlp->dato;
	lista->nelementos--;
	free(Hlp);
	return eliminado;
}

Nodo* BusquedaST(Indicador *lista, TipoDato elemento){
	int P, GD;
	Nodo *Aux, *Cont, *Hlp, *Rfz, *BSQ;
	if(lista->nelementos==0){
		printf("\nTu lista se encuentra vacia\n");
	}
	else{
		Cont=lista->PN;
		do{
			if(Cont->dato==elemento){
				if(Cont->movimientos>=3){
					if(Cont->posicion==1){
						BSQ=Cont;
						Cont->movimientos++;
						Cont=Cont->next;
					}
					else if(Cont->posicion==lista->nelementos){
						GD=Cont->movimientos;
						Cont=Cont->next;
						elemento=EliminarFinal(lista);
						InsertarInicio(lista, elemento);
						GD++;
						(lista->PN)->movimientos=GD;
						BSQ=lista->PN;
					}
					else{
						P=Cont->posicion;
						GD=Cont->movimientos;
						Cont=Cont->next;
						elemento=EliminarCPI(lista,P);
						InsertarInicio(lista, elemento);
						GD++;
						(lista->PN)->movimientos=GD;
						BSQ=lista->PN;
					}
				}
				else{
					if(Cont->posicion==1){
						BSQ=Cont;
						Cont->movimientos++;
						Cont=Cont->next;
					}
					else if(Cont->posicion==2){
						Aux=Cont;
						Cont=Cont->next;
						Aux->posicion--;
						(lista->PN)->next=Aux->next;
						Aux->next=lista->PN;
						lista->PN=Aux;
						BSQ=lista->PN;
						Aux->movimientos++;
						Aux=Aux->next;
						Aux->posicion++;
					}
					else{
						Aux=Cont;
						Cont=Cont->next;
						Aux->posicion--;
						Hlp=lista->PN;
						while((Hlp->next)->next!=Aux){
							Hlp=Hlp->next;
						}
						Rfz=Hlp->next;
						Rfz->next=Aux->next;
						Aux->next=Rfz;
						Hlp->next=Aux;
						BSQ=Aux;
						Aux->movimientos++;
						Rfz->posicion++;
					}
				}
			}
			else
			Cont=Cont->next;
		}while(Cont!=NULL);
	}
	return BSQ;
}

void ImprimirLista(Indicador *lista){
	if(lista->nelementos==0){
		printf("\nTu lista se encuentra vacia\n");
	}
	else{
		Nodo *Aux;
		Aux=lista->PN;
		do{
			printf("%d ",Aux->dato);
			Aux=Aux->next;
		}while(Aux!=NULL);
		printf("\n");
	}
	return;
}

void ImprimirPosiciones(Indicador *lista){
	if(lista->nelementos==0){
		printf("\nTu lista se encuentra vacia\n");
	}
	else{
		Nodo *Aux;
		Aux=lista->PN;
		do{
			printf("%d ",Aux->posicion);
			Aux=Aux->next;
		}while(Aux!=NULL);
		printf("\n");
	}
	return;
}

void ImprimirNelementos(Indicador *lista){
	printf("\nEl numero de elementos en tu lista es: %d\n",lista->nelementos);
	return;
}



