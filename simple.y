%{
    #include <stdio.h>
    int yylex();
    int yyerror(char *s);
%}

%token LPAREN RPAREN LSQBRACKET RSQBRACKET LBRACKET RBRACKET
%token SEMICOLON COMMA NEWLINE COLON POINT ALIGNAS ALIGNOF ELLIPSIS ELSE EQU GENERIC INLINE
%token ID INTLITERAL FLOATLITERAL DOUBLELITERAL HEXLITERAL HEXLITERALFLOAT CHARLITERAL STRINGLITERAL
%token INVALIDSUFFIX AND MUL ADD SUB TILDE NOT DIV MOD L_THAN G_THAN XOR OR QUESTION
%token SIZEOF INC_OP DEC_OP PTR_OP DEFAULT LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token TYPEDEF EXTERN STATIC THREAD_LOCAL AUTO REGISTER NORETURN STATIC_ASSERT FUNC_NAME
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED BOOL COMPLEX IMAGINARY TYPEDEF_NAME STRUCT UNION
%token ENUM CONST RESTRICT VOLATILE ATOMIC CASE IF SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <idvalue> ID
%type <intvalue> INTLITERAL
%type <floatvalue> FLOATLITERAL
%type <doublevalue> DOUBLELITERAL
%type <hexvalue> HEXLITERAL
%type <hexfloatvalue> HEXLITERALFLOAT
%type <charvalue> CHARLITERAL
%type <stringvalue> STRINGLITERAL 

%union{
	char* idvalue;
	int intvalue;
	float floatvalue;
	double doublevalue;
	int hexvalue;
	double hexfloatvalue;
	char charvalue[1];
	char* stringvalue;
}

%%
primary_expression
    : ID 
    | constant 
    | string 
    ;

constant
    : INTLITERAL
    | FLOATLITERAL
    | CHARLITERAL
    | HEXLITERALFLOAT
    | HEXLITERAL
    | DOUBLELITERAL
    ;

string
    : STRINGLITERAL
    | FUNC_NAME
    ;

%%

int yyerror(char *s)
{
	printf("Syntax Error on line %s\n", s);
	return 0;
}


int main()
{
    return 0;
}