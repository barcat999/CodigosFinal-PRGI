#include <stdio.h>

struct Direccion{
    
    char calle[50];
    int numero;

};

struct Persona{

    char nombre[50];
    int edad;
    struct Direccion domicilio;

};

int main(){

    struct Persona p;

    printf("--- CARGA DE DATOS PERSONALES ---\n");
    printf("Ingrese el nombre: "); 
    scanf(" %[^\n]", p.nombre);

    printf("Ingrese edad: ");
    scanf("%d" , &p.edad);

    printf("\n--- CARGA DE DOMICILIO ---\n");
    printf("Ingrese nombre de calle: ");
    scanf(" %[^\n]", p.domicilio.calle);

    printf("Ingrese el numero de la calle: ");
    scanf("%d" , &p.domicilio.numero);

    printf("\n--- DATOS INGRESADOS ---\n");
    printf("Nombre: %s\n" , p.nombre);
    printf("Edad: %d\n" , p.edad);
    printf("Domicilio: %s %d " , p.domicilio.calle , p.domicilio.numero);

    return 0;
    
}