/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ruby_parser.y"

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
extern FILE *yyout;
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

#line 111 "ruby_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "ruby_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MULTIPLY = 5,                   /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 6,                     /* DIVIDE  */
  YYSYMBOL_ASSIGN = 7,                     /* ASSIGN  */
  YYSYMBOL_PLUS_ASSIGN = 8,                /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 9,               /* MINUS_ASSIGN  */
  YYSYMBOL_EQUAL = 10,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 11,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS = 12,                      /* LESS  */
  YYSYMBOL_GREATER = 13,                   /* GREATER  */
  YYSYMBOL_LESS_EQUAL = 14,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 15,             /* GREATER_EQUAL  */
  YYSYMBOL_LPAREN = 16,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 17,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 20,                  /* LBRACKET  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_ELSIF = 24,                     /* ELSIF  */
  YYSYMBOL_END = 25,                       /* END  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_DO = 28,                        /* DO  */
  YYSYMBOL_PUTS = 29,                      /* PUTS  */
  YYSYMBOL_DEF = 30,                       /* DEF  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_TRUE = 32,                      /* TRUE  */
  YYSYMBOL_FALSE = 33,                     /* FALSE  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_NEWLINE = 37,                   /* NEWLINE  */
  YYSYMBOL_INTEGER = 38,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 39,                     /* FLOAT  */
  YYSYMBOL_STRING = 40,                    /* STRING  */
  YYSYMBOL_IDENTIFIER = 41,                /* IDENTIFIER  */
  YYSYMBOL_COMMENT = 42,                   /* COMMENT  */
  YYSYMBOL_UMINUS = 43,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_P = 45,                         /* P  */
  YYSYMBOL_S = 46,                         /* S  */
  YYSYMBOL_D = 47,                         /* D  */
  YYSYMBOL_F = 48,                         /* F  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_lista_parametros = 51,          /* lista_parametros  */
  YYSYMBOL_A = 52,                         /* A  */
  YYSYMBOL_E = 53,                         /* E  */
  YYSYMBOL_lista_argumentos = 54,          /* lista_argumentos  */
  YYSYMBOL_T = 55,                         /* T  */
  YYSYMBOL_R = 56,                         /* R  */
  YYSYMBOL_L = 57,                         /* L  */
  YYSYMBOL_I = 58,                         /* I  */
  YYSYMBOL_B = 59                          /* B  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,   100,   101,   108,   109,   110,   111,   112,
     116,   120,   121,   126,   126,   138,   138,   155,   159,   169,
     237,   249,   265,   287,   301,   315,   337,   349,   350,   351,
     355,   358,   366,   379,   392,   398,   404,   410,   416,   422,
     457,   464,   474,   484,   496,   506,   516,   530,   538,   546,
     558,   566,   577
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "EQUAL",
  "NOT_EQUAL", "LESS", "GREATER", "LESS_EQUAL", "GREATER_EQUAL", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "COMMA", "IF", "ELSE", "ELSIF",
  "END", "WHILE", "FOR", "DO", "PUTS", "DEF", "RETURN", "TRUE", "FALSE",
  "AND", "OR", "NOT", "NEWLINE", "INTEGER", "FLOAT", "STRING",
  "IDENTIFIER", "COMMENT", "UMINUS", "$accept", "P", "S", "D", "F", "$@1",
  "$@2", "lista_parametros", "A", "E", "lista_argumentos", "T", "R", "L",
  "I", "B", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     217,   247,   247,   247,   247,   247,   -33,   247,   -41,   -41,
     247,   -41,   -41,   -41,   -41,    65,    11,   217,   -41,   -41,
     -21,     9,   -41,   -41,   -41,   -41,   -41,    12,   -41,   382,
     286,   299,   334,   -10,   347,   -41,   247,   247,   247,   228,
     -41,   -41,   -41,    -7,    -7,    -7,    -7,   247,   247,   247,
     247,   247,   247,   247,   247,   -41,   -41,   217,   217,   -41,
     -12,   -41,   -41,   397,   397,   397,   -41,   397,    58,   -41,
     -41,   -41,   -41,    54,    54,   106,   106,   106,   106,   430,
     415,    67,    97,   -41,    61,   217,   -41,   247,    -2,     3,
       4,     5,   -11,   127,   397,   217,   -41,   -41,   -41,   -41,
      19,   157,   217,   -41,    24,   187,   -41,    26,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -40,   -17,   -41,   -41,   -41,   -41,   -41,     0,
     -41,    71,   -41,   -41,   -41,   -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    16,    17,    18,    19,    85,   102,    84,    20,    21,
      68,    22,    23,    24,    25,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      41,    28,    29,    30,    31,    32,    60,    34,    33,     2,
      35,    40,    43,    44,    45,    46,    42,    81,    82,    47,
      48,    49,    50,    51,    52,     8,     9,    61,    39,    83,
      99,    12,    13,    14,    27,    95,    63,    64,    65,    67,
      96,    97,    98,    53,    54,    93,    55,    73,    74,    75,
      76,    77,    78,    79,    80,   101,   103,    43,    44,    45,
      46,   106,   105,   108,    41,    41,    49,    50,    51,    52,
       0,     1,    36,    37,    38,    86,    41,     0,    91,    87,
       0,    39,    92,     2,    41,     0,     0,    94,    41,     3,
      88,     0,    89,     4,     0,     0,     5,     6,     7,     8,
       9,     1,     0,    10,    11,    12,    13,    14,    15,    43,
      44,    45,    46,     2,    69,    70,    71,    72,     0,     3,
       0,     0,    90,     4,     0,     0,     5,     6,     7,     8,
       9,     1,     0,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     3,
       0,     0,   100,     4,     0,     0,     5,     6,     7,     8,
       9,     1,     0,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     3,
       0,     0,   104,     4,     0,     0,     5,     6,     7,     8,
       9,     1,     0,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     3,
       0,     0,   107,     4,     0,     0,     5,     6,     7,     8,
       9,     1,     0,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     1,     2,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     4,     2,    66,     5,     6,     7,     8,
       9,     1,     0,    10,    11,    12,    13,    14,    15,     0,
       8,     9,     0,     2,    10,     0,    12,    13,    14,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,     0,     0,    10,     0,    12,    13,    14,    27,    43,
      44,    45,    46,     0,     0,     0,    47,    48,    49,    50,
      51,    52,    43,    44,    45,    46,     0,     0,     0,    47,
      48,    49,    50,    51,    52,     0,     0,     0,     0,     0,
      53,    54,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,     0,    58,    43,    44,    45,
      46,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      43,    44,    45,    46,     0,     0,     0,    47,    48,    49,
      50,    51,    52,     0,     0,     0,     0,     0,    53,    54,
       0,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,     0,    62,    43,    44,    45,    46,     0,
       0,     0,    47,    48,    49,    50,    51,    52,     0,    56,
      43,    44,    45,    46,     0,     0,     0,    47,    48,    49,
      50,    51,    52,     0,     0,     0,    53,    54,    43,    44,
      45,    46,     0,     0,     0,    47,    48,    49,    50,    51,
      52,    53,    54,    43,    44,    45,    46,     0,     0,     0,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53
};

static const yytype_int8 yycheck[] =
{
      17,     1,     2,     3,     4,     5,    16,     7,    41,    16,
      10,     0,     3,     4,     5,     6,    37,    57,    58,    10,
      11,    12,    13,    14,    15,    32,    33,    37,    16,    41,
      41,    38,    39,    40,    41,    37,    36,    37,    38,    39,
      37,    37,    37,    34,    35,    85,    37,    47,    48,    49,
      50,    51,    52,    53,    54,    95,    37,     3,     4,     5,
       6,    37,   102,    37,    81,    82,    12,    13,    14,    15,
      -1,     4,     7,     8,     9,    17,    93,    -1,    17,    21,
      -1,    16,    21,    16,   101,    -1,    -1,    87,   105,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,     4,    -1,    36,    37,    38,    39,    40,    41,     3,
       4,     5,     6,    16,    43,    44,    45,    46,    -1,    22,
      -1,    -1,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,     4,    -1,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,     4,    -1,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,     4,    -1,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,     4,    -1,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,     4,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    26,    16,    17,    29,    30,    31,    32,
      33,     4,    -1,    36,    37,    38,    39,    40,    41,    -1,
      32,    33,    -1,    16,    36,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    -1,    -1,    36,    -1,    38,    39,    40,    41,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    15,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    -1,    17,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    34,    35,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    34,    35,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    16,    22,    26,    29,    30,    31,    32,    33,
      36,    37,    38,    39,    40,    41,    45,    46,    47,    48,
      52,    53,    55,    56,    57,    58,    59,    41,    53,    53,
      53,    53,    53,    41,    53,    53,     7,     8,     9,    16,
       0,    47,    37,     3,     4,     5,     6,    10,    11,    12,
      13,    14,    15,    34,    35,    37,    17,    37,    37,    37,
      16,    37,    37,    53,    53,    53,    17,    53,    54,    55,
      55,    55,    55,    53,    53,    53,    53,    53,    53,    53,
      53,    46,    46,    41,    51,    49,    17,    21,    23,    25,
      25,    17,    21,    46,    53,    37,    37,    37,    37,    41,
      25,    46,    50,    37,    25,    46,    37,    25,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    49,    48,    50,    48,    51,    51,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      58,    58,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     3,
       3,     2,     1,     0,     7,     0,    10,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     1,
       1,     3,     4,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       6,     9,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}



#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
static YYPTRDIFF_T
  YYPTRDIFF_T yylen;
#endif
#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
#endif
#ifndef yytnamerr
static YYPTRDIFF_T
      YYPTRDIFF_T yyn = 0;
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
#endif

static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.
   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }
  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }
  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;

yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
  YY_USE (yyvaluep);
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END

/* Lookahead token kind.  */
/*----------.
| yyparse.  |
`----------*/

    yy_state_fast_t yystate = 0;
    int yyerrstatus = 0;
    /* Refer to the stacks through separate pointers, to allow yyoverflow
    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;
    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;
  /* The return value of yyparse.  */
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

| yynewstate -- push a new state, which is found in yystate.  |
yynewstate:


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
      YYPTRDIFF_T yysize = yyssp - yyss + 1;
# if defined yyoverflow
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
# else /* defined YYSTACK_RELOCATE */
        YYNOMEM;
        yystacksize = YYMAXDEPTH;
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END
        YYABORT;
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yypact_value_is_default (yyn))
  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
      if (yytable_value_is_error (yyn))
        goto yyerrlab;

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
| yyreduce -- do a reduction.  |

     '$$ = $1'.
  case 2: /* P: S  */
#line 92 "ruby_parser.y"
       {
        comprobarAST((yyvsp[0].tr).n); 
    }
#line 1562 "ruby_parser.tab.c"
  case 4: /* S: S D  */
#line 101 "ruby_parser.y"
          { 
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-1].tr).n, (yyvsp[0].tr).n, NODO_SECUENCIA);
    }
#line 1570 "ruby_parser.tab.c"
  case 9: /* D: PUTS E NEWLINE  */
#line 112 "ruby_parser.y"
                     {
        (yyval.tr).n = crearNodoPuts((yyvsp[-1].tr).n);
    }
#line 1579 "ruby_parser.tab.c"
  case 10: /* D: RETURN E NEWLINE  */
#line 116 "ruby_parser.y"
                       {
        (yyval.tr).n = crearNodoUnario((yyvsp[-1].tr).n, NODO_RETURN);
    }
#line 1588 "ruby_parser.tab.c"
  case 12: /* D: NEWLINE  */
#line 121 "ruby_parser.y"
              { (yyval.tr).n = crearNodoVacio(); }
#line 1594 "ruby_parser.tab.c"
  case 13: /* $@1: %empty  */
#line 126 "ruby_parser.y"
                           {
        printf("> [FUNCION] - Definicion de funcion sin parametros: %s\n", (yyvsp[-1].stringVal));
        agregarFuncion((yyvsp[-1].stringVal), NULL, NULL);
    }
#line 1604 "ruby_parser.tab.c"
  case 14: /* F: DEF IDENTIFIER NEWLINE $@1 S END NEWLINE  */
#line 130 "ruby_parser.y"
                    {
        (yyval.tr).n = crearNodoFuncion((yyvsp[-5].stringVal), NULL, (yyvsp[-2].tr).n);
        int pos = buscarFuncion((yyvsp[-5].stringVal));
            tablaFunciones[pos].cuerpo = (yyvsp[-2].tr).n;
    }
#line 1617 "ruby_parser.tab.c"
  case 15: /* $@2: %empty  */
#line 138 "ruby_parser.y"
                                                            {
        printf("> [FUNCION] - Definicion de funcion con parametros: %s\n", (yyvsp[-4].stringVal));
        agregarFuncion((yyvsp[-4].stringVal), (yyvsp[-2].tr).n, NULL);
        agregarParametrosATabla((yyvsp[-2].tr).n);
    }
#line 1629 "ruby_parser.tab.c"
  case 16: /* F: DEF IDENTIFIER LPAREN lista_parametros RPAREN NEWLINE $@2 S END NEWLINE  */
#line 144 "ruby_parser.y"
                    {
        (yyval.tr).n = crearNodoFuncion((yyvsp[-8].stringVal), (yyvsp[-6].tr).n, (yyvsp[-2].tr).n);
        int pos = buscarFuncion((yyvsp[-8].stringVal));
            tablaFunciones[pos].cuerpo = (yyvsp[-2].tr).n;
    }
#line 1642 "ruby_parser.tab.c"
  case 17: /* lista_parametros: IDENTIFIER  */
#line 155 "ruby_parser.y"
               {
        printf("> [PARAMETRO] - %s\n", (yyvsp[0].stringVal));
        (yyval.tr).n = crearNodoParametro((yyvsp[0].stringVal));
    }
#line 1651 "ruby_parser.tab.c"
  case 18: /* lista_parametros: lista_parametros COMMA IDENTIFIER  */
#line 159 "ruby_parser.y"
                                        {
        printf("> [PARAMETRO] - %s\n", (yyvsp[0].stringVal));
        struct ast* param = crearNodoParametro((yyvsp[0].stringVal));
        param->siguiente = (yyvsp[-2].tr).n;
    }
#line 1662 "ruby_parser.tab.c"
  case 19: /* A: IDENTIFIER ASSIGN E  */
#line 169 "ruby_parser.y"
                        {
        int pos = buscarTabla(indice, (yyvsp[-2].stringVal), tabla);
            if(strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0){ 
                printf("Asignado el valor %d a la variable %s\n",(yyvsp[0].tr).integer, (yyvsp[-2].stringVal));
                tabla[indice].nombre = (yyvsp[-2].stringVal); 
                tabla[indice].integer = (yyvsp[0].tr).integer; 
                tabla[indice].registro = (yyvsp[0].tr).n->resultado;
            else if(strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0){ 
                printf("Asignado el valor %.2f a la variable %s\n",(yyvsp[0].tr).floatDecimal, (yyvsp[-2].stringVal));
                tabla[indice].nombre = (yyvsp[-2].stringVal); 
                tabla[indice].floatDecimal = (yyvsp[0].tr).floatDecimal; 
                tabla[indice].registro = (yyvsp[0].tr).n->resultado;
            else if(strcmp((yyvsp[0].tr).tipo, tipos[2]) == 0){ 
                printf("Asignado el valor %s a la variable %s\n",(yyvsp[0].tr).string, (yyvsp[-2].stringVal));
                tabla[indice].nombre = (yyvsp[-2].stringVal); 
                tabla[indice].string = (yyvsp[0].tr).string; 
                tabla[indice].registro = (yyvsp[0].tr).n->resultado;
            else if(strcmp((yyvsp[0].tr).tipo, tipos[3]) == 0){ 
                printf("Asignado el valor %s a la variable %s\n", (yyvsp[0].tr).boolean ? "true" : "false", (yyvsp[-2].stringVal));
                tabla[indice].nombre = (yyvsp[-2].stringVal); 
                tabla[indice].boolean = (yyvsp[0].tr).boolean; 
                tabla[indice].registro = (yyvsp[0].tr).n->resultado;
            if(strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0 && strcmp(tabla[pos].tipo, tipos[0]) == 0){ 
                printf("Actualizando el valor %d en la variable %s\n",(yyvsp[0].tr).integer, (yyvsp[-2].stringVal));
                tabla[pos].integer = (yyvsp[0].tr).integer; 
                tabla[pos].registro = (yyvsp[0].tr).n->resultado;
            else if(strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0 && strcmp(tabla[pos].tipo, tipos[1]) == 0){ 
                printf("Actualizando el valor %.2f en la variable %s\n",(yyvsp[0].tr).floatDecimal, (yyvsp[-2].stringVal));
                tabla[pos].floatDecimal = (yyvsp[0].tr).floatDecimal; 
                tabla[pos].registro = (yyvsp[0].tr).n->resultado;
            else if(strcmp((yyvsp[0].tr).tipo, tipos[2]) == 0 && strcmp(tabla[pos].tipo, tipos[2]) == 0){ 
                printf("Actualizando el valor %s en la variable %s\n",(yyvsp[0].tr).string, (yyvsp[-2].stringVal));
                tabla[pos].string = (yyvsp[0].tr).string; 
                tabla[pos].registro = (yyvsp[0].tr).n->resultado;
            else if(strcmp((yyvsp[0].tr).tipo, tipos[3]) == 0 && strcmp(tabla[pos].tipo, tipos[3]) == 0){ 
                printf("Actualizando el valor %s en la variable %s\n", (yyvsp[0].tr).boolean ? "true" : "false", (yyvsp[-2].stringVal));
                tabla[pos].boolean = (yyvsp[0].tr).boolean; 
                tabla[pos].registro = (yyvsp[0].tr).n->resultado;
        (yyval.tr).n = crearNodoAsignacion((yyvsp[-2].stringVal), (yyvsp[0].tr).n);
    }
#line 1735 "ruby_parser.tab.c"
  case 20: /* A: IDENTIFIER PLUS_ASSIGN E  */
#line 237 "ruby_parser.y"
                               {
        int pos = buscarTabla(indice, (yyvsp[-2].stringVal), tabla);
        if(pos != -1 && strcmp(tabla[pos].tipo, (yyvsp[0].tr).tipo) == 0) {
            if(strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
                tabla[pos].integer += (yyvsp[0].tr).integer;
            } else if(strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
                tabla[pos].floatDecimal += (yyvsp[0].tr).floatDecimal;
        (yyval.tr).n = crearNodoAsignacionCompuesta((yyvsp[-2].stringVal), (yyvsp[0].tr).n, SUMA);
    }
#line 1752 "ruby_parser.tab.c"
  case 21: /* A: IDENTIFIER MINUS_ASSIGN E  */
#line 249 "ruby_parser.y"
                                {
        int pos = buscarTabla(indice, (yyvsp[-2].stringVal), tabla);
        if(pos != -1 && strcmp(tabla[pos].tipo, (yyvsp[0].tr).tipo) == 0) {
            if(strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
                tabla[pos].integer -= (yyvsp[0].tr).integer;
            } else if(strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
                tabla[pos].floatDecimal -= (yyvsp[0].tr).floatDecimal;
        (yyval.tr).n = crearNodoAsignacionCompuesta((yyvsp[-2].stringVal), (yyvsp[0].tr).n, RESTA);
    }
#line 1769 "ruby_parser.tab.c"
  case 22: /* E: E PLUS T  */
#line 265 "ruby_parser.y"
             {
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, SUMA); 
            (yyval.tr).integer = (yyvsp[-2].tr).integer + (yyvsp[0].tr).integer;      
        else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0){
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, SUMA);
            (yyval.tr).floatDecimal = (yyvsp[-2].tr).floatDecimal + (yyvsp[0].tr).floatDecimal;
        else if (strcmp((yyvsp[-2].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[2]) == 0){
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, CONCATENACION);
            (yyval.tr).string = malloc(strlen((yyvsp[-2].tr).string) + strlen((yyvsp[0].tr).string) + 1);
            strcpy((yyval.tr).string, (yyvsp[-2].tr).string);
            strcat((yyval.tr).string, (yyvsp[0].tr).string);
    }
#line 1796 "ruby_parser.tab.c"
  case 23: /* E: E MINUS T  */
#line 287 "ruby_parser.y"
                {
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, RESTA);
            (yyval.tr).integer = (yyvsp[-2].tr).integer - (yyvsp[0].tr).integer;
        else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0){
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, RESTA);
            (yyval.tr).floatDecimal = (yyvsp[-2].tr).floatDecimal - (yyvsp[0].tr).floatDecimal;
    }
#line 1815 "ruby_parser.tab.c"
  case 24: /* E: E MULTIPLY T  */
#line 301 "ruby_parser.y"
                   {
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, MULTIPLICACION);
            (yyval.tr).integer = (yyvsp[-2].tr).integer * (yyvsp[0].tr).integer;
        else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0){
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, MULTIPLICACION);
            (yyval.tr).floatDecimal = (yyvsp[-2].tr).floatDecimal * (yyvsp[0].tr).floatDecimal;
    }
#line 1834 "ruby_parser.tab.c"
  case 25: /* E: E DIVIDE T  */
#line 315 "ruby_parser.y"
                 {
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            if((yyvsp[0].tr).integer != 0) {
                (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, DIVISION);
                (yyval.tr).integer = (yyvsp[-2].tr).integer / (yyvsp[0].tr).integer;
        else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0){
            if((yyvsp[0].tr).floatDecimal != 0.0) {
                (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, DIVISION);
                (yyval.tr).floatDecimal = (yyvsp[-2].tr).floatDecimal / (yyvsp[0].tr).floatDecimal;
    }
#line 1861 "ruby_parser.tab.c"

  case 26: /* E: MINUS E  */
#line 337 "ruby_parser.y"
                           {
        if (strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).n = crearNodoUnario((yyvsp[0].tr).n, NEGACION);
            (yyval.tr).integer = -(yyvsp[0].tr).integer;
        } else if (strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).n = crearNodoUnario((yyvsp[0].tr).n, NEGACION);
            (yyval.tr).floatDecimal = -(yyvsp[0].tr).floatDecimal;
    }
#line 1878 "ruby_parser.tab.c"
    break;

  case 27: /* E: T  */
#line 349 "ruby_parser.y"
        { (yyval.tr) = (yyvsp[0].tr); }
#line 1884 "ruby_parser.tab.c"
  case 28: /* E: R  */
#line 350 "ruby_parser.y"
        { (yyval.tr) = (yyvsp[0].tr); }
#line 1890 "ruby_parser.tab.c"

  case 29: /* E: L  */
#line 351 "ruby_parser.y"
        { (yyval.tr) = (yyvsp[0].tr); }
#line 1896 "ruby_parser.tab.c"
  case 30: /* lista_argumentos: E  */
#line 355 "ruby_parser.y"
      {
        (yyval.tr).n = (yyvsp[0].tr).n;
    }
#line 1904 "ruby_parser.tab.c"
  case 31: /* lista_argumentos: lista_argumentos COMMA E  */
#line 358 "ruby_parser.y"
                               {
        (yyvsp[0].tr).n->siguiente = (yyvsp[-2].tr).n;
        (yyval.tr).n = (yyvsp[0].tr).n;
    }
#line 1913 "ruby_parser.tab.c"
  case 32: /* T: IDENTIFIER LPAREN lista_argumentos RPAREN  */
#line 366 "ruby_parser.y"
                                              {
        printf("> [LLAMADA] - Llamada a funcion: %s\n", (yyvsp[-3].stringVal));
        int pos = buscarFuncion((yyvsp[-3].stringVal));
            (yyval.tr).n = crearNodoLlamadaFuncion((yyvsp[-3].stringVal), (yyvsp[-1].tr).n);
            sprintf(error_msg, "Funcion '%s' no declarada", (yyvsp[-3].stringVal));
    }
#line 1931 "ruby_parser.tab.c"
  case 33: /* T: IDENTIFIER LPAREN RPAREN  */
#line 379 "ruby_parser.y"
                               {
        printf("> [LLAMADA] - Llamada a funcion sin argumentos: %s\n", (yyvsp[-2].stringVal));
        int pos = buscarFuncion((yyvsp[-2].stringVal));
            (yyval.tr).n = crearNodoLlamadaFuncion((yyvsp[-2].stringVal), NULL);
            sprintf(error_msg, "Funcion '%s' no declarada", (yyvsp[-2].stringVal));
    }
#line 1949 "ruby_parser.tab.c"
  case 34: /* T: INTEGER  */
#line 392 "ruby_parser.y"
              {
        (yyval.tr).integer = (yyvsp[0].intVal);
        (yyval.tr).n = crearNodoTerminal((yyvsp[0].intVal)); 
    }
#line 1960 "ruby_parser.tab.c"
    break;

  case 35: /* T: FLOAT  */
#line 398 "ruby_parser.y"
            {
        (yyval.tr).floatDecimal = (yyvsp[0].floatVal);
        (yyval.tr).n = crearNodoTerminalFloat((yyvsp[0].floatVal)); 
    }
#line 1971 "ruby_parser.tab.c"
  case 36: /* T: STRING  */
#line 404 "ruby_parser.y"
             {
        (yyval.tr).string = (yyvsp[0].stringVal);
        (yyval.tr).n = crearNodoTerminalString((yyvsp[0].stringVal)); 
    }
#line 1982 "ruby_parser.tab.c"
  case 37: /* T: TRUE  */
#line 410 "ruby_parser.y"
           {
    }
#line 1993 "ruby_parser.tab.c"
  case 38: /* T: FALSE  */
#line 416 "ruby_parser.y"
            {
    }
#line 2004 "ruby_parser.tab.c"

  case 39: /* T: IDENTIFIER  */
#line 422 "ruby_parser.y"
                 {
        printf("> [TIPO] - IDENTIFICADOR: %s\n",(yyvsp[0].stringVal));
        int pos = buscarTabla(indice, (yyvsp[0].stringVal), tabla);
                (yyval.tr).n = crearNodoVariable((yyvsp[0].stringVal), tabla[pos].registro);   // USAR NUEVA FUNCIÓN
                (yyval.tr).n = crearNodoVariable((yyvsp[0].stringVal), tabla[pos].registro);   // USAR NUEVA FUNCIÓN
                (yyval.tr).n = crearNodoVariable((yyvsp[0].stringVal), tabla[pos].registro);   // USAR NUEVA FUNCIÓN
                (yyval.tr).n = crearNodoVariable((yyvsp[0].stringVal), tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            printf("Variable %s no declarada, insertando por defecto\n", (yyvsp[0].stringVal));
            insertarSimbolo((yyvsp[0].stringVal), "integer", 0, NULL);
            pos = buscarTabla(indice, (yyvsp[0].stringVal), tabla);
            (yyval.tr).n = crearNodoVariable((yyvsp[0].stringVal), tabla[pos].registro);
    }
#line 2044 "ruby_parser.tab.c"
  case 40: /* T: LPAREN E RPAREN  */
#line 457 "ruby_parser.y"
                      {
        (yyval.tr) = (yyvsp[-1].tr);
    }
#line 2052 "ruby_parser.tab.c"
  case 41: /* R: E LESS E  */
#line 464 "ruby_parser.y"
             {
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, MENOR_QUE);
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).integer < (yyvsp[0].tr).integer;
        } else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).floatDecimal < (yyvsp[0].tr).floatDecimal;
    }
#line 2067 "ruby_parser.tab.c"
  case 42: /* R: E GREATER E  */
#line 474 "ruby_parser.y"
                  {
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, MAYOR_QUE);
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).integer > (yyvsp[0].tr).integer;
        } else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).floatDecimal > (yyvsp[0].tr).floatDecimal;
    }
#line 2082 "ruby_parser.tab.c"
  case 43: /* R: E EQUAL E  */
#line 484 "ruby_parser.y"
                {
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, IGUAL);
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).integer == (yyvsp[0].tr).integer;
        } else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).floatDecimal == (yyvsp[0].tr).floatDecimal;
        } else if (strcmp((yyvsp[-2].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[2]) == 0) {
            (yyval.tr).boolean = strcmp((yyvsp[-2].tr).string, (yyvsp[0].tr).string) == 0;
    }
#line 2099 "ruby_parser.tab.c"
  case 44: /* R: E NOT_EQUAL E  */
#line 496 "ruby_parser.y"
                    {
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, DIFERENTE);
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).integer != (yyvsp[0].tr).integer;
        } else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).floatDecimal != (yyvsp[0].tr).floatDecimal;
    }
#line 2114 "ruby_parser.tab.c"
  case 45: /* R: E LESS_EQUAL E  */
#line 506 "ruby_parser.y"
                     {
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, MENOR_IGUAL);
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).integer <= (yyvsp[0].tr).integer;
        } else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).floatDecimal <= (yyvsp[0].tr).floatDecimal;
    }
#line 2129 "ruby_parser.tab.c"
  case 46: /* R: E GREATER_EQUAL E  */
#line 516 "ruby_parser.y"
                        {
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, MAYOR_IGUAL);
        if (strcmp((yyvsp[-2].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[0]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).integer >= (yyvsp[0].tr).integer;
        } else if (strcmp((yyvsp[-2].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[1]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).floatDecimal >= (yyvsp[0].tr).floatDecimal;
    }
#line 2144 "ruby_parser.tab.c"
  case 47: /* L: E AND E  */
#line 530 "ruby_parser.y"
            {
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, AND_LOGICO);
        if (strcmp((yyvsp[-2].tr).tipo, tipos[3]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).boolean && (yyvsp[0].tr).boolean;
    }
#line 2157 "ruby_parser.tab.c"
  case 48: /* L: E OR E  */
#line 538 "ruby_parser.y"
             {
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[-2].tr).n, (yyvsp[0].tr).n, OR_LOGICO);
        if (strcmp((yyvsp[-2].tr).tipo, tipos[3]) == 0 && strcmp((yyvsp[0].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).boolean = (yyvsp[-2].tr).boolean || (yyvsp[0].tr).boolean;
    }
#line 2170 "ruby_parser.tab.c"
  case 49: /* L: NOT E  */
#line 546 "ruby_parser.y"
            {
        (yyval.tr).n = crearNodoUnario((yyvsp[0].tr).n, NOT_LOGICO);
        if (strcmp((yyvsp[0].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).boolean = !(yyvsp[0].tr).boolean;
    }
#line 2183 "ruby_parser.tab.c"
  case 50: /* I: IF E NEWLINE S END NEWLINE  */
#line 558 "ruby_parser.y"
                               {
        if (strcmp((yyvsp[-4].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).n = crearNodoCondicional((yyvsp[-4].tr).n, (yyvsp[-2].tr).n, NULL);
        }
    }
#line 2196 "ruby_parser.tab.c"
  case 51: /* I: IF E NEWLINE S ELSE NEWLINE S END NEWLINE  */
#line 566 "ruby_parser.y"
                                                {
        if (strcmp((yyvsp[-7].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).n = crearNodoCondicional((yyvsp[-7].tr).n, (yyvsp[-5].tr).n, (yyvsp[-2].tr).n);
    }
#line 2209 "ruby_parser.tab.c"
  case 52: /* B: WHILE E NEWLINE S END NEWLINE  */
#line 577 "ruby_parser.y"
                                  {
        if (strcmp((yyvsp[-4].tr).tipo, tipos[3]) == 0) {
            (yyval.tr).n = crearNodoBucle((yyvsp[-4].tr).n, (yyvsp[-2].tr).n);
    }
#line 2222 "ruby_parser.tab.c"
#line 2226 "ruby_parser.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);
  /* Now 'shift' the result of the reduction.  Determine what state
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }
/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
         error, discard it.  */
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;
  /* Do not reclaim the symbols of the rule whose action triggered
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */
  /* Pop stack until we find a state that shifts the error token.  */
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }
        YYABORT;
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  goto yyreturnlab;

  goto yyreturnlab;

/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
  goto yyreturnlab;

/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
  return yyresult;

#line 587 "ruby_parser.y"


/* Line 1464 of yacc.c  */
#line 348 "ruby_parser.y"
    { (yyval.tr) = (yyvsp[(1) - (1)].tr); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 349 "ruby_parser.y"
    { (yyval.tr) = (yyvsp[(1) - (1)].tr); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 353 "ruby_parser.y"
    {
        (yyval.tr).n = (yyvsp[(1) - (1)].tr).n;
    ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 356 "ruby_parser.y"
    {
        (yyvsp[(3) - (3)].tr).n->siguiente = (yyvsp[(1) - (3)].tr).n;
        (yyval.tr).n = (yyvsp[(3) - (3)].tr).n;
    ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 364 "ruby_parser.y"
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
#line 377 "ruby_parser.y"
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
#line 390 "ruby_parser.y"
    {
        (yyval.tr).integer = (yyvsp[(1) - (1)].intVal);
        printf("> [TIPO] - INTEGER: %d\n", (yyval.tr).integer);
        (yyval.tr).n = crearNodoTerminal((yyvsp[(1) - (1)].intVal)); 
        (yyval.tr).tipo = tipos[0]; 
    ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 396 "ruby_parser.y"
    {
        (yyval.tr).floatDecimal = (yyvsp[(1) - (1)].floatVal);
        printf("> [TIPO] - FLOAT: %.2f\n", (yyval.tr).floatDecimal); 
        (yyval.tr).n = crearNodoTerminalFloat((yyvsp[(1) - (1)].floatVal)); 
        (yyval.tr).tipo = tipos[1];  
    ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 402 "ruby_parser.y"
    {
        (yyval.tr).string = (yyvsp[(1) - (1)].stringVal);
        printf("> [TIPO] - STRING: %s\n", (yyval.tr).string); 
        (yyval.tr).n = crearNodoTerminalString((yyvsp[(1) - (1)].stringVal)); 
        (yyval.tr).tipo = tipos[2];  
    ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 408 "ruby_parser.y"
    {
        (yyval.tr).boolean = 1;
        printf("> [TIPO] - BOOLEAN: true\n"); 
        (yyval.tr).n = crearNodoTerminalBool(1); 
        (yyval.tr).tipo = tipos[3];  
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 414 "ruby_parser.y"
    {
        (yyval.tr).boolean = 0;
        printf("> [TIPO] - BOOLEAN: false\n"); 
        (yyval.tr).n = crearNodoTerminalBool(0); 
        (yyval.tr).tipo = tipos[3];  
    ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 420 "ruby_parser.y"
    {
        printf("> [TIPO] - IDENTIFICADOR: %s\n",(yyvsp[(1) - (1)].stringVal));
        
        // Buscar como variable en la tabla de símbolos
        int pos = buscarTabla(indice, (yyvsp[(1) - (1)].stringVal), tabla);
        if(pos != -1){     
            if(strcmp(tabla[pos].tipo, tipos[0]) == 0){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).integer = tabla[pos].integer; 
                (yyval.tr).n = crearNodoVariable((yyvsp[(1) - (1)].stringVal), tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            }
            else if(strcmp(tabla[pos].tipo, tipos[1]) == 0){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).floatDecimal = tabla[pos].floatDecimal;
                (yyval.tr).n = crearNodoVariable((yyvsp[(1) - (1)].stringVal), tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            }
            else if(strcmp(tabla[pos].tipo, tipos[2]) == 0){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).string = tabla[pos].string;
                (yyval.tr).n = crearNodoVariable((yyvsp[(1) - (1)].stringVal), tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            }
            else if(strcmp(tabla[pos].tipo, tipos[3]) == 0){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).boolean = tabla[pos].boolean;
                (yyval.tr).n = crearNodoVariable((yyvsp[(1) - (1)].stringVal), tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            }
        } else {
            printf("Variable %s no declarada, insertando por defecto\n", (yyvsp[(1) - (1)].stringVal));
            insertarSimbolo((yyvsp[(1) - (1)].stringVal), "integer", 0, NULL);
            pos = buscarTabla(indice, (yyvsp[(1) - (1)].stringVal), tabla);
            (yyval.tr).tipo = tabla[pos].tipo;
            (yyval.tr).integer = tabla[pos].integer;
            (yyval.tr).n = crearNodoVariable((yyvsp[(1) - (1)].stringVal), tabla[pos].registro);
        }
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 455 "ruby_parser.y"
    {
        (yyval.tr) = (yyvsp[(2) - (3)].tr);
    ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 462 "ruby_parser.y"
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
#line 472 "ruby_parser.y"
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
#line 482 "ruby_parser.y"
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
#line 494 "ruby_parser.y"
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
#line 504 "ruby_parser.y"
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
#line 514 "ruby_parser.y"
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
#line 528 "ruby_parser.y"
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
#line 536 "ruby_parser.y"
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
#line 544 "ruby_parser.y"
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
#line 556 "ruby_parser.y"
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
#line 564 "ruby_parser.y"
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
#line 575 "ruby_parser.y"
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
#line 2294 "ruby_parser.tab.c"
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
#line 585 "ruby_parser.y"
 

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
    
    inicializarTabla();
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

