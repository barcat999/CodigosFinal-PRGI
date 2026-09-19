#include <stdio.h>

struct Persona{

    char nombre[50];
    int edad;

};

int main(){

    struct Persona p[3];

    for(int i = 0 ; i < 3 ; i++){

        printf("Persona %d\n" , i + 1);

        printf("Ingrese el nombre: "); 
        scanf("%s" , p[i].nombre);

        printf("Ingrese edad: ");
        scanf("%d" , &p[i].edad);

        printf("\n");

    }

    for(int i = 0 ; i < 3 ; i++){

        printf("\n--- DATOS INGRESADOS ---\n");

        printf("Persona %d\n" , i + 1);

        printf("Nombre: %s\n" , p[i].nombre);
        printf("Edad: %d\n" , p[i].edad);

    }

    return 0;
    
}