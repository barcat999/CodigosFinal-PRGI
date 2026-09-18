#include <stdio.h>

struct Persona{

    char nombre[50];
    int edad;

};

int main(){

    struct Persona p;

    printf("Ingrese el nombre: "); 
    scanf("%s" , p.nombre);

    printf("Ingrese edad: ");
    scanf("%d" , &p.edad);

    printf("\n--- DATOS INGRESADOS ---\n");
    printf("Nombre: %s\n" , p.nombre);
    printf("Edad: %d\n" , p.edad);

    return 0;
    
}