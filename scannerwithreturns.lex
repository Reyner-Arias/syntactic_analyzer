/*Definitions*/
%{
    #include <stdio.h>
    #include "bison.tab.h"
    FILE* tokensTemp;
    static int next_column = 1;
    int column = 1;

    #define HANDLE_COLUMN column = next_column; next_column += strlen(yytext)

    char *lineptr = NULL;
    size_t n = 0;
    size_t consumed = 0;
    size_t available = 0;

    size_t min(size_t a, size_t b);
    #define YY_INPUT(buf,result,max_size) {\
        if(available <= 0) {\
            consumed = 0;\
            available = getline(&lineptr, &n, yyin);\
            if (available < 0) {\
                if (ferror(yyin)) { perror("read error:"); }\
                    available = 0;\
                }\
        }\
        result = min(available, max_size);\
        strncpy(buf, lineptr + consumed, result);\
        consumed += result;\
        available -= result;\
    }
%}
%option noyywrap noinput nounput yylineno
LPAREN "("
RPAREN ")"
LSQBRACKET "["
RSQBRACKET "]"
LBRACKET "{"
RBRACKET "}"
NEWLINE "\n"
SEMICOLON ";"
COMMA ","
ID (([a-z]|[A-Z])|_)((([a-z]|[A-Z])|_)|[0-9])*
INTLITERAL [0-9][0-9]*
FLOATLITERAL ({INTLITERAL}+"."{INTLITERAL}*)
DOUBLELITERAL ({FLOATLITERAL}+"e"{INTLITERAL})
HEXLITERAL 0x({INTLITERAL}|([A-F]|[a-f]))
HEXLITERALFLOAT HEXLITERAL+"."({INTLITERAL}|([A-F]|[a-f]))"p""-"?{INTLITERAL}
CHARLITERAL \'(\\.|[^"\\])\'
STRINGLITERAL \"(\\.|[^"\\])*\"
INVALIDSUFFIX [0-9]([a-z]|[A-Z]|_|[0-9])*

/*Rules*/
%%
auto {
    HANDLE_COLUMN;
    return(AUTO);
}
break {
    HANDLE_COLUMN;
    return(BREAK);
}
case {
    HANDLE_COLUMN;
    return(CASE);
}
char {
    HANDLE_COLUMN;
    return(CHAR);
}
const {
    HANDLE_COLUMN;
    return(CONST);
}
continue {
    HANDLE_COLUMN;
    return(CONTINUE);
}
default {
    HANDLE_COLUMN;
    return(DEFAULT);
}
do {
    HANDLE_COLUMN;
    return(DO);
}
else {
    HANDLE_COLUMN;
    return(ELSE);
}
enum {
    HANDLE_COLUMN;
    return(ENUM);
}
extern {
    HANDLE_COLUMN;
    return(EXTERN);
}
double {
    HANDLE_COLUMN;
    return(DOUBLE);
}
float {
    HANDLE_COLUMN;
    return(FLOAT);
}
for {
    HANDLE_COLUMN;
    return(FOR);
}
goto {
    HANDLE_COLUMN;
    return(GOTO);
}
if {
    HANDLE_COLUMN;
    return(IF);
}
int {
    HANDLE_COLUMN;
    return(INT);
}
long {
    HANDLE_COLUMN;
    return(LONG);
}
register {
    HANDLE_COLUMN;
    return(REGISTER);
}
return {
    HANDLE_COLUMN;
    return(RETURN);
}
short {
    HANDLE_COLUMN;
    return(SHORT);
}
signed {
    HANDLE_COLUMN;
    return(SIGNED);
}
sizeof {
    HANDLE_COLUMN;
    return(SIZEOF);
}
static {
    HANDLE_COLUMN;
    return(STATIC);
}
struct {
    HANDLE_COLUMN;
    return(STRUCT);
}
switch {
    HANDLE_COLUMN;
    return(SWITCH);
}
typedef {
    HANDLE_COLUMN;
    return(TYPEDEF);
}
union {
    HANDLE_COLUMN;
    return(UNION);
}
unsigned {
    HANDLE_COLUMN;
    return(UNSIGNED);
}
void {
    HANDLE_COLUMN;
    return(VOID);
}
volatile {
    HANDLE_COLUMN;
    return(VOLATILE);
}
while {
    HANDLE_COLUMN;
    return(WHILE);
}

inline {
    HANDLE_COLUMN;
    return(INLINE);
}

"_Alignas"                              { HANDLE_COLUMN; return(ALIGNAS); }
"_Alignof"                              { HANDLE_COLUMN; return(ALIGNOF); }
"_Atomic"                               { HANDLE_COLUMN; return(ATOMIC); }
"_Bool"                                 { HANDLE_COLUMN; return(BOOL); }
"_Complex"                              { HANDLE_COLUMN; return(COMPLEX); }
"_Generic"                              { HANDLE_COLUMN; return(GENERIC); }
"_Imaginary"                            { HANDLE_COLUMN; return(IMAGINARY); }
"_Noreturn"                             { HANDLE_COLUMN; return(NORETURN); }
"_Static_assert"                        { HANDLE_COLUMN; return(STATIC_ASSERT); }
"_Thread_local"                         { HANDLE_COLUMN; return(THREAD_LOCAL); }
"__func__"                              { HANDLE_COLUMN; return(FUNC_NAME); }

{STRINGLITERAL} {
    HANDLE_COLUMN;
    sscanf(yytext, "%s", yylval.stringvalue);
    return(STRINGLITERAL);
}

"..." {
    HANDLE_COLUMN;
    return(ELLIPSIS);
}

"+" {
    HANDLE_COLUMN;
    return(ADD);
}

"-" {
    HANDLE_COLUMN;
    return(SUB);
}

"*" {
    HANDLE_COLUMN;
    return(MUL);
}

"/" {
    HANDLE_COLUMN;
    return(DIV);
}

"=" {
    HANDLE_COLUMN;
    return(EQU);
}

"+=" {
    HANDLE_COLUMN;
    return(ADD_ASSIGN);
}

"-=" {
    HANDLE_COLUMN;
    return(SUB_ASSIGN);
}

"*=" {
    HANDLE_COLUMN;
    return(MUL_ASSIGN);
}

"/=" {
    HANDLE_COLUMN;
    return(DIV_ASSIGN);
}

"%" {
    HANDLE_COLUMN;
    return(MOD);
}

"%=" {
    HANDLE_COLUMN;
    return(MOD_ASSIGN);
}

"++" {
    HANDLE_COLUMN;
    return(INC_OP);
}

"--" {
    HANDLE_COLUMN;
    return(DEC_OP);
}

"<" {
    HANDLE_COLUMN;
    return(L_THAN);
}

">" {
    HANDLE_COLUMN;
    return(G_THAN);
}

"<=" {
    HANDLE_COLUMN;
    return(LE_OP);
}

">=" {
    HANDLE_COLUMN;
    return(GE_OP);
}

"==" {
    HANDLE_COLUMN;
    return(EQ_OP);
}

"!=" {
    HANDLE_COLUMN;
    return(NE_OP);
}

"!" {
    HANDLE_COLUMN;
    return(NOT);
}

"&&" {
    HANDLE_COLUMN;
    return(AND_OP);
}

"||" {
    HANDLE_COLUMN;
    return(OR_OP);
}

"<<" {
    HANDLE_COLUMN;
    return(LEFT_OP);
}

"<<=" {
    HANDLE_COLUMN;
    return(LEFT_ASSIGN);
}

">>" {
    HANDLE_COLUMN;
    return(RIGHT_OP);
}

">>=" {
    HANDLE_COLUMN;
    return(RIGHT_ASSIGN);
}

"~" {
    HANDLE_COLUMN;
    return(TILDE);
}

"&" {
    HANDLE_COLUMN;
    return(AND);
}

"&=" {
    HANDLE_COLUMN;
    return(AND_ASSIGN);
}

"|" {
    HANDLE_COLUMN;
    return(OR);
}

"|=" {
    HANDLE_COLUMN;
    return(OR_ASSIGN);
}

"^" {
    HANDLE_COLUMN;
    return(XOR);
}

"^=" {
    HANDLE_COLUMN;
    return(XOR_ASSIGN);
}

"->" {
    HANDLE_COLUMN;
    return(PTR_OP);
}

"." {
    HANDLE_COLUMN;
    return(POINT);
}

"?" {
    HANDLE_COLUMN;
    return(QUESTION);
}

":" {
    HANDLE_COLUMN;
    return(COLON);
}

{NEWLINE} {
    HANDLE_COLUMN;
    next_column = 1;
    return(NEWLINE);
}

{LPAREN} {
    HANDLE_COLUMN;
    return(LPAREN);
}

{RPAREN} {
    HANDLE_COLUMN;
    return(RPAREN);    
}

{LSQBRACKET} {
    HANDLE_COLUMN;
    return(LSQBRACKET);
}

{RSQBRACKET} {
    HANDLE_COLUMN;
    return(RSQBRACKET);
}

{LBRACKET} {
    HANDLE_COLUMN;
    return(LBRACKET);    
}

{RBRACKET} {
    HANDLE_COLUMN;
    return(RBRACKET);
}

{COMMA} {
    HANDLE_COLUMN;
    return(COMMA);
}

{SEMICOLON} {
    HANDLE_COLUMN;
    return(SEMICOLON);    
}

{ID} {
    HANDLE_COLUMN;
    sscanf(yytext, "%s", yylval.idvalue);
    return(ID);    
}

{INTLITERAL} {
    HANDLE_COLUMN;
    yylval.intvalue = atoi(yytext);
    return(INTLITERAL);
}

{FLOATLITERAL} {
    HANDLE_COLUMN;
    yylval.floatvalue = atof(yytext);
    return(FLOATLITERAL);    
}

{DOUBLELITERAL} {
    HANDLE_COLUMN;
    yylval.doublevalue = atof(yytext);
    return(DOUBLELITERAL);
}

{HEXLITERAL}|{INTLITERAL} {
    HANDLE_COLUMN;
    yylval.hexvalue = atoi(yytext);
    return(HEXLITERAL);
}

{HEXLITERALFLOAT} {
    HANDLE_COLUMN;
    yylval.hexfloatvalue = atof(yytext);
    return(HEXLITERALFLOAT);
}

{CHARLITERAL} {
    HANDLE_COLUMN;
    sscanf(yytext, "%s", yylval.charvalue);
    return(CHARLITERAL);
}

{INVALIDSUFFIX} {
    HANDLE_COLUMN;
    return(INVALIDSUFFIX);
}

[ \t]+ /* eat up whitespace */

. fprintf(tokensTemp, "%s 84\n", yytext);
%%

size_t min(size_t a, size_t b) {
    return b < a ? b : a;
}

/*User code*/
int main()
{
    tokensTemp = fopen("tokensTemp", "w");
    yyin = fopen( "cTemp.c", "r" );
    yylex();
    yyparse();
    free(lineptr);
}