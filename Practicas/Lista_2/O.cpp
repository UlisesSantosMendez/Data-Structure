#include<stdio.h>
#include<stdlib.h>

struct nodo {
	int dato;
	struct nodo*izquierdo;
	struct nodo*derecho;
};

typedef struct nodo Nodo;

Nodo*crearnodo(int dato);
Nodo*insertar(int dato,Nodo*arbol);
void pre_orden(Nodo*arbol);
void en_orden(Nodo*arbol);
void pos_orden(Nodo*arbol);

int main(){
	
	int i,dato,n;
	Nodo*arbol=NULL;
	
	printf("Numero de nodos del arbol: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Elemento No.%d: \n",i+1);
		scanf("%d",&dato);
		arbol=insertar(dato,arbol);
	}
	printf("\nEn forma Pre-Orden:\n");
	pre_orden(arbol);
	printf("\nEn forma En-Orden:\n");
	en_orden(arbol);
	printf("\nEn forma Pos-Orden:\n");
	pos_orden(arbol);
}

//funcion  de creacion de un nuevo nodo
Nodo*crearnodo(int dato){
	
	Nodo*aux=(Nodo*)malloc(sizeof(Nodo));
	aux->dato=dato;
	aux->izquierdo=NULL;
	aux->derecho=NULL;
	return aux;
}

//funcion de insertar dato
Nodo*insertar(int dato,Nodo*arbol){
	if(arbol==NULL){
		arbol=crearnodo(dato);
		arbol->dato=dato;
		arbol->izquierdo=NULL;
		arbol->derecho=NULL;
		return(arbol);
	}
	if(dato<arbol->dato){
		arbol->izquierdo=insertar(dato,arbol->izquierdo);
	}else{
		arbol->derecho=insertar(dato,arbol->derecho);
	}
	return(arbol);	
}


void pre_orden (Nodo*arbol){
	if(arbol!=NULL){
		printf("%d,",arbol->dato);
		pre_orden(arbol->izquierdo);
		pre_orden(arbol->derecho);
	}
}

void en_orden (Nodo*arbol){
	if(arbol!=NULL){
		en_orden(arbol->izquierdo);
		printf("%d,",arbol->dato);
		en_orden(arbol->derecho);
	}
}

void pos_orden (Nodo*arbol){
	if(arbol!=NULL){
		pos_orden(arbol->izquierdo);
		pos_orden(arbol->derecho);
		printf("%d,",arbol->dato);
	}
}








