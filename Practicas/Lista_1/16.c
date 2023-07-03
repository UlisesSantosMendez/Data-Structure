#include <string.h>
#include <stdio.h>
#include <conio.h>

typedef int TipoDato;

typedef struct DPST{
	TipoDato dato;
	int posicion;
	struct DPST *next;
	struct DPST *before;
}Nodo;

typedef struct INL{
	int nelementos;
	struct DPST *PN;
}Indicador;

////////////////////////////////////////////////////////////////////////////////////////////

Indicador* CrearLista(Indicador *lista);

Nodo* CrearNodo(TipoDato elemento);

void InsertarInicio(Indicador *lista, TipoDato elemento);

void InsertarFinal(Indicador *lista, TipoDato elemento);

void InsertarCPI(Indicador *lista, TipoDato elemento, int PP);

TipoDato EliminarInicio(Indicador *lista);

TipoDato EliminarFinal(Indicador *lista);

TipoDato EliminarCPI(Indicador *lista, int PP);

void EliminarLista(Indicador *lista);

void ImprimirLista(Indicador *lista);

void ImprimirPosiciones(Indicador *lista);

void ImprimirNelementos(Indicador *lista);

////////////////////////////////////////////////////////////////////////////////////////////																																					Navarro Topete Jose Alberto

int main(void){
	Indicador *Lista;
	Lista=NULL;
	Lista=CrearLista(Lista);
	
	int elemento, posicion, opcion;
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
		printf("Vaciar lista.................................................................[7]\n");
		printf("Salir del programa...........................................................[8]\n");
		
		printf("\nTu lista:\n");
		ImprimirLista(Lista);
		ImprimirNelementos(Lista);
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
			EliminarLista(Lista);
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

////////////////////////////////////////////////////////////////////////////////////////////																														Navarro Topete Jose Alberto

Indicador* CrearLista(Indicador *lista){
	lista=(Indicador*)malloc(sizeof(Indicador));
	lista->nelementos=0;
	lista->PN=NULL;
	return lista;
}

Nodo* CrearNodo(TipoDato elemento){
	Nodo *New;
	New=(Nodo*)malloc(sizeof(Nodo));
	New->next=NULL;
	New->before=NULL;
	New->dato=elemento;
	return New;
}

void ImprimirLista(Indicador *lista){
	Nodo *imp;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
		return;
	}
	else
	imp=lista->PN;
	do{
		printf("%d ",imp->dato);
		imp=imp->next;
	}while(imp!=lista->PN);
	printf("\n");
	return;
}

void ImprimirPosiciones(Indicador *lista){
	Nodo *imp;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
		return;
	}
	else
	imp=lista->PN;
	do{
		printf("%d ",imp->posicion);
		imp=imp->next;
	}while(imp!=lista->PN);
	printf("\n");
	return;
}

void ImprimirNelementos(Indicador *lista){
	printf("\nNumero de elementos en tu lista: %d\n",lista->nelementos);
	return;
}

void EliminarLista(Indicador *lista){
	Nodo *Llib, *aux;
	Llib=lista->PN;
	lista->PN=NULL;
	aux=Llib;
	do{
		aux=aux->next;
		free(Llib);
		Llib=aux;
	}while(aux->posicion!=lista->nelementos);
	free(aux);
	lista->nelementos=0;
	return;
}

void InsertarInicio(Indicador *lista, TipoDato elemento){
	Nodo *New;
	if(lista->nelementos==0){
		lista->PN=CrearNodo(elemento);
		lista->nelementos++;
		(lista->PN)->next=lista->PN;
		(lista->PN)->before=lista->PN;
		(lista->PN)->posicion=lista->nelementos;
		return;
	}
	else
	New=CrearNodo(elemento);
	New->next=lista->PN;
	New->before=(lista->PN)->before;
	(New->before)->next=New;
	(lista->PN)->before=New;
	New->posicion=1;
	do{
		(lista->PN)->posicion++;
		lista->PN=(lista->PN)->next;
	}while(lista->PN!=New);
	lista->nelementos++;
	return;
}

void InsertarFinal(Indicador *lista, TipoDato elemento){
	Nodo *New;
	if(lista->nelementos==0){
		lista->PN=CrearNodo(elemento);
		lista->nelementos++;
		(lista->PN)->next=lista->PN;
		(lista->PN)->before=lista->PN;
		(lista->PN)->posicion=lista->nelementos;
		return;
	}
	else
	New=CrearNodo(elemento);
	New->before=(lista->PN)->before;
	New->next=lista->PN;
	(New->before)->next=New;
	(lista->PN)->before=New;
	lista->nelementos++;
	New->posicion=lista->nelementos;
	return;
}

TipoDato EliminarInicio(Indicador *lista){
	Nodo *Nlib;
	TipoDato rpd;
	if(lista->nelementos==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(lista->nelementos==1){
		rpd=(lista->PN)->dato;
		free(lista->PN);
		lista->PN=NULL;
		lista->nelementos--;
		printf("Eliminaste el ultimo elemento de tu lista\n");
		return rpd;
	}
	else
	rpd=(lista->PN)->dato;
	Nlib=lista->PN;
	lista->PN=(lista->PN)->next;
	(Nlib->before)->next=lista->PN;
	(lista->PN)->before=Nlib->before;
	lista->nelementos--;
	do{
		(lista->PN)->posicion--;
		lista->PN=(lista->PN)->next;
	}while((lista->PN)->posicion!=1);
	free(Nlib);
	return rpd;
}

TipoDato EliminarFinal(Indicador *lista){
	Nodo *Nlib;
	TipoDato rpd;
	if(lista->nelementos==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(lista->nelementos==1){
		rpd=(lista->PN)->dato;
		free(lista->PN);
		lista->PN=NULL;
		lista->nelementos--;
		printf("Eliminaste el ultimo elemento de tu lista\n");
		return rpd;
	}
	else
	Nlib=(lista->PN)->before;
	rpd=Nlib->dato;
	(lista->PN)->before=Nlib->before;
	(Nlib->before)->next=lista->PN;
	lista->nelementos--;
	free(Nlib);
	return rpd;
}

void InsertarCPI(Indicador *lista, TipoDato elemento, int PP){
	Nodo *New, *aux;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
		return;
	}
	else if(PP>=lista->nelementos){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al final de la lista\n");
		return;
	}
	else if(PP<1){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al inicio de la lista\n");
		return;
	}
	else
	New=CrearNodo(elemento);
	aux=lista->PN;
	do{
		aux=aux->next;
	}while(aux->posicion!=PP);
	New->posicion=PP;
	New->before=aux;
	New->next=aux->next;
	(aux->next)->before=New;
	aux->next=New;
	do{
		New->posicion++;
		New=New->next;
	}while(New!=lista->PN);
	lista->nelementos++;
	return;
}

TipoDato EliminarCPI(Indicador *lista, int PP){
	Nodo *Nlib, *aux;
	TipoDato rpd;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
		return;
	}
	else if(PP>=lista->nelementos){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar el final de la lista\n");
		return;
	}
	else if(PP<=1){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar el inicio de la lista\n");
		return;
	}
	else
	Nlib=lista->PN;
	do{
		Nlib=Nlib->next;
	}while(Nlib->posicion!=PP);
	rpd=Nlib->dato;
	(Nlib->before)->next=Nlib->next;
	(Nlib->next)->before=Nlib->before;
	aux=Nlib->next;
	do{
		aux->posicion--;
		aux=aux->next;
	}while(aux!=lista->PN);
	lista->nelementos--;
	free(Nlib);
	return rpd;
}
