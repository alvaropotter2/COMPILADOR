#include "tabla_simbolos_funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tFuncion tablaFunciones[50];
int indiceFunciones = 0;

void agregarFuncion(char* nombre, struct ast* parametros, struct ast* cuerpo) {
    if (indiceFunciones < 50) {
        tablaFunciones[indiceFunciones].nombre = malloc(strlen(nombre) + 1);
        strcpy(tablaFunciones[indiceFunciones].nombre, nombre);
        tablaFunciones[indiceFunciones].parametros = parametros;
        tablaFunciones[indiceFunciones].cuerpo = cuerpo;
        indiceFunciones++;
        printf("Funcion '%s' agregada a la tabla\n", nombre);
    } else {
        printf("Error: Tabla de funciones llena\n");
    }
}

int buscarFuncion(char* nombre) {
    for (int i = 0; i < indiceFunciones; i++) {
        if (strcmp(tablaFunciones[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}