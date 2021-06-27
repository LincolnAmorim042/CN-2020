#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, j, ord=0, troc=0, p, maior, o=1;
float m[10][10], mul, det=1;

void most(){
    for(int ci=0; ci<ord; ci++){
        printf("\n");
        for(int cj=0; cj<ord; cj++){
            printf("%.2f ", m[ci][cj]);
        }
    }
    printf("\n\n");
}

void troca(){
    float aux;
    printf("Operacao %d:\n", o);
    printf("Troca entre L%d e L%d:", p+1, maior+1);
    for(int cj=p; cj<ord; cj++){
        aux=m[p][cj];
        m[p][cj]=m[maior][cj];
        m[maior][cj]=aux;
    }
    troc++;
    o++;
    most();
}

void pivo(){
    maior = -1;
    float modp, modi;
    modp = fabs(m[p][p]);
    for (int ci = p + 1; ci < ord; ci++){
        modi = fabs(m[ci][p]);
        if(modp < modi){
            maior = ci;
        }
    }
    if(maior != -1){
        troca();
    }
}

void op(){
    printf("Operacao %d:\n", o);
    mul = m[i][p]/m[p][p];
    printf("L%d' = L%d - (%.2f * L%d):", i+1, i+1, mul, p+1);
    for(j=p; j<ord; j++){
        m[i][j]= m[i][j] - (mul*m[p][j]);
    }
    o++;
    most();
}

int main(){
    float a;

    printf("GAUSS COM PIVOTACAO PARCIAL PARA O CALCULO DE DETERMINANTE\n");
    printf("Feito por Lincoln Amorim  RGM: 41443\n\n");
    do{
        printf("De a ordem da matriz:\n");
        scanf("%d", &ord);
    }while((ord<1)||(ord>10));

    for(i=0; i<ord; i++){
        for(j=0; j<ord; j++){
            printf("De o valor de a%d%d:\n", i+1, j+1);
            scanf("%f", &a);
            m[i][j]=a;
        }
    }
    printf("\nMatriz inicial:");
    most();

    for(p=0; p<ord; p++){
        pivo();
        for(i=p+1; i<ord; i++){
            op();
        }
    }
    for(p=0; p<ord; p++){
        det=det*m[p][p];
    }
    det=det*(pow(-1,troc));
    printf("Determinante: %.2f\n", det);

    return 0;
}
