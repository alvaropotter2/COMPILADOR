#define _GNU_SOURCE
#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables globales
struct simbolo tabla[MAX_SIMBOLOS];
int indice = 0;
// num_linea is defined in the lexer, so we don't define it here

void inicializarTabla() {
    indice = 0;
    for (int i = 0; i < MAX_SIMBOLOS; i++) {
        tabla[i].nombre = NULL;
        tabla[i].tipo = NULL;
        tabla[i].integer = 0;
        tabla[i].string = NULL;
        tabla[i].registro = -1;
        tabla[i].linea = 0;
        tabla[i].inicializada = 0;
    }
}

// Función auxiliar compatible con strdup
char* my_strdup(const char* s) {
    if (s == NULL) return NULL;
    size_t len = strlen(s) + 1;
    char* copy = malloc(len);
    if (copy) {
        memcpy(copy, s, len);
    }
    return copy;
}

int insertarSimbolo(char* nombre, char* tipo, int valor, char* cadena) {
    if (indice >= MAX_SIMBOLOS) {
        fprintf(stderr, "Error: Tabla de símbolos llena\n");
        return -1;
    }
    
    // Verificar si ya existe
    for (int i = 0; i < indice; i++) {
        if (tabla[i].nombre && strcmp(tabla[i].nombre, nombre) == 0) {
            // Actualizar el símbolo existente
            if (tipo && strcmp(tipo, "integer") == 0) {
                tabla[i].integer = valor;
            } else if (tipo && strcmp(tipo, "string") == 0 && cadena) {
                if (tabla[i].string) free(tabla[i].string);
                tabla[i].string = my_strdup(cadena);
            }
            tabla[i].linea = num_linea;
            tabla[i].inicializada = 1;
            return i;
        }
    }
    
    // Insertar nuevo símbolo
    tabla[indice].nombre = my_strdup(nombre);
    tabla[indice].tipo = my_strdup(tipo);
    tabla[indice].registro = indice % 8;
    tabla[indice].linea = num_linea;
    tabla[indice].inicializada = 1;
    
    if (strcmp(tipo, "integer") == 0) {
        tabla[indice].integer = valor;
        tabla[indice].string = NULL;
    } else if (strcmp(tipo, "string") == 0) {
        tabla[indice].integer = 0;
        tabla[indice].string = cadena ? my_strdup(cadena) : NULL;
    }
    
    return indice++;
}

int buscarSimbolo(char* nombre) {
    for (int i = 0; i < indice; i++) {
        if (tabla[i].nombre && strcmp(tabla[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void imprimirTabla() {
    printf("\n=== TABLA DE SIMBOLOS ===\n");
    printf("Pos | Nombre      | Tipo     | Valor   | Reg | Linea | Init\n");
    printf("----|-------------|----------|---------|-----|-------|-----\n");
    
    for (int i = 0; i < indice; i++) {
        if (tabla[i].nombre) {
            printf("%-3d | %-11s | %-8s | ", i, tabla[i].nombre, tabla[i].tipo);
            
            if (strcmp(tabla[i].tipo, "integer") == 0) {
                printf("%-7d", tabla[i].integer);
            } else if (strcmp(tabla[i].tipo, "string") == 0) {
                printf("%-7s", tabla[i].string ? tabla[i].string : "NULL");
            } else {
                printf("%-7s", "N/A");
            }
            
            printf(" | $t%-2d | %-5d | %-4d\n", tabla[i].registro, tabla[i].linea, tabla[i].inicializada);
        }
    }
    printf("=============================\n");
}

void liberarTabla() {
    for (int i = 0; i < indice; i++) {
        if (tabla[i].nombre) {
            free(tabla[i].nombre);
            tabla[i].nombre = NULL;
        }
        if (tabla[i].tipo) {
            free(tabla[i].tipo);
            tabla[i].tipo = NULL;
        }
        if (tabla[i].string) {
            free(tabla[i].string);
            tabla[i].string = NULL;
        }
    }
    indice = 0;
}

// Funciones adicionales para compatibilidad
int buscarTabla(int idx, char* nombre, struct simbolo tabla_param[]) {
    for (int i = 0; i < idx; i++) {
        if (tabla_param[i].nombre && strcmp(tabla_param[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

int agregarSimbolo(char* nombre, char* tipo) {
    return insertarSimbolo(nombre, tipo, 0, NULL);
}

char* obtenerRegistro(int pos) {
    static char reg[8];
    if (pos >= 0 && pos < MAX_SIMBOLOS) {
        snprintf(reg, sizeof(reg), "$t%d", tabla[pos].registro);
        return reg;
    }
    return "$t0";
}