#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTLEN 128
typedef char string [MAXSTLEN*4];
char buffer[MAXSTLEN*4];
int buffer_index = 0;
string ancestors[512];
int ancestorsIndex = 0;

typedef struct Tuples
{
    char identifier[MAXSTLEN];
    char expression[MAXSTLEN*2];
} tuple;

typedef struct NewArrays
{
    tuple defines[512];
    int index;
} newArray;

int isInclude(string s, string* list, int index){
    for(int i = 0; i<index; i++){
        if(!strcmp(s, list[i])){
            return 1;
        }
    }
    return 0;
}

void clear_buffer(void){
    memset(buffer, 0, sizeof buffer);
    buffer_index = 0;
}

void buffer_char(char c){
    buffer[buffer_index] = c;
    buffer_index++;
    if (buffer_index > MAXSTLEN*4-1)
    {
        printf("Buffer overflow\n");
        exit(-1);
    }
}

void concatArray(newArray* original, newArray* extension){
    for (int i = 0; i < extension->index; i++)
    {
        original->defines[original->index] = extension->defines[i];
        if(original->index >=512){
            printf("Too many define directives");
            exit(-1);
        }
        original->index++;
    }
}

newArray preprocessing(string pfileName){
    newArray localDef, ancestorsDef, acumulatedDef;

    string fileName;
    strcpy(fileName, pfileName);
    if(ancestorsIndex < 512) strcpy(ancestors[ancestorsIndex++], fileName);
    else {
        printf("Call stack reached his limit\n");
        exit(-1);
    }
}