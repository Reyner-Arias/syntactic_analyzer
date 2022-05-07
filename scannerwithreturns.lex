/*Definitions*/
%{
    #include <stdio.h>
    FILE* tokensTemp;
%}
%option noyywrap
LPAREN "("
RPAREN ")"
LSQBRACKET "["
RSQBRACKET "]"
LBRACKET "{"
RBRACKET "}"
SEMICOLON ";"
COMMA ","
NEWLINE "\n"
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
    return(AUTO);
}
break {
    return(BREAK);
}
case {
    return(CASE);
}
char {
    return(CHAR);
}
const {
    return(CONST);
}
continue {
    return(CONTINUE);
}
default {
    return(DEFAULT);
}
do {
    return(DO);
}
else {
    return(ELSE);
}
enum {
    return(ENUM);
}
extern {
    return(EXTERN);
}
double {
    return(DOUBLE);
}
float {
    return(FLOAT);
}
for {
    return(FOR);
}
goto {
    return(GOTO);
}
if {
    return(IF);
}
int {
    return(INT);
}
long {
    return(LONG);
}
register {
    return(REGISTER);
}
return {
    return(RETURN);
}
short {
    return(SHORT);
}
signed {
    return(SIGNED);
}
sizeof {
    return(SIZEOF);
}
static {
    return(STATIC);
}
struct {
    return(STRUCT);
}
switch {
    return(SWITCH);
}
typedef {
    return(TYPEDEF);
}
union {
    return(UNION);
}
unsigned {
    return(UNSIGNED);
}
void {
    return(VOID);
}
volatile {
    return(VOLATILE);
}
while {
    return(WHILE);
}

inline {
    return(INLINE)
}

"_Alignas"                              { return(ALIGNAS); }
"_Alignof"                              { return(ALIGNOF); }
"_Atomic"                               { return(ATOMIC); }
"_Bool"                                 { return(BOOL); }
"_Complex"                              { return(COMPLEX); }
"_Generic"                              { return(GENERIC); }
"_Imaginary"                            { return(IMAGINARY); }
"_Noreturn"                             { return(NORETURN); }
"_Static_assert"                        { return(STATIC_ASSERT); }
"_Thread_local"                         { return(THREAD_LOCAL); }
"__func__"                              { return(FUNC_NAME); }

{STRINGLITERAL} {
    return(STRINGLITERAL);
}

"+" {
    fprintf(tokensTemp, "%s 0\n", yytext);
    return(ADD);
}

"-" {
    fprintf(tokensTemp, "%s 1\n", yytext);
    return(SUB);
}

"*" {
    fprintf(tokensTemp, "%s 2\n", yytext);
    return(MUL);
}

"/" {
    fprintf(tokensTemp, "%s 3\n", yytext);
    return(DIV);
}

"=" {
    fprintf(tokensTemp, "%s 4\n", yytext);
    return(EQU);
}

"+=" {
    fprintf(tokensTemp, "%s 5\n", yytext);
    return(ADD_ASSIGN);
}

"-=" {
    fprintf(tokensTemp, "%s 6\n", yytext);
    return(SUB_ASSIGN);
}

"*=" {
    fprintf(tokensTemp, "%s 7\n", yytext);
    return(MUL_ASSIGN);
}

"/=" {
    fprintf(tokensTemp, "%s 8\n", yytext);
    return(DIV_ASSIGN);
}

"%" {
    fprintf(tokensTemp, "%s 9\n", yytext);
    return(MOD);
}

"%=" {
    fprintf(tokensTemp, "%s 10\n", yytext);
    return(MOD_ASSIGN);
}

"++" {
    fprintf(tokensTemp, "%s 11\n", yytext);
    return(INC_OP);
}

"--" {
    fprintf(tokensTemp, "%s 12\n", yytext);
    return(DEC_OP);
}

"<" {
    fprintf(tokensTemp, "%s 13\n", yytext);
    return(L_THAN);
}

">" {
    fprintf(tokensTemp, "%s 14\n", yytext);
    return(G_THAN);
}

"<=" {
    fprintf(tokensTemp, "%s 15\n", yytext);
    return(LE_OP);
}

">=" {
    fprintf(tokensTemp, "%s 16\n", yytext);
    return(GE_OP);
}

"==" {
    fprintf(tokensTemp, "%s 17\n", yytext);
    return(EQ_OP);
}

"!=" {
    fprintf(tokensTemp, "%s 18\n", yytext);
    return(NE_OP);
}

"!" {
    fprintf(tokensTemp, "%s 19\n", yytext);
    return(NOT);
}

"&&" {
    fprintf(tokensTemp, "%s 20\n", yytext);
    return(AND_OP);
}

"||" {
    fprintf(tokensTemp, "%s 21\n", yytext);
    return(OR_OP);
}

"<<" {
    fprintf(tokensTemp, "%s 22\n", yytext);
    return(LEFT_OP);
}

"<<=" {
    fprintf(tokensTemp, "%s 23\n", yytext);
    return(LEFT_ASSIGN);
}

">>" {
    fprintf(tokensTemp, "%s 24\n", yytext);
    return(RIGHT_OP);
}

">>=" {
    fprintf(tokensTemp, "%s 25\n", yytext);
    return(RIGHT_ASSIGN);
}

"~" {
    fprintf(tokensTemp, "%s 26\n", yytext);
    return(TILDE);
}

"&" {
    fprintf(tokensTemp, "%s 27\n", yytext);
    return(AND);
}

"&=" {
    fprintf(tokensTemp, "%s 28\n", yytext);
    return(AND_ASSIGN);
}

"|" {
    fprintf(tokensTemp, "%s 29\n", yytext);
    return(OR);
}

"|=" {
    fprintf(tokensTemp, "%s 30\n", yytext);
    return(OR_ASSIGN);
}

"^" {
    fprintf(tokensTemp, "%s 31\n", yytext);
    return(XOR);
}

"^=" {
    fprintf(tokensTemp, "%s 32\n", yytext);
    return(XOR_ASSIGN);
}

"->" {
    fprintf(tokensTemp, "%s 33\n", yytext);
    return(PTR_OP);
}

"." {
    fprintf(tokensTemp, "%s 34\n", yytext);
    return(POINT);
}

"?" {
    fprintf(tokensTemp, "%s 35\n", yytext);
    return(QUESTION);
}

":" {
    fprintf(tokensTemp, "%s 36\n", yytext);
    return(COLON);
}

{NEWLINE} {
    fprintf(tokensTemp, "%s", yytext);
    return();***************************************************************************
}

{LPAREN} {
    fprintf(tokensTemp, "%s 74\n", yytext);
    return(LPAREN);
}

{RPAREN} {
    fprintf(tokensTemp, "%s 75\n", yytext);
    return(RPAREN);
    
}

{LSQBRACKET} {
    fprintf(tokensTemp, "%s 76\n", yytext);
    return(LSQBRACKET)
}

{RSQBRACKET} {
    fprintf(tokensTemp, "%s 77\n", yytext);
    return(RSQBRACKET);
}

{LBRACKET} {
    fprintf(tokensTemp, "%s 78\n", yytext);
    return(LBRACKET);    
}

{RBRACKET} {
    fprintf(tokensTemp, "%s 79\n", yytext);
    return(RBRACKET);
}

{COMMA} {
    fprintf(tokensTemp, "%s 80\n", yytext);
    return(COMMA);
}

{SEMICOLON} {
    fprintf(tokensTemp, "%s 81\n", yytext);
    return(SEMICOLON);    
}

{ID} {
    fprintf(tokensTemp, "%s 82\n", yytext);
    return(ID);    
}

{HEXLITERALFLOAT} {
    fprintf(tokensTemp, "%s 39\n", yytext);
    return(HEXLITERALFLOAT);*********************************************************
}

{HEXLITERAL}|{INTLITERAL} {
    fprintf(tokensTemp, "%s 37\n", yytext);
    return();********************************************************    
}

{FLOATLITERAL} {
    fprintf(tokensTemp, "%s 38\n", yytext);
    return(FLOATLITERAL);    
}

{DOUBLELITERAL} {
    fprintf(tokensTemp, "%s 39\n", yytext);
    return(DOUBLELITERAL);*******************************************
}

{CHARLITERAL} {
    fprintf(tokensTemp, "%s 40\n", yytext);
    return(CHARLITERAL);**********************************************
}

{INVALIDSUFFIX} {
    fprintf(tokensTemp, "%s 83\n", yytext);
    return(INVALIDSUFFIX);**************************************************
}

[ \t]+ /* eat up whitespace */

. fprintf(tokensTemp, "%s 84\n", yytext);
%%

/*User code*/
int main()
{
    tokensTemp = fopen("tokensTemp", "w");
    yyin = fopen( "cTemp.c", "r" );
    yylex();
}