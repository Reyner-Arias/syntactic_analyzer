/*Definitions*/
%{
    #include <stdio.h>
    #include "bison.tab.h"
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
    return(INLINE);
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
    sscanf(yytext, "%s", yylval.stringvalue);
    return(STRINGLITERAL);
}

"..." {
    return(ELLIPSIS);
}

"+" {
    return(ADD);
}

"-" {
    return(SUB);
}

"*" {
    return(MUL);
}

"/" {
    return(DIV);
}

"=" {
    return(EQU);
}

"+=" {
    return(ADD_ASSIGN);
}

"-=" {
    return(SUB_ASSIGN);
}

"*=" {
    return(MUL_ASSIGN);
}

"/=" {
    return(DIV_ASSIGN);
}

"%" {
    return(MOD);
}

"%=" {
    return(MOD_ASSIGN);
}

"++" {
    return(INC_OP);
}

"--" {
    return(DEC_OP);
}

"<" {
    return(L_THAN);
}

">" {
    return(G_THAN);
}

"<=" {
    return(LE_OP);
}

">=" {
    return(GE_OP);
}

"==" {
    return(EQ_OP);
}

"!=" {
    return(NE_OP);
}

"!" {
    return(NOT);
}

"&&" {
    return(AND_OP);
}

"||" {
    return(OR_OP);
}

"<<" {
    return(LEFT_OP);
}

"<<=" {
    return(LEFT_ASSIGN);
}

">>" {
    return(RIGHT_OP);
}

">>=" {
    return(RIGHT_ASSIGN);
}

"~" {
    return(TILDE);
}

"&" {
    return(AND);
}

"&=" {
    return(AND_ASSIGN);
}

"|" {
    return(OR);
}

"|=" {
    return(OR_ASSIGN);
}

"^" {
    return(XOR);
}

"^=" {
    return(XOR_ASSIGN);
}

"->" {
    return(PTR_OP);
}

"." {
    return(POINT);
}

"?" {
    return(QUESTION);
}

":" {
    return(COLON);
}

{NEWLINE} {
    return(NEWLINE);
}

{LPAREN} {
    return(LPAREN);
}

{RPAREN} {
    return(RPAREN);    
}

{LSQBRACKET} {
    return(LSQBRACKET);
}

{RSQBRACKET} {
    return(RSQBRACKET);
}

{LBRACKET} {
    return(LBRACKET);    
}

{RBRACKET} {
    return(RBRACKET);
}

{COMMA} {
    return(COMMA);
}

{SEMICOLON} {
    return(SEMICOLON);    
}

{ID} {
    sscanf(yytext, "%s", yylval.idvalue);
    return(ID);    
}

{INTLITERAL} {
    yylval.intvalue = atoi(yytext);
    return(INTLITERAL);
}

{FLOATLITERAL} {
    yylval.floatvalue = atof(yytext);
    return(FLOATLITERAL);    
}

{DOUBLELITERAL} {
    yylval.doublevalue = atof(yytext);
    return(DOUBLELITERAL);
}

{HEXLITERAL}|{INTLITERAL} {
    yylval.hexvalue = atoi(yytext);
    return(HEXLITERAL);
}

{HEXLITERALFLOAT} {
    yylval.hexfloatvalue = atof(yytext);
    return(HEXLITERALFLOAT);
}

{CHARLITERAL} {
    sscanf(yytext, "%s", yylval.charvalue);
    return(CHARLITERAL);
}

{INVALIDSUFFIX} {
    return(INVALIDSUFFIX);
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