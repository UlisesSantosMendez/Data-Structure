#include<stdio.h>

typedef struct FRACCION{
    int numerador;
    int denominador;
}fraccion;



fraccion sumar(fraccion a, fraccion b){
    fraccion res;
    res.denominador = min_c_m(a.denominador, b.denominador);
    res.numerador = ((res.denominador / a.denominador) * a.numerador) + ((res.denominador / b.denominador) * b.numerador);
    return res;
}

fraccion restar(fraccion a, fraccion b){
    fraccion res;
    res.denominador = min_c_m(a.denominador, b.denominador);
    res.numerador = ((res.denominador / a.denominador) * a.numerador) - ((res.denominador / b.denominador) * b.numerador);
    return res;
}

fraccion multiplicar(fraccion a, fraccion b){
    fraccion res; int mcd;
    res.numerador = a.numerador * b.numerador;
    res.denominador = a.denominador * b.denominador;
    mcd = max_c_d(res.numerador, res.denominador);
    res.numerador = res.numerador / mcd;
    res.denominador = res.denominador /mcd;
    return res;
}

fraccion dividir(fraccion a, fraccion b){
    fraccion res; int mcd;
    res.numerador = a.numerador * b.denominador;
    res.denominador = a.denominador * b.numerador;
    mcd = max_c_d(res.numerador, res.denominador);
    res.numerador = res.numerador / mcd;
    res.denominador = res.denominador /mcd;
    return res;
}

int max_c_d(int a, int b){
    int mayor, menor, mcd, residuo = 1;
    if(a > b){
        mayor = a;
        menor = b;
    }else{
        mayor = b;
        menor = a;
    }

    while(residuo != 0){
        residuo = mayor % menor;
        mayor = menor;
        menor = residuo;
    }
    mcd = mayor;
    return mcd;
}


int min_c_m(int a, int b){
    int mcm, mcd;
    mcd = max_c_d(a,b);
    mcm =(a * b)/mcd;
    return mcm;
}


int main(){

    fraccion f1,f2,res;
    int residuo;

    printf("Introduce el numerador de la fraccion\n");
    scanf("%d",&f1.numerador);
    printf("Introduce el denominador de la fraccion\n");
    scanf("%d",&f1.denominador);
    printf("%d/%d\n\n",f1.numerador,f1.denominador);
    printf("Introduce el numerador de la segunda fraccion\n");
    scanf("%d",&f2.numerador);
    printf("Introduce el denominador de la segunda fraccion\n");
    scanf("%d",&f2.denominador);
    printf("%d/%d\n\n",f2.numerador,f2.denominador);


    res = sumar(f1,f2);
    printf("La suma de las fracciones es -> %d/%d\n\n",res.numerador,res.denominador);

    res = restar(f1,f2);
    printf("La resta de las fracciones es -> %d/%d\n\n",res.numerador,res.denominador);

    res = multiplicar(f1,f2);
    printf("La multiplicacion de las fracciones es -> %d/%d\n\n",res.numerador,res.denominador);

    res = dividir(f1,f2);
    printf("La division de las fracciones es -> %d/%d\n\n",res.numerador,res.denominador);

    return 0;
}
