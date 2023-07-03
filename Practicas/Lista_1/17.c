#include <string.h>
#include <stdio.h>
#include <conio.h>
#define MAX 20
#define COMPV 1

typedef int TipoDato;

typedef struct alm{
	int numelm;
	TipoDato dato[MAX];
}Nodo;

void CrearOVaciarLista(Nodo* Lista);

void ImpresionLista(Nodo* Lista);

void ImprimirNelementos(Nodo *lista);

void InsertarFinal(Nodo* Lista, TipoDato elemento);

void InsertarInicio(Nodo* lista, TipoDato elemento);

TipoDato EliminarFinal(Nodo* lista);

TipoDato EliminarInicio(Nodo* lista);

void InsertarCPI(Nodo *lista, TipoDato elemento, int posicion);

TipoDato EliminarCPI(Nodo *lista, int posicion);

void ConcatenarListas(Nodo *plista, Nodo *slista);

void BuscarComunes(Nodo *plista, Nodo *slista);

void CambiarDato(Nodo *plista, Nodo *slista);

///////////////////////////////////////////////////////////////////////////																																Navarro Topete Jose Alberto

int main (void){
	Nodo LU, LD, *Lista, *SL;
	Lista=&LU;
	SL=&LD;
	CrearOVaciarLista(Lista);
	CrearOVaciarLista(SL);
	int posicion, opcion, nlista, nelista, ubicacion;
	TipoDato elemento, eliminado;
	
	do{
		system("cls");
		printf("\nBienvenido al programa de dos listas\n");
		printf("Insertar un elemento al inicio de la lista...................................[1]\n");
		printf("Insertar un elemento al final de la lista....................................[2]\n");
		printf("Insertar un elemento en un punto intermedio dentro del dominio de la lista...[3]\n");
		printf("Eliminar un elemento al inicio de la lista...................................[4]\n");
		printf("Eliminar un elemento al final de la lista....................................[5]\n");
		printf("Eliminar un elemento en un punto intermedio dentro del dominio de la lista...[6]\n");
		printf("Vaciar lista.................................................................[7]\n");
		printf("Concatenar listas............................................................[8]\n");
		printf("Numeros repetidos en ambas listas............................................[9]\n");
		printf("Pasar un dato de una lista a otra............................................[10]\n");
		printf("Salir del programa...........................................................[11]\n");
		
		printf("\nPrimer lista:\n");
		ImpresionLista(Lista);
		
		printf("\nSegunda lista:\n");
		ImpresionLista(SL);
		
		if(nelista==1){
			printf("\nEl valor eliminado de la primera lista fue: %d\n", eliminado);
		}
		else if(nelista==2){
			printf("\nEl valor eliminado de la primera lista fue: %d\n",eliminado);
		}
		else{
			printf("\n");
		}
		
		printf("\nPor favor escoja una opcion del menu:\n");
		scanf("%d",&opcion);
		
		if(opcion==1){
			printf("En cual lista gustas guardar tu dato?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				printf("Introduzca el dato de su preferencia\n");
				scanf("%d",&elemento);
				InsertarInicio(Lista,elemento);
			}
			else if(nlista==2){
				printf("Introduzca el dato de su preferencia\n");
				scanf("%d",&elemento);
				InsertarInicio(SL,elemento);
			}
			else
			printf("\n Opcion invalida\n");	
		}
		else if(opcion==2){
			printf("En cual lista gustas guardar tu dato?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				printf("Introduzca el dato de su preferencia\n");
				scanf("%d",&elemento);
				InsertarFinal(Lista,elemento);
			}
			else if(nlista==2){
				printf("Introduzca el dato de su preferencia\n");
				scanf("%d",&elemento);
				InsertarFinal(SL,elemento);
			}
			else
			printf("\n Opcion invalida\n");	
		}
		else if(opcion==3){
			printf("En cual lista gustas guardar tu dato?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				printf("Introduzca el dato de su preferencia\n");
				scanf("%d",&elemento);
				printf("Introduzca la posicion de su preferencia\n");
				scanf("%d",&posicion);
				InsertarCPI(Lista,elemento,posicion);
			}
			else if(nlista==2){
				printf("Introduzca el dato de su preferencia\n");
				scanf("%d",&elemento);
				printf("Introduzca la posicion de su preferencia\n");
				scanf("%d",&posicion);
				InsertarCPI(SL,elemento,posicion);
			}
			else
			printf("\n Opcion invalida\n");	
		}
		else if(opcion==4){
			printf("En cual lista gustas deseas borrar tu dato?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				eliminado=EliminarInicio(Lista);
				nelista=nlista;
			}
			else if(nlista==2){
				eliminado=EliminarInicio(SL);
				nelista=nlista;
			}
			else
			printf("\n Opcion invalida\n");
		}
		else if(opcion==5){
			printf("En cual lista gustas deseas borrar tu dato?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				eliminado=EliminarFinal(Lista);
				nelista=nlista;
			}
			else if(nlista==2){
				eliminado=EliminarFinal(SL);
				nelista=nlista;
			}
			else
			printf("\n Opcion invalida\n");
		}
		else if(opcion==6){
			printf("En cual lista gustas borrar tu dato?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				printf("Introduzca la posicion de su preferencia\n");
				scanf("%d",&posicion);
				eliminado=EliminarCPI(Lista,posicion);
				nelista=nlista;
			}
			else if(nlista==2){
				printf("Introduzca la posicion de su preferencia\n");
				scanf("%d",&posicion);
				eliminado=EliminarCPI(SL,posicion);
				nelista=nlista;
			}
			else
			printf("\n Opcion invalida\n");
		}
		else if(opcion==7){
			printf("Que lista deseas borrar?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				CrearOVaciarLista(Lista);
			}
			else if(nlista==2){
				CrearOVaciarLista(SL);
			}
			else
			printf("\n Opcion invalida\n");
		}
		else if(opcion==8){
			printf("En cual lista gustas guardar tu dato?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				ConcatenarListas(Lista, SL);
			}
			else if(nlista==2){
				ConcatenarListas(SL, Lista);
			}
			else
			printf("\n Opcion invalida\n");
			ConcatenarListas(Lista, SL);
		}
		else if(opcion==9){
			BuscarComunes(Lista, SL);
		}
		else if(opcion==10){
			printf("De que lista deseas cambiar el dato?\n");
			printf("Primera lista........[1]\n");
			printf("Segunda lista........[2]\n");
			scanf("%d",&nlista);
			if(nlista==1){
				CambiarDato(Lista,SL);
			}
			else if(nlista==2){
				CambiarDato(SL,Lista);
			}
			else
			printf("\n Opcion invalida\n");	
		}
		else if(opcion==11){
			printf("Nos vemos\n");
			printf("\n");
		}
		else
		printf("Opcion invalida\n");
		printf("\n");
		
		
		
	}while(opcion!=11);

	return 0;
}

void CrearOVaciarLista(Nodo* lista){
	int cont=0;
	do{
		lista->dato[cont]=COMPV;
		cont++;
	}while(cont!=MAX);
	lista->numelm=0;
	return;
}

void ImpresionLista(Nodo* lista){
	int cont=0;
	if(lista->numelm==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else
	do{
		printf("%d ",lista->dato[cont]);
		cont++;
	}while(cont!=lista->numelm);
	printf("\nNumero de elementos en tu lista: %d\n",lista->numelm);
	
	return;
}

void ImprimirNelementos(Nodo *lista){
	printf("\nNumero de elementos en tu lista: %d\n",lista->numelm);
	return;
}

void InsertarFinal(Nodo* lista, TipoDato elemento){
	if(lista->numelm==MAX){
		printf("Tu lista esta llena\n");
		return;
	}
	else
	lista->dato[lista->numelm]=elemento;
	lista->numelm++;
	return;
}

void InsertarInicio(Nodo* lista, TipoDato elemento){
	if(lista->numelm==MAX){
		printf("Tu lista esta llena\n");
		return;
	}
	else if(lista->numelm<1){
		InsertarFinal(lista,elemento);
		return;
	}
	int aux,apy;
	aux=lista->numelm;
	aux--;
	apy=lista->numelm;
	do{
		lista->dato[apy]=lista->dato[aux];
		apy--;
		aux--;
	}while(apy!=0);
	lista->dato[0]=elemento;
	lista->numelm++;
	return;
}

TipoDato EliminarFinal(Nodo* lista){
	if(lista->numelm==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	int aux;
	TipoDato rpd;
	aux=lista->numelm;
	aux--;
	rpd=lista->dato[aux];
	lista->dato[aux]=COMPV;
	lista->numelm--;
	return rpd;
}

TipoDato EliminarInicio(Nodo* lista){
	int aux=1, cont=0;
	TipoDato rpd;
	if(lista->numelm==cont){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(lista->numelm==aux){
		rpd=EliminarFinal(lista);
		return rpd;
	}
	rpd=lista->dato[0];
	do{
		lista->dato[cont]=lista->dato[aux];
		cont++;
		aux++;
	}while(aux!=lista->numelm);
	lista->numelm--;
	lista->dato[lista->numelm]=COMPV;
	
	return rpd;
}

void InsertarCPI(Nodo *lista, TipoDato elemento, int posicion){
	int aux, apy;
	if(lista->numelm==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(posicion<1){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al inicio de la lista\n");
		return;
	}
	else if(posicion>=lista->numelm){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al final de la lista\n");
		return;
	}
	else
	lista->numelm++;
	aux=lista->dato[posicion];
	lista->dato[posicion]=elemento;
	posicion++;
	do{
		apy=lista->dato[posicion];
		lista->dato[posicion]=aux;
		aux=apy;
		posicion++;
	}while(posicion!=lista->numelm);
	return;
}

TipoDato EliminarCPI(Nodo *lista, int posicion){
	int aux, cont;
	TipoDato rpd;
	if(lista->numelm==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(posicion<=1){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar al inicio de la lista\n");
		return;	
	}
	else if(posicion>=lista->numelm){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar al final de la lista\n");
		return;
	}
	else
	cont=posicion;
	posicion--;
	rpd=lista->dato[posicion];
	do{
		aux=lista->dato[cont];
		lista->dato[posicion]=aux;
		cont++;
		posicion++;
	}while(cont!=lista->numelm);
	lista->numelm--;
	return rpd;
}

void ConcatenarListas(Nodo *plista, Nodo *slista){
	int cont=0, rept=0;
	if(plista->numelm==0 && slista->numelm==0){
		printf("Ambas listas se encuentran vacias, no es posible realizar esta accion\n");
		return;
	}
	else if(plista->numelm==0){
		printf("La primera lista se encuentra vacia , por lo tanto, no es posible concatenar ambas listas\n");
		return;
	}
	else if(slista->numelm==0){
		printf("La segunda lista se encuentra vacia, por lo tanto, no es posible concatenar ambas listas\n");
		return;
	}
	else
	cont=plista->numelm;
	do{
		plista->dato[cont]=slista->dato[rept];
		cont++;
		rept++;
	}while(rept!=slista->numelm);
	plista->numelm=cont;
	CrearOVaciarLista(slista);
	return;
}

void BuscarComunes(Nodo *plista, Nodo *slista){
	int rpt=0, cont=0, grd=0, mostr=0;
	TipoDato aux[MAX];
	if(plista->numelm==0 && slista->numelm==0){
		printf("Ambas listas se encuentran vacias, no es posible realizar esta accion\n");
		return;
	}
	else if(plista->numelm==0){
		printf("La primera lista se encuentra vacia , por lo tanto, no es posible concatenar ambas listas\n");
		return;
	}
	else if(slista->numelm==0){
		printf("La segunda lista se encuentra vacia, por lo tanto, no es posible concatenar ambas listas\n");
		return;
	}
	else
	do{
		do{
			if(plista->dato[rpt]==slista->dato[cont]){
				aux[grd]=plista->dato[rpt];
				grd++;
				cont++;
				mostr=rpt;
				mostr++;
				printf("\nEl numero %d de la posicion %d perteneciente a la primera lista\n",plista->dato[rpt],mostr);
				printf("\nSe repitio en la posicion %d de la segunda lista\n",cont);
				sleep(3);
			}
			else{
				cont++;
			}
		}while(cont!=slista->numelm);
		rpt++;
		cont=0;
	}while(rpt!=plista->numelm);
	rpt=0;
	printf("\nLos numeros que se repitieron fueron los siguientes:\n");
	do{
		printf("%d ",aux[rpt]);
		rpt++;
	}while(rpt!=grd);
	sleep(3);
	return;
}

void CambiarDato(Nodo *plista, Nodo *slista){
	int dop,op,posicion,postd;
	TipoDato rspd;
	if(plista->numelm==0 && slista->numelm==0){
		printf("Ambas listas se encuentran vacias, no es posible realizar esta accion\n");
		return;
	}
	else if(plista->numelm==0){
		printf("La primera lista se encuentra vacia , por lo tanto, no es posible realizar esta accion\n");
		return;
	}
	else
	printf("\nQue posicion es la del dato deseas mover?\n");
	printf("\nTu lista:\n");
	ImpresionLista(plista);
	printf("Principio..................[1]\n");
	printf("Final......................[2]\n");
	printf("Posicion intermedia........[3]\n");
	scanf("%d",&op);
	
	printf("\nA que posicion de la otra lista deseas mover el dato?\n");
	printf("\nLista destino:\n");
	ImpresionLista(slista);
	printf("Principio..................[1]\n");
	printf("Final......................[2]\n");
	printf("Posicion intermedia........[3]\n");
	scanf("%d",&dop);
	
	if(op==1){
		rspd=EliminarInicio(plista);
		if(dop==1){
			InsertarInicio(slista,rspd);
			return;
		}
		else if(dop==2){
			InsertarFinal(slista,rspd);
			return;
		}
		else if(dop==3){
			printf("Introduzca la posicion de su preferencia de la lista destino\n");
			scanf("%d",&postd);
			InsertarCPI(slista,rspd,postd);
			return;
		}
		else{
			printf("\n Opcion invalida \n");
			return;
		}
	}
	else if(op==2){
		rspd=EliminarFinal(plista);
		if(dop==1){
			InsertarInicio(slista,rspd);
			return;
		}
		else if(dop==2){
			InsertarFinal(slista,rspd);
			return;
		}
		else if(dop==3){
			printf("Introduzca la posicion de su preferencia de la lista destino\n");
			scanf("%d",&postd);
			InsertarCPI(slista,rspd,postd);
			return;
		}
		else{
			printf("\n Opcion invalida \n");
			return;
		}
	}
	else if(op==3){
		printf("Introduzca la posicion de su preferencia con respecto a los datos de la lista del dato que desea mover\n");
		scanf("%d",&posicion);
		rspd=EliminarCPI(plista,posicion);
		if(dop==1){
			InsertarInicio(slista,rspd);
			return;
		}
		else if(dop==2){
			InsertarFinal(slista,rspd);
			return;
		}
		else if(dop==3){
			printf("Introduzca la posicion de su preferencia de la lista destino\n");
			scanf("%d",&postd);
			InsertarCPI(slista,rspd,postd);
			return;
		}
		else{
			printf("\n Opcion invalida \n");
			return;
		}
	}
	else
	printf("\n Opcion invalida \n");
	return;
}

