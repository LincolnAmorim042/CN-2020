#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, ite=0;
    double p, res, ant=0;

    do{
        printf("Entre com o indice (n): ");
        scanf("%d", &n);
    }while(n<1);

    do{
        printf("Entre com o radicando (p, use '.', nao ','): ");
        scanf("%lf", &p);
    }while(p<1);

    printf("Entre com o chute inicial: ");
    scanf("%lf", &res);

    while (res - ant != 0){
        ant = res;
        res = (1.0/n)*(((n-1)*res)+(p/pow(res, n-1)));
        if(res - ant != 0) {
            ite++;
            printf("Iteracao: %d  X%d: %.9lf\n", ite, ite, res);
        }

    }
    printf("\nRaiz = %.9lf\n Iteracao: %d\n", res, ite);

}
