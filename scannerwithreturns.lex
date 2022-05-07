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
    fprintf(tokensTemp, "%s 42\n", yytext);
    return(AUTO);
}
break {
    fprintf(tokensTemp, "%s 43\n", yytext);
    return(BREAK);
}
case {
    fprintf(tokensTemp, "%s 44\n", yytext);
    return(CASE);
}
char {
    fprintf(tokensTemp, "%s 45\n", yytext);
    return(CHAR);
}
const {
    fprintf(tokensTemp, "%s 46\n", yytext);
    return(CONST);
}
continue {
    fprintf(tokensTemp, "%s 47\n", yytext);
    return(CONTINUE);
}
default {
    fprintf(tokensTemp, "%s 48\n", yytext);
    return(DEFAULT);
}
do {
    fprintf(tokensTemp, "%s 49\n", yytext);
    return(DO);
}
else {
    fprintf(tokensTemp, "%s 50\n", yytext);
    return(ELSE);
}
enum {
    fprintf(tokensTemp, "%s 51\n", yytext);
    return(ENUM);
}
extern {
    fprintf(tokensTemp, "%s 52\n", yytext);
    return(EXTERN);
}
double {
    fprintf(tokensTemp, "%s 53\n", yytext);
    return(DOUBLE);
}
float {
    fprintf(tokensTemp, "%s 54\n", yytext);
    return(FLOAT);
}
for {
    fprintf(tokensTemp, "%s 55\n", yytext);
    return(FOR);
}
goto {
    fprintf(tokensTemp, "%s 56\n", yytext);
    return(GOTO);
}
if {
    fprintf(tokensTemp, "%s 57\n", yytext);
    return(IF);
}
int {
    fprintf(tokensTemp, "%s 58\n", yytext);
    return(INT);
}
long {
    fprintf(tokensTemp, "%s 59\n", yytext);
    return(LONG);
}
register {
    fprintf(tokensTemp, "%s 60\n", yytext);
    return(REGISTER);
}
return {
    fprintf(tokensTemp, "%s 61\n", yytext);
    return(RETURN);
}
short {
    fprintf(tokensTemp, "%s 62\n", yytext);
    return(SHORT);
}
signed {
    fprintf(tokensTemp, "%s 63\n", yytext);
    return(SIGNED);
}
sizeof {
    fprintf(tokensTemp, "%s 64\n", yytext);
    return(SIZEOF);
}
static {
    fprintf(tokensTemp, "%s 65\n", yytext);
    return(STATIC);
}
struct {
    fprintf(tokensTemp, "%s 66\n", yytext);
    return(STRUCT);
}
switch {
    fprintf(tokensTemp, "%s 67\n", yytext);
    return(SWITCH);
}
typedef {
    fprintf(tokensTemp, "%s 68\n", yytext);
    return(TYPEDEF);
}
union {
    fprintf(tokensTemp, "%s 69\n", yytext);
    return(UNION);
}
unsigned {
    fprintf(tokensTemp, "%s 70\n", yytext);
    return(UNSIGNED);
}
void {
    fprintf(tokensTemp, "%s 71\n", yytext);
    return(VOID);
}
volatile {
    fprintf(tokensTemp, "%s 72\n", yytext);
    return(VOLATILE);
}
while {
    fprintf(tokensTemp, "%s 73\n", yytext);
    return(WHILE);
}

{STRINGLITERAL} {
    fprintf(tokensTemp, "%s 41\n", yytext);
    return(STRINGLITERAL);
}

"+" {
    fprintf(tokensTemp, "%s 0\n", yytext);
    return('+');
}

"-" {
    fprintf(tokensTemp, "%s 1\n", yytext);
    return('-');
}

"*" {
    fprintf(tokensTemp, "%s 2\n", yytext);
    return('*');
}

"/" {
    fprintf(tokensTemp, "%s 3\n", yytext);
    return('/');
}

"=" {
    fprintf(tokensTemp, "%s 4\n", yytext);
    return('=');
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
    return('%');
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
    return('<');
}

">" {
    fprintf(tokensTemp, "%s 14\n", yytext);
    return('>');
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
    return('!');
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
    return('~');
}

"&" {
    fprintf(tokensTemp, "%s 27\n", yytext);
    return('&');
}

"&=" {
    fprintf(tokensTemp, "%s 28\n", yytext);
    return(AND_ASSIGN);
}

"|" {
    fprintf(tokensTemp, "%s 29\n", yytext);
    return('|');
}

"|=" {
    fprintf(tokensTemp, "%s 30\n", yytext);
    return(OR_ASSIGN);
}

"^" {
    fprintf(tokensTemp, "%s 31\n", yytext);
    return('^');
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
    return('.');
}

"?" {
    fprintf(tokensTemp, "%s 35\n", yytext);
    return('?');
}

":" {
    fprintf(tokensTemp, "%s 36\n", yytext);
    return(':');
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
    return(LPAREN);
    
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
    return(LPAREN);
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