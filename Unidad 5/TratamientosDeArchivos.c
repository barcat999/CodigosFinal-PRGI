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

    /*
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

void bajaLogica(){

    FILE *archivo = fopen("archivo.dat" , "ab");
    if(archivo == NULL) return;

    struct Registro reg;
    int encontrado = 0 , claveBuscado;

    printf("Ingrese legajo a borrar: ");
    scanf("%d", &claveBuscado);

    while(fread(&reg , sizeof(struct Registro) , 1 , archivo) == 1){

        if(reg.clave == claveBuscado && reg.activo == 1){

            reg.activo = 0;
            fseek(archivo , -(long)sizeof(struct Registro) , SEEK_CUR);
            fwrite(&reg , sizeof(struct Registro) , 1 , archivo);
            encontrado = 1;
            printf("Baja logica empleada con exito\n");
            break;

        }

    }

    fclose(archivo);
    if(encontrado == 0) printf("Clave no encontrada\n");

}

void bajaFisica(){

    FILE *og = fopen("archivo.dat" , "rb") , *temp = fopen("temporal.dat" , "wb");
    if(og == NULL || temp == NULL) return;

    struct Registro reg;
    int encontrado = 0;

    while(fread(&reg , sizeof(struct Registro) , 1 , og) == 1){

        if(reg.activo == 1) fwrite(&reg , sizeof(struct Registro) , 1 , temp);
        else encontrado = 1;

    }

    fclose(og);
    fclose(temp);

    if(encontrado == 1){

        remove("archivo.dat");
        rename("temporal.dat" , "archivo.dat");
        printf("Baja fisica de mantenimiento ejecutada con exito\n");

    }
    else{

        remove("temporal.dat");
        printf("No habia regsitros dado de baja para limpiar\n");

    }

}