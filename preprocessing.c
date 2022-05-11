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
    FILE *tmp;
    int str = 0;
    clear_line_buffer();
    while ((in_char = getc(file)) != EOF){
        if(in_char == '\n'){
            tmp = fopen("cTemp.c", "a+");
            fprintf(tmp, "%s\n", line_buffer);
            fclose(tmp);
            clear_line_buffer();
        } else {
            line_buffer_char(in_char);
        }
        if(in_char == '\"') str++;
        if((str%2)==0){
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
                            //Buscar defines
                            if (c == '>'){
                                angular = 2;
                            } else if (c == '\n')
                            {
                                printf("Warning: There is no left angular bracket in the #include directive\n");
                                tmp = fopen("cTemp.c", "a+");
                                fprintf(tmp, "%s", line_buffer);
                                fclose(tmp);
                                clear_line_buffer();
                                angular = 3;
                            } else if (c == 0)
                            {
                                printf("Warning: Invalid character in a file\n");
                                ungetc(c, file);
                                line_buffer[line_buffer_index-1] = 0;
                                line_buffer_index--;
                                tmp = fopen("cTemp.c", "a+");
                                fprintf(tmp, "%s", line_buffer);
                                fclose(tmp);
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
                            tmp = fopen("cTemp.c", "a+");
                            fprintf(tmp, "%s", line_buffer);
                            fclose(tmp);
                            continue;
                        }
                        if(!isInclude(buffer, ancestors, ancestorsIndex)){
                            newArray nextAncestorsDef, tmpDef;
                            char lFilename[1024];

                            sprintf(lFilename, "/usr/include/%s", buffer);
                            nextAncestorsDef.index = 0;
                            concatArray(&nextAncestorsDef, &ancestorsDef);
                            concatArray(&nextAncestorsDef, &localDef);
                            
                            tmpDef = preprocessing(lFilename, nextAncestorsDef);
                            concatArray(&acumulatedDef, &tmpDef);
                        } else {
                            printf("Warning: There is a cycle in the include directives\n");
                            tmp = fopen("cTemp.c", "a+");
                            fprintf(tmp, "%s", line_buffer);
                            fclose(tmp);
                            continue;
                        }
                    } else if(c == '\"'){
                        line_buffer_char(c);
                        quotes = 1;
                        for (c = getc(file); quotes < 2; c = getc(file)){
                            line_buffer_char(c);
                            //Buscar defines
                            if (c == '\"'){
                                quotes = 2;
                            } else if (c == '\n')
                            {
                                printf("Warning: There is no left angular bracket in the #include directive\n");
                                tmp = fopen("cTemp.c", "a+");
                                fprintf(tmp, "%s", line_buffer);
                                fclose(tmp);
                                clear_line_buffer();
                                quotes = 3;
                            } else if (c == 0)
                            {
                                printf("Warning: Invalid character in a file\n");
                                ungetc(c, file);
                                line_buffer[line_buffer_index-1] = 0;
                                line_buffer_index--;
                                tmp = fopen("cTemp.c", "a+");
                                fprintf(tmp, "%s", line_buffer);
                                fclose(tmp);
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
                            tmp = fopen("cTemp.c", "a+");
                            fprintf(tmp, "%s", line_buffer);
                            fclose(tmp);
                            continue;
                        }
                        if(!isInclude(buffer, ancestors, ancestorsIndex)){
                            newArray nextAncestorsDef, tmpDef;
                            nextAncestorsDef.index = 0;
                            concatArray(&nextAncestorsDef, &ancestorsDef);
                            concatArray(&nextAncestorsDef, &localDef);
                            
                            tmpDef = preprocessing(buffer, nextAncestorsDef);
                            concatArray(&acumulatedDef, &tmpDef);
                        } else {
                            printf("Warning: There is a cycle in the include directives\n");
                            tmp = fopen("cTemp.c", "a+");
                            fprintf(tmp, "%s", line_buffer);
                            fclose(tmp);
                            continue;
                        }
                    } else {
                        tmp = fopen("cTemp.c", "a+");
                        fprintf(tmp, "%s", line_buffer);
                        fclose(tmp);
                    }
                } else if(!strcmp(buffer, "define")){
                    clear_buffer();
                    int section = 0;
                    tuple actualDef;
                    for (c = getc(file); c != '\n' && c != EOF; c = getc(file)){
                        line_buffer_char(c);
                        if (section == 0)
                        {
                            if((isalpha(c) || c == '_') && buffer_index == 0){
                                buffer_char(c);
                            }
                            else if ((isalnum(c) || c == '_') && buffer_index > 0)
                            {
                                buffer_char(c);
                            }
                            else if (isspace(c) && buffer_index > 0)
                            {
                                section++;
                                strcpy(actualDef.identifier, buffer);
                                clear_buffer();
                            }
                            else if (!isspace(c))
                            {
                                printf("Warning: Macro names must be identifiers\n");
                                tmp = fopen("cTemp.c", "a+");
                                fprintf(tmp, "%s", line_buffer);
                                fclose(tmp);
                                section = 2;
                            }
                        }
                        else if (section == 1)
                        {
                            if (isspace(c) && buffer_index == 0)
                            {
                                continue;
                            } else 
                            {
                                buffer_char(c);
                            }
                        }
                    }
                    if(section == 2) continue;
                    if (buffer_index == 0)
                    {
                        printf("Warning: Expected an expresion\n");
                        tmp = fopen("cTemp.c", "a+");
                        fprintf(tmp, "%s", line_buffer);
                        fclose(tmp);
                        continue;
                    }
                    strcpy(actualDef.expression, buffer);
                    localDef.defines[localDef.index] = actualDef;
                    localDef.index++;
                    //printf("%s:%s\n", actualDef.identifier, actualDef.expression);
                }
            } else if(isalpha(in_char) || in_char == '_'){
                tmp = fopen("cTemp.c", "a+");
                line_buffer[line_buffer_index-1] = 0;
                line_buffer_index--;
                fprintf(tmp, "%s", line_buffer);
                fclose(tmp);
                clear_line_buffer();
                clear_buffer();
                buffer_char(in_char);
                for(c = getc(file); isalnum(c) || c == '_'; c = getc(file)){
                    buffer_char(c);
                }
                int flag = 0;
                ungetc(c, file);
                for(int i = localDef.index-1; i > -1 && flag == 0; i--){
                    if(!strcmp(buffer, localDef.defines[i].identifier)){
                        tmp = fopen("cTemp.c", "a+");
                        fprintf(tmp, "%s", localDef.defines[i].expression);
                        fclose(tmp);
                        flag = 1;
                    }
                }
                if(flag == 1) continue;
                for(int i = acumulatedDef.index-1; i > -1 && flag == 0; i--){
                    if(!strcmp(buffer, acumulatedDef.defines[i].identifier)){
                        tmp = fopen("cTemp.c", "a+");
                        fprintf(tmp, "%s", acumulatedDef.defines[i].expression);
                        fclose(tmp);
                        flag = 1;
                    }
                }
                if(flag == 1) continue;
                for(int i = ancestorsDef.index-1; i > -1 && flag == 0; i--){
                    if(!strcmp(buffer, ancestorsDef.defines[i].identifier)){
                        tmp = fopen("cTemp.c", "a+");
                        fprintf(tmp, "%s", ancestorsDef.defines[i].expression);
                        fclose(tmp);
                        flag = 1;
                    }
                }
                if(flag == 1) continue;
                tmp = fopen("cTemp.c", "a+");
                fprintf(tmp, "%s", buffer);
                fclose(tmp);
            }
        }
    }
    tmp = fopen("cTemp.c", "a+");
    fprintf(tmp, "%s\n", line_buffer);
    fclose(tmp);
    clear_line_buffer();

    remove(tempfile);
    concatArray(&acumulatedDef, &localDef);
    return acumulatedDef;
}