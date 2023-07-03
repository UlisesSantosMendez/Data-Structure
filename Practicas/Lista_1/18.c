#include <string.h>
#include <stdio.h>
#include <conio.h>

typedef struct DPST{
	char *destino;
	char *company;
	char *salida;
	int pasajeros;
	int posicion;
	struct DPST *next;
	struct DPST *before;
}Nodo;

typedef struct INL{
	int nelementos;
	struct DPST *PN;
}Indicador;

typedef struct agenda{
	int horas;
	int minutos;
}Tiempo;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Indicador* CrearLista(Indicador *lista);

Nodo* CrearNodo(char *fate,char *sociedad,char *exit,int clientes);

void ImprimirLista(Indicador *lista);

void ImprimirPosiciones(Indicador *lista);

void ImprimirNelementos(Indicador *lista);

void ImprimirHorario (Tiempo *ahora);

void ComparadorHorario(Indicador *lista, int horas, int minutos);

void InvernarCambioH(Indicador *lista, Tiempo *ahora, int mh, int mm);

void EliminarLista(Indicador *lista);

void InsertarInicio(Indicador *lista, char *fate, char *sociedad, char *exit, int clientes);

void InsertarFinal(Indicador *lista, char *fate, char *sociedad, char *exit, int clientes);

void InsertarCPI(Indicador *lista, char *fate, char *sociedad, char *exit, int clientes, int PP);

void EliminarInicio(Indicador *lista);

void EliminarFinal(Indicador *lista);

void EliminarCPI(Indicador *lista, int PP);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	Indicador *Lista;
	Lista=CrearLista(Lista);
	Tiempo *actual;
	actual=(Tiempo*)malloc(sizeof(Tiempo));
	actual->horas=7;
	actual->minutos=20;
	int pasajeros, posicion, opcion, mh, mm;
	Nodo *eliminado; 
	char *destino, *company, *salida;
	destino=(char*)malloc(sizeof(char));
	company=(char*)malloc(sizeof(char));
	salida=(char*)malloc(sizeof(char));
	
	do{
		printf("Bienvenido al programa del aeropuerto\n");
		printf("Opciones del programa\n");
		printf("\nInsertar datos del vuelo al principio de la lista.................[1]\n");
		printf("Insertar datos del vuelo al final de la lista.....................[2]\n");
		printf("Insertar datos del vuelo en una posicion intermedia...............[3]\n");
		printf("Invernar..........................................................[4]\n");
		printf("Salir del programa................................................[5]\n");
		
		ComparadorHorario(Lista,actual->horas,actual->minutos);
		
		printf("\nTu lista:\n");
		ImprimirLista(Lista);
		ImprimirNelementos(Lista);
		
		printf("\nPor favor escoje una opcion del programa				Horario: ");
		ImprimirHorario (actual);
		scanf("%d",&opcion);
		fflush(stdin);
		
		if(opcion==1){
			printf("Por favor introduzca el destino del vuelo: ");
			gets(destino);
			printf("\nPor favor introduzca la compañia del vuelo: ");
			gets(company);
			printf("\nPor favor introduzca la hora de salida del vuelo en formato de 24 horas: ");
			gets(salida);
			fflush(stdin);
			if(ComprobarHorario(salida)==1){
				sleep(2);
				system("cls");
			}
			else{
				printf("\nPor favor introduzca el numero de pasajeros: ");
				scanf("%d",&pasajeros);
				fflush(stdin);
				system("cls");
				InsertarInicio(Lista,destino,company,salida,pasajeros);
				InvernarCambioH(Lista, actual, 0, 5);
			}
		}
		else if(opcion==2){
			printf("Por favor introduzca el destino del vuelo: ");
			gets(destino);
			printf("\nPor favor introduzca la compañia del vuelo: ");
			gets(company);
			printf("\nPor favor introduzca la hora de salida del vuelo en formato de 24 horas: ");
			gets(salida);
			fflush(stdin);
			if(ComprobarHorario(salida)==1){
				sleep(2);
				system("cls");
			}
			else{
				printf("\nPor favor introduzca el numero de pasajeros: ");
				scanf("%d",&pasajeros);
				fflush(stdin);
				system("cls");
				InsertarFinal(Lista,destino,company,salida,pasajeros);
				InvernarCambioH(Lista, actual, 0, 5);
			}
		}
		else if(opcion==3){
			printf("Por favor introduzca el destino del vuelo: ");
			gets(destino);
			printf("\nPor favor introduzca la compañia del vuelo: ");
			gets(company);
			printf("\nPor favor introduzca la hora de salida del vuelo en formato de 24 horas: ");
			gets(salida);
			fflush(stdin);
			if(ComprobarHorario(salida)==1){
				sleep(2);
				system("cls");
			}
			else{
				printf("\nPor favor introduzca el numero de pasajeros: ");
				scanf("%d",&pasajeros);
				printf("\nPor favor introduzca la posicion de su gusto: ");
				scanf("%d",&posicion);
				fflush(stdin);
				system("cls");
				InsertarCPI(Lista,destino,company,salida,pasajeros,posicion);
				InvernarCambioH(Lista, actual, 0, 5);
			}
		}
		else if(opcion==4){
			printf("Cuantas horas deseas que suspender el programa\n");
			scanf("%d",&mh);
			printf("Cuantos minutos deseas que suspender el programa\n");
			scanf("%d",&mm);
			if(mh>24 || mm>59){
				printf("Valor invalido\n");
			}
			else{
				InvernarCambioH(Lista, actual,mh,mm);
				//system("cls");
			}
		}
		else if(opcion==5){
			printf("\nNos vemos\n");
		}
		else{
			printf("\nOpcion invalido\n");
		}
		
	}while(opcion!=5);
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Indicador* CrearLista(Indicador *lista){
	lista=(Indicador*)malloc(sizeof(Indicador));
	lista->nelementos=0;
	lista->PN=NULL;
	return lista;
}

Nodo* CrearNodo(char *fate,char *sociedad,char *exit,int clientes){
	Nodo *New;
	New=(Nodo*)malloc(sizeof(Nodo));
	New->destino=(char*)malloc(sizeof(char));
	New->company=(char*)malloc(sizeof(char));
	New->salida=(char*)malloc(sizeof(char));
	New->next=NULL;
	New->before=NULL;
	strcpy(New->destino,fate);
	strcpy(New->company,sociedad);
	strcpy(New->salida,exit);
	New->pasajeros=clientes;
	return New;
}

void ImprimirLista(Indicador *lista){
	Nodo *imp;
	if(lista->nelementos==0){
		printf("\nTu lista se encuentra vacia\n");
		return;
	}
	else
	imp=lista->PN;
	do{
		printf("Vuelo %d\nDestino:             %s\nCompania:             %s\nHorario de salida:   %s\nNumero de pasajeros: %d\n",imp->posicion,imp->destino,imp->company,imp->salida,imp->pasajeros);
		imp=imp->next;
	}while(imp!=NULL);
	printf("\n");
	return;
}

void ImprimirPosiciones(Indicador *lista){
	Nodo *imp;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
		return;
	}
	else
	imp=lista->PN;
	do{
		printf("%d ",imp->posicion);
		imp=imp->next;
	}while(imp!=NULL);
	printf("\n");
	return;
}

void ImprimirNelementos(Indicador *lista){
	printf("\nNumero de vuelos en tu lista: %d\n",lista->nelementos);
	return;
}

void EliminarLista(Indicador *lista){
	Nodo *Llib, *aux;
	Llib=lista->PN;
	lista->PN=NULL;
	aux=Llib;
	do{
		aux=aux->next;
		free(Llib);
		Llib=aux;
	}while(aux->posicion!=lista->nelementos);
	free(aux);
	lista->nelementos=0;
	return;
}

void ComparadorHorario(Indicador *lista, int horas, int minutos){
	Nodo *aux;
	int lhrs, lmin, cont=1;
	char *apy=(char*)malloc(sizeof(char));
	if(lista->nelementos==0){
		return;
	}
	else
	aux=lista->PN;
	do{
		strcpy(apy,aux->salida);
		lhrs=atoi(apy);
		if(strlen(apy)==5){
			lmin=atoi(apy+3);
		}
		else if(strlen(apy)==4){
			lmin=atoi(apy+2);
		}
		else if(strlen(apy)>5 || strlen(apy)<4){
			printf("El horario no esta bien escrito en el formato de 24 horas, por favor vuelvelo a intentar");
			return;
		}
		
		if(horas==lhrs && minutos==lmin){
			printf("\nEl vuelo con:\n");
			printf("Destino:             %s\nCompañia:           %s\nHora de salida:      %s\nNum.Pasajeros: %d\n",aux->destino,aux->company,aux->salida,aux->pasajeros);
			printf("Acaba de salir\n");
			sleep(3);
			if(aux->posicion==1){
				aux=NULL;
				EliminarInicio(lista);
				aux=lista->PN;
			}
			else if(aux->posicion==lista->nelementos){
				EliminarFinal(lista);
				return;
			}
			else{
				aux=aux->next;
				EliminarCPI(lista, (aux->before)->posicion);
			}
		}
		else{
			aux=aux->next;
		}
	}while(aux!=NULL);
	return;
}

void ImprimirHorario(Tiempo *ahora){
	if(ahora->horas<10){
		if(ahora->minutos<10){
			printf("0%d : 0%d\n",ahora->horas,ahora->minutos);
		}
		else{
			printf("0%d : %d\n",ahora->horas,ahora->minutos);
		}
	}
	else{
		if(ahora->minutos<10){
			printf("%d : 0%d\n",ahora->horas,ahora->minutos);
		}
		else{
			printf("%d : %d\n",ahora->horas,ahora->minutos);
		}
	}
	return;
}

void InvernarCambioH(Indicador *lista, Tiempo *ahora, int mh, int mm){
	int aux,spt;
	ImprimirHorario(ahora);
	mm=mm+ahora->minutos;
	ImprimirHorario(ahora);
	if(mm>59){
		aux=mm/59;
		spt=59*aux;
		mm=mm-spt;
		mh=mh+aux;
	}
	mh=mh+ahora->horas;
	ImprimirHorario(ahora);
	if(mh>24){
		aux=mh/24;
		spt=24*aux;
		mh=mh-spt;
	}
	ImprimirHorario(ahora);
	if(ahora->horas==mh){
		do{
			ahora->minutos++;
			if(ahora->minutos==60){
				ahora->horas++;
				ahora->minutos=0;
				ImprimirHorario(ahora);
				ComparadorHorario(lista,ahora->horas,ahora->minutos);
				system("cls");
			}
			else if(ahora->horas==25){
				ahora->horas=1;
				ahora->minutos=0;
				ImprimirHorario(ahora);
				ComparadorHorario(lista,ahora->horas,ahora->minutos);
				system("cls");
			}
			else{
				ImprimirHorario(ahora);
				ComparadorHorario(lista,ahora->horas,ahora->minutos);
				system("cls");
			}
		}while(ahora->minutos!=mm);
		return;
	}
	else
	do{
		ahora->minutos++;
		if(ahora->minutos==60){
			ahora->horas++;
			ahora->minutos=0;
			ImprimirHorario(ahora);
			ComparadorHorario(lista,ahora->horas,ahora->minutos);
			system("cls");
		}
		else if(ahora->horas==25){
			ahora->horas=1;
			ahora->minutos=0;
			ImprimirHorario(ahora);
			ComparadorHorario(lista,ahora->horas,ahora->minutos);
			system("cls");
		}
		else{
			ImprimirHorario(ahora);
			ComparadorHorario(lista,ahora->horas,ahora->minutos);
			system("cls");
		}
	}while(ahora->horas!=mh);
	
	do{
		ahora->minutos++;
		if(ahora->minutos==60){
			ahora->horas++;
			ahora->minutos=0;
			ImprimirHorario(ahora);
			ComparadorHorario(lista,ahora->horas,ahora->minutos);
			system("cls");
		}
		else if(ahora->horas==25){
			ahora->horas=1;
			ahora->minutos=0;
			ImprimirHorario(ahora);
			ComparadorHorario(lista,ahora->horas,ahora->minutos);
			system("cls");
		}
		else{
			ImprimirHorario(ahora);
			ComparadorHorario(lista,ahora->horas,ahora->minutos);
			system("cls");
		}
	}while(ahora->minutos!=mm);
	return;
}

int ComprobarHorario(char *VHS){
	int lhrs, lmin, cont=1;
	char *apy=(char*)malloc(sizeof(char));
	strcpy(apy,VHS);
	lhrs=atoi(apy);
	if(strlen(apy)==5){
		lmin=atoi(apy+3);
	}
	else if(strlen(apy)==4){
		lmin=atoi(apy+2);
	}
	else if(strlen(apy)>5 || strlen(apy)<4){
		printf("El horario no esta bien escrito en el formato de 24 horas, por favor vuelvelo a intentar");
		return 1;
	}
	
	if(lhrs>24){
		printf("El horario no esta bien escrito en el formato de 24 horas, por favor vuelvelo a intentar");
		return 1;
	}
	else if(lmin>59){
		printf("El horario no esta bien escrito en el formato de 24 horas, por favor vuelvelo a intentar");
		return 1;
	}
	else
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertarInicio(Indicador *lista, char *fate, char *sociedad, char *exit, int clientes){
	Nodo *New;
	if(lista->nelementos==0){
		lista->PN=CrearNodo(fate, sociedad, exit, clientes);
		lista->nelementos++;
		(lista->PN)->next=NULL;
		(lista->PN)->before=NULL;
		(lista->PN)->posicion=lista->nelementos;
		return;
	}
	else
	New=CrearNodo(fate, sociedad, exit, clientes);
	New->next=lista->PN;
	New->before=NULL;
	(lista->PN)->before=New;
	New->posicion=1;
	do{
		(lista->PN)->posicion++;
		lista->PN=(lista->PN)->next;
	}while(lista->PN!=NULL);
	lista->nelementos++;
	lista->PN=New;
	return;
}

void InsertarFinal(Indicador *lista, char *fate, char *sociedad, char *exit, int clientes){
	Nodo *New, *aux;
	if(lista->nelementos==0){
		lista->PN=CrearNodo(fate, sociedad, exit, clientes);
		lista->nelementos++;
		(lista->PN)->next=NULL;
		(lista->PN)->before=NULL;
		(lista->PN)->posicion=lista->nelementos;
		return;
	}
	else if(lista->nelementos==1){
		New=CrearNodo(fate, sociedad, exit, clientes);
		New->before=lista->PN;
		New->next=NULL;
		(lista->PN)->next=New;
		lista->nelementos++;
		New->posicion=lista->nelementos;
		return;
	}
	New=CrearNodo(fate, sociedad, exit, clientes);
	aux=lista->PN;
	do{
		aux=aux->next;
	}while(aux->posicion!=lista->nelementos);
	New->before=aux;
	New->next=NULL;
	(New->before)->next=New;
	lista->nelementos++;
	New->posicion=lista->nelementos;
	return;
}

void EliminarInicio(Indicador *lista){
	Nodo *Nlib, *aux;
	if(lista->nelementos==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(lista->nelementos==1){
		free(lista->PN);
		lista->PN=NULL;
		lista->nelementos--;
		printf("Eliminaste el ultimo elemento de tu lista\n");
		return;
	}
	else
	Nlib=lista->PN;
	lista->PN=(lista->PN)->next;
	(lista->PN)->before=NULL;
	lista->nelementos--;
	aux=lista->PN;
	do{
		aux->posicion--;
		aux=aux->next;
	}while(aux!=NULL);
	free(Nlib);
	return;
}

void EliminarFinal(Indicador *lista){
	Nodo *Nlib, *aux;
	if(lista->nelementos==0){
		printf("Tu lista esta vacia\n");
		return;
	}
	else if(lista->nelementos==1){
		free(lista->PN);
		lista->PN=NULL;
		lista->nelementos--;
		printf("Eliminaste el ultimo elemento de tu lista\n");
		return;
	}
	else
	Nlib=lista->PN;
	do{
		Nlib=Nlib->next;
	}while(Nlib->posicion!=lista->nelementos);
	(Nlib->before)->next=NULL;
	lista->nelementos--;
	free(Nlib);
	return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertarCPI(Indicador *lista, char *fate, char *sociedad, char *exit, int clientes, int PP){
	Nodo *New, *aux;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
		return;
	}
	else if(PP>=lista->nelementos){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al final de la lista\n");
		return;
	}
	else if(PP<1){
		printf("La posicion que solicito no es valida pruebe con la opcion de insertar al inicio de la lista\n");
		return;
	}
	else if(PP==1){
		New=CrearNodo(fate,sociedad,exit,clientes);
		aux=(lista->PN)->next;
		New->posicion=PP;
		New->before=lista->PN;
		New->next=aux;
		(lista->PN)->next=New;
		aux->before=New;
		do{
			New->posicion++;
			New=New->next;
		}while(New!=NULL);
		lista->nelementos++;
		return;	
	}
	else
	New=CrearNodo(fate,sociedad,exit,clientes);
	aux=lista->PN;
	do{
		aux=aux->next;
	}while(aux->posicion!=PP);
	New->posicion=PP;
	New->before=aux;
	New->next=aux->next;
	(aux->next)->before=New;
	aux->next=New;
	do{
		New->posicion++;
		New=New->next;
	}while(New!=NULL);
	lista->nelementos++;
	return;
}

void EliminarCPI(Indicador *lista, int PP){
	Nodo *Nlib, *aux;
	if(lista->nelementos==0){
		printf("Tu lista se encuentra vacia\n");
		return;
	}
	else if(PP>=lista->nelementos){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar el final de la lista\n");
		return;
	}
	else if(PP<=1){
		printf("La posicion que solicito no es valida pruebe con la opcion de eliminar el inicio de la lista\n");
		return;
	}
	else
	Nlib=lista->PN;
	do{
		Nlib=Nlib->next;
	}while(Nlib->posicion!=PP);
	(Nlib->before)->next=Nlib->next;
	(Nlib->next)->before=Nlib->before;
	aux=Nlib->next;
	do{
		aux->posicion--;
		aux=aux->next;
	}while(aux!=NULL);
	lista->nelementos--;
	free(Nlib);
	return;
}

