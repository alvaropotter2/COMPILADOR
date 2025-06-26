%{
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
%}

/*Definicion de tipos y estructuras empleadas*/
%union {
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
}

/*Declaración de los TOKENS*/
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN PLUS_ASSIGN MINUS_ASSIGN
%token EQUAL NOT_EQUAL LESS GREATER LESS_EQUAL GREATER_EQUAL
%token LPAREN RPAREN LBRACE RBRACE LBRACKET COMMA
%token IF ELSE ELSIF END WHILE FOR DO PUTS DEF RETURN
%token TRUE FALSE AND OR NOT
%token NEWLINE

/*Declaración de los TOKENS que provienen de FLEX con su respectivo tipo*/
%token <intVal> INTEGER 
%token <floatVal> FLOAT 
%token <stringVal> STRING IDENTIFIER COMMENT

/*Declaración de los TOKENS NO TERMINALES con su estructura*/
%type <tr> P S D A E T R L I B F lista_parametros lista_argumentos

/*Declaración de la precedencia siendo menor la del primero y mayor la del último*/
%left OR
%left AND
%left EQUAL NOT_EQUAL
%left LESS GREATER LESS_EQUAL GREATER_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE
%right NOT UMINUS

%start P

%%

//-----------------------------------------------  PRODUCCIONES  -------------------------------------------------------

//PRODUCCION "P" (Programa), formado por sentencias
P:
    S  {
        comprobarAST($1.n); 
        printf("\n[COMPILACION FINALIZADA]\n");     
    }
;

//PRODUCCION "S" (Sentencias), puede estar formado por una sentencia o un grupo de sentencias
S:
    D
    | S D { 
        $$.n = crearNodoNoTerminal($1.n, $2.n, NODO_SECUENCIA);
    }
;

//PRODUCCION "D" (Declaracion/sentencia), puede estar formado por asignaciones, condicionales, bucles, puts, funciones o expresiones
D:   
    A NEWLINE
    | I              
    | B
    | F
    | PUTS E NEWLINE {
        printf("> [SENTENCIA] - PUTS\n");
        $$.n = crearNodoPuts($2.n);
    }
    | RETURN E NEWLINE {
        printf("> [SENTENCIA] - RETURN\n");
        $$.n = crearNodoUnario($2.n, NODO_RETURN);
    }
    | E NEWLINE
    | NEWLINE { $$.n = crearNodoVacio(); }
;

//-------------------------------------------------------- FUNCIONES --------------------------------------------------------
F:
    DEF IDENTIFIER NEWLINE {
        printf("> [FUNCION] - Definicion de funcion sin parametros: %s\n", $2);
        // Agregar función a la tabla ANTES de procesar el cuerpo
        agregarFuncion($2, NULL, NULL);
    } S END NEWLINE {
        $$.n = crearNodoFuncion($2, NULL, $5.n);
        // Actualizar el cuerpo de la función en la tabla
        int pos = buscarFuncion($2);
        if (pos != -1) {
            tablaFunciones[pos].cuerpo = $5.n;
        }
    }
    | DEF IDENTIFIER LPAREN lista_parametros RPAREN NEWLINE {
        printf("> [FUNCION] - Definicion de funcion con parametros: %s\n", $2);
        // Agregar función a la tabla ANTES de procesar el cuerpo
        agregarFuncion($2, $4.n, NULL);
        // Agregar parámetros a la tabla de símbolos ANTES de procesar el cuerpo
        agregarParametrosATabla($4.n);
    } S END NEWLINE {
        $$.n = crearNodoFuncion($2, $4.n, $8.n);
        // Actualizar el cuerpo de la función en la tabla
        int pos = buscarFuncion($2);
        if (pos != -1) {
            tablaFunciones[pos].cuerpo = $8.n;
        }
    }
;

lista_parametros:
    IDENTIFIER {
        printf("> [PARAMETRO] - %s\n", $1);
        $$.n = crearNodoParametro($1);
    }
    | lista_parametros COMMA IDENTIFIER {
        printf("> [PARAMETRO] - %s\n", $3);
        struct ast* param = crearNodoParametro($3);
        param->siguiente = $1.n;
        $$.n = param;
    }
;

//-----------------------------------------------  ASIGNACION --------------------------------------------------------
A:
    IDENTIFIER ASSIGN E {
        printf("> [SENTENCIA] - Asignacion Simple\n");
        
        // Buscar si la variable ya existe
        int pos = buscarTabla(indice, $1, tabla);
        if (pos == -1) {
            // Variable nueva - crear entrada en tabla
            if(strcmp($3.tipo, tipos[0]) == 0){ 
                printf("Asignado el valor %d a la variable %s\n",$3.integer, $1);
                tabla[indice].nombre = $1; 
                tabla[indice].tipo = tipos[0]; 
                tabla[indice].integer = $3.integer; 
                tabla[indice].registro = $3.n->resultado;
                tabla[indice].inicializada = 1;
                indice++; 
            }
            else if(strcmp($3.tipo, tipos[1]) == 0){ 
                printf("Asignado el valor %.2f a la variable %s\n",$3.floatDecimal, $1);
                tabla[indice].nombre = $1; 
                tabla[indice].tipo = tipos[1]; 
                tabla[indice].floatDecimal = $3.floatDecimal; 
                tabla[indice].registro = $3.n->resultado;
                tabla[indice].inicializada = 1;
                indice++; 
            }
            else if(strcmp($3.tipo, tipos[2]) == 0){ 
                printf("Asignado el valor %s a la variable %s\n",$3.string, $1);
                tabla[indice].nombre = $1; 
                tabla[indice].tipo = tipos[2]; 
                tabla[indice].string = $3.string; 
                tabla[indice].registro = $3.n->resultado;
                tabla[indice].inicializada = 1;
                indice++; 
            }
            else if(strcmp($3.tipo, tipos[3]) == 0){ 
                printf("Asignado el valor %s a la variable %s\n", $3.boolean ? "true" : "false", $1);
                tabla[indice].nombre = $1; 
                tabla[indice].tipo = tipos[3]; 
                tabla[indice].boolean = $3.boolean; 
                tabla[indice].registro = $3.n->resultado;
                tabla[indice].inicializada = 1;
                indice++; 
            }
        } else {
            // Variable existente - actualizar valor
            if(strcmp($3.tipo, tipos[0]) == 0 && strcmp(tabla[pos].tipo, tipos[0]) == 0){ 
                printf("Actualizando el valor %d en la variable %s\n",$3.integer, $1);
                tabla[pos].integer = $3.integer; 
                tabla[pos].registro = $3.n->resultado;
            }
            else if(strcmp($3.tipo, tipos[1]) == 0 && strcmp(tabla[pos].tipo, tipos[1]) == 0){ 
                printf("Actualizando el valor %.2f en la variable %s\n",$3.floatDecimal, $1);
                tabla[pos].floatDecimal = $3.floatDecimal; 
                tabla[pos].registro = $3.n->resultado;
            }
            else if(strcmp($3.tipo, tipos[2]) == 0 && strcmp(tabla[pos].tipo, tipos[2]) == 0){ 
                printf("Actualizando el valor %s en la variable %s\n",$3.string, $1);
                tabla[pos].string = $3.string; 
                tabla[pos].registro = $3.n->resultado;
            }
            else if(strcmp($3.tipo, tipos[3]) == 0 && strcmp(tabla[pos].tipo, tipos[3]) == 0){ 
                printf("Actualizando el valor %s en la variable %s\n", $3.boolean ? "true" : "false", $1);
                tabla[pos].boolean = $3.boolean; 
                tabla[pos].registro = $3.n->resultado;
            }
        }
        $$.n = crearNodoAsignacion($1, $3.n);
    }
    | IDENTIFIER PLUS_ASSIGN E {
        printf("> [SENTENCIA] - Asignacion con Suma\n");
        int pos = buscarTabla(indice, $1, tabla);
        if(pos != -1 && strcmp(tabla[pos].tipo, $3.tipo) == 0) {
            if(strcmp($3.tipo, tipos[0]) == 0) {
                tabla[pos].integer += $3.integer;
            } else if(strcmp($3.tipo, tipos[1]) == 0) {
                tabla[pos].floatDecimal += $3.floatDecimal;
            }
        }
        $$.n = crearNodoAsignacionCompuesta($1, $3.n, SUMA);
    }
    | IDENTIFIER MINUS_ASSIGN E {
        printf("> [SENTENCIA] - Asignacion con Resta\n");
        int pos = buscarTabla(indice, $1, tabla);
        if(pos != -1 && strcmp(tabla[pos].tipo, $3.tipo) == 0) {
            if(strcmp($3.tipo, tipos[0]) == 0) {
                tabla[pos].integer -= $3.integer;
            } else if(strcmp($3.tipo, tipos[1]) == 0) {
                tabla[pos].floatDecimal -= $3.floatDecimal;
            }
        }
        $$.n = crearNodoAsignacionCompuesta($1, $3.n, RESTA);
    }
;

//-----------------------------------------------  EXPRESIONES ARITMETICAS ---------------------------------------------
E:
    E PLUS T {
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            printf("> [OPERACION] - SUMA {integer + integer}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, SUMA); 
            $$.tipo = tipos[0]; 
            $$.integer = $1.integer + $3.integer;      
        }
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){
            printf("> [OPERACION] - SUMA {float + float}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, SUMA);
            $$.tipo = tipos[1]; 
            $$.floatDecimal = $1.floatDecimal + $3.floatDecimal;
        }  
        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[2]) == 0){
            printf("> [OPERACION] - CONCATENACION {string + string}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, CONCATENACION);
            $$.tipo = tipos[2];
            $$.string = malloc(strlen($1.string) + strlen($3.string) + 1);
            strcpy($$.string, $1.string);
            strcat($$.string, $3.string);
        }
    }
    | E MINUS T {
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            printf("> [OPERACION] - RESTA {integer - integer}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, RESTA);
            $$.tipo = tipos[0]; 
            $$.integer = $1.integer - $3.integer;
        }
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){
            printf("> [OPERACION] - RESTA {float - float}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, RESTA);
            $$.tipo = tipos[1]; 
            $$.floatDecimal = $1.floatDecimal - $3.floatDecimal;
        }
    }
    | E MULTIPLY T {
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            printf("> [OPERACION] - MULTIPLICACION {integer * integer}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, MULTIPLICACION);
            $$.tipo = tipos[0]; 
            $$.integer = $1.integer * $3.integer;
        }
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){
            printf("> [OPERACION] - MULTIPLICACION {float * float}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, MULTIPLICACION);
            $$.tipo = tipos[1]; 
            $$.floatDecimal = $1.floatDecimal * $3.floatDecimal;
        }
    }
    | E DIVIDE T {
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            if($3.integer != 0) {
                printf("> [OPERACION] - DIVISION {integer / integer}\n");
                $$.n = crearNodoNoTerminal($1.n, $3.n, DIVISION);
                $$.tipo = tipos[0]; 
                $$.integer = $1.integer / $3.integer;
            } else {
                yyerror("Error: Division por cero");
            }
        }
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){
            if($3.floatDecimal != 0.0) {
                printf("> [OPERACION] - DIVISION {float / float}\n");
                $$.n = crearNodoNoTerminal($1.n, $3.n, DIVISION);
                $$.tipo = tipos[1]; 
                $$.floatDecimal = $1.floatDecimal / $3.floatDecimal;
            } else {
                yyerror("Error: Division por cero");
            }
        }
    }
    | MINUS E %prec UMINUS {
        printf("> [OPERACION] - NEGACION UNARIA\n");
        if (strcmp($2.tipo, tipos[0]) == 0) {
            $$.n = crearNodoUnario($2.n, NEGACION);
            $$.tipo = tipos[0]; 
            $$.integer = -$2.integer;
        } else if (strcmp($2.tipo, tipos[1]) == 0) {
            $$.n = crearNodoUnario($2.n, NEGACION);
            $$.tipo = tipos[1]; 
            $$.floatDecimal = -$2.floatDecimal;
        }
    }
    | T { $$ = $1; }
    | R { $$ = $1; }
    | L { $$ = $1; }
;

lista_argumentos:
    E {
        $$.n = $1.n;
    }
    | lista_argumentos COMMA E {
        $3.n->siguiente = $1.n;
        $$.n = $3.n;
    }
;

//-----------------------------------------------  TERMINOS  ---------------------------------------------
T:
    IDENTIFIER LPAREN lista_argumentos RPAREN {
        printf("> [LLAMADA] - Llamada a funcion: %s\n", $1);
        int pos = buscarFuncion($1);
        if(pos != -1) {
            $$.n = crearNodoLlamadaFuncion($1, $3.n);
            $$.tipo = tipos[0]; // Por simplicidad, asumimos que devuelve entero
            $$.integer = 0; // Valor por defecto
        } else {
            char error_msg[100];
            sprintf(error_msg, "Funcion '%s' no declarada", $1);
            yyerror(error_msg);
        }
    }
    | IDENTIFIER LPAREN RPAREN {
        printf("> [LLAMADA] - Llamada a funcion sin argumentos: %s\n", $1);
        int pos = buscarFuncion($1);
        if(pos != -1) {
            $$.n = crearNodoLlamadaFuncion($1, NULL);
            $$.tipo = tipos[0]; // Por simplicidad, asumimos que devuelve entero
            $$.integer = 0; // Valor por defecto
        } else {
            char error_msg[100];
            sprintf(error_msg, "Funcion '%s' no declarada", $1);
            yyerror(error_msg);
        }
    }
    | INTEGER {
        $$.integer = $1;
        printf("> [TIPO] - INTEGER: %d\n", $$.integer);
        $$.n = crearNodoTerminal($1); 
        $$.tipo = tipos[0]; 
    }
    | FLOAT {
        $$.floatDecimal = $1;
        printf("> [TIPO] - FLOAT: %.2f\n", $$.floatDecimal); 
        $$.n = crearNodoTerminalFloat($1); 
        $$.tipo = tipos[1];  
    }
    | STRING {
        $$.string = $1;
        printf("> [TIPO] - STRING: %s\n", $$.string); 
        $$.n = crearNodoTerminalString($1); 
        $$.tipo = tipos[2];  
    }
    | TRUE {
        $$.boolean = 1;
        printf("> [TIPO] - BOOLEAN: true\n"); 
        $$.n = crearNodoTerminalBool(1); 
        $$.tipo = tipos[3];  
    }
    | FALSE {
        $$.boolean = 0;
        printf("> [TIPO] - BOOLEAN: false\n"); 
        $$.n = crearNodoTerminalBool(0); 
        $$.tipo = tipos[3];  
    }
    | IDENTIFIER {
        printf("> [TIPO] - IDENTIFICADOR: %s\n",$1);
        
        // Buscar como variable en la tabla de símbolos
        int pos = buscarTabla(indice, $1, tabla);
        if(pos != -1){     
            if(strcmp(tabla[pos].tipo, tipos[0]) == 0){
                $$.tipo = tabla[pos].tipo; 
                $$.integer = tabla[pos].integer; 
                $$.n = crearNodoVariable($1, tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            }
            else if(strcmp(tabla[pos].tipo, tipos[1]) == 0){
                $$.tipo = tabla[pos].tipo; 
                $$.floatDecimal = tabla[pos].floatDecimal;
                $$.n = crearNodoVariable($1, tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            }
            else if(strcmp(tabla[pos].tipo, tipos[2]) == 0){
                $$.tipo = tabla[pos].tipo; 
                $$.string = tabla[pos].string;
                $$.n = crearNodoVariable($1, tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            }
            else if(strcmp(tabla[pos].tipo, tipos[3]) == 0){
                $$.tipo = tabla[pos].tipo; 
                $$.boolean = tabla[pos].boolean;
                $$.n = crearNodoVariable($1, tabla[pos].registro);   // USAR NUEVA FUNCIÓN
            }
        } else {
            printf("Variable %s no declarada, insertando por defecto\n", $1);
            insertarSimbolo($1, "integer", 0, NULL);
            pos = buscarTabla(indice, $1, tabla);
            $$.tipo = tabla[pos].tipo;
            $$.integer = tabla[pos].integer;
            $$.n = crearNodoVariable($1, tabla[pos].registro);
        }
    }
    | LPAREN E RPAREN {
        $$ = $2;
    }
;

//-----------------------------------------------  EXPRESIONES RELACIONALES  ---------------------------------------------
R:
    E LESS E {
        printf("> [OPERACION] - MENOR QUE\n");
        $$.n = crearNodoNoTerminal($1.n, $3.n, MENOR_QUE);
        $$.tipo = tipos[3];
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            $$.boolean = $1.integer < $3.integer;
        } else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0) {
            $$.boolean = $1.floatDecimal < $3.floatDecimal;
        }
    }
    | E GREATER E {
        printf("> [OPERACION] - MAYOR QUE\n");
        $$.n = crearNodoNoTerminal($1.n, $3.n, MAYOR_QUE);
        $$.tipo = tipos[3];
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            $$.boolean = $1.integer > $3.integer;
        } else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0) {
            $$.boolean = $1.floatDecimal > $3.floatDecimal;
        }
    }
    | E EQUAL E {
        printf("> [OPERACION] - IGUAL A\n");
        $$.n = crearNodoNoTerminal($1.n, $3.n, IGUAL);
        $$.tipo = tipos[3];
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            $$.boolean = $1.integer == $3.integer;
        } else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0) {
            $$.boolean = $1.floatDecimal == $3.floatDecimal;
        } else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[2]) == 0) {
            $$.boolean = strcmp($1.string, $3.string) == 0;
        }
    }
    | E NOT_EQUAL E {
        printf("> [OPERACION] - DIFERENTE A\n");
        $$.n = crearNodoNoTerminal($1.n, $3.n, DIFERENTE);
        $$.tipo = tipos[3];
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            $$.boolean = $1.integer != $3.integer;
        } else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0) {
            $$.boolean = $1.floatDecimal != $3.floatDecimal;
        }
    }
    | E LESS_EQUAL E {
        printf("> [OPERACION] - MENOR O IGUAL QUE\n");
        $$.n = crearNodoNoTerminal($1.n, $3.n, MENOR_IGUAL);
        $$.tipo = tipos[3];
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            $$.boolean = $1.integer <= $3.integer;
        } else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0) {
            $$.boolean = $1.floatDecimal <= $3.floatDecimal;
        }
    }
    | E GREATER_EQUAL E {
        printf("> [OPERACION] - MAYOR O IGUAL QUE\n");
        $$.n = crearNodoNoTerminal($1.n, $3.n, MAYOR_IGUAL);
        $$.tipo = tipos[3];
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {
            $$.boolean = $1.integer >= $3.integer;
        } else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0) {
            $$.boolean = $1.floatDecimal >= $3.floatDecimal;
        }
    }
;

//-----------------------------------------------  EXPRESIONES LOGICAS  ---------------------------------------------
L:
    E AND E {
        printf("> [OPERACION] - AND LOGICO\n");
        $$.n = crearNodoNoTerminal($1.n, $3.n, AND_LOGICO);
        $$.tipo = tipos[3];
        if (strcmp($1.tipo, tipos[3]) == 0 && strcmp($3.tipo, tipos[3]) == 0) {
            $$.boolean = $1.boolean && $3.boolean;
        }
    }
    | E OR E {
        printf("> [OPERACION] - OR LOGICO\n");
        $$.n = crearNodoNoTerminal($1.n, $3.n, OR_LOGICO);
        $$.tipo = tipos[3];
        if (strcmp($1.tipo, tipos[3]) == 0 && strcmp($3.tipo, tipos[3]) == 0) {
            $$.boolean = $1.boolean || $3.boolean;
        }
    }
    | NOT E {
        printf("> [OPERACION] - NOT LOGICO\n");
        $$.n = crearNodoUnario($2.n, NOT_LOGICO);
        $$.tipo = tipos[3];
        if (strcmp($2.tipo, tipos[3]) == 0) {
            $$.boolean = !$2.boolean;
        }
    }
;

//-----------------------------------------------  ESTRUCTURAS DE CONTROL  ---------------------------------------------
I:
    IF E NEWLINE S END NEWLINE {
        printf("> [SENTENCIA] - IF\n");
        if (strcmp($2.tipo, tipos[3]) == 0) {
            $$.n = crearNodoCondicional($2.n, $4.n, NULL);
        } else {
            yyerror("Error: La condicion del IF debe ser booleana");
        }
    }
    | IF E NEWLINE S ELSE NEWLINE S END NEWLINE {
        printf("> [SENTENCIA] - IF-ELSE\n");
        if (strcmp($2.tipo, tipos[3]) == 0) {
            $$.n = crearNodoCondicional($2.n, $4.n, $7.n);
        } else {
            yyerror("Error: La condicion del IF debe ser booleana");
        }
    }
;

B:
    WHILE E NEWLINE S END NEWLINE {
        printf("> [SENTENCIA] - WHILE\n");
        if (strcmp($2.tipo, tipos[3]) == 0) {
            $$.n = crearNodoBucle($2.n, $4.n);
        } else {
            yyerror("Error: La condicion del WHILE debe ser booleana");
        }
    }
;

%% 

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
