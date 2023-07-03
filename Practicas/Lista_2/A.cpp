#include<stdio.h>
#include<stdlib.h>

int main(){

	int tam;
	int i,pasada,aux;
	int comparaciones=0;
	int cont=1;

	printf("Cuantos datos va ingresar?\n");
	scanf("%d",&tam);
	
	int a[tam];

	for(i=0;i<=tam-1;i++){
		printf("Ingresa los datos %d \n",i+1);
		scanf("%d",&a[i]);
	}
	
	printf("los datos ingresados son:\n");
	for(i=0;i<=tam-1;i++)
		printf("%d,",a[i]);
	
	printf("\n");
	printf("\n");
	
	for(pasada=1;pasada<=tam-1&&cont==1;pasada++){
		cont=0; 
		comparaciones++;
		for(i=0;i<=tam-2;i++){
			if(a[i]>a[i+1]){
				cont=1; 
				aux=a[i];
				a[i]=a[i+1];
				a[i+1]=aux;
			}
		}
    }
		printf("Los datos ordenados son: \n");
		for(i=0;i<=tam-1;i++){
			printf("%d,",a[i]);	
		}
		
	printf("\n");	
	printf("\n");
	printf("numero de comparaciones: %d\n",comparaciones);
	printf("\n");
}
