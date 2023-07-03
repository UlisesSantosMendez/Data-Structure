#include<stdio.h>
#include<stdlib.h>
#define MAX_VALUE 11
#define LIMITE_VELOCIDAD 100

//SE RECOMINEDA USAR LO SIGUIENTES DATOS

// 123MRJ, 275QRS, 616JMK, 958AXW, 293CMJ, 666RBK

///////////////////////////////////////////ESTRUCTURAS//////////////////////////////////////////
typedef struct CARRO{
	char placa[6];
	int num_infracciones;
	int llave;
}carro;

typedef struct NODO{
	carro *car;
	struct NODO *nodo_siguiente;
}nodo;


typedef struct LISTA{
	nodo *cabeza;
	int num_elementos;
}lista;

typedef struct T_HASH{
	lista *listas[MAX_VALUE];
}t_hash;

////////////////////////////////////////FUNCIONES DE LISTA//////////////////////////////////////////////////////
void iniciar_lista(lista *lista){
	lista->cabeza = NULL;
	lista->num_elementos = 0;
}

int es_vacia(lista *lista){
	if(lista->num_elementos == 0){
		return 1;
	}else{
		return 0;
	}
}

nodo* crear_nodo(carro *car){
	
	nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
	
	if(nuevo_nodo == NULL){
		printf("ERROR al generar el nodo para al elemento.\n");
		return nuevo_nodo;
	}else{
		nuevo_nodo->car = car; nuevo_nodo->nodo_siguiente = NULL; 
		return nuevo_nodo;
	}
}

void insertar_lista(lista *lista, nodo *nodo_nuevo){
	nodo *aux;
	
	if(es_vacia(lista) == 1){
		lista->cabeza = nodo_nuevo;
		lista->num_elementos++;
	}else{
		aux = lista->cabeza;
		while(aux != NULL){
			if(aux->nodo_siguiente == NULL){
				aux->nodo_siguiente = nodo_nuevo;
				lista->num_elementos++;
				aux = NULL;
			}else{
				aux = aux->nodo_siguiente;
			}
		}
		
	}
}


nodo* buscar_lista(lista *lista, carro *car){
	nodo *aux, *resultado = NULL; int res_strcmp;
	
	aux = lista->cabeza;
	while(aux != NULL){
		res_strcmp = strcmp(aux->car->placa, car->placa);
		if(res_strcmp != 0){
			aux = aux->nodo_siguiente;
		}else{
			resultado = aux; aux = NULL;
		}
	}
	return resultado;
}

void imprimir_lista(lista *lista){
	nodo *aux; aux = lista->cabeza;
	while(aux != NULL){
		printf("%s -> ",aux->car->placa);
		aux = aux->nodo_siguiente;
	}
	printf("NULL\t\t");printf("Num de elementos -> %d\n",lista->num_elementos);
}
//////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////FUNCIONES TABLA HASH///////////////////////////////////
void crear_tabla(t_hash *t){
	int i;
	for(i = 0; i < MAX_VALUE; i++){
		t->listas[i] = NULL;	
	}
}

int hash(carro *car){
	int suma = car->placa[3] + car->placa[4] + car->placa[5];
	int llave = (suma % (MAX_VALUE-1)) + 1;
	return llave;
}

void insertar(t_hash *t, carro *car){
	
	car->llave = hash(car);
	if(car->llave >= MAX_VALUE){
		printf("ERROR. El dato no puede ser insertado\n");
	}else{
		if(t->listas[car->llave] == NULL){
			lista *nueva_lista =(lista*)malloc(sizeof(lista)); 
			iniciar_lista(nueva_lista); insertar_lista(nueva_lista,crear_nodo(car));
			t->listas[car->llave] = nueva_lista;
		}else{
			insertar_lista(t->listas[car->llave],crear_nodo(car));
		}
	}
}

nodo* buscar(t_hash *t, carro *car){
	
	car->llave = hash(car); nodo *res;
	
	if(car->llave >= MAX_VALUE){
		res = NULL;
	}else{
		if(t->listas[car->llave] == NULL){
			res = NULL;
		}else{
			res = buscar_lista(t->listas[car->llave],car);
		}
	}
	return res;
}

void imprimir_tabla(t_hash *t){
	int i = 0;
	while(i < MAX_VALUE){
		if(t->listas[i] == NULL){
			printf("NULL\n");
		}else{
			imprimir_lista(t->listas[i]);
		}
		i++;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////FUNCIONES PARA EL TIPO DE DATO CARRO//////////////////////////////////////

void iniciar_carro(carro *car){
	car->num_infracciones = 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void menu(t_hash *t){
	
	int velocidad; int caso;  nodo *nodo_resul; carro *c;
	
	printf("Velocidad detectada por la pistola -> "); scanf(" %d", &velocidad);
	if(velocidad == LIMITE_VELOCIDAD){
		caso = 3;
	}else{
		if(velocidad < LIMITE_VELOCIDAD){
			caso = 2;
		}else{
			caso = 1;
		}
	}
	
	switch(caso){
		
		case 1:	printf("\nEl auto va por encima del limite de velocidad\n\n");
				c = (carro*)malloc(sizeof(carro)); iniciar_carro(c);
				printf("La placa se compone de 3 numeros, 3 letras (mayusculas) y sin espacios.\n\n");
				printf("Introduce la placa del automovil -> "); scanf(" %s",c->placa);
				nodo_resul = buscar(t,c);
				if(nodo_resul == NULL){
					printf("\nLa placa no se encuentra en la tabla, se procedera a insertar\n");system("pause");
					insertar(t,c); system("cls"); 
					imprimir_tabla(t); system("pause"); system("cls"); menu(t);
				}else{
					system("cls");
					printf("La placa ya se encuentra en la tabla.\n\n");
					printf("PLACA -> %s\n", nodo_resul->car->placa);
					nodo_resul->car->num_infracciones = nodo_resul->car->num_infracciones + 1;
					printf("Las veces que ha excedido el limite de velocidad es -> %d\n", nodo_resul->car->num_infracciones);system("pause"); system("cls"); menu(t);
				}
				system("pause");
				break;
		case 2: printf("El auto va por debajo del limite de velocidad\n"); system("pause"); system("cls"); menu(t);
				break;
		case 3: printf("El auto esta justamente en el limite de velocidad\n"); system("pause"); system("cls"); menu(t);
				break;
		default: printf("Caso inexistente\n"); system("pause"); system("cls"); menu(t);
	}

	
}

int main(){
	t_hash t; crear_tabla(&t); menu(&t);
}

