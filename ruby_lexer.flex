
%{
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ruby_parser.tab.h"

int num_linea = 1;
%}

%option noyywrap

/* Definiciones regulares */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*
STRING      \"([^\"\\]|\\.)*\"
COMMENT     #.*
WHITESPACE  [ \t]+
NEWLINE     \n

%%

{WHITESPACE}    { /* Ignorar espacios y tabs */ }
{NEWLINE}       { num_linea++; return NEWLINE; }
{COMMENT}       { /* Ignorar comentarios */ }

"if"            { return IF; }
"else"          { return ELSE; }
"elsif"         { return ELSIF; }
"end"           { return END; }
"while"         { return WHILE; }
"for"           { return FOR; }
"do"            { return DO; }
"puts"          { return PUTS; }
"def"           { return DEF; }
"return"        { return RETURN; }
"true"          { return TRUE; }
"false"         { return FALSE; }
"and"           { return AND; }
"or"            { return OR; }
"not"           { return NOT; }

"+="            { return PLUS_ASSIGN; }
"-="            { return MINUS_ASSIGN; }
"=="            { return EQUAL; }
"!="            { return NOT_EQUAL; }
"<="            { return LESS_EQUAL; }
">="            { return GREATER_EQUAL; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"="             { return ASSIGN; }
"<"             { return LESS; }
">"             { return GREATER; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACE; }
","             { return COMMA; }

{INTEGER}       { yylval.intVal = atoi(yytext); return INTEGER; }
{FLOAT}         { yylval.floatVal = atof(yytext); return FLOAT; }
{STRING}        { 
                  yylval.stringVal = malloc(strlen(yytext) + 1);
                  strcpy(yylval.stringVal, yytext);
                  return STRING; 
                }
{IDENTIFIER}    { 
                  yylval.stringVal = malloc(strlen(yytext) + 1);
                  strcpy(yylval.stringVal, yytext);
                  return IDENTIFIER; 
                }

.               { 
                  fprintf(stderr, "Caracter no reconocido '%c' en linea %d\n", yytext[0], num_linea);
                  return yytext[0];
                }

%%
