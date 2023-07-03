#include<stdio.h>
#include<stdlib.h>

//Definicion de las estructuras

typedef struct ELEMENTO{
	int x;
}elemento;

typedef struct NODO{
	elemento dato;
	struct NODO *nodo_siguiente;
}nodo;

typedef struct COLA{
	nodo *frente;
	nodo *final;
	int num_elementos;
}cola;

//Funciones de la cola

void iniciar_cola(cola *c){
	c->frente = NULL; c->final = NULL; c->num_elementos = 0;
}

void encolar(cola *c, elemento dato){
	
	nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
	
	if(nuevo_nodo == NULL){
		printf("ERROR. Ya no hay memoria disponible\n");
	}
	
	if(es_vacia(c) == 1){
		c->frente = nuevo_nodo; c->final = nuevo_nodo;
		c->final->dato = dato; c->final->nodo_siguiente = NULL;
		c->num_elementos++;
	}else{
		c->final->nodo_siguiente = nuevo_nodo;
		c->final = nuevo_nodo;
		c->final->dato = dato;
		c->final->nodo_siguiente = NULL;
		c->num_elementos++;
	}
}

elemento desencolar(cola *c){
	
	nodo *aux; elemento element;
	
	if(es_vacia(c) == 1){
		printf("ERROR. Subdesbordamiento de cola\n");
	}else{
		aux = c->frente;
		element = aux->dato;
		c->frente = c->frente->nodo_siguiente;
		free(aux);
		c->num_elementos--;
		return element;
	}
	
}

int es_vacia(cola *c){
	if(c->final == NULL){
		return 1;
	}else{
		return 0;
	}
}

void frente(cola *c){
	if(es_vacia(c) == 1){
		printf("ERROR. La cola no tiene un frente debido a que esta vacia\n");
	}else{
		printf("El frente de la cola es -> %d\n", c->frente->dato);
	}
}

void final(cola *c){
	if(es_vacia(c) == 1){
		printf("ERROR. La cola no tiene un final debido a que esta vacia\n");
	}else{
		printf("El final de la cola es -> %d\n", c->final->dato);
	}
}

void element(cola *c, int posicion){
	int cont = 1; nodo *aux = c->frente;
	
	if(es_vacia(c) == 1){
		printf("La cola esta vacia, no hay elementos para buscar\n");
	}else{
		if(posicion <= c->num_elementos){
			while(cont < posicion){
				aux = aux->nodo_siguiente;
				cont++;
			}
			printf("El elemento en la posicion %d es -> %d\n", posicion, aux->dato);
		}else{
			printf("ERROR. Esta tratando de acceder a una posicion inexistente\n");
		}
	}
}


int tam(cola *c){
	return c->num_elementos;
}

void eliminar_cola(cola *c){
	nodo *aux;
	while(c->frente != NULL){
		aux = c->frente;
		c->frente = c->frente->nodo_siguiente;
		free(aux);
	}
	c->num_elementos = 0;
	c->final = NULL;
}

//////////////////////////////////////////////////////////////////////

int main(){
	cola c; elemento e1,e2,e3,e4,e5,e6;
	e1.x = 10; e2.x = 20; e3.x = 30; e4.x = 40; e5.x = 50; e6.x = 60;
	
	//elemento *p_A;
	//p_A = &c.A;
	
	//printf("%p\n",p_A);
	
	//Se llama a iniciar_cola
	iniciar_cola(&c);
	
	//Se insertan los 3 primeros elementos
	encolar(&c,e1);
	encolar(&c,e2);
	encolar(&c,e3);
	
	//Se pregunta por el frente y final de la cola
	frente(&c);
	final(&c);
	
	//Se sacan 2 elementos de la cola
	printf("El elemento desencolado es -> %d\n", desencolar(&c));
	printf("El elemento desencolado es -> %d\n", desencolar(&c));
	
	//Se pregunta por el frente, final y tamaño de la cola
	frente(&c);
	final(&c);
	printf("El tam de la cola es -> %d\n",tam(&c));
	
	//Se meten 3 elementos mas
	encolar(&c,e4);
	encolar(&c,e5);
	encolar(&c,e6);
	
	//Se pregunta por el frente, final y tamaño de la cola
	frente(&c);
	final(&c);
	printf("El tam de la cola es -> %d\n",tam(&c));
	
	//Se encola otro elemento
	encolar(&c,e1);
	
	//Se pregunta por el frente, final y tamaño de la cola
	frente(&c);
	final(&c);
	printf("El tam de la cola es -> %d\n",tam(&c));
	
	//----Se trata de encolar otro elemento
	encolar(&c,e2);
	
	//----Se pregunta por el frente, final y tamaño de la cola
	frente(&c);
	final(&c);
	printf("El tam de la cola es -> %d\n",tam(&c));
	
	//Se busca el dato en la posicion 5 de la cola
	element(&c,5);
	
	//Se saca un elemento de la cola
	desencolar(&c);
	//se pregunta por el frente, final y tam de la cola
	frente(&c);
	final(&c);
	printf("El tam de la cola es -> %d\n",tam(&c));
	
	
	
	//Se elimina la cola
	eliminar_cola(&c);
	
	//se pregunta por el frente, final y tam de la cola
	frente(&c);
	final(&c);
	printf("El tam de la cola es -> %d\n",tam(&c));

	return 0;
}
