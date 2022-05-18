#include <stdio.h>
#include <string.h>
#include "preprocessing.c"

void command(char c []){
    char command[256];
    strcpy(command, c);
    system(command);
}

void compile(){
    command("flex -l scannerwithreturns.lex");
    command("bison -dv bison.y");
    command("gcc -o test bison.tab.c lex.yy.c -lfl");
}

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
    
    remove("cTemp.c");
    preprocessing(argv[1], ancestorsDef);
    remove("interTemp.c");
    compile();
}