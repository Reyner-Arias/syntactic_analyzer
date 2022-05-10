#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTLEN 128
typedef char string [MAXSTLEN*4];
char buffer[MAXSTLEN*4];
int buffer_index = 0;
char line_buffer[MAXSTLEN*8];
int line_buffer_index = 0;
string ancestors[512];
int ancestorsIndex = 0;
int fileCounter = 0;

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

void clear_line_buffer(void){
    memset(line_buffer, 0, sizeof line_buffer);
    line_buffer_index = 0;
}

void line_buffer_char(char c){
    line_buffer[line_buffer_index] = c;
    line_buffer_index++;
    if (line_buffer_index > MAXSTLEN*8-1)
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

newArray preprocessing(char* pfileName, newArray ancestorsDef){
    newArray localDef, acumulatedDef;
    
    string fileName;
    strcpy(fileName, pfileName);
    if(ancestorsIndex < 512) strcpy(ancestors[ancestorsIndex++], fileName);
    else {
        printf("Call stack reached his limit\n");
        exit(-1);
    }

    int multLineCom = 0;
    localDef.index = 0;
    acumulatedDef.index = 0;
    int in_char, c;
    
    //Remove comments to simplify the code
    FILE *inFile = fopen(fileName, "r");
    if (inFile == NULL)
    {
        printf("Error! Could not open file\n");
        return acumulatedDef;
    }
    char tempfile[12];
    sprintf(tempfile, "wComm%d.c", fileCounter);
    fileCounter++;

    FILE *wComments = fopen(tempfile, "w");

    while ((in_char = getc(inFile)) != EOF){
        if(in_char == '/'){
            in_char = getc(inFile);
            if(in_char == '/'){
                for (c = getc(inFile); c != '\n' && c != EOF; c = getc(inFile));
                ungetc(c, inFile);
            } else if (in_char == '*'){
                multLineCom = 1;
            } else {
                if(multLineCom == 0) {
                    fprintf(wComments, "/%c", in_char);
                }
            }
        } else if(in_char == '*'){
            in_char = getc(inFile);
            if (in_char == '/'){
                multLineCom = 0;
            } else {
                if(multLineCom == 0) {
                    fprintf(wComments, "*%c", in_char);
                }
            }
        } else {
            if(multLineCom == 0) {
                fprintf(wComments, "%c", in_char);
            }
        }
    }
    if(multLineCom == 1) {
        printf("Warning: Expected a comment enclosed before end of file\n");
    }
    fclose(inFile);
    fclose(wComments);


    // Start analyzing the file without comments
    FILE *file = fopen(tempfile, "r");
    if (file == NULL)
    {
        printf("Error! Could not open file\n");
        return;
    }
    FILE *tmp = fopen("cTemp.c", "a+");

    clear_line_buffer();
    while ((in_char = getc(file)) != EOF){
        if(in_char == '\n'){
            fprintf(tmp, "%s\n", line_buffer);
            clear_line_buffer();
        } else {
            line_buffer_char(in_char);
        }
        if (in_char == '#'){
            clear_buffer();
            for (c = getc(file); isspace(c); c = getc(file)){
                line_buffer_char(c);
            }
            ungetc(c, file);
            for (c = getc(file); isalpha(c); c = getc(file)){
                buffer_char(c);
                line_buffer_char(c);
            }
            ungetc(c, file);
            if (!strcmp(buffer, "include"))
            {
                int angular = 0;
                int quotes = 0;

                clear_buffer();
                for(c = getc(file); c != '<' && c != '\"' && c != '\n' && c != EOF; c = getc(file)){
                    line_buffer_char(c);
                    //Buscar defines actuales
                }
                if(c == '<'){
                    line_buffer_char(c);
                    angular = 1;
                    for (c = getc(file); angular < 2; c = getc(file)){
                        line_buffer_char(c);
                        if (c == '>'){
                            angular = 2;
                        } else if (c == '\n')
                        {
                            printf("Warning: There is no left angular bracket in the #include directive\n");
                            fprintf(tmp, "%s", line_buffer);
                            clear_line_buffer();
                            angular = 3;
                        } else if (c == 0)
                        {
                            printf("Warning: Invalid character in a file\n");
                            ungetc(c, file);
                            line_buffer[line_buffer_index-1] = 0;
                            line_buffer_index--;
                            fprintf(tmp, "%s", line_buffer);
                            angular = 3;
                        } else
                        {
                            buffer_char(c);
                        } 
                    }
                    ungetc(c, file);
                    if (angular == 3) continue;
                    if (buffer_index == 0)
                    {
                        printf("Warning: Expected filename\n");
                        fprintf(tmp, "%s", line_buffer);
                        continue;
                    }
                    if(!isInclude(buffer, ancestors, ancestorsIndex)){
                        newArray nextAncestorsDef, tmpDef;
                        char lFilename[1024];

                        sprintf(lFilename, "/usr/include/%s", buffer);
                        nextAncestorsDef.index = 0;
                        concatArray(&nextAncestorsDef, &ancestorsDef);
                        concatArray(&nextAncestorsDef, &localDef);

                        fclose(tmp);
                        tmpDef = preprocessing(lFilename, nextAncestorsDef);
                        tmp = fopen("cTemp.c", "a+");
                        concatArray(&acumulatedDef, &tmpDef);
                    } else {
                        printf("Warning: There is a cycle in the include directives\n");
                        fprintf(tmp, "%s", line_buffer);
                        continue;
                    }
                } else if(c == '\"'){
                    line_buffer_char(c);
                    quotes = 1;
                    for (c = getc(file); quotes < 2; c = getc(file)){
                        line_buffer_char(c);
                        if (c == '\"'){
                            quotes = 2;
                        } else if (c == '\n')
                        {
                            printf("Warning: There is no left angular bracket in the #include directive\n");
                            fprintf(tmp, "%s", line_buffer);
                            clear_line_buffer();
                            quotes = 3;
                        } else if (c == 0)
                        {
                            printf("Warning: Invalid character in a file\n");
                            ungetc(c, file);
                            line_buffer[line_buffer_index-1] = 0;
                            line_buffer_index--;
                            fprintf(tmp, "%s", line_buffer);
                            quotes = 3;
                        } else
                        {
                            buffer_char(c);
                        } 
                    }
                    if (quotes == 3) continue;
                    if (buffer_index == 0)
                    {
                        printf("Warning: Expected filename\n");
                        fprintf(tmp, "%s", line_buffer);
                        continue;
                    }
                    if(!isInclude(buffer, ancestors, ancestorsIndex)){
                        newArray nextAncestorsDef, tmpDef;
                        nextAncestorsDef.index = 0;
                        concatArray(&nextAncestorsDef, &ancestorsDef);
                        concatArray(&nextAncestorsDef, &localDef);
                        fclose(tmp);
                        tmpDef = preprocessing(buffer, nextAncestorsDef);
                        tmp = fopen("cTemp.c", "a+");
                        concatArray(&acumulatedDef, &tmpDef);
                    } else {
                        printf("Warning: There is a cycle in the include directives\n");
                        fprintf(tmp, "%s", line_buffer);
                        continue;
                    }
                } else {
                    fprintf(tmp, "%s", line_buffer);
                    //Buscar defines
                }
            } 
        }
    }
    fprintf(tmp, "%s\n", line_buffer);
    clear_line_buffer();

    remove(tempfile);
    concatArray(&acumulatedDef, &localDef);
    return acumulatedDef;
}