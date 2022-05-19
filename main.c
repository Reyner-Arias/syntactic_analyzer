#include <stdio.h>
#include <string.h>
#include "preprocessing.c"

void command(char c []){
    char command[256];
    strcpy(command, c);
    system(command);
}

void compile(){
    command("lex scannerwithreturns.lex");
    command("bison -d simple.y");
    command("gcc simple.tab.c lex.yy.c -o result");
    command("./result");
}

int main(int argc, char *argv[])
{
    newArray ancestorsDef;
    ancestorsDef.index = 0;
    printf("Welcome to the syntactic analyzer\n");
    if (argc != 2)
    {
        printf("Argumento inválido para hacer funcionar este programa debe ingresar:\n ./main nombreArchivo \n");
        exit(1);
    }
    
    remove("cTemp.c");
    preprocessing(argv[1], ancestorsDef);
    compile();
}