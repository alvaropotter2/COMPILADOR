#ifndef TABLA_SIMBOLOS_FUNCIONES_H
#define TABLA_SIMBOLOS_FUNCIONES_H

#include "AST_ruby.h"

// Estructura para almacenar funciones
typedef struct {
    char* nombre;
    struct ast* parametros;
    struct ast* cuerpo;
} tFuncion;

// Tabla de funciones
extern tFuncion tablaFunciones[50];
extern int indiceFunciones;

// Prototipos de funciones
void agregarFuncion(char* nombre, struct ast* parametros, struct ast* cuerpo);
int buscarFuncion(char* nombre);

#endif