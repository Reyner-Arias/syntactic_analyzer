#include <stdio.h>
#include <string.h>
#include "preprocessing.c"

int main()
{
    newArray ancestorsDef;
    ancestorsDef.index = 0;
    printf("Welcome to the lexical analyzer, please type the name of the file that you want to analyze:\n");
    string fileName = {};
    scanf("%s", fileName);
    remove("cTemp.c");
    preprocessing(fileName, ancestorsDef);
    remove("interTemp.c");
}