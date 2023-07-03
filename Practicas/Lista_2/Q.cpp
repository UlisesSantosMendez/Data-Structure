#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int TipoDato;

typedef struct DPST{
	TipoDato dato;
	struct DPST *ds;
	struct DPST *is;
}Nodo;

typedef struct INR{
	int nelementos;
	struct DPST *raiz;
}Indicador;

//////////////////////////////////////////////

Indicador* CrearArbol(Indicador *tree);

Nodo* CrearNodo(TipoDato elemento);

void InsertarElemento(Indicador *tree, TipoDato elemento);

int EliminarElemento(Indicador *tree, TipoDato elemento);

Nodo* Busqueda(Nodo *tree, TipoDato elemento);

Nodo* Espejo(Nodo *tree);

void Inorden(Nodo *tree);

void Preorden(Nodo *tree);

void Postorden(Nodo *tree);

/////////////////////////////////////////////

int main(void){
	Indicador *Arbol;
	Arbol=CrearArbol(Arbol);
	Nodo *muestra;
	int opcion, mirror=0;
	TipoDato elemento, eliminado;
	
	do{
		printf("\nBienvenido al programa de arbol binario\n");
		printf("Insertar elemento............................................................[1]\n");
		printf("Eliminar elemento............................................................[2]\n");
		printf("Busqueda de elemento.........................................................[3]\n");
		printf("Espejo.......................................................................[4]\n");
		printf("Salir del programa...........................................................[5]\n");
		printf("\nArbol en Inorden: ");
		Inorden(Arbol->raiz);
		printf("\nArbol en Preorden: ");
		Preorden(Arbol->raiz);
		printf("\nArbol en Postorden: ");
		Postorden(Arbol->raiz);
		printf("\nEl numero de elementos en tu arbol es de: %d\n",Arbol->nelementos);	
		
		printf("\nEl dato eliminado es: %d\n",eliminado);
		
		printf("\nPor favor escoja una opcion del menu:\n");
		scanf("%d",&opcion);
		
		if(opcion==1){
			printf("Introduzca el dato de su preferencia\n");
			scanf("%d",&elemento);
			system("cls");
			InsertarElemento(Arbol,elemento);
		}
		else if(opcion==2){
			printf("Introduzca el dato de su preferencia\n");
			scanf("%d",&elemento);
			system("cls");
			eliminado=EliminarElemento(Arbol,elemento);
		}
		else if(opcion==3){
			printf("Introduzca el dato de su preferencia\n");
			scanf("%d",&elemento);
			system("cls");
			muestra=Busqueda(Arbol->raiz,elemento);
			if(muestra!=NULL){
				printf("El dato %d si se encuentra en el arbol\n",muestra->dato);
			}
		}
		else if(opcion==4){
			system("cls");
			Arbol->raiz=Espejo(Arbol->raiz);
			if(Arbol->raiz==NULL){
				printf("El arbol se encuentra vacio\n");
			}
		}
		else{
			printf("Opcion invalida\n");
		}
	}while(opcion!=5);
	
	
	return 0;
}

////////////////////////////////////////////

Indicador* CrearArbol(Indicador *tree){
	tree=(Indicador*)malloc(sizeof(Indicador));
	tree->nelementos=0;
	tree->raiz=NULL;
	return tree;
}

Nodo* CrearNodo(TipoDato elemento){
	Nodo *rama;
	rama=(Nodo*)malloc(sizeof(Nodo));
	rama->dato=elemento;
	rama->ds=NULL;
	rama->is=NULL;
	return rama;
}

void InsertarElemento(Indicador *tree, TipoDato elemento){
	Nodo *rama, *comp;
	if(tree->nelementos==0){
		rama=CrearNodo(elemento);
		tree->raiz=rama;
		tree->nelementos++;
	}
	else{
		rama=CrearNodo(elemento);
		comp=tree->raiz;
		do{
			if(rama->dato>comp->dato){
				if(comp->ds!=NULL){
					comp=comp->ds;
				}
				else{
					comp->ds=rama;
					tree->nelementos++;
					comp=NULL;
				}
			}
			else if(rama->dato<comp->dato){
				if(comp->is!=NULL){
					comp=comp->is;
				}
				else{
					comp->is=rama;
					tree->nelementos++;
					comp=NULL;
				}
			}
			else{
				printf("El valor que intenta agregar ya se encuentra contenido en el arbol binario\n");
				free(rama);
				comp=NULL;	
			}
		}while(comp!=NULL);
	}
	return;
}

int EliminarElemento(Indicador *tree, TipoDato elemento){
	int comp;
	TipoDato eliminado;
	Nodo *sup, *aux, *camb, *apy, *hlp;
	comp=tree->nelementos;
	if(tree->nelementos==0){
		printf("Tu arbol se encuentra vacio\n");
	}
	else if(elemento==(tree->raiz)->dato){
		if((tree->raiz)->ds==NULL && (tree->raiz)->is==NULL){
			tree->nelementos--;
			eliminado=(tree->raiz)->dato;
			sup=tree->raiz;
			tree->raiz=NULL;
			free(sup);
			printf("Caso 1\n");
		}
		else if((tree->raiz)->ds==NULL){
			sup=tree->raiz;
			tree->raiz=(tree->raiz)->is;
			tree->nelementos--;
			eliminado=sup->dato;
			free(sup);
			printf("Caso 2\n");
		}
		else{
			aux=tree->raiz;
			camb=aux->ds;
			while(camb->is!=NULL){
				aux=camb;
				camb=aux->is;
			}
			if(camb->ds!=NULL){
				if(aux==tree->raiz){
					tree->raiz=camb;
					camb->is=aux->is;
					tree->nelementos--;
					eliminado=aux->dato;
					free(aux);
					printf("Caso 3\n");
				}
				else{
					sup=tree->raiz;
					aux->is=camb->ds;
					camb->is=sup->is;
					camb->ds=sup->ds;
					tree->raiz=camb;
					tree->nelementos--;
					eliminado=sup->dato;
					free(sup);
					printf("Caso 4\n");
				}
			}
			else{
				if(aux==tree->raiz){
					tree->raiz=camb;
					camb->is=aux->is;
					tree->nelementos--;
					eliminado=aux->dato;
					free(aux);
					printf("Caso 5\n");
				}
				else{
					aux->is=NULL;
					sup=tree->raiz;
					camb->is=sup->is;
					camb->ds=sup->ds;
					tree->raiz=camb;
					tree->nelementos--;
					eliminado=sup->dato;
					free(sup);
					printf("Caso 6\n");
				}
			}
		}
	}
	else if(elemento<(tree->raiz)->dato && (tree->raiz)->is!=NULL){
		aux=tree->raiz;
		sup=aux->is;
		while(sup!=NULL){
			if(sup->dato==elemento){
				if(sup->dato<aux->dato){
					if(sup->is==NULL && sup->ds==NULL){
						eliminado=sup->dato;
						aux->is=NULL;
						tree->nelementos--;
						free(sup);
						sup=NULL;
						printf("Caso 7\n");
					}
					else if(sup->ds==NULL){
						aux->is=sup->is;
						eliminado=sup->dato;
						tree->nelementos--;
						free(sup);
						printf("Caso 8\n");
					}
					else{
						apy=sup;
						camb=apy->ds;
						while(camb->is!=NULL){
							apy=camb;
							camb=apy->is;
						}
						if(camb->ds!=NULL){
							if(apy==sup){
								aux->is=camb;
								camb->is=sup->is;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 9\n");
							}
							else{
								hlp=camb->ds;
								apy->is=hlp;
								aux->is=camb;
								camb->is=sup->is;
								camb->ds=sup->ds;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 10\n");
							}
						}
						else{
							if(apy==sup){
								aux->is=camb;
								camb->is=sup->is;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 11\n");
							}
							else{
								aux->is=camb;
								apy->is=NULL;
								camb->is=sup->is;
								camb->ds=sup->ds;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 12\n");
							}
						}
					}
				}
				else{
					if(sup->is==NULL && sup->ds==NULL){
						eliminado=sup->dato;
						aux->ds=NULL;
						tree->nelementos--;
						free(sup);
						printf("Caso 13\n");
					}
					else if(sup->ds==NULL){
						aux->ds=sup->is;
						eliminado=sup->dato;
						tree->nelementos--;
						free(sup);
						printf("Caso 14\n");
					}
					else{
						apy=sup;
						camb=apy->ds;
						while(camb->is!=NULL){
							apy=camb;
							camb=apy->is;
						}
						if(camb->ds!=NULL){
							if(apy==sup){
								aux->ds=camb;
								camb->is=sup->is;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 15\n");
							}
							else{
								hlp=camb->ds;
								apy->is=hlp;
								aux->ds=camb;
								camb->is=sup->is;
								camb->ds=sup->ds;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 16\n");
							}
						}
						else{
							if(apy==sup){
								aux->ds=camb;
								camb->is=sup->is;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 17\n");
							}
							else{
								aux->ds=camb;
								apy->is=NULL;
								camb->is=sup->is;
								camb->ds=sup->ds;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 18\n");
							}
						}
					}
				}
			}
			else if(elemento<sup->dato){
				aux=sup;
				sup=sup->is;
				printf("Movimiento menor\n");
			}
			else{
				aux=sup;
				sup=sup->ds;
				printf("Movimiento mayor\n");
			}
		}
		return eliminado;
	}
	else if(elemento>(tree->raiz)->dato && (tree->raiz)->ds!=NULL){
		aux=tree->raiz;
		sup=aux->ds;
		while(sup!=NULL){
			if(sup->dato==elemento){
				if(sup->dato<aux->dato){
					if(sup->is==NULL && sup->ds==NULL){
						eliminado=sup->dato;
						aux->is=NULL;
						tree->nelementos--;
						free(sup);
						sup=NULL;
						printf("Caso 7\n");
					}
					else if(sup->ds==NULL){
						aux->is=sup->is;
						eliminado=sup->dato;
						tree->nelementos--;
						free(sup);
						printf("Caso 8\n");
					}
					else{
						apy=sup;
						camb=apy->ds;
						while(camb->is!=NULL){
							apy=camb;
							camb=apy->is;
						}
						if(camb->ds!=NULL){
							if(apy==sup){
								aux->is=camb;
								camb->is=sup->is;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 9\n");
							}
							else{
								hlp=camb->ds;
								apy->is=hlp;
								aux->is=camb;
								camb->is=sup->is;
								camb->ds=sup->ds;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 10\n");
							}
						}
						else{
							if(apy==sup){
								aux->is=camb;
								camb->is=sup->is;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 11\n");
							}
							else{
								aux->is=camb;
								apy->is=NULL;
								camb->is=sup->is;
								camb->ds=sup->ds;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 12\n");
							}
						}
					}
				}
				else{
					if(sup->is==NULL && sup->ds==NULL){
						eliminado=sup->dato;
						aux->ds=NULL;
						tree->nelementos--;
						free(sup);
						printf("Caso 13\n");
					}
					else if(sup->ds==NULL){
						aux->ds=sup->is;
						eliminado=sup->dato;
						tree->nelementos--;
						free(sup);
						printf("Caso 14\n");
					}
					else{
						apy=sup;
						camb=apy->ds;
						while(camb->is!=NULL){
							apy=camb;
							camb=apy->is;
						}
						if(camb->ds!=NULL){
							if(apy==sup){
								aux->ds=camb;
								camb->is=sup->is;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 15\n");
							}
							else{
								hlp=camb->ds;
								apy->is=hlp;
								aux->ds=camb;
								camb->is=sup->is;
								camb->ds=sup->ds;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 16\n");
							}
						}
						else{
							if(apy==sup){
								aux->ds=camb;
								camb->is=sup->is;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 17\n");
							}
							else{
								aux->ds=camb;
								apy->is=NULL;
								camb->is=sup->is;
								camb->ds=sup->ds;
								eliminado=sup->dato;
								tree->nelementos--;
								free(sup);
								printf("Caso 18\n");
							}
						}
					}
				}
			}
			else if(elemento<sup->dato){
				aux=sup;
				sup=sup->is;
				printf("Movimiento menor\n");
			}
			else{
				aux=sup;
				sup=sup->ds;
				printf("Movimiento mayor\n");
			}
		}
		return eliminado;
	}
	else{
		printf("El elemento que deseas eliminar no se encuentra en el arbol\n");
	}
	//return eliminado;
}

Nodo* Busqueda(Nodo *tree, TipoDato elemento){
	while(tree!=NULL){
		if(tree->dato==elemento){
			return tree;
		}
		else if(tree->ds!=NULL && elemento>tree->dato){
			tree=tree->ds;
		}
		else if(tree->is!=NULL && elemento<tree->dato){
			tree=tree->is;
		}
		else{
			printf("El elemento que deseas buscar no se encuentra en el arbol\n");
			return NULL;
		}
	}
	printf("Tu arbol se encuentra vacio\n");
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////

Nodo* Espejo(Nodo *tree){
	Nodo *mirror;
	if(tree!=NULL){
		Espejo(tree->is);
		Espejo(tree->ds);
		mirror=tree->is;
		tree->is=tree->ds;
		tree->ds=mirror;
	}
}

////////////////////////////////////////////////////////////////////////////////

Nodo* MenorValor(Nodo *mn){
	if(mn->is==NULL){
		return mn;
	}
	else{
		return MenorValor(mn->is);
	}
}

void Inorden(Nodo *tree){
	if(tree!=NULL){
		Inorden(tree->is);
		printf("%d ",tree->dato);
		Inorden(tree->ds);
	}
	return;
}

void Preorden(Nodo *tree){
	if(tree!=NULL){
		printf("%d ",tree->dato);
		Preorden(tree->is);
		Preorden(tree->ds);
	}
	return;
}

void Postorden(Nodo *tree){
	if(tree!=NULL){
		Postorden(tree->is);
		Postorden(tree->ds);
		printf("%d ",tree->dato);
	}
}





