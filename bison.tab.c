/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

    #include <stdio.h>
    int yylex();
    int yyerror(char *s);

#line 72 "bison.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.tab.h".  */
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
#line 26 "bison.y" /* yacc.c:355  */

	char* idvalue;
	int intvalue;
	float floatvalue;
	double doublevalue;
	int hexvalue;
	double hexfloatvalue;
	char charvalue;
	char+ stringvalue;

#line 228 "bison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "bison.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1476

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  229
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    39,    39,    40,    41,    42,    43,    47,    48,    49,
      53,    57,    58,    62,    66,    67,    71,    72,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    89,    90,
      94,    95,    96,    97,    98,    99,   100,   104,   105,   106,
     107,   108,   109,   113,   114,   118,   119,   120,   121,   125,
     126,   127,   131,   132,   133,   137,   138,   139,   140,   141,
     145,   146,   147,   151,   152,   156,   157,   161,   162,   166,
     167,   171,   172,   176,   177,   181,   182,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   200,   201,
     205,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   238,   239,   240,   241,   242,   243,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   266,   267,   268,   272,   273,   277,   278,
     282,   283,   284,   288,   289,   290,   291,   295,   296,   300,
     301,   302,   306,   307,   308,   309,   310,   314,   315,   319,
     320,   324,   328,   329,   330,   331,   335,   336,   340,   341,
     345,   346,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   367,   368,   369,   370,
     374,   375,   380,   381,   385,   386,   390,   391,   392,   396,
     397,   401,   402,   406,   407,   408,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   436,   437,   438,
     442,   443,   444,   445,   449,   453,   454,   458,   459,   463
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LPAREN", "RPAREN", "LSQBRACKET",
  "RSQBRACKET", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "NEWLINE",
  "COLON", "POINT", "ALIGNAS", "ALIGNOF", "ELLIPSIS", "ELSE", "EQU",
  "GENERIC", "INLINE", "ID", "INTLITERAL", "FLOATLITERAL", "DOUBLELITERAL",
  "HEXLITERAL", "HEXLITERALFLOAT", "CHARLITERAL", "STRINGLITERAL",
  "INVALIDSUFFIX", "AND", "MUL", "ADD", "SUB", "TILDE", "NOT", "DIV",
  "MOD", "L_THAN", "G_THAN", "XOR", "OR", "QUESTION", "SIZEOF", "INC_OP",
  "DEC_OP", "PTR_OP", "DEFAULT", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC",
  "THREAD_LOCAL", "AUTO", "REGISTER", "NORETURN", "STATIC_ASSERT",
  "FUNC_NAME", "VOID", "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE",
  "SIGNED", "UNSIGNED", "BOOL", "COMPLEX", "IMAGINARY", "TYPEDEF_NAME",
  "STRUCT", "UNION", "ENUM", "CONST", "RESTRICT", "VOLATILE", "ATOMIC",
  "CASE", "IF", "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE",
  "BREAK", "RETURN", "$accept", "primary_expression", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration_specifiers",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359
};
# endif

#define YYPACT_NINF -303

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-303)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,  1294,    36,  -303,  -303,  -303,  -303,  -303,    54,  -303,
    -303,  -303,  -303,   258,    60,  -303,  -303,  -303,  -303,  -303,
    -303,  1327,  1360,  1360,  -303,    16,   346,  1294,  -303,   146,
     172,   208,   164,   211,    41,    70,    93,    64,   -20,  -303,
    -303,   134,  1294,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,    37,
    -303,  -303,  -303,   145,  1382,  -303,   114,    28,  -303,  -303,
    1382,   133,  1382,   258,  -303,   258,  -303,  -303,  1195,  1294,
     135,  -303,  -303,   180,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  1294,  -303,  -303,  1294,  1294,
    1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,
    1294,  1294,  1294,  1294,  1294,  1294,  1294,  -303,  1294,   198,
     197,   214,  1382,  -303,  1362,   225,   381,   473,   102,    77,
    -303,   182,  -303,  1228,   254,   264,   272,  -303,   176,  -303,
     148,  -303,  -303,  -303,  -303,  -303,  -303,   146,   146,   172,
     172,   208,   208,   208,   208,   164,   164,   211,    41,    70,
      93,   178,    64,  -303,  1331,  -303,   266,   201,  -303,   197,
     278,   284,   884,  -303,    34,  -303,  1362,  -303,   291,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,   144,  1004,  1004,
    1004,  1004,  1004,   292,   288,  -303,   296,  -303,   300,   797,
    -303,   301,  -303,   527,  -303,   102,   182,   858,   581,  1162,
    -303,  -303,   303,   303,  -303,  1294,  -303,  1294,  1294,   188,
    -303,   302,  1294,  -303,   119,   217,  -303,  1294,  -303,  -303,
     138,  -303,  1294,  -303,   257,  -303,   304,   226,    66,   923,
     258,   352,  -303,    35,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,   965,  -303,  -303,   306,   797,  -303,  -303,  1294,   307,
    -303,  -303,  -303,   311,  -303,   313,   797,   314,   635,  1294,
    1162,   305,  -303,  -303,   243,  1261,    29,  -303,  -303,  -303,
    -303,  -303,  1331,  1294,  -303,  -303,  -303,  -303,  -303,   121,
     315,   317,  -303,  -303,   150,  1294,   829,   689,   226,  -303,
     319,   320,  -303,  -303,  -303,   321,   322,  -303,  -303,  -303,
     323,   797,  -303,  -303,  1294,   324,   325,   244,  -303,  -303,
    1096,  -303,  -303,  -303,  -303,  -303,  -303,   289,  -303,  -303,
    -303,  -303,  -303,   349,   196,  -303,   353,   797,   354,   743,
    -303,  -303,  -303,  -303,  -303,   355,   356,  -303,  -303,  -303,
    1129,  -303,  -303,  1261,   359,  -303,  -303,   337,  -303,   361,
     797,  -303,  -303,   362,  1294,   363,  -303,  -303,  -303,  -303,
     365,  -303,  -303,   364,  -303,   369,  -303,  -303,  -303,  -303
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     7,     8,    11,    12,     0,     3,
       9,     4,     6,     0,     0,    37,    38,    39,    40,    41,
      42,     0,     0,     0,    18,    30,    43,     0,    45,    49,
      52,    55,    60,    63,    65,    67,    69,    71,    73,    75,
      88,     0,     0,     1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   122,   126,   127,     0,
     152,   153,   154,   155,   134,   120,     0,   192,   121,   119,
     136,     0,     0,     0,    34,     0,    31,    32,     0,     0,
       0,    24,    25,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,    43,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,   146,     0,   133,     0,   125,     0,     0,   179,   194,
     191,   195,   135,     0,     0,     0,     0,    20,     0,    28,
       0,    22,    23,    76,    46,    47,    48,    50,    51,    53,
      54,    56,    57,    58,    59,    61,    62,    64,    66,    68,
      70,     0,    72,    89,     0,    10,   150,     0,   147,     0,
       0,     0,     0,   128,     0,   132,     0,   213,     0,   156,
     101,   102,   103,   104,   105,   106,   157,   188,    92,    94,
      96,    98,   100,     0,   183,   184,     0,   197,    38,     0,
     155,     0,   180,     0,   178,   177,   193,     0,     0,     0,
      44,    36,    35,     0,    21,     0,    19,     0,     0,     0,
      14,     0,     0,   142,     0,     0,   151,     0,   123,   129,
       0,   130,     0,   162,     0,   137,   141,   161,     0,     0,
       0,     0,   186,   194,   187,    91,    93,    95,    97,    99,
     214,     0,   196,   198,     0,     0,   204,   203,     0,     0,
     181,   176,   215,     0,   205,    38,     0,     0,     0,     0,
       0,     0,   219,   221,     0,     0,     0,   225,    29,    74,
      17,    13,     0,     0,    90,   149,   143,   148,   144,     0,
       0,     0,   139,   131,     0,     0,     0,     0,   160,   124,
       0,     0,   182,   185,   200,     0,     0,   202,   216,   206,
       0,     0,   212,   211,     0,     0,     0,     0,   228,    26,
       0,   220,   224,   226,    15,    16,   145,     0,   163,   138,
     140,   174,   189,     0,     0,   164,    38,     0,     0,     0,
     159,   158,   199,   201,   208,     0,     0,   209,   227,   217,
       0,    27,   223,     0,     0,   173,   175,     0,   165,     0,
       0,   172,   171,    38,     0,     0,   207,   210,   218,   222,
       0,   190,   167,     0,   168,     0,   170,   229,   166,   169
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,   371,  -303,  -117,  -303,  -303,  -303,    83,  -303,  -303,
     -10,  -303,   -25,   169,   171,   137,   195,   265,   267,   268,
     263,   262,  -303,   -72,   -42,  -303,   -70,  -212,    48,  -303,
      58,  -303,  -303,   204,  -162,   -40,  -303,    88,  -303,   218,
    -210,  -303,   -77,  -303,  -303,   -78,   -92,   -62,  -127,  -191,
    -303,   139,  -303,    -5,   -63,  -123,  -234,   118,  -302,  -303,
     113,  -303
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,     9,    10,    11,    12,   219,   220,    25,   138,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    95,    41,   285,   187,   188,
      64,    65,    66,   172,   173,    67,   234,   235,    68,   167,
     168,    69,    70,   191,   192,   236,   237,   238,   203,   193,
     194,   195,   334,   221,   196,   131,   273,   274,   275,   276,
     277,   175
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     119,   205,    97,   166,   130,   129,   206,     1,    71,   140,
     229,    74,    76,    77,   287,   290,   263,    96,   353,    78,
     292,    79,   115,     2,   123,     3,     4,     5,   300,    80,
     132,   126,     6,   127,   269,   116,   139,   230,   241,    42,
     127,   321,   271,   231,   120,   161,   232,   322,   353,   190,
     202,   202,   166,   143,    43,   233,   233,   316,   121,   128,
      81,    82,    83,    72,   129,   128,   204,   134,   135,   230,
     136,   111,   255,   144,   145,   146,   163,   229,     7,   287,
     126,   268,   127,   330,   174,   201,   352,   233,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,   333,    96,   166,   210,   242,
     112,   190,   190,   190,   190,   190,   352,   170,   114,   369,
     206,   124,   202,    96,   244,   243,   260,   286,   260,   326,
     190,   202,   174,   128,   113,   125,   174,   133,   117,   311,
     165,   230,   165,   261,   118,   279,   298,   241,   122,   127,
     284,   298,   291,   230,   216,   284,   141,   254,   118,   233,
     284,   259,   232,   291,   190,   233,   267,   272,   284,   128,
     339,   233,   166,   278,   190,   128,   280,    98,   260,   243,
     214,   128,    99,   100,   189,   207,   215,   208,   118,   202,
     217,   260,   281,    60,    61,    62,   200,   284,   282,   174,
     356,   142,   105,   106,   101,   102,   357,    96,   164,   223,
     360,   224,    96,   305,   107,   108,   306,    96,   165,   190,
     202,   169,    96,   284,   310,   288,   315,   289,   272,   296,
      96,   297,   176,   272,   260,   301,   245,   246,   247,   248,
     249,   325,   151,   152,   153,   154,   189,   189,   189,   189,
     189,   319,   349,   320,   350,   338,   103,   104,   211,    96,
     202,    13,   260,   109,   110,   189,   293,   294,   212,   345,
     147,   148,   346,    14,   149,   150,   213,     2,   272,     3,
       4,     5,   226,   260,   222,    96,     6,   227,    15,    16,
      17,    18,    19,    20,   240,   359,   250,   365,   251,   189,
     252,    21,    22,    23,   155,   156,   253,   256,   272,   189,
     209,   272,   304,   307,   283,   308,   295,   354,   373,   309,
     312,   328,   375,   340,   341,   327,   318,   342,   343,   344,
     347,   348,     7,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   355,   189,   241,   177,   127,   371,   358,
     361,   366,   367,   370,    84,   324,   178,   372,   374,   376,
     378,     8,   179,   233,   377,   379,   157,   160,   162,   158,
     239,   159,   329,   128,   126,   177,   127,   225,   317,   323,
     303,     0,     0,     0,     0,   178,     0,     0,     0,     0,
       0,   179,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   128,     0,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,   186,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   180,   181,   182,
     183,   184,   185,   186,     0,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    13,     0,     0,   197,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     2,     0,     3,     4,     5,     0,     0,     0,
       0,     6,     0,    15,   198,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,   199,    14,     0,     0,     0,     2,     7,     3,     4,
       5,     0,     0,     0,     0,     6,     0,    15,    16,    17,
      18,    19,    20,     0,    60,    61,    62,   200,     0,     0,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,   264,     0,     0,
       0,     0,     0,     0,     0,   258,    14,     0,     0,     0,
       2,     7,     3,     4,     5,     0,     0,     0,     0,     6,
       0,    15,   265,    17,    18,    19,    20,     0,    60,    61,
      62,   200,     0,     0,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,   313,     0,     0,     0,     0,     0,     0,     0,   266,
      14,     0,     0,     0,     2,     7,     3,     4,     5,     0,
       0,     0,     0,     6,     0,    15,    16,    17,    18,    19,
      20,     0,    60,    61,    62,   200,     0,     0,    21,    22,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,   335,     0,     0,     0,     0,
       0,     0,     0,   314,    14,     0,     0,     0,     2,     7,
       3,     4,     5,     0,     0,     0,     0,     6,     0,    15,
     336,    17,    18,    19,    20,     0,    60,    61,    62,   200,
       0,     0,    21,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,   362,
       0,     0,     0,     0,     0,     0,     0,   337,    14,     0,
       0,     0,     2,     7,     3,     4,     5,     0,     0,     0,
       0,     6,     0,    15,   363,    17,    18,    19,    20,     0,
      60,    61,    62,   200,     0,     0,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,    14,     0,     0,     0,     2,     7,     3,     4,
       5,     0,     0,     0,     0,     6,     0,    15,    16,    17,
      18,    19,    20,   331,    60,    61,    62,   200,     0,     0,
      21,    22,    23,   178,     0,     0,     0,     0,     0,   179,
     332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   178,     0,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,   200,   228,     0,     0,   180,   181,   182,   183,   184,
     185,   186,     0,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   180,   181,   182,   183,   184,   185,
     186,   299,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,     0,     0,     0,   171,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   178,
       0,   302,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   178,     0,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,   180,   181,   182,   183,   184,   185,   186,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,   183,   184,   185,   186,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    13,
       0,   269,     0,   270,   351,     0,     0,     0,     0,   271,
       0,    14,     0,     0,     0,     2,     0,     3,     4,     5,
       0,     0,     0,     0,     6,     0,    15,    16,    17,    18,
      19,    20,    13,     0,   269,     0,   270,   368,     0,    21,
      22,    23,   271,     0,    14,     0,     0,     0,     2,     0,
       3,     4,     5,     0,     0,     0,     0,     6,     0,    15,
      16,    17,    18,    19,    20,    13,     0,   269,     0,   270,
       7,     0,    21,    22,    23,   271,     0,    14,     0,     0,
       0,     2,     0,     3,     4,     5,     0,     0,     0,     0,
       6,     0,    15,    16,    17,    18,    19,    20,    13,   137,
       0,     0,     0,     7,     0,    21,    22,    23,     0,     0,
      14,     0,     0,     0,     2,     0,     3,     4,     5,     0,
       0,     0,     0,     6,     0,    15,    16,    17,    18,    19,
      20,    13,     0,     0,     0,   209,     7,     0,    21,    22,
      23,     0,     0,    14,     0,     0,     0,     2,     0,     3,
       4,     5,     0,     0,     0,     0,     6,     0,    15,    16,
      17,    18,    19,    20,    13,     0,     0,     0,   270,     7,
       0,    21,    22,    23,     0,     0,    14,     0,     0,     0,
       2,     0,     3,     4,     5,     0,     0,     0,     0,     6,
       0,    15,    16,    17,    18,    19,    20,    13,     0,     0,
       0,     0,     7,     0,    21,    22,    23,     0,     0,    14,
       0,     0,     0,     2,     0,     3,     4,     5,     0,     0,
       0,     0,     6,     0,    15,    16,    17,    18,    19,    20,
      73,     0,     0,     0,     0,     7,     0,    21,    22,    23,
       0,     0,    14,     0,     0,     0,     2,     0,     3,     4,
       5,     0,     0,     0,     0,     6,     0,    15,    16,    17,
      18,    19,    20,    75,     0,     0,     0,     0,     7,     0,
      21,    22,    23,     0,     0,    14,     0,     0,   218,     2,
       0,     3,     4,     5,     0,     0,     0,     0,     6,     0,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     7,     0,    21,    22,    23,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   171,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63
};

static const yytype_int16 yycheck[] =
{
      42,   128,    27,   120,    67,    67,   129,     3,    13,    79,
     172,    21,    22,    23,   224,   227,   207,    27,   320,     3,
     232,     5,    42,    19,    64,    21,    22,    23,   240,    13,
      70,     3,    28,     5,     5,    55,    78,     3,     3,     3,
       5,   275,    13,     9,     7,   115,    12,    18,   350,   126,
     127,   128,   169,    95,     0,    21,    21,   269,    21,    31,
      44,    45,    46,     3,   126,    31,   128,    72,    73,     3,
      75,    30,   199,    98,    99,   100,   118,   239,    74,   289,
       3,   208,     5,   295,   124,   127,   320,    21,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   296,   116,   224,   133,   187,
      40,   188,   189,   190,   191,   192,   350,   122,    54,   353,
     243,     7,   199,   133,   187,   187,   203,     8,   205,     8,
     207,   208,   172,    31,    41,    21,   176,     4,     4,   266,
      21,     3,    21,   205,    10,   217,   238,     3,     3,     5,
     222,   243,   230,     3,     6,   227,    21,   199,    10,    21,
     232,   203,    12,   241,   241,    21,   208,   209,   240,    31,
     297,    21,   289,   215,   251,    31,   218,    31,   255,   241,
       4,    31,    36,    37,   126,     3,    10,     5,    10,   266,
      12,   268,     4,    91,    92,    93,    94,   269,    10,   239,
       4,    21,    38,    39,    32,    33,    10,   217,    10,     8,
     337,    10,   222,   255,    50,    51,   258,   227,    21,   296,
     297,     7,   232,   295,   266,     8,   268,    10,   270,     3,
     240,     5,     7,   275,   311,   240,   188,   189,   190,   191,
     192,   283,   105,   106,   107,   108,   188,   189,   190,   191,
     192,     8,     8,    10,    10,   297,    48,    49,     4,   269,
     337,     3,   339,    52,    53,   207,     9,    10,     4,   311,
     101,   102,   314,    15,   103,   104,     4,    19,   320,    21,
      22,    23,     4,   360,    18,   295,    28,     3,    30,    31,
      32,    33,    34,    35,     3,   337,     4,   339,    10,   241,
       4,    43,    44,    45,   109,   110,     6,     6,   350,   251,
       7,   353,     6,     6,    12,     4,    12,    28,   360,     6,
       6,     4,   364,     4,     4,    10,    21,     6,     6,     6,
       6,     6,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     4,   296,     3,     4,     5,    21,     6,
       6,     6,     6,     4,    18,   282,    14,     6,     6,     6,
       6,     0,    20,    21,     9,     6,   111,   114,   116,   112,
     176,   113,   294,    31,     3,     4,     5,   169,   270,   276,
     251,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    31,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     3,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    19,    -1,    21,    22,    23,    -1,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    15,    -1,    -1,    -1,    19,    74,    21,    22,
      23,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    -1,    91,    92,    93,    94,    -1,    -1,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    15,    -1,    -1,    -1,
      19,    74,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      -1,    30,    31,    32,    33,    34,    35,    -1,    91,    92,
      93,    94,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      15,    -1,    -1,    -1,    19,    74,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    -1,    30,    31,    32,    33,    34,
      35,    -1,    91,    92,    93,    94,    -1,    -1,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    15,    -1,    -1,    -1,    19,    74,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,    -1,    91,    92,    93,    94,
      -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    15,    -1,
      -1,    -1,    19,    74,    21,    22,    23,    -1,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    33,    34,    35,    -1,
      91,    92,    93,    94,    -1,    -1,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    15,    -1,    -1,    -1,    19,    74,    21,    22,
      23,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,     4,    91,    92,    93,    94,    -1,    -1,
      43,    44,    45,    14,    -1,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,     8,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    66,    67,    68,    69,    70,    71,
      72,     8,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    -1,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    14,
      -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    14,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     3,
      -1,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,    13,
      -1,    15,    -1,    -1,    -1,    19,    -1,    21,    22,    23,
      -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,     3,    -1,     5,    -1,     7,     8,    -1,    43,
      44,    45,    13,    -1,    15,    -1,    -1,    -1,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,     3,    -1,     5,    -1,     7,
      74,    -1,    43,    44,    45,    13,    -1,    15,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,     3,     4,
      -1,    -1,    -1,    74,    -1,    43,    44,    45,    -1,    -1,
      15,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    -1,    30,    31,    32,    33,    34,
      35,     3,    -1,    -1,    -1,     7,    74,    -1,    43,    44,
      45,    -1,    -1,    15,    -1,    -1,    -1,    19,    -1,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,
      32,    33,    34,    35,     3,    -1,    -1,    -1,     7,    74,
      -1,    43,    44,    45,    -1,    -1,    15,    -1,    -1,    -1,
      19,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      -1,    30,    31,    32,    33,    34,    35,     3,    -1,    -1,
      -1,    -1,    74,    -1,    43,    44,    45,    -1,    -1,    15,
      -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    -1,    30,    31,    32,    33,    34,    35,
       3,    -1,    -1,    -1,    -1,    74,    -1,    43,    44,    45,
      -1,    -1,    15,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,     3,    -1,    -1,    -1,    -1,    74,    -1,
      43,    44,    45,    -1,    -1,    15,    -1,    -1,    47,    19,
      -1,    21,    22,    23,    -1,    -1,    -1,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    43,    44,    45,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    19,    21,    22,    23,    28,    74,   106,   107,
     108,   109,   110,     3,    15,    30,    31,    32,    33,    34,
      35,    43,    44,    45,   106,   113,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   131,     3,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   135,   136,   137,   140,   143,   146,
     147,   158,     3,     3,   115,     3,   115,   115,     3,     5,
      13,    44,    45,    46,    18,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   130,   115,   117,    31,    36,
      37,    32,    33,    48,    49,    38,    39,    50,    51,    52,
      53,    30,    40,    41,    54,    42,    55,     4,    10,   129,
       7,    21,     3,   140,     7,    21,     3,     5,    31,   152,
     159,   160,   140,     4,   158,   158,   158,     4,   114,   129,
     131,    21,    21,   129,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   120,   120,   121,   121,   122,   123,   124,
     125,   131,   126,   129,    10,    21,   108,   144,   145,     7,
     158,    73,   138,   139,   140,   166,     7,     4,    14,    20,
      66,    67,    68,    69,    70,    71,    72,   133,   134,   135,
     147,   148,   149,   154,   155,   156,   159,     6,    31,    68,
      94,   129,   147,   153,   152,   153,   160,     3,     5,     7,
     117,     4,     4,     4,     4,    10,     6,    12,    47,   111,
     112,   158,    18,     8,    10,   144,     4,     3,     8,   139,
       3,     9,    12,    21,   141,   142,   150,   151,   152,   138,
       3,     3,   150,   152,   159,   133,   133,   133,   133,   133,
       4,    10,     4,     6,   129,   153,     6,     6,    68,   129,
     147,   152,     4,   154,     6,    31,    68,   129,   153,     5,
       7,    13,   129,   161,   162,   163,   164,   165,   129,   128,
     129,     4,    10,    12,   128,   132,     8,   145,     8,    10,
     132,   150,   132,     9,    10,    12,     3,     5,   151,     8,
     132,   158,    16,   156,     6,   129,   129,     6,     4,     6,
     129,   153,     6,     6,    68,   129,   132,   162,    21,     8,
      10,   161,    18,   165,   112,   129,     8,    10,     4,   142,
     132,     4,    21,   154,   157,     6,    31,    68,   129,   153,
       4,     4,     6,     6,     6,   129,   129,     6,     6,     8,
      10,     8,   161,   163,    28,     4,     4,    10,     6,   129,
     153,     6,     6,    31,    68,   129,     6,     6,     8,   161,
       4,    21,     6,   129,     6,   129,     6,     9,     6,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   106,   106,   107,   107,   107,
     108,   109,   109,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   118,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   121,   121,   121,
     122,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     132,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   134,   134,   134,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   139,   140,   140,   140,   140,   141,   141,   142,
     142,   142,   143,   143,   143,   143,   143,   144,   144,   145,
     145,   146,   147,   147,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   152,   152,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   156,   157,
     157,   158,   158,   159,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   161,   161,   161,
     162,   162,   162,   162,   163,   164,   164,   165,   165,   166
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     2,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     2,     1,     1,     1,     2,
       2,     3,     1,     2,     1,     2,     1,     1,     3,     2,
       3,     1,     4,     5,     5,     6,     2,     1,     3,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     4,     4,
       2,     1,     1,     3,     3,     4,     6,     5,     5,     6,
       5,     4,     4,     4,     3,     4,     3,     2,     2,     1,
       1,     2,     3,     1,     1,     3,     2,     2,     1,     1,
       3,     2,     1,     2,     1,     1,     3,     2,     3,     5,
       4,     5,     4,     3,     3,     3,     4,     6,     5,     5,
       6,     4,     4,     2,     3,     3,     4,     3,     4,     1,
       2,     1,     4,     3,     2,     1,     2,     3,     2,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
#line 1846 "bison.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 544 "bison.y" /* yacc.c:1906  */


int yyerror(char *s)
{
	printf("Syntax Error on line %s\n", s);
	return 0;
}


int main()
{
    return 0;
}
