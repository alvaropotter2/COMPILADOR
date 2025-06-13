/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

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
#line 2 "ruby_parser.y"

// ----------------------------- GLOSARIO DE IMPORTS -------------------------------------------
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "tabla_simbolos_funciones.h"
#include "AST_ruby.h"

// ----------------------------- DECLARACION DE VARIABLES Y ESTRUCTURAS -------------------------------------------

//Declaracion de variables "extern" sirve para declararlas como variables globales
FILE *yyout;
extern FILE* yyin;
extern int yylex();
extern int num_linea; //Almacena el numero de linea durante la ejecucion
extern tSimbolos tabla[256];
extern int indice; //Se almacena el índice de la tabla de símbolos
char* tipos[] = {"integer", "float", "string", "boolean"}; //Para parsear el tipo que se detecta en flex al tipo del nodo

// Declaración de yyerror
void yyerror(const char* s);

// Función auxiliar para agregar parámetros a la tabla de símbolos
void agregarParametrosATabla(struct ast* parametros) {
    struct ast* actual = parametros;
    while (actual != NULL) {
        if (actual->tipo == NODO_PARAMETRO) {
            printf("Agregando parametro '%s' a la tabla de simbolos\n", actual->valor.stringVal);
            int pos = agregarSimbolo(actual->valor.stringVal, "integer"); // Por simplicidad, asumimos que son enteros
            if (pos != -1) {
                tabla[pos].inicializada = 1; // Marcar como inicializado
            }
        }
        actual = actual->siguiente;
    }
}


/* Line 189 of yacc.c  */
#line 113 "ruby_parser.tab.c"

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
     PLUS = 258,
     MINUS = 259,
     MULTIPLY = 260,
     DIVIDE = 261,
     ASSIGN = 262,
     PLUS_ASSIGN = 263,
     MINUS_ASSIGN = 264,
     EQUAL = 265,
     NOT_EQUAL = 266,
     LESS = 267,
     GREATER = 268,
     LESS_EQUAL = 269,
     GREATER_EQUAL = 270,
     LPAREN = 271,
     RPAREN = 272,
     LBRACE = 273,
     RBRACE = 274,
     LBRACKET = 275,
     RBRACKET = 276,
     COMMA = 277,
     IF = 278,
     ELSE = 279,
     ELSIF = 280,
     END = 281,
     WHILE = 282,
     FOR = 283,
     DO = 284,
     PUTS = 285,
     DEF = 286,
     RETURN = 287,
     TRUE = 288,
     FALSE = 289,
     AND = 290,
     OR = 291,
     NOT = 292,
     NEWLINE = 293,
     INTEGER = 294,
     FLOAT = 295,
     STRING = 296,
     IDENTIFIER = 297,
     COMMENT = 298,
     UMINUS = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 43 "ruby_parser.y"

  int intVal;
  float floatVal;
  char* stringVal;
  int boolVal;
  struct atributos{
    int integer;
    float floatDecimal;
    char* string;
    int boolean;
    char* tipo;             //Define el tipo que se esta usando
    struct ast *n;          //Para almacenar los nodos del AST
  }tr;



/* Line 214 of yacc.c  */
#line 210 "ruby_parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 222 "ruby_parser.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNRULES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    17,    19,
      23,    27,    30,    32,    33,    41,    42,    53,    55,    59,
      63,    67,    71,    75,    79,    83,    87,    90,    92,    94,
      96,    98,   102,   107,   111,   113,   115,   117,   119,   121,
     123,   127,   131,   135,   139,   143,   147,   151,   155,   159,
     162,   169,   179
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    -1,    47,    48,    -1,
      53,    38,    -1,    59,    -1,    60,    -1,    49,    -1,    30,
      54,    38,    -1,    32,    54,    38,    -1,    54,    38,    -1,
      38,    -1,    -1,    31,    42,    38,    50,    47,    26,    38,
      -1,    -1,    31,    42,    16,    52,    17,    38,    51,    47,
      26,    38,    -1,    42,    -1,    52,    22,    42,    -1,    42,
       7,    54,    -1,    42,     8,    54,    -1,    42,     9,    54,
      -1,    54,     3,    56,    -1,    54,     4,    56,    -1,    54,
       5,    56,    -1,    54,     6,    56,    -1,     4,    54,    -1,
      56,    -1,    57,    -1,    58,    -1,    54,    -1,    55,    22,
      54,    -1,    42,    16,    55,    17,    -1,    42,    16,    17,
      -1,    39,    -1,    40,    -1,    41,    -1,    33,    -1,    34,
      -1,    42,    -1,    16,    54,    17,    -1,    54,    12,    54,
      -1,    54,    13,    54,    -1,    54,    10,    54,    -1,    54,
      11,    54,    -1,    54,    14,    54,    -1,    54,    15,    54,
      -1,    54,    35,    54,    -1,    54,    36,    54,    -1,    37,
      54,    -1,    23,    54,    38,    47,    26,    38,    -1,    23,
      54,    38,    47,    24,    38,    47,    26,    38,    -1,    27,
      54,    38,    47,    26,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    99,   100,   107,   108,   109,   110,   111,
     115,   119,   120,   125,   125,   137,   137,   154,   158,   168,
     200,   212,   228,   250,   264,   278,   300,   312,   313,   314,
     318,   321,   329,   342,   355,   361,   367,   373,   379,   385,
     417,   424,   434,   444,   456,   466,   476,   490,   498,   506,
     518,   526,   537
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "EQUAL", "NOT_EQUAL", "LESS",
  "GREATER", "LESS_EQUAL", "GREATER_EQUAL", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "COMMA", "IF", "ELSE", "ELSIF", "END",
  "WHILE", "FOR", "DO", "PUTS", "DEF", "RETURN", "TRUE", "FALSE", "AND",
  "OR", "NOT", "NEWLINE", "INTEGER", "FLOAT", "STRING", "IDENTIFIER",
  "COMMENT", "UMINUS", "$accept", "P", "S", "D", "F", "$@1", "$@2",
  "lista_parametros", "A", "E", "lista_argumentos", "T", "R", "L", "I",
  "B", 0
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
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    50,    49,    51,    49,    52,    52,    53,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      59,    59,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     3,
       3,     2,     1,     0,     7,     0,    10,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     1,
       1,     3,     4,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       6,     9,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    37,    38,
       0,    12,    34,    35,    36,    39,     0,     2,     3,     8,
       0,     0,    27,    28,    29,     6,     7,    39,    26,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       1,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    40,     0,     0,     9,
       0,    13,    10,    19,    20,    21,    33,    30,     0,    22,
      23,    24,    25,    43,    44,    41,    42,    45,    46,    47,
      48,     0,     0,    17,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    50,    52,    15,    18,
       0,     0,     0,    14,     0,     0,    51,     0,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    85,   102,    84,    20,    21,
      68,    22,    23,    24,    25,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int16 yypact[] =
{
     170,   190,   190,   190,   190,   190,   -33,   190,   -41,   -41,
     190,   -41,   -41,   -41,   -41,    63,    27,   170,   -41,   -41,
      -9,   241,   -41,   -41,   -41,   -41,   -41,    30,   -41,   352,
     254,   290,   303,   -10,   339,   -41,   190,   190,   190,   201,
     -41,   -41,   -41,    -8,    -8,    -8,    -8,   190,   190,   190,
     190,   190,   190,   190,   190,   -41,   -41,   170,   170,   -41,
      14,   -41,   -41,   379,   379,   379,   -41,   379,    -6,   -41,
     -41,   -41,   -41,    54,    54,    37,    37,    37,    37,   392,
       9,    59,    90,   -41,    13,   170,   -41,   190,    23,    35,
      36,    39,    38,   110,   379,   170,   -41,   -41,   -41,   -41,
      40,   130,   170,   -41,    43,   150,   -41,    57,   -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -40,   -17,   -41,   -41,   -41,   -41,   -41,     0,
     -41,    64,   -41,   -41,   -41,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    28,    29,    30,    31,    32,    60,    34,     2,    33,
      35,    86,    43,    44,    45,    46,    87,    81,    82,    47,
      48,    49,    50,    51,    52,     8,     9,    40,    61,    42,
      91,    12,    13,    14,    27,    92,    63,    64,    65,    67,
      43,    44,    45,    46,    53,    93,    39,    73,    74,    75,
      76,    77,    78,    79,    80,   101,    83,    43,    44,    45,
      46,    95,   105,     1,    41,    41,    49,    50,    51,    52,
      36,    37,    38,    96,    97,     2,    41,    98,   103,    39,
      99,   106,     3,    88,    41,    89,     4,    94,    41,     5,
       6,     7,     8,     9,     1,   108,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     2,    69,    70,    71,
      72,     0,     0,     3,     1,     0,    90,     4,     0,     0,
       5,     6,     7,     8,     9,     0,     2,    10,    11,    12,
      13,    14,    15,     3,     1,     0,   100,     4,     0,     0,
       5,     6,     7,     8,     9,     0,     2,    10,    11,    12,
      13,    14,    15,     3,     1,     0,   104,     4,     0,     0,
       5,     6,     7,     8,     9,     0,     2,    10,    11,    12,
      13,    14,    15,     3,     1,     0,   107,     4,     0,     0,
       5,     6,     7,     8,     9,     0,     2,    10,    11,    12,
      13,    14,    15,     3,     1,     0,     0,     4,     0,     0,
       5,     6,     7,     8,     9,     1,     2,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     2,    66,     0,
       0,     0,     0,     8,     9,     0,     0,    10,     0,    12,
      13,    14,    27,     0,     8,     9,     0,     0,    10,     0,
      12,    13,    14,    27,    43,    44,    45,    46,     0,     0,
       0,    47,    48,    49,    50,    51,    52,    43,    44,    45,
      46,     0,     0,     0,    47,    48,    49,    50,    51,    52,
       0,     0,     0,     0,     0,     0,    53,    54,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,     0,    57,    43,    44,    45,    46,     0,     0,     0,
      47,    48,    49,    50,    51,    52,    43,    44,    45,    46,
       0,     0,     0,    47,    48,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,    53,    54,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
       0,    59,    43,    44,    45,    46,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    43,    44,    45,    46,     0,
       0,     0,    47,    48,    49,    50,    51,    52,     0,    56,
       0,     0,     0,     0,    53,    54,     0,    62,     0,     0,
       0,     0,    43,    44,    45,    46,     0,    53,    54,    47,
      48,    49,    50,    51,    52,    43,    44,    45,    46,     0,
       0,     0,    47,    48,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,    53,    54
};

static const yytype_int8 yycheck[] =
{
      17,     1,     2,     3,     4,     5,    16,     7,    16,    42,
      10,    17,     3,     4,     5,     6,    22,    57,    58,    10,
      11,    12,    13,    14,    15,    33,    34,     0,    38,    38,
      17,    39,    40,    41,    42,    22,    36,    37,    38,    39,
       3,     4,     5,     6,    35,    85,    16,    47,    48,    49,
      50,    51,    52,    53,    54,    95,    42,     3,     4,     5,
       6,    38,   102,     4,    81,    82,    12,    13,    14,    15,
       7,     8,     9,    38,    38,    16,    93,    38,    38,    16,
      42,    38,    23,    24,   101,    26,    27,    87,   105,    30,
      31,    32,    33,    34,     4,    38,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    16,    43,    44,    45,
      46,    -1,    -1,    23,     4,    -1,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    16,    37,    38,    39,
      40,    41,    42,    23,     4,    -1,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    16,    37,    38,    39,
      40,    41,    42,    23,     4,    -1,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    16,    37,    38,    39,
      40,    41,    42,    23,     4,    -1,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    16,    37,    38,    39,
      40,    41,    42,    23,     4,    -1,    -1,    27,    -1,    -1,
      30,    31,    32,    33,    34,     4,    16,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    37,    -1,    39,
      40,    41,    42,    -1,    33,    34,    -1,    -1,    37,    -1,
      39,    40,    41,    42,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    38,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    38,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    -1,    -1,    35,    36,    -1,    38,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    35,    36,    10,
      11,    12,    13,    14,    15,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    16,    23,    27,    30,    31,    32,    33,    34,
      37,    38,    39,    40,    41,    42,    46,    47,    48,    49,
      53,    54,    56,    57,    58,    59,    60,    42,    54,    54,
      54,    54,    54,    42,    54,    54,     7,     8,     9,    16,
       0,    48,    38,     3,     4,     5,     6,    10,    11,    12,
      13,    14,    15,    35,    36,    38,    17,    38,    38,    38,
      16,    38,    38,    54,    54,    54,    17,    54,    55,    56,
      56,    56,    56,    54,    54,    54,    54,    54,    54,    54,
      54,    47,    47,    42,    52,    50,    17,    22,    24,    26,
      26,    17,    22,    47,    54,    38,    38,    38,    38,    42,
      26,    47,    51,    38,    26,    47,    38,    26,    38
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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

/* Line 1464 of yacc.c  */
#line 91 "ruby_parser.y"
    {
        comprobarAST((yyvsp[(1) - (1)].tr).n); 
        printf("\n[COMPILACION FINALIZADA]\n");     
    ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 100 "ruby_parser.y"
    { 
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (2)].tr).n, (yyvsp[(2) - (2)].tr).n, NODO_SECUENCIA);
    ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 111 "ruby_parser.y"
    {
        printf("> [SENTENCIA] - PUTS\n");
        (yyval.tr).n = crearNodoPuts((yyvsp[(2) - (3)].tr).n);
    ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 115 "ruby_parser.y"
    {
        printf("> [SENTENCIA] - RETURN\n");
        (yyval.tr).n = crearNodoUnario((yyvsp[(2) - (3)].tr).n, NODO_RETURN);
    ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 120 "ruby_parser.y"
    { (yyval.tr).n = crearNodoVacio(); ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 125 "ruby_parser.y"
    {
        printf("> [FUNCION] - Definicion de funcion sin parametros: %s\n", (yyvsp[(2) - (3)].stringVal));
        // Agregar función a la tabla ANTES de procesar el cuerpo
        agregarFuncion((yyvsp[(2) - (3)].stringVal), NULL, NULL);
    ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 129 "ruby_parser.y"
    {
        (yyval.tr).n = crearNodoFuncion((yyvsp[(2) - (7)].stringVal), NULL, (yyvsp[(5) - (7)].tr).n);
        // Actualizar el cuerpo de la función en la tabla
        int pos = buscarFuncion((yyvsp[(2) - (7)].stringVal));
        if (pos != -1) {
            tablaFunciones[pos].cuerpo = (yyvsp[(5) - (7)].tr).n;
        }
    ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 137 "ruby_parser.y"
    {
        printf("> [FUNCION] - Definicion de funcion con parametros: %s\n", (yyvsp[(2) - (6)].stringVal));
        // Agregar función a la tabla ANTES de procesar el cuerpo
        agregarFuncion((yyvsp[(2) - (6)].stringVal), (yyvsp[(4) - (6)].tr).n, NULL);
        // Agregar parámetros a la tabla de símbolos ANTES de procesar el cuerpo
        agregarParametrosATabla((yyvsp[(4) - (6)].tr).n);
    ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 143 "ruby_parser.y"
    {
        (yyval.tr).n = crearNodoFuncion((yyvsp[(2) - (10)].stringVal), (yyvsp[(4) - (10)].tr).n, (yyvsp[(8) - (10)].tr).n);
        // Actualizar el cuerpo de la función en la tabla
        int pos = buscarFuncion((yyvsp[(2) - (10)].stringVal));
        if (pos != -1) {
            tablaFunciones[pos].cuerpo = (yyvsp[(8) - (10)].tr).n;
        }
    ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 154 "ruby_parser.y"
    {
        printf("> [PARAMETRO] - %s\n", (yyvsp[(1) - (1)].stringVal));
        (yyval.tr).n = crearNodoParametro((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 158 "ruby_parser.y"
    {
        printf("> [PARAMETRO] - %s\n", (yyvsp[(3) - (3)].stringVal));
        struct ast* param = crearNodoParametro((yyvsp[(3) - (3)].stringVal));
        param->siguiente = (yyvsp[(1) - (3)].tr).n;
        (yyval.tr).n = param;
    ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 168 "ruby_parser.y"
    {
        printf("> [SENTENCIA] - Asignacion Simple\n");
        
        //Para crear un nuevo simbolo de tipo integer
        if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){ 
            printf("Asignado el valor %d a la variable %s\n",(yyvsp[(3) - (3)].tr).integer, (yyvsp[(1) - (3)].stringVal));
            tabla[indice].nombre = (yyvsp[(1) - (3)].stringVal); 
            tabla[indice].tipo = tipos[0]; 
            tabla[indice].integer = (yyvsp[(3) - (3)].tr).integer; 
            tabla[indice].registro = (yyvsp[(3) - (3)].tr).n->resultado;
            indice++; 
        }
        //Para crear un nuevo simbolo de tipo float
        else if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){ 
            printf("Asignado el valor %.2f a la variable %s\n",(yyvsp[(3) - (3)].tr).floatDecimal, (yyvsp[(1) - (3)].stringVal));
            tabla[indice].nombre = (yyvsp[(1) - (3)].stringVal); 
            tabla[indice].tipo = tipos[1]; 
            tabla[indice].floatDecimal = (yyvsp[(3) - (3)].tr).floatDecimal; 
            tabla[indice].registro = (yyvsp[(3) - (3)].tr).n->resultado;
            indice++; 
        }
        //Para crear un nuevo simbolo de tipo string
        else if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){ 
            printf("Asignado el valor %s a la variable %s\n",(yyvsp[(3) - (3)].tr).string, (yyvsp[(1) - (3)].stringVal));
            tabla[indice].nombre = (yyvsp[(1) - (3)].stringVal); 
            tabla[indice].tipo = tipos[2]; 
            tabla[indice].string = (yyvsp[(3) - (3)].tr).string; 
            tabla[indice].registro = (yyvsp[(3) - (3)].tr).n->resultado;
            indice++; 
        }
        (yyval.tr).n = crearNodoAsignacion((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].tr).n);
    ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 200 "ruby_parser.y"
    {
        printf("> [SENTENCIA] - Asignacion con Suma\n");
        int pos = buscarTabla(indice, (yyvsp[(1) - (3)].stringVal), tabla);
        if(pos != -1 && strcmp(tabla[pos].tipo, (yyvsp[(3) - (3)].tr).tipo) == 0) {
            if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
                tabla[pos].integer += (yyvsp[(3) - (3)].tr).integer;
            } else if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0) {
                tabla[pos].floatDecimal += (yyvsp[(3) - (3)].tr).floatDecimal;
            }
        }
        (yyval.tr).n = crearNodoAsignacionCompuesta((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].tr).n, SUMA);
    ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 212 "ruby_parser.y"
    {
        printf("> [SENTENCIA] - Asignacion con Resta\n");
        int pos = buscarTabla(indice, (yyvsp[(1) - (3)].stringVal), tabla);
        if(pos != -1 && strcmp(tabla[pos].tipo, (yyvsp[(3) - (3)].tr).tipo) == 0) {
            if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
                tabla[pos].integer -= (yyvsp[(3) - (3)].tr).integer;
            } else if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0) {
                tabla[pos].floatDecimal -= (yyvsp[(3) - (3)].tr).floatDecimal;
            }
        }
        (yyval.tr).n = crearNodoAsignacionCompuesta((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].tr).n, RESTA);
    ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 228 "ruby_parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            printf("> [OPERACION] - SUMA {integer + integer}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, SUMA); 
            (yyval.tr).tipo = tipos[0]; 
            (yyval.tr).integer = (yyvsp[(1) - (3)].tr).integer + (yyvsp[(3) - (3)].tr).integer;      
        }
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){
            printf("> [OPERACION] - SUMA {float + float}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, SUMA);
            (yyval.tr).tipo = tipos[1]; 
            (yyval.tr).floatDecimal = (yyvsp[(1) - (3)].tr).floatDecimal + (yyvsp[(3) - (3)].tr).floatDecimal;
        }  
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){
            printf("> [OPERACION] - CONCATENACION {string + string}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, CONCATENACION);
            (yyval.tr).tipo = tipos[2];
            (yyval.tr).string = malloc(strlen((yyvsp[(1) - (3)].tr).string) + strlen((yyvsp[(3) - (3)].tr).string) + 1);
            strcpy((yyval.tr).string, (yyvsp[(1) - (3)].tr).string);
            strcat((yyval.tr).string, (yyvsp[(3) - (3)].tr).string);
        }
    ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 250 "ruby_parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            printf("> [OPERACION] - RESTA {integer - integer}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, RESTA);
            (yyval.tr).tipo = tipos[0]; 
            (yyval.tr).integer = (yyvsp[(1) - (3)].tr).integer - (yyvsp[(3) - (3)].tr).integer;
        }
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){
            printf("> [OPERACION] - RESTA {float - float}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, RESTA);
            (yyval.tr).tipo = tipos[1]; 
            (yyval.tr).floatDecimal = (yyvsp[(1) - (3)].tr).floatDecimal - (yyvsp[(3) - (3)].tr).floatDecimal;
        }
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 264 "ruby_parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            printf("> [OPERACION] - MULTIPLICACION {integer * integer}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, MULTIPLICACION);
            (yyval.tr).tipo = tipos[0]; 
            (yyval.tr).integer = (yyvsp[(1) - (3)].tr).integer * (yyvsp[(3) - (3)].tr).integer;
        }
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){
            printf("> [OPERACION] - MULTIPLICACION {float * float}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, MULTIPLICACION);
            (yyval.tr).tipo = tipos[1]; 
            (yyval.tr).floatDecimal = (yyvsp[(1) - (3)].tr).floatDecimal * (yyvsp[(3) - (3)].tr).floatDecimal;
        }
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 278 "ruby_parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            if((yyvsp[(3) - (3)].tr).integer != 0) {
                printf("> [OPERACION] - DIVISION {integer / integer}\n");
                (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, DIVISION);
                (yyval.tr).tipo = tipos[0]; 
                (yyval.tr).integer = (yyvsp[(1) - (3)].tr).integer / (yyvsp[(3) - (3)].tr).integer;
            } else {
                yyerror("Error: Division por cero");
            }
        }
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){
            if((yyvsp[(3) - (3)].tr).floatDecimal != 0.0) {
                printf("> [OPERACION] - DIVISION {float / float}\n");
                (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, DIVISION);
                (yyval.tr).tipo = tipos[1]; 
                (yyval.tr).floatDecimal = (yyvsp[(1) - (3)].tr).floatDecimal / (yyvsp[(3) - (3)].tr).floatDecimal;
            } else {
                yyerror("Error: Division por cero");
            }
        }
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 300 "ruby_parser.y"
    {
        printf("> [OPERACION] - NEGACION UNARIA\n");
        if (strcmp((yyvsp[(2) - (2)].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).n = crearNodoUnario((yyvsp[(2) - (2)].tr).n, NEGACION);
            (yyval.tr).tipo = tipos[0]; 
            (yyval.tr).integer = -(yyvsp[(2) - (2)].tr).integer;
        } else if (strcmp((yyvsp[(2) - (2)].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).n = crearNodoUnario((yyvsp[(2) - (2)].tr).n, NEGACION);
            (yyval.tr).tipo = tipos[1]; 
            (yyval.tr).floatDecimal = -(yyvsp[(2) - (2)].tr).floatDecimal;
        }
    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 312 "ruby_parser.y"
    { (yyval.tr) = (yyvsp[(1) - (1)].tr); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 313 "ruby_parser.y"
    { (yyval.tr) = (yyvsp[(1) - (1)].tr); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 314 "ruby_parser.y"
    { (yyval.tr) = (yyvsp[(1) - (1)].tr); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 318 "ruby_parser.y"
    {
        (yyval.tr).n = (yyvsp[(1) - (1)].tr).n;
    ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 321 "ruby_parser.y"
    {
        (yyvsp[(3) - (3)].tr).n->siguiente = (yyvsp[(1) - (3)].tr).n;
        (yyval.tr).n = (yyvsp[(3) - (3)].tr).n;
    ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 329 "ruby_parser.y"
    {
        printf("> [LLAMADA] - Llamada a funcion: %s\n", (yyvsp[(1) - (4)].stringVal));
        int pos = buscarFuncion((yyvsp[(1) - (4)].stringVal));
        if(pos != -1) {
            (yyval.tr).n = crearNodoLlamadaFuncion((yyvsp[(1) - (4)].stringVal), (yyvsp[(3) - (4)].tr).n);
            (yyval.tr).tipo = tipos[0]; // Por simplicidad, asumimos que devuelve entero
            (yyval.tr).integer = 0; // Valor por defecto
        } else {
            char error_msg[100];
            sprintf(error_msg, "Funcion '%s' no declarada", (yyvsp[(1) - (4)].stringVal));
            yyerror(error_msg);
        }
    ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 342 "ruby_parser.y"
    {
        printf("> [LLAMADA] - Llamada a funcion sin argumentos: %s\n", (yyvsp[(1) - (3)].stringVal));
        int pos = buscarFuncion((yyvsp[(1) - (3)].stringVal));
        if(pos != -1) {
            (yyval.tr).n = crearNodoLlamadaFuncion((yyvsp[(1) - (3)].stringVal), NULL);
            (yyval.tr).tipo = tipos[0]; // Por simplicidad, asumimos que devuelve entero
            (yyval.tr).integer = 0; // Valor por defecto
        } else {
            char error_msg[100];
            sprintf(error_msg, "Funcion '%s' no declarada", (yyvsp[(1) - (3)].stringVal));
            yyerror(error_msg);
        }
    ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 355 "ruby_parser.y"
    {
        (yyval.tr).integer = (yyvsp[(1) - (1)].intVal);
        printf("> [TIPO] - INTEGER: %d\n", (yyval.tr).integer);
        (yyval.tr).n = crearNodoTerminal((yyvsp[(1) - (1)].intVal)); 
        (yyval.tr).tipo = tipos[0]; 
    ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 361 "ruby_parser.y"
    {
        (yyval.tr).floatDecimal = (yyvsp[(1) - (1)].floatVal);
        printf("> [TIPO] - FLOAT: %.2f\n", (yyval.tr).floatDecimal); 
        (yyval.tr).n = crearNodoTerminalFloat((yyvsp[(1) - (1)].floatVal)); 
        (yyval.tr).tipo = tipos[1];  
    ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 367 "ruby_parser.y"
    {
        (yyval.tr).string = (yyvsp[(1) - (1)].stringVal);
        printf("> [TIPO] - STRING: %s\n", (yyval.tr).string); 
        (yyval.tr).n = crearNodoTerminalString((yyvsp[(1) - (1)].stringVal)); 
        (yyval.tr).tipo = tipos[2];  
    ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 373 "ruby_parser.y"
    {
        (yyval.tr).boolean = 1;
        printf("> [TIPO] - BOOLEAN: true\n"); 
        (yyval.tr).n = crearNodoTerminalBool(1); 
        (yyval.tr).tipo = tipos[3];  
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 379 "ruby_parser.y"
    {
        (yyval.tr).boolean = 0;
        printf("> [TIPO] - BOOLEAN: false\n"); 
        (yyval.tr).n = crearNodoTerminalBool(0); 
        (yyval.tr).tipo = tipos[3];  
    ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 385 "ruby_parser.y"
    {
        printf("> [TIPO] - IDENTIFICADOR: %s\n",(yyvsp[(1) - (1)].stringVal));
        
        // Buscar como variable en la tabla de símbolos
        int pos = buscarTabla(indice, (yyvsp[(1) - (1)].stringVal), tabla);
        if(pos != -1){     
            if(strcmp(tabla[pos].tipo, tipos[0]) == 0){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).integer = tabla[pos].integer; 
                (yyval.tr).n = crearVariableTerminal(&tabla[pos].integer, tabla[pos].registro);   
            }
            else if(strcmp(tabla[pos].tipo, tipos[1]) == 0){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).floatDecimal = tabla[pos].floatDecimal;
                (yyval.tr).n = crearVariableTerminal(&tabla[pos].floatDecimal, tabla[pos].registro);       
            }
            else if(strcmp(tabla[pos].tipo, tipos[2]) == 0){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).string = tabla[pos].string;
                (yyval.tr).n = crearVariableTerminal(tabla[pos].string, tabla[pos].registro);       
            }
            else if(strcmp(tabla[pos].tipo, tipos[3]) == 0){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).boolean = tabla[pos].boolean;
                (yyval.tr).n = crearVariableTerminal(&tabla[pos].boolean, tabla[pos].registro);       
            }
        } else {
            char error_msg[100];
            sprintf(error_msg, "Variable '%s' no declarada", (yyvsp[(1) - (1)].stringVal));
            yyerror(error_msg);
        }
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 417 "ruby_parser.y"
    {
        (yyval.tr) = (yyvsp[(2) - (3)].tr);
    ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 424 "ruby_parser.y"
    {
        printf("> [OPERACION] - MENOR QUE\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, MENOR_QUE);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).integer < (yyvsp[(3) - (3)].tr).integer;
        } else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).floatDecimal < (yyvsp[(3) - (3)].tr).floatDecimal;
        }
    ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 434 "ruby_parser.y"
    {
        printf("> [OPERACION] - MAYOR QUE\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, MAYOR_QUE);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).integer > (yyvsp[(3) - (3)].tr).integer;
        } else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).floatDecimal > (yyvsp[(3) - (3)].tr).floatDecimal;
        }
    ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 444 "ruby_parser.y"
    {
        printf("> [OPERACION] - IGUAL A\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, IGUAL);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).integer == (yyvsp[(3) - (3)].tr).integer;
        } else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).floatDecimal == (yyvsp[(3) - (3)].tr).floatDecimal;
        } else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0) {
            (yyval.tr).boolean = strcmp((yyvsp[(1) - (3)].tr).string, (yyvsp[(3) - (3)].tr).string) == 0;
        }
    ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 456 "ruby_parser.y"
    {
        printf("> [OPERACION] - DIFERENTE A\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, DIFERENTE);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).integer != (yyvsp[(3) - (3)].tr).integer;
        } else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).floatDecimal != (yyvsp[(3) - (3)].tr).floatDecimal;
        }
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 466 "ruby_parser.y"
    {
        printf("> [OPERACION] - MENOR O IGUAL QUE\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, MENOR_IGUAL);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).integer <= (yyvsp[(3) - (3)].tr).integer;
        } else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).floatDecimal <= (yyvsp[(3) - (3)].tr).floatDecimal;
        }
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 476 "ruby_parser.y"
    {
        printf("> [OPERACION] - MAYOR O IGUAL QUE\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, MAYOR_IGUAL);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).integer >= (yyvsp[(3) - (3)].tr).integer;
        } else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).floatDecimal >= (yyvsp[(3) - (3)].tr).floatDecimal;
        }
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 490 "ruby_parser.y"
    {
        printf("> [OPERACION] - AND LOGICO\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, AND_LOGICO);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[3]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).boolean && (yyvsp[(3) - (3)].tr).boolean;
        }
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 498 "ruby_parser.y"
    {
        printf("> [OPERACION] - OR LOGICO\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, OR_LOGICO);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[3]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).boolean = (yyvsp[(1) - (3)].tr).boolean || (yyvsp[(3) - (3)].tr).boolean;
        }
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 506 "ruby_parser.y"
    {
        printf("> [OPERACION] - NOT LOGICO\n");
        (yyval.tr).n = crearNodoUnario((yyvsp[(2) - (2)].tr).n, NOT_LOGICO);
        (yyval.tr).tipo = tipos[3];
        if (strcmp((yyvsp[(2) - (2)].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).boolean = !(yyvsp[(2) - (2)].tr).boolean;
        }
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 518 "ruby_parser.y"
    {
        printf("> [SENTENCIA] - IF\n");
        if (strcmp((yyvsp[(2) - (6)].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).n = crearNodoCondicional((yyvsp[(2) - (6)].tr).n, (yyvsp[(4) - (6)].tr).n, NULL);
        } else {
            yyerror("Error: La condicion del IF debe ser booleana");
        }
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 526 "ruby_parser.y"
    {
        printf("> [SENTENCIA] - IF-ELSE\n");
        if (strcmp((yyvsp[(2) - (9)].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).n = crearNodoCondicional((yyvsp[(2) - (9)].tr).n, (yyvsp[(4) - (9)].tr).n, (yyvsp[(7) - (9)].tr).n);
        } else {
            yyerror("Error: La condicion del IF debe ser booleana");
        }
    ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 537 "ruby_parser.y"
    {
        printf("> [SENTENCIA] - WHILE\n");
        if (strcmp((yyvsp[(2) - (6)].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).n = crearNodoBucle((yyvsp[(2) - (6)].tr).n, (yyvsp[(4) - (6)].tr).n);
        } else {
            yyerror("Error: La condicion del WHILE debe ser booleana");
        }
    ;}
    break;



/* Line 1464 of yacc.c  */
#line 2250 "ruby_parser.tab.c"
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



/* Line 1684 of yacc.c  */
#line 547 "ruby_parser.y"
 

//--------------------------------------------------- METODO MAIN -----------------------------------------------
int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Uso: %s <archivo.rb>\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "rt");
    if(!yyin) {
        fprintf(stderr, "Error: No se puede abrir el archivo %s\n", argv[1]);
        return 1;
    }
    
    yyout = fopen("./ruby.asm", "wt");
    if(!yyout) {
        fprintf(stderr, "Error: No se puede crear el archivo de salida\n");
        fclose(yyin);
        return 1;
    }
    
    printf("Iniciando compilacion de %s...\n", argv[1]);
    int result = yyparse();
    
    fclose(yyin);
    fclose(yyout);
    
    if(result == 0) {
        printf("Compilacion exitosa. Codigo MIPS generado en ruby.asm\n");
    } else {
        printf("Error en la compilacion\n");
    }
    
    return result;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error en linea %d: %s\n", num_linea, s);
}
