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
	char charvalue;
	char* stringvalue;
}

%%
primary_expression
    : ID 
    | constant 
    | string 
    | LPAREN expression RPAREN 
    | generic_selection
    ;

constant
    : INTLITERAL
    | FLOATLITERAL
    | enumeration_constant
    ;

enumeration_constant
    : ID
    ;

string
    : STRINGLITERAL
    | FUNC_NAME
    ;

generic_selection
    : GENERIC LPAREN assignment_expression COMMA generic_assoc_list RPAREN
    ;

generic_assoc_list
    : generic_association
    | generic_assoc_list COMMA generic_association
    ;

generic_association 
    : type_name COLON assignment_expression
    | DEFAULT assignment_expression
    ;

postfix_expression
    : primary_expression
    | postfix_expression LSQBRACKET expression RSQBRACKET
    | postfix_expression LPAREN RPAREN
    | postfix_expression LPAREN argument_expression_list RPAREN
    | postfix_expression POINT ID
    | postfix_expression PTR_OP ID
    | postfix_expression INC_OP 
    | postfix_expression DEC_OP
    | LPAREN type_name RPAREN LBRACKET initializer_list RBRACKET
    | LPAREN type_name RPAREN LBRACKET initializer_list COMMA RBRACKET
    ;

argument_expression_list
    : assignment_expression
    | argument_expression_list COMMA assignment_expression
    ;

unary_expression
    : postfix_expression
    | INC_OP unary_expression
    | DEC_OP unary_expression
    | unary_operator cast_expression
    | SIZEOF unary_expression
    | SIZEOF LPAREN type_name RPAREN
    | ALIGNOF LPAREN type_name RPAREN
    ;

unary_operator
	: AND
	| MUL
	| ADD
	| SUB
	| TILDE
	| NOT
	;

cast_expression
	: unary_expression
	| LPAREN type_name RPAREN cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression MUL cast_expression
	| multiplicative_expression DIV cast_expression
	| multiplicative_expression MOD cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression
	| additive_expression SUB multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression L_THAN shift_expression
	| relational_expression G_THAN shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression AND equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression XOR and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression OR exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression QUESTION expression COLON conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: EQU
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression COMMA assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers SEMICOLON
	| declaration_specifiers init_declarator_list SEMICOLON
	| static_assert_declaration
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
	| storage_class_specifier
	| type_specifier declaration_specifiers
	| type_specifier
	| type_qualifier declaration_specifiers
	| type_qualifier
	| function_specifier declaration_specifiers
	| function_specifier
	| alignment_specifier declaration_specifiers
	| alignment_specifier
	;

init_declarator_list
	: init_declarator
	| init_declarator_list COMMA init_declarator
	;

init_declarator
	: declarator EQU initializer
	| declarator
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| THREAD_LOCAL
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY	  	/* non-mandated extension */
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME		/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union LBRACKET struct_declaration_list RBRACKET
	| struct_or_union ID LBRACKET struct_declaration_list RBRACKET
	| struct_or_union ID
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list SEMICOLON
	| specifier_qualifier_list struct_declarator_list SEMICOLON
	| static_assert_declaration
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list COMMA struct_declarator
	;

struct_declarator
	: COLON constant_expression
	| declarator COLON constant_expression
	| declarator
	;

enum_specifier
	: ENUM LBRACKET enumerator_list RBRACKET
	| ENUM LBRACKET enumerator_list COMMA RBRACKET
	| ENUM ID LBRACKET enumerator_list RBRACKET
	| ENUM ID LBRACKET enumerator_list COMMA RBRACKET
	| ENUM ID
	;

enumerator_list
	: enumerator
	| enumerator_list COMMA enumerator
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant EQU constant_expression
	| enumeration_constant
	;

atomic_type_specifier
	: ATOMIC LPAREN type_name RPAREN
	;

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	| ATOMIC
	;

function_specifier
	: INLINE
	| NORETURN
	;

alignment_specifier
	: ALIGNAS LPAREN type_name RPAREN
	| ALIGNAS LPAREN constant_expression RPAREN
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: ID
	| LPAREN declarator RPAREN
	| direct_declarator LSQBRACKET RSQBRACKET
	| direct_declarator LSQBRACKET MUL RSQBRACKET
	| direct_declarator LSQBRACKET STATIC type_qualifier_list assignment_expression RSQBRACKET
	| direct_declarator LSQBRACKET STATIC assignment_expression RSQBRACKET
	| direct_declarator LSQBRACKET type_qualifier_list MUL RSQBRACKET
	| direct_declarator LSQBRACKET type_qualifier_list STATIC assignment_expression RSQBRACKET
	| direct_declarator LSQBRACKET type_qualifier_list assignment_expression RSQBRACKET
	| direct_declarator LSQBRACKET type_qualifier_list RSQBRACKET
	| direct_declarator LSQBRACKET assignment_expression RSQBRACKET
	| direct_declarator LPAREN parameter_type_list RPAREN
	| direct_declarator LPAREN RPAREN
	| direct_declarator LPAREN identifier_list RPAREN
	;

pointer
	: MUL type_qualifier_list pointer
	| MUL type_qualifier_list
	| MUL pointer
	| MUL
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list COMMA ELLIPSIS
	| parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: ID
	| identifier_list COMMA ID
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: LPAREN abstract_declarator RPAREN
	| LSQBRACKET RSQBRACKET
	| LSQBRACKET MUL RSQBRACKET
	| LSQBRACKET STATIC type_qualifier_list assignment_expression RSQBRACKET
	| LSQBRACKET STATIC assignment_expression RSQBRACKET
	| LSQBRACKET type_qualifier_list STATIC assignment_expression RSQBRACKET
	| LSQBRACKET type_qualifier_list assignment_expression RSQBRACKET
	| LSQBRACKET type_qualifier_list RSQBRACKET
	| LSQBRACKET assignment_expression RSQBRACKET
	| direct_abstract_declarator LSQBRACKET RSQBRACKET
	| direct_abstract_declarator LSQBRACKET MUL RSQBRACKET
	| direct_abstract_declarator LSQBRACKET STATIC type_qualifier_list assignment_expression RSQBRACKET
	| direct_abstract_declarator LSQBRACKET STATIC assignment_expression RSQBRACKET
	| direct_abstract_declarator LSQBRACKET type_qualifier_list assignment_expression RSQBRACKET
	| direct_abstract_declarator LSQBRACKET type_qualifier_list STATIC assignment_expression RSQBRACKET
	| direct_abstract_declarator LSQBRACKET type_qualifier_list RSQBRACKET
	| direct_abstract_declarator LSQBRACKET assignment_expression RSQBRACKET
	| LPAREN RPAREN
	| LPAREN parameter_type_list RPAREN
	| direct_abstract_declarator LPAREN RPAREN
	| direct_abstract_declarator LPAREN parameter_type_list RPAREN
	;

initializer
	: LBRACKET initializer_list RBRACKET
	| LBRACKET initializer_list COMMA RBRACKET
	| assignment_expression
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list COMMA designation initializer
	| initializer_list COMMA initializer
	;

designation
	: designator_list EQU
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: LSQBRACKET constant_expression RSQBRACKET
	| POINT ID
	;

static_assert_declaration
	: STATIC_ASSERT LPAREN constant_expression COMMA STRINGLITERAL RPAREN SEMICOLON
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: ID COLON statement
	| CASE constant_expression COLON statement
	| DEFAULT COLON statement
	;

compound_statement
	: LBRACKET RBRACKET
	| LBRACKET  block_item_list RBRACKET
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: SEMICOLON
	| expression SEMICOLON
	;

selection_statement
	: IF LPAREN expression RPAREN statement ELSE statement
	| IF LPAREN expression RPAREN statement
	| SWITCH LPAREN expression RPAREN statement
	;

iteration_statement
	: WHILE LPAREN expression RPAREN statement
	| DO statement WHILE LPAREN expression RPAREN SEMICOLON
	| FOR LPAREN expression_statement expression_statement RPAREN statement
	| FOR LPAREN expression_statement expression_statement expression RPAREN statement
	| FOR LPAREN declaration expression_statement RPAREN statement
	| FOR LPAREN declaration expression_statement expression RPAREN statement
	;

jump_statement
	: GOTO ID SEMICOLON
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
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