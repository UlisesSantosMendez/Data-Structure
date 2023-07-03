#include<stdio.h>
#define MAX_VALUE 5

//-------DECLARACION DE LAS ESTRUCTURAS-------//
typedef struct ELEMENTO{
	int x;
}elemento;

typedef struct COLA{
	elemento A[MAX_VALUE];
	int frente, final; 
	int num_elemento;
}cola;

//-------OPERACIONES DE UNA COLA-------//

void iniciar_cola(cola *c){
	c->frente = -1; c->final = -1; c->num_elemento = 0;
}

void encolar(cola *c, elemento dato){
	if(es_vacia(c) == 1){
		c->frente++; c->final++;
		c->A[c->final] = dato;
		c->num_elemento++;
	}else{
		if(es_llena(c) == 1){
			printf("Error. La cola esta llena.\n");
		}else{
			if(c->frente != 0 && c->final == MAX_VALUE-1){
				c->final = 0;
				c->A[c->final] = dato;
				c->num_elemento++;
			}else{
				c->final++;
				c->A[c->final] = dato;
				c->num_elemento++;
			}
		}
	}
}

elemento desencolar(cola *c){
	elemento element;
	if(es_vacia(c) == 1){
		printf("ERROR. No hay elementos para desencolar.\n");
	}else{
		element = c->A[c->frente];
		c->frente++;
		c->num_elemento--;
		return element;
	}
}
int es_vacia(cola *c){
	if(c->num_elemento == 0){
		return 1;
	}else{
		return 0;
	}
}
int es_llena(cola *c){
	if(c->num_elemento == MAX_VALUE){
		return 1;
	}else{
		return 0;
	}
}
void frente(cola *c){
	printf("El frente de la cola es -> %d\n", c->A[c->frente]);
}
void final(cola *c){
	printf("El final de la cola es -> %d\n", c->A[c->final]);
}
void element(cola *c, int posicion){
	
    int cont = 1, bandera = c->frente; 
    
	if(posicion > MAX_VALUE){
		printf("ERROR. Se esta tratando de acceder a una posicion inexistente\n");
	}else{
		while(cont < posicion){
			if(bandera == MAX_VALUE-1){
				bandera = -1;
			}
			bandera++; cont++;
		}
		printf("El dato que se encuentra en la posicion %d es -> %d\n", posicion, c->A[bandera]);
	}
}
void eliminar_cola(cola *c){
	iniciar_cola(c);
}
int tam(cola *c){
	return c->num_elemento;
}


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
	
	//Se trata de encolar otro elemento (MARCA EL ERROR, PUES LA COLA YA ESTA LLENA)
	encolar(&c,e2);
	
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
	
	//Se trata de desencolar un elemento (MARCA ERROR, PUES LA COLA ESTA VACIA)
	printf("", desencolar(&c));
	
	return 0;
}
