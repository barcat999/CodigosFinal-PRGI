#include <stdio.h>

struct Registro{

    int clave;
    char nombre[50];
    int activo;

};

void alta(){

    FILE *archivo = fopen("archivo.dat" , "ab");
    if(archivo == NULL) return;

    struct Registro nuevo;

    printf("Ingrese clave: ");
    scanf("%d " , &nuevo.clave);

    /**
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nuevo.nombre);
    */

    nuevo.activo = 1;

    fwrite(&nuevo , sizeof(struct Registro) , 1 , archivo);

    fclose(archivo);
    printf("Alta exitosa\n");

}

void modificar(){

    FILE *archivo = fopen("archivo.dat" , "ab");

    struct Registro reg;
    int encontrado = 0 , claveBuscado;

    printf("Ingrese clave a modificar: ");
    scanf("%d " , &reg.clave);

    while(fread(&reg , sizeof(struct Registro) , 1 , archivo) == 1){

        if(reg.clave == claveBuscado && reg.activo == 1){

            printf("Nombre actual: %s\n" , reg.nombre);

            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(reg.nombre);

            fseek(archivo , -(long)sizeof(struct Registro) , SEEK_CUR);
            fwrite(&reg , sizeof(struct Registro) , 1 , archivo);

            encontrado = 1;
            printf("Modificada con exito\n");
            break;

        }

    }

    fclose(archivo);
    if(encontrado == 0) printf("Clave no encontrada o dada de baja\n");

}