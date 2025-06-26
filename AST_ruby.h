#ifndef AST_RUBY_H
#define AST_RUBY_H

#include <stdio.h>

// Tipos de nodos del AST
typedef enum {
    // Nodos terminales
    NODO_NUMERO,
    NODO_IDENTIFICADOR,
    NODO_STRING,
    NODO_BOOLEAN,
    
    // Operaciones aritméticas
    SUMA,
    RESTA,
    MULTIPLICACION,
    DIVISION,
    NEGACION,
    CONCATENACION,
    
    // Operaciones relacionales
    MENOR_QUE,
    MAYOR_QUE,
    MENOR_IGUAL,
    MAYOR_IGUAL,
    IGUAL,
    DIFERENTE,
    
    // Operaciones lógicas
    AND_LOGICO,
    OR_LOGICO,
    NOT_LOGICO,
    
    // Sentencias
    NODO_ASIGNACION,
    NODO_ASIGNACION_COMPUESTA,
    NODO_PUTS,
    NODO_CONDICIONAL,
    NODO_BUCLE,
    NODO_SECUENCIA,
    NODO_VACIO,
    NODO_RETURN,
    
    // Funciones (Hito 2)
    NODO_FUNCION,
    NODO_LLAMADA_FUNCION,
    NODO_PARAMETRO,
    LISTA_PARAMETROS,
    LISTA_ARGUMENTOS,
    
    // Arrays (Hito 2)
    NODO_ACCESO_ARRAY,
    NODO_ASIGNACION_ARRAY,
    
    // Variables
    NODO_VARIABLE
} tipoNodo;

// Estructura del nodo del AST
struct ast {
    tipoNodo tipo;                  // Tipo de nodo
    union {
        int intVal;                 // Para números enteros
        float floatVal;             // Para números decimales
        char* stringVal;            // Para strings e identificadores
        int boolVal;                // Para valores booleanos (0 o 1)
    } valor;
    int esFloat;    

    struct ast* izquierdo;          // Hijo izquierdo
    struct ast* derecho;            // Hijo derecho
    struct ast* siguiente;          // Para listas (parámetros, argumentos)
    
    int resultado;                  // Registro donde se almacena el resultado
    char* etiqueta;                 // Para saltos condicionales
    int linea;                      // Línea del código fuente
};

// Función para determinar si un nodo es float
int esNodoFloat(struct ast* nodo);

// Prototipos de funciones para crear nodos
struct ast* crearNodoTerminal(int valor);
struct ast* crearNodoTerminalFloat(float valor);
struct ast* crearNodoTerminalString(char* valor);
struct ast* crearNodoTerminalBool(int valor);
struct ast* crearVariableTerminal(void* valor, int registro);
struct ast* crearNodoVariable(char* nombre, int registro);

struct ast* crearNodoNoTerminal(struct ast* izq, struct ast* der, tipoNodo tipo);
struct ast* crearNodoUnario(struct ast* hijo, tipoNodo tipo);

struct ast* crearNodoAsignacion(char* identificador, struct ast* expresion);
struct ast* crearNodoAsignacionCompuesta(char* identificador, struct ast* expresion, tipoNodo operacion);
struct ast* crearNodoPuts(struct ast* expresion);
struct ast* crearNodoCondicional(struct ast* condicion, struct ast* bloqueIf, struct ast* bloqueElse);
struct ast* crearNodoBucle(struct ast* condicion, struct ast* cuerpo);
struct ast* crearNodoVacio();

// Funciones para Hito 2
struct ast* crearNodoFuncion(char* nombre, struct ast* parametros, struct ast* cuerpo);
struct ast* crearNodoLlamadaFuncion(char* nombre, struct ast* argumentos);
struct ast* crearNodoParametro(char* nombre);
struct ast* crearNodoAccesoArray(char* nombre, struct ast* indice1, struct ast* indice2);
struct ast* crearNodoAsignacionArray(char* nombre, struct ast* indice1, struct ast* indice2, struct ast* valor);

// Funciones de utilidad
void liberarAST(struct ast* nodo);
void imprimirAST(struct ast* nodo, int nivel);
void comprobarAST(struct ast* nodo);

// Generación de código
void generarCodigo(struct ast* nodo);
void generarCodigoMIPS(struct ast* nodo);
void generarCodigoMIPSArchivo(struct ast* nodo, FILE* archivo);
void generarMIPSCompleto(struct ast* nodo, const char* nombreArchivo);
void generarDefinicionesFunciones(struct ast* nodo, FILE* archivo);
void generarCodigoFuncion(struct ast* nodo, FILE* archivo, const char* nombreFuncion);
void generarCodigoPrincipal(struct ast* nodo, FILE* archivo);
void generarStringsEnDatos(struct ast* nodo, FILE* archivo);
int obtenerNuevoRegistro();
char* obtenerNuevaEtiqueta();

// Función auxiliar para operaciones con floats
int esOperacionFloat(struct ast* nodo);

#endif
