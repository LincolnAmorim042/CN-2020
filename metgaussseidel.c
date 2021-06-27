#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double m[10][10], e, et, x[10][2], r[10];
int ord, k=0;

void most(){
    if(k==0){
        printf("\nMatriz inicial:");
        for(int ci=0; ci<ord; ci++){
            printf("\n");
            for(int cj=0; cj<ord; cj++){
                printf("%.9lf ", m[ci][cj]);
            }
        }
        printf("\nk=%d\n", k);
        for(int ci=0; ci<ord; ci++){
            printf("x%d: %.9lf\n", ci, x[ci][0]);
        }
        printf("Erro inicial: %.9lf\n\n", e);
    }else{
        printf("\nk=%d \n", k);
        for(int ci=0; ci<ord; ci++){
            printf("x%d: %.9lf\n", ci, x[ci][1]);
        }
        printf("Erro: %.9lf\n", et);
    }
}

int conv(){
    int co=0;
    double aux;

	for(int ci=0; ci<ord; ci++){
        aux=0;
        for(int cj=0; cj<ord; cj++){
            if(cj!=ci){
                aux = aux+m[ci][cj];
            }
        }
        if((aux/m[ci][ci])<1){
            co++;
        }
	}

	if(co==ord){
        printf("Convergencia satisfeita!\n");
        printf("De os resultados das equacoes:\n");
        for(int i=0; i<ord; i++){
            printf("r%d: ", i+1);
            scanf("%lf", &r[i]);
        }
        printf("De os coeficientes iniciais:\n");
        for(int i=0; i<ord; i++){
            printf("Coeficiente x%d: ", i+1);
            scanf("%lf", &x[i][0]);
        }
        printf("De o erro: ");
        scanf("%lf", &e);
        return 1;
	}else{
        printf("Convergencia nao satisfeita!\nTente novamente\n");
        return 0;
	}
}

void op(){
    double aux=0.0, xm=0.0, dr=0.0;

    k++;
    printf("Iteracao %d:", k);

    if(x[0][1]!=0){
        for(int i=0; i<ord; i++){
            x[i][0] = x[i][1];
        }
    }
    for(int i=0; i<ord; i++){
        aux=0;
        for(int j=0; j<i; j++){
            aux = aux + (m[i][j]*x[j][1]);
        }
        for(int j = i+1; j<ord; j++){
            aux = aux + (m[i][j]*x[j][0]);
        }
        x[i][1] = (r[i]-aux)/m[i][i];
    }

    for(int i=0; i<ord; i++){
        if(fabs(x[i][1] - x[i][0]) > dr){
            dr = fabs(x[i][1] - x[i][0]);
        }
        if(fabs(x[i][1]) > xm){
            xm = fabs(x[i][1]);
        }
    }

    et = (dr/xm);
}

int main(){
    double a;

    printf("GAUSS-SEIDEL PARA SOLUCAO DE SISTEMAS LINEARES\n");
    printf("Feito por Lincoln Amorim  RGM: 41443\n\n");
    do{
        printf("De a ordem da matriz:\n");
        scanf("%d", &ord);
    }while((ord<1)||(ord>10));


    for(int i=0; i<ord; i++){
        for(int j=0; j<ord; j++){
            printf("De o valor de a%d%d\n", i+1, j+1);
            scanf("%lf", &a);
            m[i][j]=a;
        }
    }

    if(conv()==0){
        return 0;
    }

    most();

    do{
       op();
       most();
    }while(et>=e);

   return 0;
}
