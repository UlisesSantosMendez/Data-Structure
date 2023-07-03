#include <string.h>
#include <stdio.h>
#include <conio.h>

typedef int TipoDato;

typedef struct DPST{
	TipoDato dato;
	int posicion;
	struct DPST *next;
}Nodo;

typedef struct INL{
	int nelementos;
	struct DPST *PN;
}Indicador;

/////////////////////////////////////////////////////////

Indicador* CrearLista(Indicador *lista);

Nodo* CrearNodo(TipoDato elemento);

void InsertarFinal(Indicador *lista, TipoDato elemento);

TipoDato EliminarInicio(Indicador *lista);

TipoDato EliminarFinal(Indicador *lista);

Nodo* Posiciones(Indicador *lista, char *a, char*b, int cont, int comp);

void ImprimirLista(Indicador *lista);

void ImprimirPosiciones(Indicador *lista);

/////////////////////////////////////////////////////////

int main(void){
	Indicador *Lista;
	Lista=CrearLista(Lista);
	int p,s;
	char *a,*b;
	char*a=(char*)malloc(sizeof(char));
	b=(char*)malloc(sizeof(char));
	fflush(stdin);
	printf("Introduce una cadena de caracteres\n");
	gets(a);
	printf("Introduce la cadena a comparar\n");
	gets(b);
	fflush(stdin);
	Posiciones(Lista,a,b,0,0);
	printf("\nResultado:");
	ImprimirLista(Lista);
	return 0;
}

////////////////////////////////////////////////////////

Nodo* Posiciones(Indicador *lista, char *a, char*b, int cont, int comp){
	TipoDato grd;
	if(a[cont]!='\0'){
		if(b[comp]=='\0'){
			grd=cont;
			grd=grd-comp;
			comp=0;
			InsertarFinal(lista, grd);
		}
		
		if(a[cont]!=b[comp]){
			comp=0;
			cont++;
			Posiciones(lista,a,b,cont,comp);	
		}
		else{
			comp++;
			cont++;
			Posiciones(lista,a,b,cont,comp);
		}
	}
	else if(a[cont]=='\0' && b[comp]=='\0'){
		grd=cont;
		grd=grd-comp;
		InsertarFinal(lista, grd);
	}
	return lista->PN;
}

////////////////////////////////////////////////////////

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
	New->next=NULL;
	return New;
}

void InsertarFinal(Indicador *lista, TipoDato elemento){
	if(lista->nelementos==0){
		lista->PN=CrearNodo(elemento);
		lista->nelementos++;
		(lista->PN)->posicion=lista=lista->nelementos;
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

TipoDato EliminarInicio(Indicador *lista){
	TipoDato eliminado;
	Nodo *Aux;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
		return;
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
		return;
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
