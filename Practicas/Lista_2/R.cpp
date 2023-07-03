#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct nodo abb;

struct nodo{
	int dato;
	abb*izquierdo;
	abb*derecho;
};


abb*cambia(abb*arbol,abb*arbol1);
int num_nodos(abb*arbol);
abb*suprimir(abb*arbol,int dato);
int buscar(abb*arbol,int dato);
int buscar_min(abb*arbol);
int buscar_max(abb*arbol);
void ver(int nivel,abb*arbol);
void pre_orden(abb*arbol);
void en_orden(abb*arbol);
void pos_orden(abb*arbol);
abb*insertar(int dato,abb*arbol);


int main(){
	
	int n,i,dato;
	char op;
	abb*arbol=NULL;
	
	while(1){
		printf("\nOperaciones Basicas con un Arbol Binario de Busqueda\n");
		printf("a= Llenar un arbol binario de busqueda manual\n");
		printf("b= Ver arbol\n");
		printf("c= Buscar minimo y maximo\n");
		printf("d= Contar nodos\n");
		printf("e= Buscar dato\n");
		printf("f= Ver recorridos (Pre-orde, En orden, Pos-orden)\n");
		printf("g= Suprimir dato\n");
		printf("h= Salir\n");
		printf("Eliga una opcion: \n");
		fflush( stdin );
		scanf("%c",&op);
		switch(op){
			case 'a':
				printf ("Numero de nodos del arbol\n");
				scanf("%d",&n);
				for(i=0;i<n;i++){
					printf("Elemento no.%d: \n",i+1);
					scanf("%d",&dato);
					arbol=insertar(dato,arbol);
				}
				break;
				
			case 'b': 
				printf("Arbol Binario de Busqueda\n");
				ver(0,arbol);
				break;
				
			case 'c':
				printf("El minimo nodo: %d",buscar_min(arbol));
				printf("\nEl maximo nodo: %d",buscar_max(arbol));
				break;
			
			case 'd':
				printf("Numeros de Nodos: %d",num_nodos(arbol));
				break;
			
			case 'e':
				printf("Ingresa el dato que deseas buscar: \n");
				scanf("%d",&dato);
				printf("\n");
				if(buscar(arbol,dato)!=NULL){
					printf("Se encontro el dato %d\n",dato);
				}else{
					printf("No se encontro el dato %d",dato);
				}
				break;
			
			case 'f':
				printf("Recorrido en Pre-orden: \n");
				pre_orden(arbol);
				printf("\nRecorrido En Orden:\n");
				en_orden(arbol);
				printf("\nRecorrido en Pos-Orden:\n");
				pos_orden(arbol);
				break;
			
			case 'g':
				printf("Ingresa el dato que quieres suprimir:\n");
				scanf("%d",&dato);
				suprimir(arbol,dato);
				break;
			
			case 'h':
				exit(1);
				break;
		}
	}
	
}


abb*crearnodo(int dato){
	abb*aux=(abb*)malloc(sizeof(abb));
	aux->dato=dato;
	aux->izquierdo=NULL;
	aux->derecho=NULL;
	return aux;
}

abb*cambia(abb*arbol,abb*arbol1){
	abb*temp;
	if(arbol1->derecho!=NULL)
	arbol1->derecho=cambia(arbol,arbol1->derecho);
	else{
		temp=arbol1;
		arbol->dato=arbol1->dato;
		arbol1=arbol1->izquierdo;
		free(temp);
	}
	return(arbol1);
}

int num_nodos(abb*arbol){
	if(arbol==NULL)
	return(0);
	return(num_nodos(arbol->izquierdo)+1+num_nodos(arbol->derecho));
}

abb*suprimir(abb*arbol,int dato){
	abb*temp;
	if(arbol==NULL){
		printf("\nArbol Vacio...\n");
	}else{
		if(dato<arbol->dato){
			arbol->izquierdo=suprimir(arbol->izquierdo,dato);
		}else{
			if(dato>arbol->dato){
				arbol->derecho=suprimir(arbol->derecho,dato);
			}else{
				temp=arbol;
				if(temp->derecho==NULL){
					arbol=temp->izquierdo;
					free(temp);
				}else{
					if(temp->izquierdo==NULL){
						arbol=temp->derecho;
						free(temp);
					}else{
						temp->izquierdo=cambia(temp,temp->izquierdo);
					}
				}
			}
		}
	}
	return(arbol);
}

int buscar(abb*arbol,int dato){
	if(arbol==NULL){
		return(NULL);
	}
	if(dato==arbol->dato){
		return(1);
	}
	if(dato<arbol->dato){
		return(buscar(arbol->izquierdo,dato));
	}else{
		return(buscar(arbol->derecho,dato));
	}
}

int buscar_min(abb*arbol){
	if(arbol==NULL){
		return(NULL);
	}else{
		if(arbol->izquierdo==NULL){
			return(arbol->dato);
		}else{
			return(buscar_min(arbol->izquierdo));
		}
	}
}

int buscar_max(abb*arbol){
	if(arbol==NULL){
		return (NULL);
	}else{
		if(arbol->derecho==NULL){
			return(arbol->dato);
		}else{
			return(buscar_max(arbol->derecho));
		}
	}
}

void ver(int nivel,abb*arbol){
	int i;
	if(arbol!=NULL){
		ver(nivel+1,arbol->derecho);
		printf("\n");
		for(i=0;i<nivel;i++)
		printf(" ");
		printf("%d",arbol->dato);
		ver(nivel+1,arbol->izquierdo);
	}
}

void pre_orden(abb*arbol){
	if(arbol!=NULL){
		printf("%d,",arbol->dato);
		pre_orden(arbol->izquierdo);
		pre_orden(arbol->derecho);	
	}
}

void en_orden(abb*arbol){
	if(arbol!=NULL){
		en_orden(arbol->izquierdo);
		printf("%d,",arbol->dato);
		en_orden(arbol->derecho);	
	}
}

void pos_orden(abb*arbol){
	if(arbol!=NULL){
		pos_orden(arbol->izquierdo);
		pos_orden(arbol->derecho);
		printf("%d,",arbol->dato);	
	}
}

abb*insertar(int dato,abb*arbol){
	if(arbol==NULL){
		arbol=crearnodo(dato);
		arbol->dato=dato;
		arbol->izquierdo=NULL;
		arbol->derecho=NULL;
		return(arbol);
	}
	if(dato<arbol->dato)
	arbol->izquierdo=insertar(dato,arbol->izquierdo);
	else
	arbol->derecho=insertar(dato,arbol->derecho);
	return(arbol);
}



