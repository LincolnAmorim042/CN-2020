#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double in, ip, er, xant, xatu, aux, aer;

    printf("Entre com o intervalo (negativo): ");
    scanf("%lf", &in);
    printf("Entre com o intervalo (positivo): ");
    scanf("%lf", &ip);
    printf("Entre com o erro: ");
    scanf("&lf", &er);

    do{
        xatu = (in+np)/2;
        aux = ; //descobre qual é o nosso exercício, é só colocar a função aqui nessa linha
        if(aux<0){
            in = xatu;
        }else{
            ip = xatu;
        }
        aer = fabs(xatu-xant);
        xant = xatu;
    }while(aer>er);
}
