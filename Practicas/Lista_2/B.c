//Programa para ordenar datos de un arreglo empleando Quicksort

#include<stdio.h>


//Prototipos de funcion
int particiones(int arr[], int, int);
void quicksort(int nums[],int,int);
void intercambiar(int *, int *);

int main(void){

	int num[19];
	int t,op,i;
	int res=1;
	t= sizeof(num)/sizeof(int);

	printf("--------Ordenar arreglo con Quicksort--------\n");
	
	for(i=0;i<=t;i++){
		printf("Ingrese el valor %d: \n",i+1);
		scanf("%d",&num[i]);
	}
	printf("Los datos de tu arreglo son: ");
	for(i=0; i<=t;i++){
		printf("%d,",num[i]);
	}
	quicksort(num,0,t);
	printf("Tu arreglo ordenado es:\n");
	for(i=0;i<=t;i++){
		printf("%d,",num[i]);
	}
	
	
	
	return 0;

}

//Particiones de arreglo
int particiones(int arr[], int izquierda, int derecha){
	
	int pivote;
	pivote=arr[izquierda];
	while(1){
		while(arr[izquierda]<pivote){
			izquierda++;
		}
		
		while(arr[derecha]>pivote){
			derecha--;
		}
		if(izquierda >= derecha){
			return derecha;
		}
		else{
			intercambiar(&arr[izquierda],&arr[derecha]);
			izquierda++;
			derecha--;
		}
	}
}

//Recepcion del arreglo y ordenamiento
void quicksort(int nums[], int izquierda, int derecha){
	int partarray;
	if(izquierda<derecha){
		partarray = particiones(nums,izquierda,derecha);
		quicksort(nums,izquierda,partarray);
		quicksort(nums,partarray+1,derecha);
	}
}

void intercambiar(int *a, int *b){
	
	int temp= *a;
	*a=*b;
	*b=temp;
}

