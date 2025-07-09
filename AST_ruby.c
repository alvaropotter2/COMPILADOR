#define _GNU_SOURCE
#include "AST_ruby.h"
#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables globales para generar código
static int etiqueta_contador = 0;
static int registro_contador = 0;
static int string_concat_contador = 0;

// ========================= FUNCIONES DE CREACIÓN DE NODOS =========================

struct ast* crearNodoTerminal(int valor) {
    struct ast* nodo = malloc(sizeof(struct ast));
    if (!nodo) {
        printf("ERROR: No se pudo allocar memoria para nodo\n");
        return NULL;
    }
    
    // CRÍTICO: Inicializar TODO a 0 primero
    memset(nodo, 0, sizeof(struct ast));
    
    nodo->tipo = NODO_NUMERO;
    // CRÍTICO: Asignar DIRECTAMENTE el valor entero
    nodo->valor.intVal = valor;
    nodo->esFloat = 0;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    
    printf("DEBUG CRITICO: Creando nodo entero con valor %d (stored as intVal=%d, address=%p)\n", 
           valor, nodo->valor.intVal, (void*)nodo);
    
    return nodo;
}

struct ast* crearNodoTerminalFloat(float valor) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_NUMERO;
    nodo->valor.floatVal = valor;
    nodo->esFloat = 1;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    printf("DEBUG: Creando nodo float con valor %.6f\n", valor);
    return nodo;
}

struct ast* crearNodoTerminalString(char* valor) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_STRING;
    nodo->valor.stringVal = strdup(valor);
    nodo->esFloat = 0;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoTerminalBool(int valor) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_BOOLEAN;
    nodo->valor.boolVal = valor;
    nodo->esFloat = 0;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearVariableTerminal(void* valor, int registro) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_VARIABLE;
    nodo->valor.stringVal = (char*)valor;
    nodo->esFloat = 0;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->resultado = registro % 10;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoVariable(char* nombre, int registro) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_VARIABLE;
    nodo->valor.stringVal = strdup(nombre);
    nodo->esFloat = 0;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->resultado = registro % 10;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoNoTerminal(struct ast* izq, struct ast* der, tipoNodo tipo) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = tipo;
    nodo->izquierdo = izq;
    nodo->derecho = der;
    nodo->siguiente = NULL;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoUnario(struct ast* hijo, tipoNodo tipo) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = tipo;
    nodo->izquierdo = hijo;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoAsignacion(char* identificador, struct ast* expresion) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_ASIGNACION;
    nodo->valor.stringVal = strdup(identificador);
    nodo->esFloat = 0;
    nodo->izquierdo = NULL;
    nodo->derecho = expresion;
    nodo->siguiente = NULL;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoAsignacionCompuesta(char* identificador, struct ast* expresion, tipoNodo operacion) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_ASIGNACION_COMPUESTA;
    nodo->valor.stringVal = strdup(identificador);
    nodo->izquierdo = expresion;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoPuts(struct ast* expresion) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_PUTS;
    nodo->izquierdo = expresion;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoCondicional(struct ast* condicion, struct ast* bloqueIf, struct ast* bloqueElse) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_CONDICIONAL;
    nodo->izquierdo = condicion;
    nodo->derecho = bloqueIf;
    nodo->siguiente = bloqueElse;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoBucle(struct ast* condicion, struct ast* cuerpo) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_BUCLE;
    nodo->izquierdo = condicion;
    nodo->derecho = cuerpo;
    nodo->esFloat = 0;
    nodo->siguiente = NULL;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoVacio() {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_VACIO;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->resultado = 0;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    nodo->esFloat = 0;
    return nodo;
}

// Funciones para Hito 2
struct ast* crearNodoFuncion(char* nombre, struct ast* parametros, struct ast* cuerpo) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_FUNCION;
    nodo->valor.stringVal = strdup(nombre);
    nodo->izquierdo = parametros;
    nodo->derecho = cuerpo;
    nodo->siguiente = NULL;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoLlamadaFuncion(char* nombre, struct ast* argumentos) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_LLAMADA_FUNCION;
    nodo->valor.stringVal = strdup(nombre);
    nodo->izquierdo = argumentos;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoParametro(char* nombre) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_PARAMETRO;
    nodo->valor.stringVal = strdup(nombre);
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->siguiente = NULL;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoAccesoArray(char* nombre, struct ast* indice1, struct ast* indice2) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_ACCESO_ARRAY;
    nodo->valor.stringVal = strdup(nombre);
    nodo->izquierdo = indice1;
    nodo->derecho = indice2;
    nodo->siguiente = NULL;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

struct ast* crearNodoAsignacionArray(char* nombre, struct ast* indice1, struct ast* indice2, struct ast* valor) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipo = NODO_ASIGNACION_ARRAY;
    nodo->valor.stringVal = strdup(nombre);
    nodo->izquierdo = indice1;
    nodo->derecho = indice2;
    nodo->siguiente = valor;
    nodo->esFloat = 0;
    nodo->resultado = registro_contador % 10;
    registro_contador++;
    nodo->etiqueta = NULL;
    nodo->linea = 0;
    return nodo;
}

// ========================= FUNCIONES DE UTILIDAD =========================

void liberarAST(struct ast* nodo) {
    if (nodo == NULL) return;
    
    liberarAST(nodo->izquierdo);
    liberarAST(nodo->derecho);
    liberarAST(nodo->siguiente);
    
    if (nodo->valor.stringVal && (nodo->tipo == NODO_STRING || nodo->tipo == NODO_IDENTIFICADOR || 
        nodo->tipo == NODO_VARIABLE || nodo->tipo == NODO_ASIGNACION)) {
        free(nodo->valor.stringVal);
    }
    
    if (nodo->etiqueta) {
        free(nodo->etiqueta);
    }
    
    free(nodo);
}

void imprimirAST(struct ast* nodo, int nivel) {
    if (nodo == NULL) return;
    
    for (int i = 0; i < nivel; i++) printf("  ");
    
    switch (nodo->tipo) {
        case NODO_NUMERO:
            printf("NUMERO: %d\n", nodo->valor.intVal);
            break;
        case NODO_STRING:
            printf("STRING: %s\n", nodo->valor.stringVal);
            break;
        case NODO_BOOLEAN:
            printf("BOOLEAN: %s\n", nodo->valor.boolVal ? "true" : "false");
            break;
        case NODO_VARIABLE:
            printf("VARIABLE: %s\n", nodo->valor.stringVal);
            break;
        case NODO_ASIGNACION:
            printf("ASIGNACION a %s\n", nodo->valor.stringVal);
            break;
        case SUMA:
            printf("SUMA\n");
            break;
        case RESTA:
            printf("RESTA\n");
            break;
        case MULTIPLICACION:
            printf("MULTIPLICACION\n");
            break;
        case DIVISION:
            printf("DIVISION\n");
            break;
        case CONCATENACION:
            printf("CONCATENACION\n");
            break;
        case AND_LOGICO:
            printf("AND_LOGICO\n");
            break;
        case OR_LOGICO:
            printf("OR_LOGICO\n");
            break;
        case NOT_LOGICO:
            printf("NOT_LOGICO\n");
            break;
        case NODO_PUTS:
            printf("PUTS\n");
            break;
        case NODO_CONDICIONAL:
            printf("IF\n");
            break;
        case NODO_BUCLE:
            printf("WHILE\n");
            break;
        case NODO_FUNCION:
            printf("FUNCION: %s\n", nodo->valor.stringVal);
            break;
        default:
            printf("NODO_TIPO_%d\n", nodo->tipo);
            break;
    }
    
    if (nodo->izquierdo) {
        imprimirAST(nodo->izquierdo, nivel + 1);
    }
    if (nodo->derecho) {
        imprimirAST(nodo->derecho, nivel + 1);
    }
    if (nodo->siguiente) {
        imprimirAST(nodo->siguiente, nivel + 1);
    }
}

void comprobarAST(struct ast* nodo) {
    if (nodo == NULL) {
        printf("AST está vacío\n");
        return;
    }
    
    printf("\n=== ESTRUCTURA DEL AST ===\n");
    imprimirAST(nodo, 0);
    printf("========================\n");
    
    // AGREGAR IMPRESIÓN DE LA TABLA DE SÍMBOLOS
    imprimirTabla();
    
    printf("Generando código MIPS...\n");
    generarMIPSCompleto(nodo, "programa.rb");
}

// ========================= FUNCIONES DE GENERACIÓN DE CÓDIGO =========================

void generarCodigo(struct ast* nodo) {
    if (nodo == NULL) return;
    generarCodigoMIPS(nodo);
}

void generarCodigoMIPS(struct ast* nodo) {
    if (nodo == NULL) return;
    generarCodigoMIPSArchivo(nodo, stdout);
}

void generarStringsEnDatos(struct ast* nodo, FILE* archivo) {
    if (nodo == NULL) return;
    
    if (nodo->tipo == NODO_STRING) {
        fprintf(archivo, "    str_%p: .asciiz %s\n", (void*)nodo, nodo->valor.stringVal);
    }
    
    generarStringsEnDatos(nodo->izquierdo, archivo);
    generarStringsEnDatos(nodo->derecho, archivo);
    generarStringsEnDatos(nodo->siguiente, archivo);
}

void generarDefinicionesFunciones(struct ast* nodo, FILE* archivo) {
    if (nodo == NULL) return;
    
    if (nodo->tipo == NODO_FUNCION) {
        fprintf(archivo, "# Función: %s\n", nodo->valor.stringVal);
        fprintf(archivo, "func_%s:\n", nodo->valor.stringVal);
        generarCodigoMIPSArchivo(nodo->derecho, archivo);
        fprintf(archivo, "    jr $ra\n\n");
    }
    
    generarDefinicionesFunciones(nodo->izquierdo, archivo);
    generarDefinicionesFunciones(nodo->derecho, archivo);
    generarDefinicionesFunciones(nodo->siguiente, archivo);
}

void generarCodigoFuncion(struct ast* nodo, FILE* archivo, const char* nombreFuncion) {
    if (nodo == NULL) return;
    
    fprintf(archivo, "# Cuerpo de función %s\n", nombreFuncion);
    generarCodigoMIPSArchivo(nodo, archivo);
}

void generarCodigoPrincipal(struct ast* nodo, FILE* archivo) {
    if (nodo == NULL) return;
    
    fprintf(archivo, "programa_principal:\n");
    generarCodigoMIPSArchivo(nodo, archivo);
}

int obtenerNuevoRegistro() {
    int reg = registro_contador % 10;
    registro_contador++;
    return reg;
}

char* obtenerNuevaEtiqueta() {
    char* etiqueta = malloc(20);
    sprintf(etiqueta, "etiq_%d", etiqueta_contador++);
    return etiqueta;
}

int esOperacionFloat(struct ast* nodo) {
    if (nodo == NULL) return 0;
    
    if (nodo->tipo == NODO_NUMERO && nodo->valor.floatVal != (int)nodo->valor.intVal) {
        return 1;
    }
    
    return 0;
}

// FUNCIONES AUXILIARES CORREGIDAS

int esVariableString(char* nombreVar) {
    int pos = buscarSimbolo(nombreVar);
    if (pos != -1 && tabla[pos].tipo && strcmp(tabla[pos].tipo, "string") == 0) {
        return 1;
    }
    return 0;
}

int esVariableFloat(char* nombreVar) {
    int pos = buscarSimbolo(nombreVar);
    if (pos != -1 && tabla[pos].tipo && strcmp(tabla[pos].tipo, "float") == 0) {
        return 1;
    }
    return 0;
}

int esComparacionStrings(struct ast* izq, struct ast* der) {
    if (izq && izq->tipo == NODO_STRING) return 1;
    if (der && der->tipo == NODO_STRING) return 1;
    
    if (izq && izq->tipo == NODO_VARIABLE && esVariableString(izq->valor.stringVal)) return 1;
    if (der && der->tipo == NODO_VARIABLE && esVariableString(der->valor.stringVal)) return 1;
    
    return 0;
}

// FUNCIÓN COMPLETAMENTE CORREGIDA: Solo es float si realmente tiene decimales
int esNodoFloat(struct ast* nodo) {
    if (nodo == NULL) return 0;
    
 
    if (nodo->tipo == NODO_NUMERO) {
        return nodo->esFloat;
    }

    if (nodo->tipo == SUMA || nodo->tipo == RESTA || nodo->tipo == MULTIPLICACION || nodo->tipo == DIVISION) {
        return esNodoFloat(nodo->izquierdo) || esNodoFloat(nodo->derecho);
    }
    
    if (nodo->tipo == NODO_IDENTIFICADOR || nodo->tipo == NODO_VARIABLE) {
        int pos = buscarSimbolo(nodo->valor.stringVal);
        if (pos >= 0 && tabla[pos].tipo) {
            return strcmp(tabla[pos].tipo, "float") == 0;
        }
    }
    
    return 0;
}

int esNodoEntero(struct ast* nodo) {
    if (nodo == NULL) return 0;
    
    if (nodo->tipo == NODO_NUMERO) {
        return 1;  // TODOS los números son enteros
    }
    
    if (nodo->tipo == NODO_VARIABLE) {
        int pos = buscarSimbolo(nodo->valor.stringVal);
        if (pos != -1 && tabla[pos].tipo && strcmp(tabla[pos].tipo, "integer") == 0) {
            return 1;
        }
    }
    
    return 0;
}

// FUNCIÓN PRINCIPAL COMPLETAMENTE CORREGIDA PARA USAR SOLO ENTEROS
void generarCodigoMIPSArchivo(struct ast* nodo, FILE* archivo) {
    if (nodo == NULL) return;
    
    switch (nodo->tipo) {
        case NODO_SECUENCIA:
            fprintf(archivo, "    # Secuencia de instrucciones\n");
            generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
            generarCodigoMIPSArchivo(nodo->derecho, archivo);
            if (nodo->siguiente != NULL) {
                generarCodigoMIPSArchivo(nodo->siguiente, archivo);
            }
            break;
            
        case NODO_ASIGNACION:
            fprintf(archivo, "    # Asignacion a %s\n", nodo->valor.stringVal);
            if (nodo->derecho != NULL) {
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                if (esVariableFloat(nodo->valor.stringVal)) {
                    /* Guardar resultado float en variable (resultado en $f0) */
                    fprintf(archivo, "    s.s $f0, var_%s\n", nodo->valor.stringVal);
                } else if (esVariableString(nodo->valor.stringVal)) {
                    /* Para strings, $v0 ya contiene la direccion */
                    fprintf(archivo, "    sw $v0, var_%s\n", nodo->valor.stringVal);
                } else {
                    fprintf(archivo, "    sw $v0, var_%s\n", nodo->valor.stringVal);
                }
            }
            break;
            
        case NODO_PUTS:
            fprintf(archivo, "    # PUTS statement\n");
            if (nodo->izquierdo != NULL) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                
                switch (nodo->izquierdo->tipo) {
                    case NODO_STRING:
                        fprintf(archivo, "    la $a0, str_%p\n", (void*)nodo->izquierdo);
                        fprintf(archivo, "    li $v0, 4\n");
                        break;
                    case NODO_VARIABLE:
                    case NODO_IDENTIFICADOR:
                        if (esVariableString(nodo->izquierdo->valor.stringVal)) {
                            fprintf(archivo, "    lw $a0, var_%s\n", nodo->izquierdo->valor.stringVal);
                            fprintf(archivo, "    li $v0, 4\n");
			} else if (esVariableFloat(nodo->izquierdo->valor.stringVal)) {
                            fprintf(archivo, "    l.s $f12, var_%s\n", nodo->izquierdo->valor.stringVal);
                            fprintf(archivo, "    li $v0, 2\n");

                        } else {
                            
                            fprintf(archivo, "    lw $a0, var_%s\n", nodo->izquierdo->valor.stringVal);
                            fprintf(archivo, "    li $v0, 1\n");
                        }
                        break;
                    default:

                        if (esNodoFloat(nodo->izquierdo)) {
                            fprintf(archivo, "    mov.s $f12, $f0\n");
                            fprintf(archivo, "    li $v0, 2\n");
                        } else {
                            fprintf(archivo, "    move $a0, $v0\n");
                            fprintf(archivo, "    li $v0, 1\n");
                        }
			break;
                }
                
                fprintf(archivo, "    syscall\n");
                fprintf(archivo, "    la $a0, newline\n");
                fprintf(archivo, "    li $v0, 4\n");
                fprintf(archivo, "    syscall\n");
            }
            break;
            
        case NODO_NUMERO:
            if (esNodoFloat(nodo)) {
                printf("DEBUG: Generando codigo para float %.6f\n", nodo->valor.floatVal);
                fprintf(archivo, "    l.s $f0, flt_%p\n", (void*)nodo);
            } else {
                printf("DEBUG CRITICO: Generando código para nodo NUMERO - intVal=%d (address=%p)\n",
                       nodo->valor.intVal, (void*)nodo);
                fprintf(archivo, "    li $v0, %d\n", nodo->valor.intVal);
            }
            break;

	case NODO_BOOLEAN:
            fprintf(archivo, "    li $v0, %d\n", nodo->valor.boolVal);
            break;
	
	case NODO_STRING:
            fprintf(archivo, "    la $v0, str_%p\n", (void*)nodo);
            break;
            
        case NODO_VARIABLE:
            if (esVariableFloat(nodo->valor.stringVal)) {
                fprintf(archivo, "    l.s $f0, var_%s\n", nodo->valor.stringVal);
            } else {
                fprintf(archivo, "    lw $v0, var_%s\n", nodo->valor.stringVal);
            }
            break;
            
        case SUMA:
            fprintf(archivo, "    # Suma\n");
            if (esNodoFloat(nodo->izquierdo) || esNodoFloat(nodo->derecho)) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                if (!esNodoFloat(nodo->izquierdo)) {
                    fprintf(archivo, "    mtc1 $v0, $f2\n");
                    fprintf(archivo, "    cvt.s.w $f2, $f2\n");
                } else {
                    fprintf(archivo, "    mov.s $f2, $f0\n");
                }
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                if (!esNodoFloat(nodo->derecho)) {
                    fprintf(archivo, "    mtc1 $v0, $f4\n");
                    fprintf(archivo, "    cvt.s.w $f4, $f4\n");
                } else {
                    fprintf(archivo, "    mov.s $f4, $f0\n");
                }
                fprintf(archivo, "    add.s $f0, $f2, $f4\n");
            } else {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    move $t8, $v0       # Guardar primer operando\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    add $v0, $t8, $v0   # Sumar\n");
            }
            break;
            
        case RESTA:
            fprintf(archivo, "    # Resta\n");
            if (esNodoFloat(nodo->izquierdo) || esNodoFloat(nodo->derecho)) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                if (!esNodoFloat(nodo->izquierdo)) {
                    fprintf(archivo, "    mtc1 $v0, $f2\n");
                    fprintf(archivo, "    cvt.s.w $f2, $f2\n");
                } else {
                    fprintf(archivo, "    mov.s $f2, $f0\n");
                }
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                if (!esNodoFloat(nodo->derecho)) {
                    fprintf(archivo, "    mtc1 $v0, $f4\n");
                    fprintf(archivo, "    cvt.s.w $f4, $f4\n");
                } else {
                    fprintf(archivo, "    mov.s $f4, $f0\n");
                }
                fprintf(archivo, "    sub.s $f0, $f2, $f4\n");
            } else {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    move $t8, $v0       # Guardar primer operando\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    sub $v0, $t8, $v0   # Restar\n");
            }
            break;
            
        case MULTIPLICACION:
            fprintf(archivo, "    # Multiplicacion\n");
            if (esNodoFloat(nodo->izquierdo) || esNodoFloat(nodo->derecho)) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                if (!esNodoFloat(nodo->izquierdo)) {
                    fprintf(archivo, "    mtc1 $v0, $f2\n");
                    fprintf(archivo, "    cvt.s.w $f2, $f2\n");
                } else {
                    fprintf(archivo, "    mov.s $f2, $f0\n");
                }
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                if (!esNodoFloat(nodo->derecho)) {
                    fprintf(archivo, "    mtc1 $v0, $f4\n");
                    fprintf(archivo, "    cvt.s.w $f4, $f4\n");
                } else {
                    fprintf(archivo, "    mov.s $f4, $f0\n");
                }
                fprintf(archivo, "    mul.s $f0, $f2, $f4\n");
            } else {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    move $t8, $v0       # Guardar primer operando\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    mult $t8, $v0       # Multiplicar\n");
                fprintf(archivo, "    mflo $v0            # Obtener resultado\n");
            }
            break;
            
        case DIVISION:
            fprintf(archivo, "    # Division\n");
            if (esNodoFloat(nodo->izquierdo) || esNodoFloat(nodo->derecho)) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                if (!esNodoFloat(nodo->izquierdo)) {
                    fprintf(archivo, "    mtc1 $v0, $f2\n");
                    fprintf(archivo, "    cvt.s.w $f2, $f2\n");
                } else {
                    fprintf(archivo, "    mov.s $f2, $f0\n");
                }
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                if (!esNodoFloat(nodo->derecho)) {
                    fprintf(archivo, "    mtc1 $v0, $f4\n");
                    fprintf(archivo, "    cvt.s.w $f4, $f4\n");
                } else {
                    fprintf(archivo, "    mov.s $f4, $f0\n");
                }
                fprintf(archivo, "    div.s $f0, $f2, $f4\n");
            } else {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    move $t8, $v0       # Guardar primer operando\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    div $t8, $v0        # Dividir\n");
                fprintf(archivo, "    mflo $v0            # Obtener cociente\n");
            }
            break;

        case CONCATENACION:
            fprintf(archivo, "    # Concatenacion de strings\n");
	    generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
	    fprintf(archivo, "    move $a0, $v0\n");
            generarCodigoMIPSArchivo(nodo->derecho, archivo);
            fprintf(archivo, "    move $a1, $v0\n");
            fprintf(archivo, "    jal concatenar_strings\n");
            break;

	 case AND_LOGICO:
            fprintf(archivo, "    # AND logico\n");
	    generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
	    fprintf(archivo, "    move $t8, $v0\n");
            generarCodigoMIPSArchivo(nodo->derecho, archivo);
	    fprintf(archivo, "    move $t9, $v0\n");
            fprintf(archivo, "    and $t6, $t8, $t9\n");
            fprintf(archivo, "    sltu $v0, $zero, $t6\n");
            break;

        case OR_LOGICO:
            fprintf(archivo, "    # OR logico\n");
            generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
            fprintf(archivo, "    move $t8, $v0\n");
            generarCodigoMIPSArchivo(nodo->derecho, archivo);
            fprintf(archivo, "    move $t9, $v0\n");
            fprintf(archivo, "    or $t6, $t8, $t9\n");
            fprintf(archivo, "    sltu $v0, $zero, $t6\n");
            break;

        case NOT_LOGICO:
            fprintf(archivo, "    # NOT logico\n");
            generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
            fprintf(archivo, "    sltu $v0, $zero, $v0\n");
            fprintf(archivo, "    xori $v0, $v0, 1\n");
            break;
            
        case MAYOR_QUE:
            fprintf(archivo, "    # Comparacion mayor que\n");
            if (esNodoFloat(nodo->izquierdo) || esNodoFloat(nodo->derecho)) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                if (!esNodoFloat(nodo->izquierdo)) {
                    fprintf(archivo, "    mtc1 $v0, $f2\n");
                    fprintf(archivo, "    cvt.s.w $f2, $f2\n");
                } else {
                    fprintf(archivo, "    mov.s $f2, $f0\n");
                }
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                if (!esNodoFloat(nodo->derecho)) {
                    fprintf(archivo, "    mtc1 $v0, $f4\n");
                    fprintf(archivo, "    cvt.s.w $f4, $f4\n");
                } else {
                    fprintf(archivo, "    mov.s $f4, $f0\n");
                }
                {
                    char* etiq_true = obtenerNuevaEtiqueta();
                    char* etiq_fin = obtenerNuevaEtiqueta();
                    fprintf(archivo, "    c.le.s $f4, $f2\n");
                    fprintf(archivo, "    bc1f %s\n", etiq_true);
                    fprintf(archivo, "    li $v0, 1\n");
                    fprintf(archivo, "    j %s\n", etiq_fin);
                    fprintf(archivo, "%s:\n", etiq_true);
                    fprintf(archivo, "    li $v0, 0\n");
                    fprintf(archivo, "%s:\n", etiq_fin);
                }
            } else {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    move $t8, $v0       # Guardar primer operando\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    move $t9, $v0       # Guardar segundo operando\n");
                fprintf(archivo, "    slt $v0, $t9, $t8   # $v0 = ($t9 < $t8) ? 1 : 0, es decir ($t8 > $t9)\n");
            }
            break;
            
        case MENOR_QUE:
            fprintf(archivo, "    # Comparacion menor que\n");
            if (esNodoFloat(nodo->izquierdo) || esNodoFloat(nodo->derecho)) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                if (!esNodoFloat(nodo->izquierdo)) {
                    fprintf(archivo, "    mtc1 $v0, $f2\n");
                    fprintf(archivo, "    cvt.s.w $f2, $f2\n");
                } else {
                    fprintf(archivo, "    mov.s $f2, $f0\n");
                }
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                if (!esNodoFloat(nodo->derecho)) {
                    fprintf(archivo, "    mtc1 $v0, $f4\n");
                    fprintf(archivo, "    cvt.s.w $f4, $f4\n");
                } else {
                    fprintf(archivo, "    mov.s $f4, $f0\n");
                }
                {
                    char* etiq_true = obtenerNuevaEtiqueta();
                    char* etiq_fin = obtenerNuevaEtiqueta();
                    fprintf(archivo, "    c.lt.s $f2, $f4\n");
                    fprintf(archivo, "    bc1t %s\n", etiq_true);
                    fprintf(archivo, "    li $v0, 0\n");
                    fprintf(archivo, "    j %s\n", etiq_fin);
                    fprintf(archivo, "%s:\n", etiq_true);
                    fprintf(archivo, "    li $v0, 1\n");
                    fprintf(archivo, "%s:\n", etiq_fin);
                }
            } else {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    move $t8, $v0       # Guardar primer operando\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    move $t9, $v0       # Guardar segundo operando\n");
                fprintf(archivo, "    slt $v0, $t8, $t9   # $v0 = ($t8 < $t9) ? 1 : 0\n");
            }
            break;
            
        case IGUAL:
            fprintf(archivo, "    # Comparacion de igualdad\n");
            if (esComparacionStrings(nodo->izquierdo, nodo->derecho)) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    move $a0, $v0\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    move $a1, $v0\n");
                fprintf(archivo, "    jal comparar_strings\n");
            } else if (esNodoFloat(nodo->izquierdo) || esNodoFloat(nodo->derecho)) {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                if (!esNodoFloat(nodo->izquierdo)) {
                    fprintf(archivo, "    mtc1 $v0, $f2\n");
                    fprintf(archivo, "    cvt.s.w $f2, $f2\n");
                } else {
                    fprintf(archivo, "    mov.s $f2, $f0\n");
                }
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                if (!esNodoFloat(nodo->derecho)) {
                    fprintf(archivo, "    mtc1 $v0, $f4\n");
                    fprintf(archivo, "    cvt.s.w $f4, $f4\n");
                } else {
                    fprintf(archivo, "    mov.s $f4, $f0\n");
                }
                {
                    char* etiq_true = obtenerNuevaEtiqueta();
                    char* etiq_fin = obtenerNuevaEtiqueta();
                    fprintf(archivo, "    c.eq.s $f2, $f4\n");
                    fprintf(archivo, "    bc1t %s\n", etiq_true);
                    fprintf(archivo, "    li $v0, 0\n");
                    fprintf(archivo, "    j %s\n", etiq_fin);
                    fprintf(archivo, "%s:\n", etiq_true);
                    fprintf(archivo, "    li $v0, 1\n");
                    fprintf(archivo, "%s:\n", etiq_fin);
                }
            } else {
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    move $t8, $v0       # Guardar primer operando\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    move $t9, $v0       # Guardar segundo operando\n");
                fprintf(archivo, "    seq $v0, $t8, $t9   # $v0 = ($t8 == $t9) ? 1 : 0\n");
            }
            
        case NODO_CONDICIONAL:
            {
                char etiq_else[32], etiq_fin[32];
                sprintf(etiq_else, "else_%d", etiqueta_contador);
                sprintf(etiq_fin, "fin_if_%d", etiqueta_contador);
                etiqueta_contador++;
                
                fprintf(archivo, "    # IF condicional\n");
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    beq $v0, $zero, %s   # Si condicion es falsa, ir a else\n", etiq_else);
                
                fprintf(archivo, "    # Bloque IF\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    j %s                # Saltar al final\n", etiq_fin);
                
                fprintf(archivo, "%s:\n", etiq_else);
                fprintf(archivo, "    # Bloque ELSE\n");
                if (nodo->siguiente != NULL) {
                    generarCodigoMIPSArchivo(nodo->siguiente, archivo);
                }
                
                fprintf(archivo, "%s:\n", etiq_fin);
            }
            break;
            
        case NODO_BUCLE:
            {
                char etiq_inicio[32], etiq_fin[32];
                sprintf(etiq_inicio, "while_start_%d", etiqueta_contador);
                sprintf(etiq_fin, "while_end_%d", etiqueta_contador);
                etiqueta_contador++;
                
                fprintf(archivo, "    # WHILE bucle\n");
                fprintf(archivo, "%s:\n", etiq_inicio);
                
                fprintf(archivo, "    # Evaluar condicion del while\n");
                generarCodigoMIPSArchivo(nodo->izquierdo, archivo);
                fprintf(archivo, "    beq $v0, $zero, %s   # Si condicion es falsa, salir del bucle\n", etiq_fin);
                
                fprintf(archivo, "    # Cuerpo del while\n");
                generarCodigoMIPSArchivo(nodo->derecho, archivo);
                fprintf(archivo, "    j %s                # Volver al inicio del bucle\n", etiq_inicio);
                
                fprintf(archivo, "%s:\n", etiq_fin);
            }
            break;
            
        case NODO_VACIO:
            // No hacer nada para nodos vacíos
            break;
            
        default:
            fprintf(archivo, "    # Nodo tipo %d no implementado\n", nodo->tipo);
            break;
    }
}
