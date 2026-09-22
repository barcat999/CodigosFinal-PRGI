#include <stdio.h>

int main(){

    int vector[5] = {6 , 3 , 18 , 32 , 23} , *zz , *aa;

    /*1. Imprimimos el mapa de memoria para ver donde cayo cada numero*/
    printf("--- MAPA DE MEMORIA DEL ARRAY ---\n");
    for(int i = 0; i < 5; i++){
        
        printf("vector[%d] (Valor: %2d) esta en: %p\n" , i , vector[i] , (void*)&vector[i]);
            
    }
    printf("---------------------------------\n\n");

    /*2. Asignacion directa (equivalente a zz = &vector[0])*/
    zz = vector; 
    printf("zz arranca apuntando al valor %d en la direccion: %p\n\n" , *zz , (void*)zz);

    /*3. Pruebas de impresion (el puntero zz NO se mueve de lugar)*/
    printf("*(zz + 1) -> imprime: %d\n" , *(zz + 1)); 
    printf("*zz + 1   -> imprime: %d\n\n" , *zz + 1); 

    /*4. Aritmetica de punteros (aca SI movemos la direccion de memoria)*/
    aa = zz + 4;        // aa salta 4 posiciones desde el inicio
    zz = zz + 3;        // zz actualiza su posicion saltando 3 lugares

    printf("Despues de hacer la aritmetica:\n");
    printf("zz ahora apunta al valor %d en la direccion: %p\n" , *zz , (void*)zz);
    printf("aa ahora apunta al valor %d en la direccion: %p\n" , *aa , (void*)aa);
    
    return 0;

}