#include<stdio.h>
#include<stdlib.h>
#define MAX_VALUE 11

//SE RECOMIENDA EL USO DE LOS SIGUIENTES DATOS

// 525, 79, 25, 49, 31, 69, 6, 1, 21, 89

///////////////////////////////////////////ESTRUCTURAS//////////////////////////////////////////
typedef struct ELEMENTO{
	int entero_x;
	int llave;
}elemento;

typedef struct NODO{
	elemento *dato;
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

nodo* crear_nodo(elemento *dato){
	
	nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
	
	if(nuevo_nodo == NULL){
		printf("ERROR al generar el nodo para al elemento.\n");
		return nuevo_nodo;
	}else{
		nuevo_nodo->dato = dato; nuevo_nodo->nodo_siguiente = NULL; 
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

void eliminar_elemento_lista(lista *lista, elemento *dato){
	nodo *anterior, *actual, *auxf, *posicion; int control;
	
	posicion = lista->cabeza;
	while(posicion != NULL){
		if(posicion->dato->entero_x == dato->entero_x){
			control = 1; posicion = NULL;
		}else{
			posicion = posicion->nodo_siguiente;
		}
	}
	
	switch(control){
		case 1:	if(lista->cabeza->dato->entero_x == dato->entero_x){
					auxf = lista->cabeza;
					lista->cabeza = lista->cabeza->nodo_siguiente;
					free(auxf); lista->num_elementos--;
				}else{
					anterior = lista->cabeza; actual = lista->cabeza->nodo_siguiente;
					while(actual != NULL){
						if(actual->dato->entero_x == dato->entero_x){
							auxf = actual;
							anterior->nodo_siguiente = actual->nodo_siguiente;
							free(auxf); lista->num_elementos--;
							actual = NULL;
						}else{
							anterior = actual;
							actual = actual->nodo_siguiente;
						}
					}
				}
				break;
		default: printf("El elemento no se encuntra en la lista.\n");
	}
}

int buscar_lista(lista *lista, elemento *dato){
	int control = 0; nodo *aux;
	
	aux = lista->cabeza;
	while(aux != NULL){
		if(aux->dato->entero_x != dato->entero_x){
			aux = aux->nodo_siguiente;
		}else{
			control = 1; aux = NULL;
		}
	}
	return control;
}

void imprimir_lista(lista *lista){
	nodo *aux; aux = lista->cabeza;
	while(aux != NULL){
		printf("%d -> ",aux->dato->entero_x);
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

int hash(elemento *dato){
	int llave = (dato->entero_x % (MAX_VALUE-1)) + 1;
	return llave;
}

void insertar(t_hash *t, elemento *dato){
	
	dato->llave = hash(dato);
	if(dato->llave >= MAX_VALUE){
		printf("ERROR. El dato no puede ser insertado\n");
	}else{
		if(t->listas[dato->llave] == NULL){
			lista *nueva_lista =(lista*)malloc(sizeof(lista)); 
			iniciar_lista(nueva_lista); insertar_lista(nueva_lista,crear_nodo(dato));
			t->listas[dato->llave] = nueva_lista;
		}else{
			insertar_lista(t->listas[dato->llave],crear_nodo(dato));
		}
	}
}

void eliminar(t_hash *t, elemento *dato){
	dato->llave = hash(dato);
	if(dato->llave >= MAX_VALUE){
		printf("ERROR. El elemento no se encuntra en la tabla.\n");
	}else{
		if(t->listas[dato->llave] == NULL){
			printf("ERROR. El elemento no se encuntra en la tabla.\n");
		}else{
			eliminar_elemento_lista(t->listas[dato->llave],dato);
		}
	}
}

void buscar(t_hash *t, elemento *dato){
	dato->llave = hash(dato); int res;
	
	if(dato->llave >= MAX_VALUE){
		printf("ERROR. El elemento no se encuntra en la tabla.\n");
	}else{
		if(t->listas[dato->llave] == NULL){
			printf("ERROR. El elemento no se encuntra en la tabla.\n");
		}else{
			res = buscar_lista(t->listas[dato->llave],dato);
			if(res == 1 ){
				printf("El dato se encuentra en la lista de la posicion -> %d -> de la tabla\n",dato->llave);
			}else{
				printf("El dato NO esta en la lista de la posicion -> %d -> de la tabla\n",dato->llave);
			}
		}
	}
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
//////////////////////////////////////////////////////////////////////////////////


void menu(t_hash *t){
	
	int op; elemento *element;
	
	printf("------IMPLEMENTACION DE UNA TABLA HASH ABIERTA------\n");
	printf("Selecciona la opcion que deseas realziar\n");
	printf("1.- Insertar elemento\n");
	printf("2.- Eliminar elemento\n");
	printf("3.- Buscar elemento\n");
	printf("4.- Mostrar tabla\n\n");
	printf("Tu eleccion -> "); scanf(" %d",&op);
	
	switch(op){
		
		case 1: system("cls"); char c = 's'; 
				while(c == 's'){
					element = (elemento*)malloc(sizeof(elemento));
					if(element == NULL){
						printf("ERROR al generar la variable.\n");
					}else{
						printf("Introduce el elemento a insertar -> "); scanf(" %d", &element->entero_x);
						insertar(t,element);
						printf("\nDeseas seguir insertando elementos ? Pulsa 's' para si y 'n' para no.\n\n");
						printf("Tu decision -> "); scanf(" %c",&c); printf("\n");
					}
				}
				system("cls"); menu(t);
				break;
		case 2: system("cls"); element = (elemento*)malloc(sizeof(elemento));
				printf("Introduce el dato que deseas eliminar -> "); scanf(" %d",&element->entero_x);
				eliminar(t,element); system("pause"); system("cls"); menu(t);
				break;
		case 3: system("cls"); element = (elemento*)malloc(sizeof(elemento));
				printf("Introduce el dato que deseas buscar -> "); scanf(" %d",&element->entero_x);
				buscar(t,element); system("pause"); system("cls"); menu(t); 
				break;
		case 4: system("cls"); imprimir_tabla(t); system("pause"); system("cls"); menu(t);
				break;
		default: printf("Esa opcion no es valida. Selecciona una que si lo sea.");
		menu(t);
	}
	
}

int main(){
	t_hash t; crear_tabla(&t); menu(&t);
	
	return 0;
}
