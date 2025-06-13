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

/* Line 1685 of yacc.c  */
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



/* Line 1685 of yacc.c  */
#line 112 "ruby_parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


