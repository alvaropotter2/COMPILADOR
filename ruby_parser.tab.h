/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_RUBY_PARSER_TAB_H_INCLUDED
# define YY_YY_RUBY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MULTIPLY = 260,                /* MULTIPLY  */
    DIVIDE = 261,                  /* DIVIDE  */
    ASSIGN = 262,                  /* ASSIGN  */
    PLUS_ASSIGN = 263,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 264,            /* MINUS_ASSIGN  */
    EQUAL = 265,                   /* EQUAL  */
    NOT_EQUAL = 266,               /* NOT_EQUAL  */
    LESS = 267,                    /* LESS  */
    GREATER = 268,                 /* GREATER  */
    LESS_EQUAL = 269,              /* LESS_EQUAL  */
    GREATER_EQUAL = 270,           /* GREATER_EQUAL  */
    LPAREN = 271,                  /* LPAREN  */
    RPAREN = 272,                  /* RPAREN  */
    LBRACE = 273,                  /* LBRACE  */
    RBRACE = 274,                  /* RBRACE  */
    LBRACKET = 275,                /* LBRACKET  */
    COMMA = 276,                   /* COMMA  */
    IF = 277,                      /* IF  */
    ELSE = 278,                    /* ELSE  */
    ELSIF = 279,                   /* ELSIF  */
    END = 280,                     /* END  */
    WHILE = 281,                   /* WHILE  */
    FOR = 282,                     /* FOR  */
    DO = 283,                      /* DO  */
    PUTS = 284,                    /* PUTS  */
    DEF = 285,                     /* DEF  */
    RETURN = 286,                  /* RETURN  */
    TRUE = 287,                    /* TRUE  */
    FALSE = 288,                   /* FALSE  */
    AND = 289,                     /* AND  */
    OR = 290,                      /* OR  */
    NOT = 291,                     /* NOT  */
    NEWLINE = 292,                 /* NEWLINE  */
    INTEGER = 293,                 /* INTEGER  */
    FLOAT = 294,                   /* FLOAT  */
    STRING = 295,                  /* STRING  */
    IDENTIFIER = 296,              /* IDENTIFIER  */
    COMMENT = 297,                 /* COMMENT  */
    UMINUS = 298                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "ruby_parser.y"

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

#line 122 "ruby_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_RUBY_PARSER_TAB_H_INCLUDED  */
