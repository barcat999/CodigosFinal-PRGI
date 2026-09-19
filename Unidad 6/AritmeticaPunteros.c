#include <stdio.h>

int main(){

    int vector[5] = {6 , 3 , 18 , 32 , 23} , *zz , *aa;

    zz = &vector[0];        //      apunta a 6

    printf("%d\n" , *(zz + 1));     //      zz se desplaza temporalmente un lugar para imprimir -> imprime 3
    printf("%d\n" , *zz + 1);       //      se le suma 1 matematicamente al valor al que apunta zz (6 + 1) -> imprime 7

    aa = zz + 4;        //      aa se desplaza 4 lugares desde el inicio , ahora apunta a 23
    zz = zz + 3;        //      zz actualiza su propia posicion desplazandose 3 lugares , ahora apunta a 32

    printf("%d\n" , *zz);        //      imprime 32
    printf("%d\n" , *aa);        //      imprime 23
    
    return 0;

}