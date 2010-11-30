
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liblex.h"
#include "libmepa.h"

extern char retorno[100];
extern int linha;

//pilhas
tpilha_rot *rotulo;
tpilha_ts *ts;

int yydebug=1;

//variaveis compilador
int nivlex=0;
int desloc=0;
int num=0;
int numvar=0;
int numpar=0;
int numpass=0;
int aux[10];
int cont=0;
int rotulocorrente=0;
char recebe[30];
char relacao[10];
char nomerotina[30];
int i;

//variaveis de controle
int decvar=0;
int decif=0;
int decloop=0;
int decproc=0;
int decfunc=0;
int declabel=0;
int decparam=0;
int passvalor=0;
int passreferencia=0;
int temsubrot=0;
int chpr=0; 
int parsubrotina=0;
int leitura=0;
int escrita=0;
int atribuicao=0;

//Funcao de erro
void yyerror(const char *str){
	printf("Erro: %s - linha: %d \n",str,linha);
	exit(1);
}

int yywrap(){
	return 1;
}


main(int argc, char **argv)
{
	if(argc!=2)
	{
		printf("USO: ./compilador arquivo.pas\n");
		exit(2);
	}
	yyin=fopen(argv[1],"r");
	yyout=fopen("saida.mepa","w");
	rotulo=criaPilhaRotulo();
	ts=criaPilhaTS();
	yyparse();
}



/* Line 189 of yacc.c  */
#line 149 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEIRO = 258,
     IDENT = 259,
     LABEL = 260,
     VAR = 261,
     INTEGER = 262,
     IF = 263,
     THEN = 264,
     ELSE = 265,
     WHILE = 266,
     GOTO = 267,
     DO = 268,
     READ = 269,
     WRITE = 270,
     FUNCTION = 271,
     PROCEDURE = 272,
     PROGRAM = 273,
     _BEGIN = 274,
     END = 275,
     AND = 276,
     OR = 277,
     NOT = 278,
     MAIORIG = 279,
     MENORIG = 280,
     MAIOR = 281,
     MENOR = 282,
     IGUAL = 283,
     ATRIBUICAO = 284,
     MAIS = 285,
     MENOS = 286,
     MULT = 287,
     DIV = 288,
     DIF = 289,
     ABREPAR = 290,
     FECHAPAR = 291,
     ABRECH = 292,
     FECHACH = 293,
     PTOVIRG = 294,
     DOISPTS = 295,
     VIRGULA = 296,
     PONTO = 297,
     LOWER_THEN_ELSE = 298
   };
#endif
/* Tokens.  */
#define INTEIRO 258
#define IDENT 259
#define LABEL 260
#define VAR 261
#define INTEGER 262
#define IF 263
#define THEN 264
#define ELSE 265
#define WHILE 266
#define GOTO 267
#define DO 268
#define READ 269
#define WRITE 270
#define FUNCTION 271
#define PROCEDURE 272
#define PROGRAM 273
#define _BEGIN 274
#define END 275
#define AND 276
#define OR 277
#define NOT 278
#define MAIORIG 279
#define MENORIG 280
#define MAIOR 281
#define MENOR 282
#define IGUAL 283
#define ATRIBUICAO 284
#define MAIS 285
#define MENOS 286
#define MULT 287
#define DIV 288
#define DIF 289
#define ABREPAR 290
#define FECHAPAR 291
#define ABRECH 292
#define FECHACH 293
#define PTOVIRG 294
#define DOISPTS 295
#define VIRGULA 296
#define PONTO 297
#define LOWER_THEN_ELSE 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 277 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNRULES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    14,    16,    20,    21,    22,    29,
      30,    34,    36,    40,    41,    45,    48,    52,    58,    60,
      61,    64,    68,    70,    72,    74,    75,    76,    84,    85,
      86,    87,    98,    99,   100,   101,   107,   108,   109,   116,
     117,   118,   124,   125,   126,   135,   136,   137,   145,   148,
     149,   154,   156,   160,   164,   166,   168,   170,   172,   174,
     176,   178,   180,   182,   183,   188,   190,   191,   192,   199,
     200,   206,   207,   213,   216,   217,   218,   226,   227,   231,
     232,   233,   234,   241,   243,   247,   249,   253,   255,   258,
     261,   264,   268,   272,   275,   278,   281,   285,   289,   293,
     295,   298,   301,   304,   307,   311,   315,   319,   321,   323,
     325,   329,   332,   334,   336,   338,   340,   342,   344,   346,
     347,   348,   355,   357
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    -1,    18,   114,    46,    35,    47,    36,
      39,    48,    42,    -1,   114,    -1,    47,    41,   114,    -1,
      -1,    -1,    51,    49,    53,    50,    56,    78,    -1,    -1,
       5,    52,    39,    -1,   113,    -1,    52,    41,   113,    -1,
      -1,     6,    54,    39,    -1,    54,    39,    -1,    47,    40,
      55,    -1,    54,    39,    47,    40,    55,    -1,     7,    -1,
      -1,    57,    39,    -1,    57,    39,    58,    -1,    58,    -1,
      59,    -1,    62,    -1,    -1,    -1,    17,    60,   114,    61,
      66,    39,    48,    -1,    -1,    -1,    -1,    16,    63,   114,
      64,    66,    40,    55,    65,    39,    48,    -1,    -1,    -1,
      -1,    35,    67,    69,    68,    36,    -1,    -1,    -1,     6,
      70,    47,    71,    40,    55,    -1,    -1,    -1,    72,    47,
      73,    40,    55,    -1,    -1,    -1,    69,    39,     6,    74,
      47,    75,    40,    55,    -1,    -1,    -1,    69,    39,    76,
      47,    77,    40,    55,    -1,    19,    20,    -1,    -1,    19,
      79,    80,    20,    -1,    81,    -1,    80,    39,    81,    -1,
     113,    40,    82,    -1,    82,    -1,    83,    -1,    85,    -1,
      92,    -1,    88,    -1,    90,    -1,    78,    -1,    93,    -1,
      98,    -1,    -1,   109,    84,    29,   102,    -1,   114,    -1,
      -1,    -1,   114,    86,    35,   101,    87,    36,    -1,    -1,
      89,    14,    35,   101,    36,    -1,    -1,    91,    15,    35,
     101,    36,    -1,    12,   113,    -1,    -1,    -1,     8,    94,
     102,    95,     9,    82,    96,    -1,    -1,    10,    97,    82,
      -1,    -1,    -1,    -1,    11,    99,   102,   100,    13,    82,
      -1,   102,    -1,   101,    41,   102,    -1,   103,    -1,   103,
     108,   103,    -1,   105,    -1,    30,   105,    -1,    31,   105,
      -1,   105,   104,    -1,    30,   105,   104,    -1,    31,   105,
     104,    -1,    30,   105,    -1,    31,   105,    -1,    22,   105,
      -1,   104,    30,   105,    -1,   104,    31,   105,    -1,   104,
      22,   105,    -1,   107,    -1,   107,   106,    -1,    32,   107,
      -1,    33,   107,    -1,    21,   107,    -1,   106,    32,   107,
      -1,   106,    33,   107,    -1,   106,    21,   107,    -1,   109,
      -1,   113,    -1,   110,    -1,    35,   102,    36,    -1,    23,
     107,    -1,    28,    -1,    34,    -1,    25,    -1,    24,    -1,
      27,    -1,    26,    -1,   114,    -1,    -1,    -1,   114,   111,
      35,   101,   112,    36,    -1,     3,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    96,   104,   105,   109,   116,   108,   125,
     126,   129,   131,   134,   135,   140,   147,   148,   151,   154,
     155,   158,   159,   162,   163,   167,   174,   166,   190,   197,
     199,   189,   213,   215,   222,   214,   239,   241,   238,   243,
     245,   243,   248,   250,   247,   253,   255,   252,   259,   261,
     260,   271,   272,   275,   276,   279,   280,   281,   282,   283,
     284,   285,   286,   290,   289,   305,   311,   316,   310,   324,
     324,   329,   329,   334,   338,   340,   337,   352,   351,   359,
     362,   369,   361,   379,   380,   383,   384,   387,   388,   389,
     390,   391,   392,   395,   396,   397,   398,   399,   400,   403,
     404,   407,   408,   409,   410,   411,   412,   415,   434,   439,
     440,   441,   445,   446,   447,   448,   449,   450,   453,   457,
     462,   456,   470,   485
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEIRO", "IDENT", "LABEL", "VAR",
  "INTEGER", "IF", "THEN", "ELSE", "WHILE", "GOTO", "DO", "READ", "WRITE",
  "FUNCTION", "PROCEDURE", "PROGRAM", "_BEGIN", "END", "AND", "OR", "NOT",
  "MAIORIG", "MENORIG", "MAIOR", "MENOR", "IGUAL", "ATRIBUICAO", "MAIS",
  "MENOS", "MULT", "DIV", "DIF", "ABREPAR", "FECHAPAR", "ABRECH",
  "FECHACH", "PTOVIRG", "DOISPTS", "VIRGULA", "PONTO", "LOWER_THEN_ELSE",
  "$accept", "programa", "$@1", "listaidentificadores", "bloco", "$@2",
  "$@3", "p_declaracaorotulos", "listanumeros", "p_declaracaovariaveis",
  "declaracaovariaveis", "tipo", "p_declaracaosubrotinas",
  "listadeclaracaosubrotinas", "declaracaosubrotinas", "declaracaoproc",
  "$@4", "$@5", "declaracaofuncao", "$@6", "$@7", "$@8",
  "parametrosformais", "$@9", "$@10", "s_parametrosformais", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18",
  "comandocomposto", "$@19", "listacomandos", "comando",
  "comandosemrotulo", "atribuicao", "$@20", "chamadaprocedimento", "$@21",
  "$@22", "read", "$@23", "write", "$@24", "desvio", "comandocondicional",
  "$@25", "$@26", "condicaoelse", "$@27", "comandorepetitivo", "$@28",
  "$@29", "listaexpressoes", "expressao", "expressaosimples",
  "listaexpressoessimples", "termo", "listatermos", "fator", "relacao",
  "variavel", "chamadafuncao", "$@30", "$@31", "numero", "identificador", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    47,    49,    50,    48,    51,
      51,    52,    52,    53,    53,    53,    54,    54,    55,    56,
      56,    57,    57,    58,    58,    60,    61,    59,    63,    64,
      65,    62,    66,    67,    68,    66,    70,    71,    69,    72,
      73,    69,    74,    75,    69,    76,    77,    69,    78,    79,
      78,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    84,    83,    85,    86,    87,    85,    89,
      88,    91,    90,    92,    94,    95,    93,    97,    96,    96,
      99,   100,    98,   101,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   104,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   109,   111,
     112,   110,   113,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     1,     3,     0,     0,     6,     0,
       3,     1,     3,     0,     3,     2,     3,     5,     1,     0,
       2,     3,     1,     1,     1,     0,     0,     7,     0,     0,
       0,    10,     0,     0,     0,     5,     0,     0,     6,     0,
       0,     5,     0,     0,     8,     0,     0,     7,     2,     0,
       4,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     0,     0,     6,     0,
       5,     0,     5,     2,     0,     0,     7,     0,     3,     0,
       0,     0,     6,     1,     3,     1,     3,     1,     2,     2,
       2,     3,     3,     2,     2,     2,     3,     3,     3,     1,
       2,     2,     2,     2,     3,     3,     3,     1,     1,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     6,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   123,     2,     1,     0,     0,     0,     4,
       0,     0,     9,     5,     0,     0,     6,   122,     0,    11,
       3,    13,    10,     0,     0,     0,     7,     0,    12,     0,
       0,    19,    15,    14,    18,    16,    28,    25,     0,     0,
      22,    23,    24,     0,     0,     0,    49,     8,    20,     0,
      29,    26,    48,    69,    21,    17,    32,    32,    74,    80,
       0,    60,     0,    51,    54,    55,    56,    58,     0,    59,
       0,    57,    61,    62,    63,     0,    65,    33,     0,     0,
       0,     0,    73,    50,    69,     0,     0,     0,    69,     0,
      39,     0,     9,     0,     0,     0,     0,    75,    85,    87,
      99,   107,   109,   108,   118,    81,    52,     0,     0,     0,
      53,     0,    36,    34,     0,    30,    27,   111,    88,    89,
       0,     0,   115,   114,   117,   116,   112,   113,     0,     0,
       0,     0,    90,     0,     0,     0,   100,     0,     0,     0,
      83,     0,    64,    67,     0,    45,     0,    40,     0,    91,
      92,   110,    69,    86,    95,    93,    94,     0,     0,     0,
     103,   101,   102,     0,     0,     0,     0,    69,    70,     0,
      72,     0,    37,    42,     0,    35,     0,     9,    79,    98,
      96,    97,   106,   104,   105,   120,    82,    84,    68,     0,
       0,    46,     0,    31,    77,    76,     0,     0,    43,     0,
      41,    69,   121,    38,     0,     0,    78,     0,    47,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    25,    15,    21,    31,    16,    18,    26,
      27,    35,    38,    39,    40,    41,    45,    57,    42,    44,
      56,   148,    78,    90,   146,   113,   144,   189,   114,   176,
     190,   204,   174,   199,    61,    53,    62,    63,    64,    65,
      87,    66,    89,   171,    67,    68,    69,    70,    71,    72,
      80,   121,   195,   201,    73,    81,   138,   139,   140,    98,
     132,    99,   136,   100,   128,   101,   102,   137,   196,   103,
     104
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
      12,    30,    40,  -101,  -101,  -101,    41,    30,    19,  -101,
      47,    30,    86,  -101,    89,    63,  -101,  -101,   -24,  -101,
    -101,    35,  -101,    89,    30,   -16,  -101,    71,  -101,    73,
     100,    45,    30,    30,  -101,  -101,  -101,  -101,   101,    90,
    -101,  -101,  -101,    49,    30,    30,   114,  -101,    45,   100,
    -101,  -101,  -101,   111,  -101,  -101,    96,    96,  -101,  -101,
      89,  -101,   -11,  -101,  -101,  -101,  -101,  -101,   119,  -101,
     122,  -101,  -101,  -101,  -101,    99,   -13,  -101,   102,   106,
      50,    50,  -101,  -101,   111,   109,   118,   112,   113,   120,
     134,   100,    86,    15,    15,    15,    50,  -101,    69,    37,
      24,  -101,  -101,  -101,   121,  -101,  -101,    50,    50,    50,
    -101,    50,  -101,   107,    30,  -101,  -101,  -101,    37,    37,
     123,   139,  -101,  -101,  -101,  -101,  -101,  -101,    50,    15,
      15,    15,   105,    15,    15,    15,    42,   126,   136,    68,
    -101,    70,  -101,   116,    30,   148,   127,   117,   125,   105,
     105,  -101,   113,  -101,  -101,  -101,  -101,    15,    15,    15,
    -101,  -101,  -101,    15,    15,    15,    50,   113,  -101,    50,
    -101,   129,   117,  -101,    30,  -101,   130,    86,   157,  -101,
    -101,  -101,  -101,  -101,  -101,   116,  -101,  -101,  -101,   131,
      30,   117,   100,  -101,  -101,  -101,   133,   100,   117,   132,
    -101,   113,  -101,  -101,   135,   100,  -101,   100,  -101,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,    -6,   -89,  -101,  -101,  -101,  -101,  -101,
     150,   -45,  -101,  -101,   128,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,   124,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,   140,  -101,  -101,    93,   -83,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -100,   -67,    51,
     -54,   -59,  -101,   -86,  -101,   -51,  -101,  -101,  -101,    -2,
      -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -120
static const yytype_int16 yytable[] =
{
       4,     8,    74,   116,    55,   110,     9,   117,   141,    83,
      13,   143,    19,    97,   105,    22,  -118,    23,    17,     3,
       9,    28,   -66,     9,    30,    11,    43,    43,    84,   120,
       1,     9,     9,    74,     3,   118,   119,    74,    93,     3,
       5,    24,   142,    50,    51,   133,   115,   160,   161,   162,
      96,    75,    76,    17,     3,    10,   134,   135,    82,   129,
      11,    36,    37,   163,   149,   150,   185,   130,   131,   178,
     154,   155,   156,    93,   164,   165,     7,   182,   183,   184,
      94,    95,    75,    76,   186,    96,    12,    76,   193,    49,
      11,    14,    17,   122,   123,   124,   125,   126,   179,   180,
     181,    74,   187,   127,   168,    20,   170,    34,   147,   169,
      32,   169,    33,     9,    17,     3,    74,     3,   206,    58,
      46,    58,    59,    60,    59,    60,   -71,   157,   -71,    48,
      46,    77,    46,    85,    52,   158,   159,    86,   172,    88,
     112,   109,    91,     9,   107,    92,   145,   200,   152,   167,
      74,    76,   203,   108,   173,   111,  -119,   169,    11,   151,
     208,   166,   209,   175,   177,   188,    76,   194,   191,   202,
     192,   197,   205,     9,    29,   207,    54,   106,    47,   153,
       0,    79,     0,     0,   198,     0,     0,     0,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76
};

static const yytype_int16 yycheck[] =
{
       1,     7,    53,    92,    49,    88,     7,    93,   108,    20,
      11,   111,    14,    80,    81,    39,    29,    41,     3,     4,
      21,    23,    35,    24,    40,    41,    32,    33,    39,    96,
      18,    32,    33,    84,     4,    94,    95,    88,    23,     4,
       0,     6,   109,    44,    45,    21,    91,   133,   134,   135,
      35,    53,    53,     3,     4,    36,    32,    33,    60,    22,
      41,    16,    17,    21,   118,   119,   166,    30,    31,   152,
     129,   130,   131,    23,    32,    33,    35,   163,   164,   165,
      30,    31,    84,    84,   167,    35,    39,    88,   177,    40,
      41,     5,     3,    24,    25,    26,    27,    28,   157,   158,
     159,   152,   169,    34,    36,    42,    36,     7,   114,    41,
      39,    41,    39,   114,     3,     4,   167,     4,   201,     8,
      19,     8,    11,    12,    11,    12,    15,    22,    15,    39,
      19,    35,    19,    14,    20,    30,    31,    15,   144,    40,
       6,    29,    40,   144,    35,    39,    39,   192,     9,    13,
     201,   152,   197,    35,     6,    35,    35,    41,    41,    36,
     205,    35,   207,    36,    39,    36,   167,    10,   174,    36,
      40,    40,    40,   174,    24,    40,    48,    84,    38,   128,
      -1,    57,    -1,    -1,   190,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    45,     4,   114,     0,    46,    35,    47,   114,
      36,    41,    39,   114,     5,    48,    51,     3,    52,   113,
      42,    49,    39,    41,     6,    47,    53,    54,   113,    54,
      40,    50,    39,    39,     7,    55,    16,    17,    56,    57,
      58,    59,    62,    47,    63,    60,    19,    78,    39,    40,
     114,   114,    20,    79,    58,    55,    64,    61,     8,    11,
      12,    78,    80,    81,    82,    83,    85,    88,    89,    90,
      91,    92,    93,    98,   109,   113,   114,    35,    66,    66,
      94,    99,   113,    20,    39,    14,    15,    84,    40,    86,
      67,    40,    39,    23,    30,    31,    35,   102,   103,   105,
     107,   109,   110,   113,   114,   102,    81,    35,    35,    29,
      82,    35,     6,    69,    72,    55,    48,   107,   105,   105,
     102,    95,    24,    25,    26,    27,    28,    34,   108,    22,
      30,    31,   104,    21,    32,    33,   106,   111,   100,   101,
     102,   101,   102,   101,    70,    39,    68,    47,    65,   104,
     104,    36,     9,   103,   105,   105,   105,    22,    30,    31,
     107,   107,   107,    21,    32,    33,    35,    13,    36,    41,
      36,    87,    47,     6,    76,    36,    73,    39,    82,   105,
     105,   105,   107,   107,   107,   101,    82,   102,    36,    71,
      74,    47,    40,    48,    10,    96,   112,    40,    47,    77,
      55,    97,    36,    55,    75,    40,    82,    40,    55,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 97 "yacc.y"
    { fprintf(yyout,"INPP\n"); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 99 "yacc.y"
    {
		fprintf(yyout,"DMEM %d\n", buscaDemem(ts,nivlex));
		fprintf(yyout,"PARA\n");
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 109 "yacc.y"
    {
		decproc=0; 
		decvar=1; 
		decfunc=0; 
		parsubrotina=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 116 "yacc.y"
    {
		decvar=0;
		fprintf(yyout,"DSVS R%d\n",rotulocorrente);
		incrementaRotulo(rotulo,rotulocorrente); 
		rotulocorrente++; 
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 130 "yacc.y"
    { fprintf(yyout,"%s",retorno);	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 136 "yacc.y"
    {
		fprintf(yyout,"AMEM %d\n", numvar); 
		numvar=0; 
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 141 "yacc.y"
    {
		fprintf(yyout,"AMEM %d\n", numvar); 
		numvar=0; 
	}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 167 "yacc.y"
    {
		decproc=1; 
		decvar=0; 
		decfunc=0; 
		parsubrotina=0;
	}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 174 "yacc.y"
    {
		strcpy(nomerotina,retorno);
		decproc=0; 
		decvar=0; 
		decfunc=0; 
		parsubrotina=0;
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 183 "yacc.y"
    {
		fprintf(yyout,"DMEM %d\n", buscaDemem(ts,nivlex));
		fprintf(yyout,"RTPR %d,%d\n", nivlex, buscaNumParam(ts,nomerotina));
		nivlex--;
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 190 "yacc.y"
    {
		decproc=0; 
		decvar=0; 
		decfunc=1; 
		parsubrotina=0;
	}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 197 "yacc.y"
    { strcpy(nomerotina,retorno); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 199 "yacc.y"
    {
		numpar++;
		ts->topo->parametro.desloc[numpar-1]=-3-numpar;
		strcpy(ts->topo->parametro.ident[numpar-1],nomerotina);
		ts->topo->parametro.passagem[numpar-1]=VALOR;
		ts->topo->numparam=numpar;
	}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 207 "yacc.y"
    {
		fprintf(yyout,"DMEM %d\n", buscaDemem(ts,nivlex));
		fprintf(yyout,"RTPR %d,%d\n", nivlex, (buscaNumParam(ts,nomerotina)-1));
		nivlex--;
	}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 215 "yacc.y"
    {
		decproc=0; 
		decvar=0; 
		decfunc=0; 
		parsubrotina=1;
	}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 222 "yacc.y"
    {
		decproc=0; 
		decvar=0; 
		decfunc=0; 
		parsubrotina=0; 
		for(i=ts->topo->numparam-1;i>=0;i--)
		{
			aux[i]=ts->topo->parametro.desloc[cont];
			cont++;
		}
		for(i=0;i<ts->topo->numparam;i++)
			ts->topo->parametro.desloc[i]=aux[i];
	}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 239 "yacc.y"
    { passreferencia=1; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 241 "yacc.y"
    { passreferencia=0; }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 243 "yacc.y"
    {passvalor=1;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 245 "yacc.y"
    { passvalor=0; }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 248 "yacc.y"
    { passreferencia=1; }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 250 "yacc.y"
    { passreferencia=0; }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 253 "yacc.y"
    { passvalor=1; }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 255 "yacc.y"
    { passvalor=1; }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 261 "yacc.y"
    {
		if ((decloop==0)&&(decif==0))
		{
			num=desempilhaRotulo(rotulo);
			fprintf(yyout,"R%d: NADA\n",num); 
		}
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 290 "yacc.y"
    {
		atribuicao=1; 
		strcpy(recebe,retorno);
        printf("Copiei %s\n", retorno);
        printf("Copiei %s\n", yytext);
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 297 "yacc.y"
    { 
		if (buscaPassagem(ts,recebe)==VALOR)
			 fprintf(yyout,"ARMZ %d,%d\n", buscaNivLexTS(ts,recebe),buscaDeslocamentoTS(ts,recebe)); 
		else if (buscaPassagem(ts,recebe)==REFERENCIA)
			 fprintf(yyout,"ARMI %d,%d\n", buscaNivLexTS(ts,recebe),buscaDeslocamentoTS(ts,recebe)); 
		atribuicao=0;
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 306 "yacc.y"
    {	
		strcpy(nomerotina,retorno);
		fprintf(yyout,"CHPR R%d,%d\n", buscaIdentificador(ts,nomerotina),nivlex);
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 311 "yacc.y"
    {	
		chpr=1;
		strcpy(nomerotina,retorno);
	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 316 "yacc.y"
    { 
		fprintf(yyout,"CHPR R%d,%d\n", buscaIdentificador(ts,nomerotina),nivlex);
		chpr=0;
		numpass=0;
	}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 324 "yacc.y"
    { leitura=1; }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 326 "yacc.y"
    { leitura=0; }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 329 "yacc.y"
    { escrita=1; }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 331 "yacc.y"
    { escrita=0; }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 338 "yacc.y"
    { decif=1; }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 340 "yacc.y"
    {
		fprintf(yyout,"DSVF R%d\n",rotulocorrente); 
		incrementaRotulo(rotulo,rotulocorrente);
		rotulocorrente++;
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 346 "yacc.y"
    {
		fprintf(yyout,"R%d: NADA\n", desempilhaRotulo(rotulo));
		decif=0;
	}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 352 "yacc.y"
    {
		fprintf(yyout,"DSVS R%d\n", rotulocorrente);
		fprintf(yyout,"R%d: NADA\n", desempilhaRotulo(rotulo));
		incrementaRotulo(rotulo,rotulocorrente);
		rotulocorrente++;		
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 362 "yacc.y"
    {
		decloop=1;
		incrementaRotulo(rotulo,rotulocorrente);
		fprintf(yyout,"R%d: NADA\n", rotulocorrente);
		rotulocorrente++;
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 369 "yacc.y"
    { fprintf(yyout,"DSVF R%d\n",rotulocorrente); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 371 "yacc.y"
    {
		fprintf(yyout,"DSVS R%d\n", desempilhaRotulo(rotulo));
		incrementaRotulo(rotulo,rotulocorrente);
		fprintf(yyout,"R%d: NADA\n", desempilhaRotulo(rotulo));
		rotulocorrente++;
		decloop=0;
	}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 384 "yacc.y"
    { fprintf(yyout,"%s",relacao); }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 395 "yacc.y"
    {fprintf(yyout,"SOMA\n");}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 396 "yacc.y"
    {fprintf(yyout,"SUBT\n");}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 397 "yacc.y"
    {fprintf(yyout,"DISJ\n");}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 398 "yacc.y"
    {fprintf(yyout,"SOMA\n");}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 399 "yacc.y"
    {fprintf(yyout,"SUBT\n");}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 400 "yacc.y"
    {fprintf(yyout,"DISJ\n");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 407 "yacc.y"
    {fprintf(yyout,"MULT\n");}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 408 "yacc.y"
    {fprintf(yyout,"DIVI\n");}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 409 "yacc.y"
    {fprintf(yyout,"CONJ\n");}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 410 "yacc.y"
    {fprintf(yyout,"MULT\n");}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 411 "yacc.y"
    {fprintf(yyout,"DIVI\n");}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 412 "yacc.y"
    {fprintf(yyout,"CONJ\n");}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 416 "yacc.y"
    {
		if ((escrita==0)&&(leitura==0)&&(buscaPassagem(ts,retorno)==VALOR)&&(chpr==0))
			fprintf(yyout,"CRVL %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno)); 
 		else if((escrita==0)&&(leitura==0)&&(buscaPassagem(ts,retorno)==REFERENCIA)&&(chpr==0))
			fprintf(yyout,"CRVI %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno)); 
		if (chpr==1)
		{
			if ((buscaPassagem(ts,retorno)==REFERENCIA)&&(buscaPassagemParam(ts,nomerotina,numpass)==VALOR))
				fprintf(yyout,"CRVI %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
			if ((buscaPassagem(ts,retorno)==VALOR)&&(buscaPassagemParam(ts,nomerotina,numpass)==VALOR))
				fprintf(yyout,"CRVL %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
			if ((buscaPassagem(ts,retorno)==VALOR)&&(buscaPassagemParam(ts,nomerotina,numpass)==REFERENCIA))
				fprintf(yyout,"CREN %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
			if ((buscaPassagem(ts,retorno)==REFERENCIA)&&(buscaPassagemParam(ts,nomerotina,numpass)==REFERENCIA))
				fprintf(yyout,"CRVL %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
			numpass++;
		}
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 435 "yacc.y"
    {
 		if ((escrita==0)&&(leitura==0))
			fprintf(yyout,"CRCT %d\n", num);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 442 "yacc.y"
    { fprintf(yyout,"NEGA\n"); }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 445 "yacc.y"
    {strcpy(relacao,"CMIG\n");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 446 "yacc.y"
    {strcpy(relacao,"CMDG\n");}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 447 "yacc.y"
    {strcpy(relacao,"CMEG\n");}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 448 "yacc.y"
    {strcpy(relacao,"CMAG\n");}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 449 "yacc.y"
    {strcpy(relacao,"CMME\n");}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 450 "yacc.y"
    {strcpy(relacao,"CMMA\n");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 457 "yacc.y"
    {
		strcpy(nomerotina,retorno);
		chpr=1;
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 462 "yacc.y"
    {	
		fprintf(yyout,"CHPR R%d,%d\n", buscaIdentificador(ts,nomerotina),nivlex);
		chpr=0;
		numpass=0;
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 471 "yacc.y"
    { 
		num=atoi(retorno);
		if (declabel==1 && buscaSimboloTS(ts,nivlex,retorno)==1)
		{
			novoSimbolo(ts);
			strcpy(ts->topo->ident,retorno);
			incrementaRotulo(rotulo, rotulocorrente);
			rotulocorrente++;
			ts->topo->tipo=LABGOTO;
			ts->topo->rotulo=rotulo->topo->label;
			ts->topo->nivlexico=nivlex;
		}
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 486 "yacc.y"
    {	
		if (decvar==1 && buscaSimboloTS(ts,nivlex,retorno)==1)
		{	
			novoSimbolo(ts);
			strcpy(ts->topo->ident,retorno);
			ts->topo->nivlexico=nivlex;
			ts->topo->deslocamento=numvar;
			ts->topo->tipo=VARIAVEL;
			numvar++;
		}
		if ((leitura==1) && (buscaPassagem(ts,retorno)==VALOR))
			fprintf(yyout,"LEIT\nARMZ %d,%d\n", buscaNivLexTS(ts,retorno), buscaDeslocamentoTS(ts,retorno));
		else if ((leitura==1) && (buscaPassagem(ts,retorno)==REFERENCIA))
			fprintf(yyout,"LEIT\nARMI %d,%d\n", buscaNivLexTS(ts,retorno), buscaDeslocamentoTS(ts,retorno));
		if ((escrita==1) && (buscaPassagem(ts,retorno)==VALOR))
			fprintf(yyout,"CRVL %d,%d\nIMPR\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts,retorno));
		else if(escrita==1 && (buscaPassagem(ts,retorno)==REFERENCIA))
			fprintf(yyout,"CRVI %d,%d\nIMPR\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
		if (decproc==1 && buscaSimboloTS(ts,nivlex,retorno)==1)
		{	
			fprintf(yyout,"R%d: NADA\n",rotulocorrente);
			incrementaRotulo(rotulo,rotulocorrente);
			nivlex++;
			fprintf(yyout,"ENPR %d\n", nivlex);
			novoSimbolo(ts);
			strcpy(ts->topo->ident,retorno);
			ts->topo->nivlexico=nivlex;
			ts->topo->rotulo=rotulocorrente;
			ts->topo->tipo=PROCEDIMENTO;
			rotulocorrente++;
			numpar=desempilhaRotulo(rotulo);
			numpar=0;
		}
		if (decfunc==1 && buscaSimboloTS(ts,nivlex,retorno)==1)
		{	
			fprintf(yyout,"R%d: NADA\n",rotulocorrente);
			incrementaRotulo(rotulo,rotulocorrente);
			nivlex++;
			fprintf(yyout,"ENPR %d\n", nivlex);
			novoSimbolo(ts);
			strcpy(ts->topo->ident,retorno);
			ts->topo->nivlexico=nivlex;
			ts->topo->rotulo=rotulocorrente;
			ts->topo->tipo=FUNCAO;
			rotulocorrente++;
			numpar=desempilhaRotulo(rotulo);
			numpar=0;
		}
		if ((parsubrotina==1)&&(passvalor==1))
		{
			numpar++;
			ts->topo->parametro.desloc[numpar-1]=-3-numpar;
			strcpy(ts->topo->parametro.ident[numpar-1],retorno);
			ts->topo->numparam=numpar;
			ts->topo->parametro.passagem[numpar-1]=VALOR;			
		}
		if ((parsubrotina==1)&&(passreferencia==1))
		{
			numpar++;
			ts->topo->parametro.desloc[numpar-1]=-3-numpar;
			strcpy(ts->topo->parametro.ident[numpar-1],retorno);
			ts->topo->numparam=numpar;
			ts->topo->parametro.passagem[numpar-1]=REFERENCIA;			
		}
	}
    break;



/* Line 1455 of yacc.c  */
#line 2365 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



