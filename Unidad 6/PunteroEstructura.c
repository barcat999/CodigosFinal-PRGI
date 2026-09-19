#include <stdio.h>>

struct Alumno{

    char nombre[50];
    int mu;
    float promedio;

};

int main(){

    struct Alumno alumno , *ptr = &alumno; 

    printf("Ingrese nombre del alumno: ");
    scanf("%s" , ptr->nombre);

    printf("Ingrese matricula del alumno: ");
    scanf("%d" , &ptr->mu);

    printf("Ingrese promeidio del alumno: ");
    scanf("%f" , &ptr->promedio);

    printf("\n-- DATOS INGRESADOS--\n");
    printf("Nombre del alumno: %s\n " , ptr->nombre);
    printf("Matricula del alumno: %d\n " , ptr->mu);
    printf("Promedio del alumno: %.2f\n " , ptr->promedio);

    return 0;

}