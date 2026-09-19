#include <stdio.h>

int main(){

    int edad = 21;
    void *p = &edad;

    printf("%d" , *(int *)p);

    return 0;

}