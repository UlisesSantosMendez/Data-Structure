#include<stdio.h>
#include<stdlib.h>

//-------DECLARACION DE LAS ESTRUCTURAS-------//
typedef struct ELEMENTO{
	int x;
}elemento;

typedef struct NODO{
	elemento dato;
	struct NODO *nodo_abajo;
}nodo;

typedef struct PILA{
	nodo *nodo_tope;
}pila;

//-------FUNCIONES DE LA PILA-------//

void iniciar_pila(pila *p){
	p->nodo_tope = NULL;
}

void push_pila(pila *p, elemento dato){
	nodo *aux = (nodo*)malloc(sizeof(nodo));
	if(aux != NULL){
		aux->dato = dato;
		aux->nodo_abajo = p->nodo_tope;
		p->nodo_tope = aux;
	}else{
		printf("ERROR. Ya no hay memoria disponible\n");
	}
}

elemento pop_pila(pila *p){
	elemento element; nodo *aux;
	if(es_vacia(p) == 1){
		printf("ERROR. No hay elementos en la pila\n");
	}else{
		element = p->nodo_tope->dato;
		aux = p->nodo_tope;
		p->nodo_tope = p->nodo_tope->nodo_abajo;
		free(aux);
	}
	return element;
}

int es_vacia(pila *p){
	if(p->nodo_tope == NULL){
		return 1;
	}else{
		return 0;
	}
}

void tope_pila(pila *p){
	if(es_vacia(p) == 1){
		printf("Como la pila esta vacia, no hay un tope\n");
	}else{
		printf("El tope de la pila es -> %d\n",p->nodo_tope->dato);
	}
}

void eliminar_pila(pila *p){
	nodo *aux;
	while(p->nodo_tope != NULL){
		aux = p->nodo_tope;
		p->nodo_tope = p->nodo_tope->nodo_abajo;
		free(aux);
	}
}


int main(){
	//DECLARACION DE LA PILA Y DE LOS ELEMENTOS A GUARDAR EN ELLA
	pila p; elemento e1,e2,e3,e4,e5;
	
	//inicializacion de las variables de tipo elemento
	e1.x = 10; e2.x = 20; e3.x = 30; e4.x = 40; e5.x = 50;
	
	//Se inicializa la pila para su uso
	iniciar_pila(&p);
	
	//Se insertan los 3 primeros elementos de la píla
	push_pila(&p,e1);
	push_pila(&p,e2);
	push_pila(&p,e3);
	
	//Se pregunta por el tope de la pila
	tope_pila(&p);
	
	//Se insertan los 2 valores restantes
	push_pila(&p,e4);
	push_pila(&p,e5);

	//Se pregunta nuevamente por el tope de la pila
	tope_pila(&p);
	
	//Se eliminan 3 elementos de la pila
	printf("%d\n",pop_pila(&p));
	printf("%d\n",pop_pila(&p));
	printf("%d\n",pop_pila(&p));
	
	//Se pregunta nuevamente por el tope de la pila
	tope_pila(&p);
	
	//Se elimina la pila
	eliminar_pila(&p);
	
	//Se hace un pop (Marca error por que la pila esta vacia)
	printf("",pop_pila(&p));
	

	return 0;
}
