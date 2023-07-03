//Programa para implementar un TAD de lista lineal vinculada
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct nodo{
	int dato;	
	struct nodo *sig;
};

//--------PROTOTIPOS DE FUNCION-------------------
struct nodo *inicio = NULL;
struct nodo *crear_list(struct nodo *);
struct nodo *mostrar(struct nodo *);
struct nodo *insertar_inicio(struct nodo *);
struct nodo *insertar_final(struct nodo *);
struct nodo *insertar_antes(struct nodo *);
struct nodo *insertar_desp(struct nodo *);
struct nodo *eliminar_inicio(struct nodo *);
struct nodo *eliminar_final(struct nodo *);
struct nodo *eliminar_node(struct nodo *);
struct nodo *eliminar_despues(struct nodo *);
struct nodo *eliminar_lista(struct nodo *);

int main(void){
	int op;
	do{
		printf("\n*****OPERACIONES DE LA LISTA ENLAZADA*****");
		printf("\n1. CREAR LISTA");
		printf("\n2.MOSTRAR LISTA");
		printf("\n3.AGREGAR NODO AL INICIO");
		printf("\n4.AGREGAR NODO AL FINAL");
		printf("\n5.AGREGAR UN NODO ANTES DE UN NODO DADO");
		printf("\n6.AGREGAR UN NODO DESPUES DE UN NODO DADO");
		printf("\n7.ELIMINAR UN NODO DEL INICIO");
		printf("\n8.ELIMINAR UN NODO DEL FINAL");
		printf("\n9.ELIMINAR UN NODO DADO");
		printf("\n10.ELIMINAR UN NODO DESPUES DE UN NODO DADO");
		printf("\n11.ELIMINAR LA LISTA COMPLETA");
		printf("\n12.SALIR");
		printf("\n\nIngresa la operacion que deseas elegir: ");
		scanf("%d",&op);
		switch(op)
		{
			
			case 1: 
				inicio = crear_list(inicio);
				printf("\nLISTA ENLAZADA CREADA");
				break;
				
			case 2:
				inicio = mostrar(inicio);
				break; 
			
			case 3:
				inicio = insertar_inicio(inicio);
				break;
				
			case 4:
				inicio = insertar_final(inicio);
				break;
				
			case 5:
				inicio = insertar_antes(inicio);
				break;
				
			case 6:
				inicio = insertar_desp(inicio);
				break;
				
			case 7:
				inicio = eliminar_inicio(inicio);
				break;
				
			case 8:
				inicio = eliminar_final(inicio);
				break;
				
			case 9:
				inicio = eliminar_node(inicio);
				break;
				
			case 10:
				inicio = eliminar_despues(inicio);
				break;
				
			case 11:
				inicio = eliminar_lista(inicio);
				printf("\nLISTA ENLAZADA ELIMINADA");
				break;
		}	
	}
	while(op != 12);
	getch();
	return 0;
}


//Funcion para crear la lista
struct nodo *crear_list(struct nodo *inicio){
	struct nodo *nuevo_nodo, *ptr;
	int num;
	printf("\nIngrese -1 para finalizar");
	printf("\nIngrese su dato: ");
	scanf("%d",&num);
	while(num != -1){
		nuevo_nodo = (struct nodo*)malloc(sizeof(struct nodo));
		nuevo_nodo ->dato = num;
		if(inicio == NULL){
			nuevo_nodo->sig = NULL;
			inicio = nuevo_nodo;
		}
		else{
			ptr=inicio;	
			while(ptr->sig!=NULL){
				ptr=ptr->sig;
				ptr->sig=nuevo_nodo;
				nuevo_nodo->sig=NULL;
			}
		}
		printf("\nIngrese su dato: ");
		scanf("%d",&num);
	}	
	return inicio;
}

//Funcion para mostrar los datos de la lista
struct nodo *mostrar(struct nodo *inicio){
	struct nodo *ptr;
	ptr=inicio;
		while(ptr != NULL){
			printf("\t %d",ptr ->dato);
			ptr=ptr->sig;
		}
	return inicio;
}

//Funcion para insertar un nodo al inicio
struct nodo *insertar_inicio(struct nodo *inicio){
	struct nodo *nuevo_nodo;
	int num;
	printf("\nIngrese su dato: ");
	scanf("%d",&num);
	nuevo_nodo=(struct nodo*)malloc(sizeof(struct nodo));
	nuevo_nodo->dato=num;
	nuevo_nodo->sig=inicio;
	inicio=nuevo_nodo;
	return inicio;
}


//Funcion para insertar un nodo al final
struct nodo *insertar_final(struct nodo *inicio){
	struct nodo *ptr, *nuevo_nodo;
	int num;
	printf("\nIngrese su dato: ");
	scanf("%d",&num);
	nuevo_nodo=(struct nodo*)malloc(sizeof(struct nodo));
	nuevo_nodo->dato=num;
	nuevo_nodo->sig=NULL;
	ptr=inicio;
		while(ptr->sig != NULL){
			ptr = ptr->sig;
			ptr->sig=nuevo_nodo;
		}
	return inicio;
}


//Funcion para insertar un nodo antes de uno dado
struct nodo *insertar_antes(struct nodo *inicio){
	struct nodo *nuevo_nodo, *ptr, *preptr;
	int num, val;
	printf("\nIngrese su dato: ");
	scanf("%d",&num);
	printf("\nIngrese el valor anterior a donde el dato no ha sido insertado: ");
	scanf("%d",&val);	
	nuevo_nodo=(struct nodo *)malloc(sizeof(struct nodo));
	nuevo_nodo->dato=num;
	ptr=inicio;
		while(ptr->dato!=val){
			preptr =ptr;
			ptr=ptr->sig;
		}
	preptr->sig=nuevo_nodo;
	nuevo_nodo->sig=ptr;
	return inicio;
}

//Funcion para insertar un nodo despues de uno dado
struct nodo *insertar_desp(struct nodo *inicio){
	struct nodo *nuevo_nodo, *ptr, *preptr;
	int num, val;
	printf("\nIngrese su dato: ");
	scanf("%d",&num);
	printf("\nIngrese el valor posterior a donde se insertara el dato: ");
	scanf("%d",&val);
	nuevo_nodo = (struct nodo *)malloc(sizeof(struct nodo));
	nuevo_nodo->dato=num;
	ptr=inicio;
	preptr=ptr;
	while(preptr->dato!=val){
		preptr =ptr;
		ptr=ptr->sig;		
	}
	preptr->sig=nuevo_nodo;
	nuevo_nodo ->sig=ptr;
	return inicio;
}


//Funcion para eliminar un nodo del inicio
struct nodo *eliminar_inicio(struct nodo *inicio){
	struct nodo *ptr;
	ptr = inicio;
	inicio = inicio->sig;
	free(ptr);
	return inicio;
}

//Funcion para eliminar un nodo al final
struct nodo *eliminar_final(struct nodo *inicio){

 struct nodo *ptr, *preptr;
 ptr = inicio;
 while(ptr->sig != NULL){
 	preptr = ptr;
 	ptr = ptr -> sig;	
 }
 preptr -> sig = NULL;
 free(ptr);
 return inicio;
}

//Funcion para eliminar nodo
struct nodo *eliminar_node(struct nodo *inicio){
	struct nodo *ptr, *preptr;
	int val;
	printf("\nIngresa el valor del nodo que deseas eliminar: ");
	scanf("",&val);
	ptr = inicio;
	if(ptr->dato == val){
		inicio= eliminar_inicio(inicio);
		return inicio;
	}
	else{
		while(ptr->dato != val){
			preptr =ptr;
			ptr =ptr ->sig;
		}
		preptr->sig =ptr-> sig;
		free(ptr);
		return inicio;
	}
}


//Funcion para eliminar un nodo despues del que se haya ingresddo
struct nodo *eliminar_despues(struct nodo *inicio){
	struct nodo *ptr, *preptr;
	int val;
	printf("\nIngresa el valor despues del nodo que se desea eliminar: ");
	scanf("%d",&val);
	ptr = inicio;
	preptr = ptr;
		while(preptr-> dato != val){
			preptr = ptr;
			ptr = ptr -> sig;
		}
	preptr->sig=ptr->sig;
	free(ptr);
	return inicio;
}

//Funcion para eliminar toda la lista
struct nodo *eliminar_lista(struct nodo *inicio){
	struct nodo *ptr;
		if(inicio != NULL){
			ptr = inicio;
			while(ptr != NULL){
				printf("\n %d va a ser eliminado", ptr->dato);
				inicio = eliminar_inicio(ptr);
				ptr = inicio;
			}
		}
	return inicio;
}
