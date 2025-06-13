#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include "AST_ruby.h"

// Definir MAX_SIMBOLOS si no está definido
#ifndef MAX_SIMBOLOS
#define MAX_SIMBOLOS 256
#endif

// Estructura para la tabla de símbolos
struct simbolo {
    char* nombre;           // Nombre del identificador
    char* tipo;             // Tipo: "integer", "float", "string", "boolean"
    int integer;            // Valor si es entero
    float floatDecimal;     // Valor si es float
    char* string;           // Valor si es string
    int boolean;            // Valor si es boolean (0 o 1)
    int registro;           // Registro MIPS asignado ($t0, $t1, etc.)
    int direccion;          // Dirección en memoria
    int linea;              // Línea donde se declara
    int inicializada;       // Si la variable ha sido inicializada (0 o 1)
};

// Alias para compatibilidad
typedef struct simbolo tSimbolos;

// Variables globales
extern struct simbolo tabla[MAX_SIMBOLOS];  // Tabla de símbolos
extern int indice;                          // Índice actual en la tabla
extern int num_linea;                       // Número de línea actual

// Prototipos de funciones
void inicializarTabla();
int insertarSimbolo(char* nombre, char* tipo, int valor, char* cadena);
int buscarSimbolo(char* nombre);
void imprimirTabla();
void liberarTabla();

// Funciones adicionales para compatibilidad
int buscarTabla(int indice, char* nombre, struct simbolo tabla[]);
int agregarSimbolo(char* nombre, char* tipo);
char* obtenerRegistro(int pos);

#endif
