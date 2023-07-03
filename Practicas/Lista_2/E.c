#include<stdio.h>
#include<stdlib.h>
#define MAX_VALUE 11

//SE RECOMIENDA EL USO DE LOS SIGUIENTES DATOS

// 525, 79, 25, 49, 31, 69, 6, 1, 21, 89

typedef struct ELEMENTO{
	int entero_x;
	int llave;
}elemento;

typedef struct T_HASH{
	elemento *datos[MAX_VALUE];
}t_hash;

//FUNCIONES//

void crear_tabla(t_hash *t){
	int i;
	for(i = 0; i < MAX_VALUE; i++){
		t->datos[i] = NULL;	
	}
}

int hash(elemento *dato){
	
	int llave = (dato->entero_x % (MAX_VALUE-1)) + 1;
	return llave;
}


void insertar(t_hash *t, elemento *dato){
	int control;
	if(llena(t) == 1){
		printf("ERROR al introducir el dato. La tabla esta llena.\n");
	}else{
		dato->llave = hash(dato);		
		if(t->datos[dato->llave] == NULL){
			t->datos[dato->llave] = dato;
		}else{
			dato->llave++;
			if(dato->llave >= MAX_VALUE){
				dato->llave = 0; control = dato->llave;
				while(control < MAX_VALUE){
					if(t->datos[dato->llave]==NULL){
						t->datos[dato->llave] = dato;
						control = MAX_VALUE;
					}else{
						dato->llave++; control++;
					}
				}
			}else{
				control = dato->llave;
				while(control < MAX_VALUE){
					if(t->datos[dato->llave] == NULL){
						t->datos[dato->llave] = dato;
						control = MAX_VALUE;
					}else{
						dato->llave++;
					}
					control++;
				}	
			}
		}
	}
}

void eliminar(t_hash *t, int llave){
	if(llave >= MAX_VALUE-1){
		printf("ERROR. Se dio una llave invalida\n");
	}
	if(t->datos[llave] == NULL){
		printf("EROR. No hay ningun dato con esa llave.\n");
	}else{
		printf("El dato que eliminara es -> %d\n",*t->datos[llave]);
		free(t->datos[llave]);
		t->datos[llave] = NULL;
	}
}


void buscar(t_hash *t, int llave){
	
	if(llave >= MAX_VALUE-1){
		printf("ERROR. Se dio una llave invalida\n");
	}
	if(t->datos[llave] == NULL){
		printf("EROR. No hay ningun dato con esa llave.\n");
	}else{
		printf("El dato con esa llave es -> %d\n",*t->datos[llave]);
	}
}

void mostrar_tabla(t_hash *t){
	int i;
	for(i = 0; i < MAX_VALUE; i++){
		if(t->datos[i] == NULL){
			printf("Posicion %d  -> ",i); printf("NULL\n");
		}else{
			printf("Posicion %d  ->",i); printf("%d\n",*t->datos[i]);
		}
	}
}

int llena(t_hash *t){
	int i; int cont = 0;
	for(i = 0; i < MAX_VALUE; i++){
		if(t->datos[i] != NULL){
			cont++;
		}
	}
	if(cont == MAX_VALUE-1){
		return 1;
	}else{
		return 0;
	}
	
}

void menu(t_hash *t){
	
	int op; elemento *element;
	
	printf("----------IMPLEMENTACION DE UNA TABLA HASH CERRADA------------\n\n");
	printf(" Para seleccionar una opcion, introduce el numero de la misma\n\n");
	printf("    1.- Introducir elemento a la tabla\n");
	printf("    2.- Eliminar elemento de la tabla\n");
	printf("    3.- Buscar elemento en la tabla\n");
	printf("    4.- Mostrar tabla\n\n");
	printf(" Tu eleccion -> "); scanf("%d",&op);
	
	switch(op){
		case 1: system("cls"); char c = 's';
				while(c == 's'){
					element = (elemento*)malloc(sizeof(elemento));
					if(element == NULL){
						printf("ERROR al generar la variable\n");
					}
					printf("Introduce el elemento a insertar -> "), scanf("%d",&element->entero_x);
					insertar(t,element);
					printf("\nDeseas seguir insertando elementos ? Pulsa 's' para si y 'n' para no.\n\n");
					printf("Tu decision -> "); scanf(" %c",&c); printf("\n");
				}
				system("cls"); menu(t);	
				break;
		case 2: system("cls"); int llave;
				printf("Introduce la llave del dato que deseas eliminar -> "); scanf(" %d",&llave);
				eliminar(t,llave); system("pause"); system("cls"); menu(t);
				break;
		case 3: system("cls");
				printf("Introduce la llave del dato que deseas buscar -> "); scanf(" %d",&llave);
				buscar(t,llave); system("pause"); system("cls"); menu(t);
				break;
		case 4: system("cls"); mostrar_tabla(t); system("pause"); system("cls"); menu(t);
				break;
		default: printf("Esa no es una opcion valida. Intenta de nuevo.\n\n");
				 system("pause"); system("cls"); menu(t);
				 break;
	}
}
//////// MAIN DEL PROGRAMA///////////

int main(){
	/// Se recomiendan los siguiente numeros para su ejecucion rapida
	/// 525,79,25,49,31,69,6,1,21,89
	t_hash t; crear_tabla(&t); menu(&t);
	return 0;
}
