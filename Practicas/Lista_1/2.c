/* Programa de operaciones con numeros complejos
*Suma
*Resta
*Multiplicación
*División
*De rectangular a polar
*¿Cuál es la parte real? ¿Cuál es la parte imaginaria?
*/
#include<stdio.h>
#include<math.h>
#define PI 3.1415169

//PROTOTIPOS DE FUNCION
void suma(float r[],int, float i[], int);
void resta(float e[], int, float m[], int);
void multiplicacion(float ar[], int, float ma[], int);
void division(float dr[], int, float di[], int);
void conversion(float real[],int, float imag[],int);

int main(void){
	
	int op,i,t,t1;
	int r=1;
	float res;
	float a[1],b[1];
	
	
	t= sizeof(a)/sizeof(float);
	t1=sizeof(b)/sizeof(float);
	
	while(r==1){
		printf("OPERACIONES CON NUMEROS COMPLEJOS\n");
		printf("\t\t\t\t\tMENU:");
		printf("\n1. SUMA");
		printf("\n2. RESTA");
		printf("\n3. MULTIPLICACION");
		printf("\n4. DIVISION");
		printf("\n5. CONVERSION BINOMIAL(RECTANGULAR) A POLAR");
		printf("\n\nIngrese la operacion que desee realizar: ");
		scanf("%d",&op);
		for(i=0;i<=1;i++){
			printf("\n\tIgrese el valor real %d: ",i+1);
			scanf("%f",&a[i]);
			printf("\n\tIngrese el valor imaginario %d: ",i+1);
			scanf("%f",&b[i]);
		}
		printf("\nTus valores reales son: %.1f y %.1f, tus valores imaginarios son: %.1f y %.1f",a[0],a[1],b[0],b[1]);
		switch(op){
		
			case 1:
				suma(a,t,b,t1);
			break;
				
			case 2:
				resta(a,t,b,t1);
			break;
			
			case 3:
				multiplicacion(a,t,b,t1);
			break;
				
			case 4:
				division(a,t,b,t1);
			break;
			
			case 5:
				conversion(a,t,b,t1);
			break;
			
			default:
				printf("\nOpcion no valida");	
			break;
		}

		printf("\n\t¿Quieres realizar alguna otra operacion?\n");
		printf("\n\t\t1.SI\t\t\t2.NO\n");
		scanf("%d",&r);
	}
	

	return 0;
}

void suma(float r[], int t, float i[], int t1){
	
	float re,ima;
	
	re= (r[0]+r[1]);
	ima=(i[0]+i[1]);
	
	printf("\n\nLa suma de (%.1f+(%.1f)i)+(%.1f+(%.1f)i) es: %.1f +( %.1f)i", r[0],i[0],r[1],i[1],re,ima);
}

void resta(float e[], int t, float m[], int t1){
	
	float re,ima;
	
	re= (e[0]-(e[1]));
	ima=(m[0]-(m[1]));

	printf("\n\nLa resta de (%.1f+(%.1f)i)-(%.1f+(%.1f)i) es: %.1f +( %.1f)i", e[0],m[0],e[1],m[1],re,ima);
}

void multiplicacion(float ar[], int t, float ma[], int t1){
//i^2= -1	
	float re,ima; 
	
	re= ((ar[0]*ar[1])-(ma[0]*ma[1]));
	
	ima= ((ar[0]*ma[1])+(ma[0]*ar[1]));
	
	printf("\n\n La multiplicacion de (%.1f+(%.1f)i)(%.1f+(%.1f)i) es: %.1f + (%.1f)i", ar[0],ma[0],ar[1],ma[1],re,ima);
}

void division(float dr[], int t, float di[], int t1){
	
	float re,ima,den;
		
		re=((dr[0]*dr[1])+(di[0]*di[1]));
		ima=((di[0]*dr[1])-(dr[0]*di[1]));
		den=pow(dr[1],2)+pow(di[1],2);
		
		printf("\nLa division de (%.1f+(%.1f)i)/(%.1f+(%.1f)i) es:  %f+(%.1f)i/%.1f",dr[0],di[0],dr[1],di[1],re,ima,den);
		
}

void conversion(float real[],int t, float imag[],int t1){
	
	float o,z,o1,z1,rtog;
	
	rtog= 180/PI;
	z= sqrt(pow(real[0],2)+pow(imag[0],2));
	o= atan2(imag[0],real[0])*rtog;
	z1= sqrt(pow(real[1],2)+pow(imag[1],2));
	o1=atan2(imag[1],real[1])*rtog;

	
	printf(" El polar 1 es: %.2f |%.2f",z,o);
	printf(" El polar 2 es: %.2f |%.2f",z1,o1);
	
}
