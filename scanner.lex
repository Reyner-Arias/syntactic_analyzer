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
}
break {
    fprintf(tokensTemp, "%s 43\n", yytext);
}
case {
    fprintf(tokensTemp, "%s 44\n", yytext);
}
char {
    fprintf(tokensTemp, "%s 45\n", yytext);
}
const {
    fprintf(tokensTemp, "%s 46\n", yytext);
}
continue {
    fprintf(tokensTemp, "%s 47\n", yytext);
}
default {
    fprintf(tokensTemp, "%s 48\n", yytext);
}
do {
    fprintf(tokensTemp, "%s 49\n", yytext);
}
else {
    fprintf(tokensTemp, "%s 50\n", yytext);
}
enum {
    fprintf(tokensTemp, "%s 51\n", yytext);
}
extern {
    fprintf(tokensTemp, "%s 52\n", yytext);
}
double {
    fprintf(tokensTemp, "%s 53\n", yytext);
}
float {
    fprintf(tokensTemp, "%s 54\n", yytext);
}
for {
    fprintf(tokensTemp, "%s 55\n", yytext);
}
goto {
    fprintf(tokensTemp, "%s 56\n", yytext);
}
if {
    fprintf(tokensTemp, "%s 57\n", yytext);
}
int {
    fprintf(tokensTemp, "%s 58\n", yytext);
}
long {
    fprintf(tokensTemp, "%s 59\n", yytext);
}
register {
    fprintf(tokensTemp, "%s 60\n", yytext);
}
return {
    fprintf(tokensTemp, "%s 61\n", yytext);
}
short {
    fprintf(tokensTemp, "%s 62\n", yytext);
}
signed {
    fprintf(tokensTemp, "%s 63\n", yytext);
}
sizeof {
    fprintf(tokensTemp, "%s 64\n", yytext);
}
static {
    fprintf(tokensTemp, "%s 65\n", yytext);
}
struct {
    fprintf(tokensTemp, "%s 66\n", yytext);
}
switch {
    fprintf(tokensTemp, "%s 67\n", yytext);
}
typedef {
    fprintf(tokensTemp, "%s 68\n", yytext);
}
union {
    fprintf(tokensTemp, "%s 69\n", yytext);
}
unsigned {
    fprintf(tokensTemp, "%s 70\n", yytext);
}
void {
    fprintf(tokensTemp, "%s 71\n", yytext);
}
volatile {
    fprintf(tokensTemp, "%s 72\n", yytext);
}
while {
    fprintf(tokensTemp, "%s 73\n", yytext);
}

{STRINGLITERAL} fprintf(tokensTemp, "%s 41\n", yytext);

"+" {
    fprintf(tokensTemp, "%s 0\n", yytext);
}

"-" {
    fprintf(tokensTemp, "%s 1\n", yytext);
}

"*" {
    fprintf(tokensTemp, "%s 2\n", yytext);
}

"/" {
    fprintf(tokensTemp, "%s 3\n", yytext);
}

"=" {
    fprintf(tokensTemp, "%s 4\n", yytext);
}

"+=" {
    fprintf(tokensTemp, "%s 5\n", yytext);
}

"-=" {
    fprintf(tokensTemp, "%s 6\n", yytext);
}

"*=" {
    fprintf(tokensTemp, "%s 7\n", yytext);
}

"/=" {
    fprintf(tokensTemp, "%s 8\n", yytext);
}

"%" {
    fprintf(tokensTemp, "%s 9\n", yytext);
}

"%=" {
    fprintf(tokensTemp, "%s 10\n", yytext);
}

"++" {
    fprintf(tokensTemp, "%s 11\n", yytext);
}

"--" {
    fprintf(tokensTemp, "%s 12\n", yytext);
}

"<" {
    fprintf(tokensTemp, "%s 13\n", yytext);
}

">" {
    fprintf(tokensTemp, "%s 14\n", yytext);
}

"<=" {
    fprintf(tokensTemp, "%s 15\n", yytext);
}

">=" {
    fprintf(tokensTemp, "%s 16\n", yytext);
}

"==" {
    fprintf(tokensTemp, "%s 17\n", yytext);
}

"!=" {
    fprintf(tokensTemp, "%s 18\n", yytext);
}

"!" {
    fprintf(tokensTemp, "%s 19\n", yytext);
}

"&&" {
    fprintf(tokensTemp, "%s 20\n", yytext);
}

"||" {
    fprintf(tokensTemp, "%s 21\n", yytext);
}

"<<" {
    fprintf(tokensTemp, "%s 22\n", yytext);
}

"<<=" {
    fprintf(tokensTemp, "%s 23\n", yytext);
}

">>" {
    fprintf(tokensTemp, "%s 24\n", yytext);
}

">>=" {
    fprintf(tokensTemp, "%s 25\n", yytext);
}

"~" {
    fprintf(tokensTemp, "%s 26\n", yytext);
}

"&" {
    fprintf(tokensTemp, "%s 27\n", yytext);
}

"&=" {
    fprintf(tokensTemp, "%s 28\n", yytext);
}

"|" {
    fprintf(tokensTemp, "%s 29\n", yytext);
}

"|=" {
    fprintf(tokensTemp, "%s 30\n", yytext);
}

"^" {
    fprintf(tokensTemp, "%s 31\n", yytext);
}

"^=" {
    fprintf(tokensTemp, "%s 32\n", yytext);
}

"->" {
    fprintf(tokensTemp, "%s 33\n", yytext);
}

"." {
    fprintf(tokensTemp, "%s 34\n", yytext);
}

"?" {
    fprintf(tokensTemp, "%s 35\n", yytext);
}

":" {
    fprintf(tokensTemp, "%s 36\n", yytext);
}

{NEWLINE} fprintf(tokensTemp, "%s", yytext);

{LPAREN} fprintf(tokensTemp, "%s 74\n", yytext);

{RPAREN} fprintf(tokensTemp, "%s 75\n", yytext);

{LSQBRACKET} fprintf(tokensTemp, "%s 76\n", yytext);

{RSQBRACKET} fprintf(tokensTemp, "%s 77\n", yytext);

{LBRACKET} fprintf(tokensTemp, "%s 78\n", yytext);

{RBRACKET} fprintf(tokensTemp, "%s 79\n", yytext);

{COMMA} fprintf(tokensTemp, "%s 80\n", yytext);

{SEMICOLON} fprintf(tokensTemp, "%s 81\n", yytext);

{ID} fprintf(tokensTemp, "%s 82\n", yytext);

{HEXLITERALFLOAT} fprintf(tokensTemp, "%s 39\n", yytext);

{HEXLITERAL}|{INTLITERAL} fprintf(tokensTemp, "%s 37\n", yytext);

{FLOATLITERAL} fprintf(tokensTemp, "%s 38\n", yytext);

{DOUBLELITERAL} fprintf(tokensTemp, "%s 39\n", yytext);

{CHARLITERAL} fprintf(tokensTemp, "%s 40\n", yytext);

{INVALIDSUFFIX} fprintf(tokensTemp, "%s 83\n", yytext);

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