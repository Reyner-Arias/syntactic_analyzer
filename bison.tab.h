/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LPAREN = 258,
    RPAREN = 259,
    LSQBRACKET = 260,
    RSQBRACKET = 261,
    LBRACKET = 262,
    RBRACKET = 263,
    SEMICOLON = 264,
    COMMA = 265,
    NEWLINE = 266,
    COLON = 267,
    POINT = 268,
    ALIGNAS = 269,
    ALIGNOF = 270,
    ELLIPSIS = 271,
    ELSE = 272,
    EQU = 273,
    GENERIC = 274,
    INLINE = 275,
    ID = 276,
    INTLITERAL = 277,
    FLOATLITERAL = 278,
    DOUBLELITERAL = 279,
    HEXLITERAL = 280,
    HEXLITERALFLOAT = 281,
    CHARLITERAL = 282,
    STRINGLITERAL = 283,
    INVALIDSUFFIX = 284,
    AND = 285,
    MUL = 286,
    ADD = 287,
    SUB = 288,
    TILDE = 289,
    NOT = 290,
    DIV = 291,
    MOD = 292,
    L_THAN = 293,
    G_THAN = 294,
    XOR = 295,
    OR = 296,
    QUESTION = 297,
    SIZEOF = 298,
    INC_OP = 299,
    DEC_OP = 300,
    PTR_OP = 301,
    DEFAULT = 302,
    LEFT_OP = 303,
    RIGHT_OP = 304,
    LE_OP = 305,
    GE_OP = 306,
    EQ_OP = 307,
    NE_OP = 308,
    AND_OP = 309,
    OR_OP = 310,
    MUL_ASSIGN = 311,
    DIV_ASSIGN = 312,
    MOD_ASSIGN = 313,
    ADD_ASSIGN = 314,
    SUB_ASSIGN = 315,
    LEFT_ASSIGN = 316,
    RIGHT_ASSIGN = 317,
    AND_ASSIGN = 318,
    XOR_ASSIGN = 319,
    OR_ASSIGN = 320,
    TYPEDEF = 321,
    EXTERN = 322,
    STATIC = 323,
    THREAD_LOCAL = 324,
    AUTO = 325,
    REGISTER = 326,
    NORETURN = 327,
    STATIC_ASSERT = 328,
    FUNC_NAME = 329,
    VOID = 330,
    CHAR = 331,
    SHORT = 332,
    INT = 333,
    LONG = 334,
    FLOAT = 335,
    DOUBLE = 336,
    SIGNED = 337,
    UNSIGNED = 338,
    BOOL = 339,
    COMPLEX = 340,
    IMAGINARY = 341,
    TYPEDEF_NAME = 342,
    STRUCT = 343,
    UNION = 344,
    ENUM = 345,
    CONST = 346,
    RESTRICT = 347,
    VOLATILE = 348,
    ATOMIC = 349,
    CASE = 350,
    IF = 351,
    SWITCH = 352,
    WHILE = 353,
    DO = 354,
    FOR = 355,
    GOTO = 356,
    CONTINUE = 357,
    BREAK = 358,
    RETURN = 359
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "bison.y" /* yacc.c:1909  */

	char* idvalue;
	int intvalue;
	float floatvalue;
	double doublevalue;
	int hexvalue;
	double hexfloatvalue;
	char charvalue;
	char+ stringvalue;

#line 170 "bison.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
