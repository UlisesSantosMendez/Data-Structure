//Programa para calcular de forma recursiva a^b donde a y b sean números enteros

#include<stdio.h>

//PROTOTIPOS DE FUNCIONES
int potencia(int,int);

int main(void){
	
	int a,b,res;
	
	printf("PROGRAMA PARA CALCULAR a^b\n");
	printf("Ingresa el valor de tu base a: ");
	scanf("%d",&a);	
	printf("\nIngresa el valor de tu exponente b: ");
	scanf("%d",&b);
	res=potencia(a,b);
	printf("El resultado de a^b es: %d ",res);
	
	return 0;
}

int potencia(int x, int y){
	
	int res;

	if(y==1){
		res=x;
	}
	else{
		res=x*potencia(x,y-1);
	}
	return res;
}
