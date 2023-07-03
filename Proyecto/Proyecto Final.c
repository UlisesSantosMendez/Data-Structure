#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

typedef struct REGISTRO{
	char nombre[20];
	char apellido[20];
	char sexo[9];
	int edad;
	char estado[50];
	char trabaja[3];
	char hijos[3];
	char preferencia_perros_gatos[8];
	char esta_cuidando[3];
	char adoptado_comprado[9];
	char raza_mestizo[8];
	int cantidad_mascotas;
}registro;

typedef struct NODO_PILA{
	registro *regis;
	struct NODO_PILA *nodo_abajo;
}nodo_pila;

typedef struct PILA{
	nodo_pila *nodo_tope;
}pila;

typedef struct DPST{
	registro *dato;
	struct DPST *ds;
	struct DPST *is;
}Nodo;

typedef struct INR{
	int nelementos;
	struct DPST *raiz;
}Indicador;




//////////////////////////////////////////////////////////////////////////////PEDIR DATOS//////////////////////////////////////////////////////////////77
registro* PedirDatos(){
	
	int res;
	
	registro *nuevo_registro = (registro*)malloc(sizeof(registro));
	
	if(nuevo_registro == NULL){
		printf("ERROR, ya no hay memoria para un registro nuevo\n");
	}else{
		
		printf("Ingrese el nombre: ");fflush( stdin ); scanf(" %s", nuevo_registro->nombre);
		
		printf("Ingrese el apellido: ");fflush( stdin ); scanf(" %s", nuevo_registro->apellido);
	
		printf("Ingrese el sexo: ");fflush( stdin ); scanf(" %s", nuevo_registro->sexo);
	
		printf("Ingrese su edad: ");fflush( stdin ); scanf(" %d",&nuevo_registro->edad);
		
		printf("De donde es ? : ");fflush( stdin ); scanf(" %s",nuevo_registro->estado);
		
		printf("Trabaja ? : ");fflush( stdin ); scanf(" %s", nuevo_registro->trabaja);
	
		printf("Tiene hijos ? : ");fflush( stdin ); scanf(" %s", nuevo_registro->hijos);
	
		printf("Prefiere perros o gatos ? : ");fflush( stdin ); scanf(" %s", nuevo_registro->preferencia_perros_gatos);

		printf("Esta cuidando a algun perro o gato ? : ");fflush( stdin ); scanf(" %s", nuevo_registro->esta_cuidando);
	
		
		if(strcmp(nuevo_registro->esta_cuidando, "Si") == 0){
			system("cls");
			printf("Es adoptado o comprado?: ");fflush( stdin ); scanf(" %s",nuevo_registro->adoptado_comprado);
			printf("Es de raza o mestizo? : ");fflush( stdin ); scanf(" %s", nuevo_registro->raza_mestizo);
			printf("Cuantos perros o gatos estas cuidando en total? : ");fflush( stdin ); scanf(" %d",&nuevo_registro->cantidad_mascotas);	
		}else{
			nuevo_registro->cantidad_mascotas = 0;
		}
		
		return nuevo_registro;
	}
}

void imprimirRegistro(registro *reg){
	printf("Nombre -> %s",reg->nombre);
	printf("\nApellido -> %s",reg->apellido);
	printf("\nSexo -> %s",reg->sexo);
	printf("\nEdad -> %d",reg->edad);
	printf("\nEstado -> %s",reg->estado);
	printf("\nTrabaja -> %s",reg->trabaja);
	printf("\nHijos -> %s",reg->hijos);
	printf("\nPreferencia perros o gatos -> %s",reg->preferencia_perros_gatos);
	printf("\nEsta cuidando a algun perro o gato -> %s", reg->esta_cuidando);
	
	if(strcmp(reg->esta_cuidando, "Si") == 0){
		printf("\nAdoptado o comprado -> %s",reg->adoptado_comprado);
		printf("\nRaza o mestizo -> %s",reg->raza_mestizo);
		printf("\nNumero de mascotas -> %d",reg->cantidad_mascotas);
	}
	
	printf("\n\n");
}

/////////////////////////////////////////////////////////////////////////////////(RANDOM)///7//////////////////////////////////////////////////////////////////////////////////
int ValorRandom(int n, int mi, int ma){
	srand(n);
	return (rand()%(ma-mi))+mi;
}

registro* Automatico(int num1, int num2){
	registro *nuevo_registro = (registro*)malloc(sizeof(registro));
	srand(time(NULL));
	int ma = 20;
	int mi = 0;
	char *nombres[20]={
		"Jose", "Juan", "Pablo", "Edgar", "Alejandro", "Esteban", "Erick", "Victor", "Alberto", "Joaquin", "Maria", "Lucia", "Mercedes", "Lorena", "Jimena", "Veronica", "Ester", "Johana", "Guadalupe", "Jessica"
	};
	char *apellidos[20]={
		"Rodriguez", "Hernandez", "Garcia", "Martinez", "Lopez", "Gonzales", "Sanchez", "Ramirez", "Perez", "Gomez", "Fernandez", "Diaz", "Torres", "Ruiz", "Sosa", "Alvarez", "Benites", "Acosta", "Herrera", "Aguirre"
	};
	int n = rand()%num1;
	//nuevo_registro->nombre = nombres[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->nombre,nombres[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->nombre);
	/*---------------------------------------------Sexo------------------------------- */
	if(ValorRandom(n, mi, ma) >= 0 && ValorRandom(n, mi, ma) <= 9)
	{
		//nuevo_registro->sexo = "Masculino";
		strcpy(nuevo_registro->sexo,"Masculino");
	}
	else
	{
		//nuevo_registro->sexo = "Femenino";
		strcpy(nuevo_registro->sexo,"Femenino");
	}
	//printf("%s\n",nuevo_registro->sexo);
/*---------------------------------------------Apellidos------------------------------------*/
	n = rand()%num2;
	//nuevo_registro->apellido = apellidos[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->apellido,apellidos[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->apellido);
/*------------------------------------------------------------------- Edad Random--------------------------------------------*/
	ma = 70;
	mi = 18;
	n = rand()%num2;
	nuevo_registro->edad = ValorRandom(n, mi, ma);
	//printf("%d\n",nuevo_registro->edad);
	mi = 0;
/*------------------------------------------------------------------- Estado Random--------------------------------------------*/
	ma = 32;
	char *estados[32]={
		"Aguascalientes", "Baja California", "Baja California Sur", "Campeche", "Coahuila", "Colima", "Chiapas", "Chihuahua", "Cuidad de Mexico", "Durango", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Estado de Mexico", "Michoacan", "Morelos", "Nayarit", "Nuevo Leon", "Oaxaca", "Puebla", "Queretaro", "Quintana Roo", "San Luis Potosi", "Sinaloa", "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas"
	};
	n = (rand()%num2)+ma;
	//nuevo_registro->estado = estados[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->estado,estados[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->estado);
/*------------------------------------------------------------------- Trabaja?--------------------------------------------*/
	ma = 2;
	char *respuesta[2]={"Si", "No"};
	n = rand()%num2;
	//nuevo_registro->trabaja = respuesta[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->trabaja,respuesta[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->trabaja);
/*------------------------------------------------------------------- Tiene Hijos?--------------------------------------------*/
	ma = 2;
	char *hijos[2]={"Si", "No"};
	n = rand()%num2;
	//nuevo_registro->hijos = hijos[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->hijos,hijos[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->hijos);
/*------------------------------------------------------------------- Preferencia (Perros / Gatos)--------------------------------------------*/
	ma = 2;
	char *prefer[2]={"Perros", "Gatos"};
	n = rand()%num2;
	//nuevo_registro->preferencia_perros_gatos = prefer[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->preferencia_perros_gatos,prefer[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->preferencia_perros_gatos);
/*------------------------------------------------------------------- Esta cuidando algun perro o gato?--------------------------------------------*/
	ma = 2;
	char *cuid[2]={"Si", "No"};
	n = rand()%num2;
	//nuevo_registro->esta_cuidando = cuid[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->esta_cuidando,cuid[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->esta_cuidando);
/*------------------------------------------------------------------- Adoptado o Comprado--------------------------------------------*/
	ma = 2;
	char *ad[2] = {"Adoptado", "Comprado"};
	n = rand()%num2;
	//nuevo_registro->adoptado_comprado = ad[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->adoptado_comprado,ad[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->adoptado_comprado);
/*------------------------------------------------------------------- Es de raza o mestizo?--------------------------------------------*/
	ma = 2;
	char *rame[2] = {"Raza", "Mestizo"};
	n = rand()%num2;
	//nuevo_registro->raza_mestizo = rame[ValorRandom(n, mi, ma)];
	strcpy(nuevo_registro->raza_mestizo,rame[ValorRandom(n, mi, ma)]);
	//printf("%s\n",nuevo_registro->raza_mestizo);
/*------------------------------------------------------------------- Numero de perros o gatos--------------------------------------------*/
	ma = 4;
	mi = 1;
	n = rand()%num2;
	nuevo_registro->cantidad_mascotas = ValorRandom(n, mi, ma);
	//printf("%d\n",nuevo_registro->cantidad_mascotas);
	//sleep(10);
	return nuevo_registro;
}
////////////////////////////////////////////////////////////////////////////////// FUNCIONES PILA ///////////////////////////////////////////////////////////////////////////////
void ini_stack(pila *stack){
	stack->nodo_tope = NULL;
}

void push_pila(pila *stack, registro *nuevo_registro){
	
	nodo_pila *nuevo_nodo = (nodo_pila*)malloc(sizeof(nodo_pila));
	
	if(nuevo_nodo != NULL){
		nuevo_nodo->regis = nuevo_registro;
		nuevo_nodo->nodo_abajo = stack->nodo_tope;
		stack->nodo_tope = nuevo_nodo;
	}else{
		printf("ERROR. Ya no hay memoria para insertar mas registros.\n");
	}
	
}

nodo_pila* pop_pila(pila *stack){
	
	nodo_pila *nodo_fuera; nodo_pila *aux;
	
	if(es_vacia(stack) == 1){
		//printf("ERROR. No hay elementos en la pila\n");
		nodo_fuera = NULL;
	}else{
		nodo_fuera = stack->nodo_tope;
		aux = stack->nodo_tope;
		stack->nodo_tope = stack->nodo_tope->nodo_abajo;
		free(aux);
	}
	return nodo_fuera;
}

int es_vacia(pila *stack){
	if(stack->nodo_tope == NULL){
		return 1;
	}else{
		return 0;
	}
}

void imprimir_stack(pila *stack){
	
	if(es_vacia(stack) == 1){
		printf("ERROR. No hay registros en la pila para imprimir.\n");
	}else{
		nodo_pila *aux = stack->nodo_tope;
		int cont=0;
		while(aux != NULL){
			cont++;
			imprimirRegistro(aux->regis);
			aux = aux->nodo_abajo;
		}
		printf("%d\n",cont);
	}
}

void eliminar_pila(pila *stack){
	ini_stack(stack);
}

////////////////////////////////////////////////////////// LLENAR DATOS DE MANERA AUTOMATICA ////////////////////////////////////////////////////////////////

void llenarDatos(pila *stack, int cantidad){
	int control;
	int num1 = cantidad*2;
	int num2 = cantidad*2;
	for(control = 1; control <= cantidad; control++){
		push_pila(stack, Automatico(num1,num2));
		num1--;
		num2 = num2 - 2;
		//printf("registro %d\n",control);
	}
	
}

/////////////////////////////////////////////////////////////////////////////////////////Arbol/////////////////////////////////////////////////////////////////////////////////////
Indicador* CrearArbol(Indicador *tree){
	tree=(Indicador*)malloc(sizeof(Indicador));
	tree->nelementos=0;
	tree->raiz=NULL;
	return tree;
}

Nodo* CrearNodo(registro *elemento){
	Nodo *rama;
	rama=(Nodo*)malloc(sizeof(Nodo));
	if(rama == NULL){
		printf("NO HAY MEMORIA\n");
	}else{
		rama->dato=elemento;
		rama->ds=NULL;
		rama->is=NULL;
		return rama;
	}
}

void InsertarElemento(Indicador *tree, registro *elemento){
	Nodo *rama, *comp;
	if(tree->nelementos==0){
		rama=CrearNodo(elemento);
		tree->raiz=rama;
		tree->nelementos++;
	}
	else{
		rama=CrearNodo(elemento);
		comp=tree->raiz;
		if(strcmp(rama->dato->preferencia_perros_gatos,comp->dato->preferencia_perros_gatos)!=0){
			if(comp->ds!=NULL){
				comp=comp->ds;
				do{
					if(strcmp(rama->dato->sexo,comp->dato->sexo)!=0){
						if(comp->ds!=NULL){
							comp=comp->ds;
						}
						else{
							comp->ds=rama;                  
							tree->nelementos++;
							comp=NULL; 
							//printf("diferente derecha\n");
						}
					}
					else{
						if(comp->is!=NULL){
							comp=comp->is;
						}
						else{
							comp->is=rama;
							tree->nelementos++;
							comp=NULL;
							//printf("diferente izquierda\n");
						}
					}		
				}while(comp!=NULL);
			}
			else{
				comp->ds=rama;
				tree->nelementos++;
			}		
		}
		else{
			if(comp->is!=NULL){
				comp=comp->is;
				do{
					if(strcmp(rama->dato->sexo,comp->dato->sexo)!=0){
						if(comp->ds!=NULL){
							comp=comp->ds;
						}
						else{
							comp->ds=rama;
							tree->nelementos++;
							comp=NULL;
							//printf("igual derecha\n");
						}
					}
					else{
						if(comp->is!=NULL){
							comp=comp->is;
						}
						else{
							comp->is=rama;
							tree->nelementos++;
							comp=NULL;
							//printf("igual izquierda\n");
						}
					}		
				}while(comp!=NULL);
			}
			else{
				comp->is=rama;
				tree->nelementos++;
			}		
		}
	}
	return;
}

void Inorden(Nodo *tree){
	if(tree!=NULL){
		Inorden(tree->is);
		imprimirRegistro(tree->dato);
		Inorden(tree->ds);
	}
	return;
}
///////////////////////////////////////////////////////////////////////////////// BUSCAR DATOS ///////////////////////////////////////////////////////////////////////

void busquedaNombreApellido(Nodo *tree, char nombre[], char apellido[]){
	if(tree!=NULL){
		busquedaNombreApellido(tree->is,nombre,apellido);
		if(strcmp(tree->dato->nombre,nombre) == 0 && strcmp(tree->dato->apellido,apellido) == 0){
			printf("\n"); imprimirRegistro(tree->dato);
		}
		busquedaNombreApellido(tree->ds,nombre,apellido);
	}
	return;
}

void busquedaSexo(Nodo *tree, char sexo[]){
	if(tree!=NULL){
		busquedaSexo(tree->is,sexo);
		if(strcmp(tree->dato->sexo,sexo) == 0){
			printf("\n"); imprimirRegistro(tree->dato);
		}
		busquedaSexo(tree->ds,sexo);
	}
	return;
}

void busquedaEdad(Nodo *tree, int edad){
	int cont = 0;
	if(tree!=NULL){
		busquedaEdad(tree->is,edad);
		if(tree->dato->edad == edad){
			printf("\n"); imprimirRegistro(tree->dato); cont++;
		}
		busquedaEdad(tree->ds,edad);
	}
	
	return;
}

void busquedaEstado(Nodo *tree, char estado[]){
	int cont = 0;
	if(tree!=NULL){
		busquedaEstado(tree->is,estado);
		if(strcmp(tree->dato->estado,estado) == 0){
			printf("\n"); imprimirRegistro(tree->dato); cont++;
		}
		busquedaEstado(tree->ds,estado);
	}
	
	return;
}

void busquedaTrabaja(Nodo *tree, char trabaja[]){
	int cont = 0;
	if(tree!=NULL){
		busquedaTrabaja(tree->is,trabaja);
		if(strcmp(tree->dato->trabaja,trabaja) == 0){
			printf("\n"); imprimirRegistro(tree->dato); cont++;
		}
		busquedaTrabaja(tree->ds,trabaja);
	}
	
	return;
}

void busquedaHijos(Nodo *tree, char hijos[]){
	int cont = 0;
	if(tree!=NULL){
		busquedaHijos(tree->is,hijos);
		if(strcmp(tree->dato->hijos,hijos) == 0){
			printf("\n"); imprimirRegistro(tree->dato); cont++;
		}
		busquedaHijos(tree->ds,hijos);
	}
	
	return;
}

void busquedaPreferencias(Nodo *tree, char preferencias[]){
	int cont = 0;
	if(tree!=NULL){
		busquedaPreferencias(tree->is,preferencias);
		if(strcmp(tree->dato->preferencia_perros_gatos,preferencias) == 0){
			printf("\n"); imprimirRegistro(tree->dato); cont++;
		}
		busquedaPreferencias(tree->ds,preferencias);
	}
	
	return;
}

void busquedaCuidando(Nodo *tree, char cuidando[]){
	int cont = 0;
	if(tree!=NULL){
		busquedaCuidando(tree->is,cuidando);
		if(strcmp(tree->dato->esta_cuidando,cuidando) == 0){
			printf("\n"); imprimirRegistro(tree->dato); cont++;
		}
		busquedaCuidando(tree->ds,cuidando);
	}
	
	return;
}

void busquedaAdopComp(Nodo *tree, char ac[]){
	int cont = 0;
	if(tree!=NULL){
		busquedaAdopComp(tree->is,ac);
		if(strcmp(tree->dato->adoptado_comprado,ac) == 0 && strcmp(tree->dato->esta_cuidando,"Si")==0){
			printf("\n"); imprimirRegistro(tree->dato); cont++;
		}
		busquedaAdopComp(tree->ds,ac);
	}
	
	return;
}

void busquedaRM(Nodo *tree, char rm[]){
	int cont = 0;
	if(tree!=NULL){
		busquedaRM(tree->is,rm);
		if(strcmp(tree->dato->raza_mestizo,rm) == 0 && strcmp(tree->dato->esta_cuidando,"Si")==0){
			printf("\n"); imprimirRegistro(tree->dato); cont++;
		}
		busquedaRM(tree->ds,rm);
	}
	
	return;
}

void busquedaCM(Nodo *tree, int cm){
	if(tree != NULL){
		busquedaCM(tree->is,cm);
		if(tree->dato->cantidad_mascotas == cm && strcmp(tree->dato->esta_cuidando,"Si")==0){
		//printf("%d",tree->dato->cantidad_mascotas);
			printf("\n"); imprimirRegistro(tree->dato); 
		}
		busquedaCM(tree->ds,cm);
	}
	return;
}


void buscarDatosGeneral(Indicador *tree, int opcion){
	switch(opcion){
		case 1: printf("Opcion 1 -> Busqueda por nombre y apellido\n");
				char nombre[20]; char apellido[20];
				printf("Introduce el nombre -> ");fflush( stdin ); scanf(" %s",nombre);
				printf("Introduce el apellido -> ");fflush( stdin ); scanf(" %s",apellido);
				busquedaNombreApellido(tree->raiz,nombre,apellido);
				break;
		case 2: printf("Opcion 2 -> Busqueda por sexo\n"); char sexo[9];
				printf("Se mostraran todos los registros segun el sexo que ingreses\n");
				printf("Introduce el sexo a buscar -> ");fflush( stdin ); scanf(" %s",sexo);
				busquedaSexo(tree->raiz,sexo);
				break;
		case 3: printf("Opcion 3 -> Edad\n"); int edad;
				printf("Se mostraran todos los registros segun la edad que ingreses\n");
				printf("Introduce la edad a buscar -> ");fflush( stdin ); scanf(" %d",&edad);
				busquedaEdad(tree->raiz,edad);
				break;
		case 4: printf("Opcion 4 -> Estado\n"); char estado[50];
				printf("Se mostraran todos los registros segun el estado que ingreses\n");
				printf("Introduce el estado a buscar -> ");fflush( stdin ); scanf(" %s",estado);
				busquedaEstado(tree->raiz,estado);
				break;
		case 5: printf("Opcion 5 -> Trabaja ?\n"); char trabaja[3];
				printf("Se mostraran todos los registros segun si la persona trabaja o no.\n");
				printf("Introduzca 'No' o 'Si' segun quiera obtener los registros -> ");fflush( stdin ); scanf(" %s",trabaja);
				busquedaTrabaja(tree->raiz,trabaja);
				break;
		case 6: printf("Opcion 6 -> Hijos\n"); char hijos[3];
				printf("Se mostraran todos los registros segun si la persona tiene hijos o no.\n");
				printf("Introduzca 'No' o 'Si' segun quiera obtener los registros -> ");fflush( stdin ); scanf(" %s",hijos);
				busquedaHijos(tree->raiz,hijos);
				break;
		case 7: printf("Opcion 7 -> Preferencia\n"); char preferencias[8];
				printf("Se mostraran todos los registros segun la preferencia de animal de la persona.\n");
				printf("Introduzca 'Perros' o 'Gatos' segun quiera obtener los registros -> ");fflush( stdin ); scanf(" %s",preferencias);
				busquedaPreferencias(tree->raiz,preferencias);
				break;
		case 8: printf("Opcion 8 -> Esta Cuidadndo\n"); char cuidando[3];
				printf("Se mostraran todos los registros segun si la persona esta o no cuidando a un perro o gato.\n");
				printf("Introduzca 'No' o 'Si' segun quiera obtener los registros -> ");fflush( stdin ); scanf(" %s",cuidando);
				busquedaCuidando(tree->raiz,cuidando);
				break;
		case 9: printf("Opcion 9 -> Adoptado o Comprado\n"); char ac[9];
				printf("Se mostraran todos los registros segun si la persona adopto o compro a su mascota.\n");
				printf("Introduzca 'Adoptado' o 'Comprado' segun quiera obtener los registros -> ");fflush( stdin ); scanf(" %s",ac);
				busquedaAdopComp(tree->raiz,ac);
				break;
		case 10: printf("Opcion 10 -> Raza o Mestizo\n"); char rm[8];
				 printf("Se mostraran todos los registros segun si la mascota de la persona es de raza o mestizo.\n");
				 printf("Introduzca 'Raza' o 'Mestizo' segun quiera obtener los registros -> ");fflush( stdin ); scanf(" %s",rm);
				 busquedaRM(tree->raiz,rm);
				 break;
		case 11: printf("Opcion 11 -> Cantidad de mascotas\n"); int cm;
				 printf("Se mostraran todos los registros segun la cantidad de mascotas de la persona.\n");
				 printf("Introduzca el numero de mascotas -> ");fflush( stdin ); scanf(" %d",&cm);
				 busquedaCM(tree->raiz,cm);
				 break;
		default: printf("Esa opcion no esta disponible\n");
	}
}



void menubuscarDatos(Indicador *tree){
	
	int opcion;
	
	printf("\nCon respecto a que atributo del registro desea buscar ?\n");
	printf("1.- Nombre y Apellido\n");;
	printf("2.- Sexo\n");
	printf("3.- Edad\n");
	printf("4.- Estado\n");
	printf("5.- Trabaja ?\n");
	printf("6.- Hijos\n");
	printf("7.- Preferencias perros o gatos\n");
	printf("8.- Esta cuidando ?\n");
	printf("9.- Adoptado o comprado\n");
	printf("10.- Raza o mestizo\n");
	printf("11.- Cantidad de mascotas\n");
	scanf("%d",&opcion); buscarDatosGeneral(tree,opcion);
}
//////////////////////////////////////////////////////////////////////////////////////// MENU ///////////////////////////////////////////////////////////////////

void funcionar(pila *stack){
  
	char op = 's';
	
	while(op == 's'){
		system("cls");
		push_pila(stack,PedirDatos());
		printf("Continuas -> "); scanf(" %c",&op);
	}
	system("cls");
	imprimir_stack(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////PROMEDIO DE DATOS EN LA PILA///////////////////////////////////////////////////////////////////

void insertar(pila *stack, Indicador *Arbol){
	nodo_pila *aux = pop_pila(stack); int cont = 0;
	while(aux != NULL){
		InsertarElemento(Arbol,aux->regis);
		cont++; printf("%d\n",cont);
		aux = pop_pila(stack);
	}
	
}



void promediar(pila *stack, Indicador *Arbol, int ref){
	
	nodo_pila *aux;
	float prom=0;
	float sum_adop=0;
	float sum_comp=0;
	float sum_qmas=0;
	float sum_pprros=0;
	float sum_pgatos=0;
	float sum_pmas=0;
	float sum_raza=0;
	float sum_mest=0;
	char a_c= 'A';
	char a_R= 'R';
	char a_P= 'P';
	
//variables donde se guarda promedio de cada dato
	float prom_adop=0;
	float prom_comp=0;
	float prom_pprros=0;
	float prom_pgatos=0;
	float prom_qprros=0;
	float prom_qgatos=0;
	float prom_raza=0;
	float prom_mestizo=0;
	int cont = 0;
	
	aux = pop_pila(stack);
	
	if(ref>185){
		while(cont != 185){ 
		
			if(strchr(aux->regis->adoptado_comprado,a_c) != NULL){
				sum_adop++;
			}else{
				sum_comp++;
			}
			
			if(strchr(aux->regis->raza_mestizo,a_R) != NULL){
				sum_raza++;
			}else{
				sum_mest++;
			}
			
			if(strchr(aux->regis->preferencia_perros_gatos,a_P) != NULL){
				sum_pprros++;
			}else{
				sum_pgatos++;
			}
			InsertarElemento(Arbol,aux->regis);
			cont++;
			//printf("%d\n",cont);
			aux = pop_pila(stack);
			//printf("%d\n",cont);
		}
	}
	else{
		while(cont != ref){ 
		
			if(strchr(aux->regis->adoptado_comprado,a_c) != NULL){
				sum_adop++;
			}else{
				sum_comp++;
			}
			
			if(strchr(aux->regis->raza_mestizo,a_R) != NULL){
				sum_raza++;
			}else{
				sum_mest++;
			}
			
			if(strchr(aux->regis->preferencia_perros_gatos,a_P) != NULL){
				sum_pprros++;
			}else{
				sum_pgatos++;
			}
			InsertarElemento(Arbol,aux->regis);
			cont++;
			//printf("%d\n",cont);
			aux = pop_pila(stack);
			//printf("%d\n",cont);
		}
	}
	
	printf("\n\nPromedios:");
	//printf("%d",cont);
	prom_adop=(sum_adop/cont)*(100.00);
	printf("\n El promedio de mascotas adoptados: %.2f",prom_adop);
	prom_comp=(sum_comp/cont)*(100.00);
	printf("\n El promedio de mascotas compradas: %.2f",prom_comp);
	prom_raza=(sum_raza/cont)*(100.00);
	printf("\n El promedio de mascotas de raza: %.2f",prom_raza);
	prom_mestizo=(sum_mest/cont)*(100.00);
	printf("\n El promedio de mascotas mestizas: %.2f",prom_mestizo);
	prom_pprros=(sum_pprros/cont)*(100.00);
	printf("\n El promedio de preferencia por perros: %.2f",prom_pprros);
	prom_pgatos=(sum_pgatos/cont)*(100.00);
	printf("\n El promedio de preferencia por gatos: %.2f",prom_pgatos);
	printf("\n\n");
	return;	
}


int main(){
	pila stack; char opcion = 's';
	Indicador *Arbol;
	Arbol=CrearArbol(Arbol);
	ini_stack(&stack);
	//funcionar(&stack);
	llenarDatos(&stack,199);
	funcionar(&stack);
	imprimir_stack(&stack);
	
	 //insertar(&stack,Arbol);
	promediar(&stack,Arbol,200);
	//Inorden(Arbol->raiz);
	//Inorden(Arbol->raiz);
	while(opcion == 's'){
		menubuscarDatos(Arbol);
		printf("\n\nDeseas seguir haciendo busquedas ? -> "); scanf(" %c",&opcion);
	}
	

	return 0;
}

