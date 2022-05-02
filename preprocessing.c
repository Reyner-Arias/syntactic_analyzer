#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTLEN 128
typedef char string [MAXSTLEN*4];
char buffer[MAXSTLEN*4];
int buffer_index = 0;
string files[512];
int filesIndex = 0;
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

void replace(tuple actualDef){
    FILE* interTemp = fopen("interTemp.c", "a+");
    int in_char, c;
    FILE* tmp = fopen("interTemp.c", "a+");
    int str = 0;
    while ((in_char = getc(interTemp)) != EOF)
    {
        clear_buffer();
        if(isalnum(in_char) || in_char == '_') buffer_char(in_char);
        for (c = getc(interTemp); isalnum(c) || c == '_'; c = getc(interTemp)){
            buffer_char(c);
        }
        ungetc(c, interTemp);
        if (!isalnum(in_char) && in_char != '_')
        {
            fprintf(tmp, "%c", in_char);
            if(in_char == '\"' && str == 1)
                str = 0;
            else if(in_char == '\"')
                str++;
        } 
        if (!strcmp(actualDef.identifier, buffer))
        {
            if(str != 1){
                fprintf(tmp, "%s", actualDef.expression);
            }else{
                fprintf(tmp, "%s", actualDef.identifier);
            }
        } else if (buffer_index > 0){
            fprintf(tmp, "%s", buffer);
        } 
    }
    fclose(interTemp);
    interTemp = fopen("interTemp.c", "w");
    while ((in_char = getc(tmp)) != EOF)
    {
        clear_buffer();
        if (in_char != '\n' && in_char != EOF)
        {
            buffer_char(in_char);
        }else if (in_char == '\n')
        {
            fprintf(interTemp, "%s\n", buffer);
        } else{
            fprintf(interTemp, "%s", buffer);
        }
    }
    fclose(tmp);
    fclose(interTemp);
}

newArray preprocessing(string pfileName){
    newArray localDef, tmpDef;
    string fileName;
    strcpy(fileName, pfileName);
    int isInCtemp = isInclude(fileName, files, filesIndex);
    if(ancestorsIndex < 512) strcpy(ancestors[ancestorsIndex++], fileName);
    else {
        printf("Call stack reached his limit\n");
        exit(-1);
    }
    int multLineCom = 0;
    localDef.index = 0;
    tmpDef.index = 0;
    int in_char, c;

    //Remove comments to simplify the code
    FILE *inFile = fopen(fileName, "r");
    if (inFile == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1);
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
        printf("Expected a comment enclosed before end of file\n");
        exit(-1);
    }
    fclose(inFile);
    fclose(wComments);

    //Find all includes in current file
    FILE *file = fopen(tempfile, "r");

    while ((in_char = getc(file)) != EOF){
        if (in_char == '#'){
            clear_buffer();
            for (c = getc(file); isalpha(c); c = getc(file)){
                buffer_char(c);
            }
            ungetc(c, file);
            if (!strcmp(buffer, "include"))
            {
                clear_buffer();
                int quotes = 0;
                for (c = getc(file); quotes < 2; c = getc(file)){
                    if (c == '\"')
                    {   
                        quotes++;
                    }else if (c == '\n')
                    {
                        printf("There are not enough quotes in the #include directive\n");
                        fclose(file);
                        exit(-1);
                    } else if (c == '/' || c == 0)
                    {
                        printf("Invalid character in a file\n");
                        fclose(file);
                        exit(-1);
                    } else if (quotes >= 1)
                    {
                        buffer_char(c);
                    } else if (!isspace(c))
                    {
                        printf("Expected filename\n");
                        fclose(file);
                        exit(-1);
                    }
                }
                int extraChar = 0;
                while (c != '\n' && c != EOF){
                    if (!isspace(c) && extraChar == 0)
                    {
                        printf("Warning: Extra characters after #include directive\n");
                        extraChar++;
                    }
                    c = getc(file);
                }
                if (buffer_index == 0)
                {
                    printf("Expected filename\n");
                    fclose(file);
                    exit(-1);
                }
                if(!isInclude(buffer, ancestors, ancestorsIndex)){
                    tmpDef = preprocessing(buffer);
                    concatArray(&localDef, &tmpDef);
                } else {
                    printf("There is a cycle in the include directives\n");
                    exit(-1);
                }
            } 
        }
    }
    
    fclose(file);
    if(!isInCtemp){
        FILE* tmpFile = fopen("interTemp.c", "w");
        file = fopen(tempfile, "r");
        while ((in_char = getc(file)) != EOF){
            clear_buffer();
            if (in_char == '#'){
                for (c = getc(file); isalpha(c); c = getc(file)){
                    buffer_char(c);
                }
                ungetc(c, file);
                if (!strcmp(buffer, "include"))
                {
                    for (c = getc(file); c != '\n' && c != EOF; c = getc(file));
                } else if (!strcmp(buffer, "define"))
                {
                    fprintf(tmpFile, "#%s", buffer);
                }
            } else
            {
                fprintf(tmpFile, "%c", in_char);
            }
        }
        fclose(file);
        fclose(tmpFile);

        //Replace children defines to the current file
        for(int i = 0; i < localDef.index; i++){
            replace(localDef.defines[i]);
        }
    }

    file = fopen(tempfile, "r");
    clear_buffer();
    if(feof(file))
        return;
    while ((in_char = getc(file)) != EOF){
        if (in_char == '\n' || in_char == ' ') continue;
        if (in_char == '#'){
            clear_buffer();
            for (c = getc(file); isalpha(c); c = getc(file)){
                buffer_char(c);
            }
            ungetc(c, file);
            if (!strcmp(buffer, "define"))
            {
                clear_buffer();
                int section = 0;
                tuple actualDef;
                for (c = getc(file); c != '\n' && c != EOF; c = getc(file)){
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
                            printf("Macro names must be identifiers\n");
                            fclose(file);
                            exit(-1);
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
                if (buffer_index == 0)
                {
                    printf("Expected an expresion\n");
                    fclose(file);
                    exit(-1);
                }
                strcpy(actualDef.expression, buffer);
                //printf("%s:%s\n", actualDef.identifier, actualDef.expression);
                localDef.defines[localDef.index] = actualDef;
                localDef.index++;
                if(!isInCtemp) replace(actualDef);
            }
        } else for (c = getc(file); c != '\n' && c != EOF; c = getc(file));
    }
    fclose(file);
    // Add to the final temporary file the inter temp data
    if(!isInCtemp){
        FILE* interTemp = fopen("interTemp.c", "r");
        FILE* cTemp = fopen("cTemp.c", "a+");
        while ((in_char = getc(interTemp)) != EOF){
            if (in_char == '\n' || in_char == ' ') continue;
            if (in_char != '#'){
                clear_buffer();
                buffer_char(in_char);
                for (c = getc(interTemp); c != '\n' && c != EOF; c = getc(interTemp)){
                    buffer_char(c);
                }
                fprintf(cTemp, "%s\n", buffer);
            } else {
                for (c = getc(interTemp); c != '\n' && c != EOF; c = getc(interTemp));
            } 
        }
        fclose(interTemp);
        fclose(cTemp);
        if(filesIndex < 512){
            strcpy(files[filesIndex], fileName);
            filesIndex++;
        }else{
            printf("Too many includes directives\n");
            exit(-1);
        }
    }
    strcpy(ancestors[--ancestorsIndex], "");
    remove(tempfile);
    return localDef;
}