%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%{
#include <stdio.h>
#include "simple.tab.h"

extern void yyerror(const char *);  /* prints grammar violation message */

extern int sym_type(const char *);  /* returns type from symbol table */

#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

static void comment(void);
static int check_type(void);

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

%option noinput nounput yylineno

%%

"auto"					{ HANDLE_COLUMN; return(AUTO); }
"break"					{ HANDLE_COLUMN; return(BREAK); }
"case"					{ HANDLE_COLUMN; return(CASE); }
"char"					{ HANDLE_COLUMN; return(CHAR); }
"const"					{ HANDLE_COLUMN; return(CONST); }
"continue"				{ HANDLE_COLUMN; return(CONTINUE); }
"default"				{ HANDLE_COLUMN; return(DEFAULT); }
"do"					{ HANDLE_COLUMN; return(DO); }
"double"				{ HANDLE_COLUMN; return(DOUBLE); }
"else"					{ HANDLE_COLUMN; return(ELSE); }
"enum"					{ HANDLE_COLUMN; return(ENUM); }
"extern"				{ HANDLE_COLUMN; return(EXTERN); }
"float"					{ HANDLE_COLUMN; return(FLOAT); }
"for"					{ HANDLE_COLUMN; return(FOR); }
"goto"					{ HANDLE_COLUMN; return(GOTO); }
"if"					{ HANDLE_COLUMN; return(IF); }
"inline"				{ HANDLE_COLUMN; return(INLINE); }
"int"					{ HANDLE_COLUMN; return(INT); }
"long"					{ HANDLE_COLUMN; return(LONG); }
"register"				{ HANDLE_COLUMN; return(REGISTER); }
"restrict"				{ HANDLE_COLUMN; return(RESTRICT); }
"return"				{ HANDLE_COLUMN; return(RETURN); }
"short"					{ HANDLE_COLUMN; return(SHORT); }
"signed"				{ HANDLE_COLUMN; return(SIGNED); }
"sizeof"				{ HANDLE_COLUMN; return(SIZEOF); }
"static"				{ HANDLE_COLUMN; return(STATIC); }
"struct"				{ HANDLE_COLUMN; return(STRUCT); }
"switch"				{ HANDLE_COLUMN; return(SWITCH); }
"typedef"				{ HANDLE_COLUMN; return(TYPEDEF); }
"union"					{ HANDLE_COLUMN; return(UNION); }
"unsigned"				{ HANDLE_COLUMN; return(UNSIGNED); }
"void"					{ HANDLE_COLUMN; return(VOID); }
"volatile"				{ HANDLE_COLUMN; return(VOLATILE); }
"while"					{ HANDLE_COLUMN; return(WHILE); }
"_Alignas"                              { HANDLE_COLUMN; return ALIGNAS; }
"_Alignof"                              { HANDLE_COLUMN; return ALIGNOF; }
"_Atomic"                               { HANDLE_COLUMN; return ATOMIC; }
"_Bool"                                 { HANDLE_COLUMN; return BOOL; }
"_Complex"                              { HANDLE_COLUMN; return COMPLEX; }
"_Generic"                              { HANDLE_COLUMN; return GENERIC; }
"_Imaginary"                            { HANDLE_COLUMN; return IMAGINARY; }
"_Noreturn"                             { HANDLE_COLUMN; return NORETURN; }
"_Static_assert"                        { HANDLE_COLUMN; return STATIC_ASSERT; }
"_Thread_local"                         { HANDLE_COLUMN; return THREAD_LOCAL; }
"__func__"                              { HANDLE_COLUMN; return FUNC_NAME; }

{L}{A}*					{ return check_type(); }

{HP}{H}+{IS}?				{ HANDLE_COLUMN; return I_CONSTANT; }
{NZ}{D}*{IS}?				{ HANDLE_COLUMN; return I_CONSTANT; }
"0"{O}*{IS}?				{ HANDLE_COLUMN; return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ HANDLE_COLUMN; return I_CONSTANT; }

{D}+{E}{FS}?				{ HANDLE_COLUMN; return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{ HANDLE_COLUMN; return F_CONSTANT; }
{D}+"."{E}?{FS}?			{ HANDLE_COLUMN; return F_CONSTANT; }
{HP}{H}+{P}{FS}?			{ HANDLE_COLUMN; return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{ HANDLE_COLUMN; return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			{ HANDLE_COLUMN; return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ HANDLE_COLUMN; return STRING_LITERAL; }

"..."					{ HANDLE_COLUMN; return ELLIPSIS; }
">>="					{ HANDLE_COLUMN; return RIGHT_ASSIGN; }
"<<="					{ HANDLE_COLUMN; return LEFT_ASSIGN; }
"+="					{ HANDLE_COLUMN; return ADD_ASSIGN; }
"-="					{ HANDLE_COLUMN; return SUB_ASSIGN; }
"*="					{ HANDLE_COLUMN; return MUL_ASSIGN; }
"/="					{ HANDLE_COLUMN; return DIV_ASSIGN; }
"%="					{ HANDLE_COLUMN; return MOD_ASSIGN; }
"&="					{ HANDLE_COLUMN; return AND_ASSIGN; }
"^="					{ HANDLE_COLUMN; return XOR_ASSIGN; }
"|="					{ HANDLE_COLUMN; return OR_ASSIGN; }
">>"					{ HANDLE_COLUMN; return RIGHT_OP; }
"<<"					{ HANDLE_COLUMN; return LEFT_OP; }
"++"					{ HANDLE_COLUMN; return INC_OP; }
"--"					{ HANDLE_COLUMN; return DEC_OP; }
"->"					{ HANDLE_COLUMN; return PTR_OP; }
"&&"					{ HANDLE_COLUMN; return AND_OP; }
"||"					{ HANDLE_COLUMN; return OR_OP; }
"<="					{ HANDLE_COLUMN; return LE_OP; }
">="					{ HANDLE_COLUMN; return GE_OP; }
"=="					{ HANDLE_COLUMN; return EQ_OP; }
"!="					{ HANDLE_COLUMN; return NE_OP; }
";"					{ HANDLE_COLUMN; return ';'; }
("{"|"<%")				{ HANDLE_COLUMN; return '{'; }
("}"|"%>")				{ HANDLE_COLUMN; return '}'; }
","					{ HANDLE_COLUMN; return ','; }
":"					{ HANDLE_COLUMN; return ':'; }
"="					{ HANDLE_COLUMN; return '='; }
"("					{ HANDLE_COLUMN; return '('; }
")"					{ HANDLE_COLUMN; return ')'; }
("["|"<:")				{ HANDLE_COLUMN; return '['; }
("]"|":>")				{ HANDLE_COLUMN; return ']'; }
"."					{ HANDLE_COLUMN; return '.'; }
"&"					{ HANDLE_COLUMN; return '&'; }
"!"					{ HANDLE_COLUMN; return '!'; }
"~"					{ HANDLE_COLUMN; return '~'; }
"-"					{ HANDLE_COLUMN; return '-'; }
"+"					{ HANDLE_COLUMN; return '+'; }
"*"					{ HANDLE_COLUMN; return '*'; }
"/"					{ HANDLE_COLUMN; return '/'; }
"%"					{ HANDLE_COLUMN; return '%'; }
"<"					{ HANDLE_COLUMN; return '<'; }
">"					{ HANDLE_COLUMN; return '>'; }
"^"					{ HANDLE_COLUMN; return '^'; }
"|"					{ HANDLE_COLUMN; return '|'; }
"?"					{ HANDLE_COLUMN; return '?'; }

{WS}+					{ /* whitespace separates tokens */ }
.					{ /* discard bad characters */ }

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static int check_type(void)
{
    switch (sym_type(yytext))
    {
    case TYPEDEF_NAME:                /* previously defined */
        HANDLE_COLUMN; 
        return TYPEDEF_NAME;
    case ENUMERATION_CONSTANT:        /* previously defined */
        HANDLE_COLUMN; 
        return ENUMERATION_CONSTANT;
    default:                          /* includes undefined */
        HANDLE_COLUMN;
        return IDENTIFIER;
    }
}

int main(){
    yyin = fopen( "cTemp.c", "r" );
    yyparse();
    fprintf(stderr, "holaaaaaa\n");
    free(lineptr);
}

size_t min(size_t a, size_t b) {
    return b < a ? b : a;
}