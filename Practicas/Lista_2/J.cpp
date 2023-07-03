#include <string.h>
#include <stdio.h>
#include <conio.h>

int Com(int n, int k);

int main(void){
	int k,n;
	printf("Introduzca el numero de personas\n");
	scanf("%d",&n);
	printf("Introduzca la cantidad maxima de personas por comite\n");
	scanf("%d",&k);
	printf("El resultado de com(%d,%d) es: %d",n,k,Com(n,k));
	return 0;
}

int Com(int n, int k){
	if(n<k){
		return 0;
	}
	else if(k==1){
		return n;
	}
	else{
		return Com(n-1,k)+Com(n-1,k-1);
	}
}
