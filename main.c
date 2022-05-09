#include <stdio.h>
#include <string.h>
#include "preprocessing.c"

int main(int argc, char *argv[])
{
    newArray ancestorsDef;
    ancestorsDef.index = 0;
    printf("Welcome to the syntactic analyzer\n");
    if (argc != 2)
    {
        printf("Argumento inválido\n para hacer funcionar este programa debe ingresar:\n ./main nombreArchivo");
        exit(1);
    }
    printf("%s\n", argv[1]);
    scanf("%s", argv[1]);
    remove("cTemp.c");
    preprocessing(argv[1], ancestorsDef);
    remove("interTemp.c");
}