#include "AST_ruby.h"
#include "tabla_simbolos.h"
#include "tabla_simbolos_funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNCIÓN CORREGIDA: NO generar constantes float para números enteros
void generarConstantesFloatEnDatos(struct ast* nodo, FILE* archivo) {
    if (nodo == NULL) return;
    
    if (nodo->tipo == NODO_NUMERO) {
        // CRÍTICO: NO generar float para ningún número entero
        printf("DEBUG: Examinando número %d - NO generando constante float\n", nodo->valor.intVal);
    }
    
    // Recorrer recursivamente todos los nodos
    generarConstantesFloatEnDatos(nodo->izquierdo, archivo);
    generarConstantesFloatEnDatos(nodo->derecho, archivo);
    generarConstantesFloatEnDatos(nodo->siguiente, archivo);
}

void generarFuncionesAuxiliares(FILE* archivo) {
    fprintf(archivo, "\n# ===== FUNCIONES AUXILIARES =====\n");
    
    // Función para concatenar strings (implementación corregida)
    fprintf(archivo, "concatenar_strings:\n");
    fprintf(archivo, "    # $a0 = string1, $a1 = string2\n");
    fprintf(archivo, "    # Guardar parámetros antes del syscall\n");
    fprintf(archivo, "    move $t8, $a0       # guardar string1 original\n");
    fprintf(archivo, "    move $t9, $a1       # guardar string2 original\n");
    fprintf(archivo, "    \n");
    fprintf(archivo, "    # Reservar espacio para resultado concatenado (512 bytes)\n");
    fprintf(archivo, "    li $v0, 9           # syscall para sbrk (allocate memory)\n");
    fprintf(archivo, "    li $a0, 512         # 512 bytes para el resultado\n");
    fprintf(archivo, "    syscall             # $v0 ahora contiene dirección del buffer\n");
    fprintf(archivo, "    move $t0, $v0       # guardar dirección del buffer en $t0\n");
    fprintf(archivo, "    move $t1, $v0       # $t1 = posición actual en buffer\n");
    fprintf(archivo, "    \n");
    fprintf(archivo, "    # Copiar primer string\n");
    fprintf(archivo, "    move $t2, $t8       # $t2 = dirección del primer string (restaurado)\n");
    fprintf(archivo, "copy_first:\n");
    fprintf(archivo, "    lb $t3, 0($t2)      # cargar byte del primer string\n");
    fprintf(archivo, "    beq $t3, $zero, copy_second  # si es 0, terminar primer string\n");
    fprintf(archivo, "    sb $t3, 0($t1)      # guardar byte en buffer\n");
    fprintf(archivo, "    addi $t2, $t2, 1    # siguiente byte del primer string\n");
    fprintf(archivo, "    addi $t1, $t1, 1    # siguiente posición en buffer\n");
    fprintf(archivo, "    j copy_first\n");
    fprintf(archivo, "    \n");
    fprintf(archivo, "copy_second:\n");
    fprintf(archivo, "    move $t2, $t9       # $t2 = dirección del segundo string (restaurado)\n");
    fprintf(archivo, "copy_second_loop:\n");
    fprintf(archivo, "    lb $t3, 0($t2)      # cargar byte del segundo string\n");
    fprintf(archivo, "    beq $t3, $zero, concat_done  # si es 0, terminar\n");
    fprintf(archivo, "    sb $t3, 0($t1)      # guardar byte en buffer\n");
    fprintf(archivo, "    addi $t2, $t2, 1    # siguiente byte del segundo string\n");
    fprintf(archivo, "    addi $t1, $t1, 1    # siguiente posición en buffer\n");
    fprintf(archivo, "    j copy_second_loop\n");
    fprintf(archivo, "    \n");
    fprintf(archivo, "concat_done:\n");
    fprintf(archivo, "    sb $zero, 0($t1)    # terminar string con null\n");
    fprintf(archivo, "    move $v0, $t0       # devolver dirección del buffer\n");
    fprintf(archivo, "    jr $ra\n\n");
    
    // Función para comparar strings
    fprintf(archivo, "comparar_strings:\n");
    fprintf(archivo, "    # $a0 = string1, $a1 = string2\n");
    fprintf(archivo, "    move $t0, $a0       # $t0 = dirección string1\n");
    fprintf(archivo, "    move $t1, $a1       # $t1 = dirección string2\n");
    fprintf(archivo, "compare_loop:\n");
    fprintf(archivo, "    lb $t2, 0($t0)      # cargar byte de string1\n");
    fprintf(archivo, "    lb $t3, 0($t1)      # cargar byte de string2\n");
    fprintf(archivo, "    bne $t2, $t3, not_equal  # si son diferentes, no son iguales\n");
    fprintf(archivo, "    beq $t2, $zero, strings_equal  # si ambos son 0, son iguales\n");
    fprintf(archivo, "    addi $t0, $t0, 1    # siguiente byte string1\n");
    fprintf(archivo, "    addi $t1, $t1, 1    # siguiente byte string2\n");
    fprintf(archivo, "    j compare_loop\n");
    fprintf(archivo, "not_equal:\n");
    fprintf(archivo, "    li $v0, 0           # devolver 0 (false)\n");
    fprintf(archivo, "    jr $ra\n");
    fprintf(archivo, "strings_equal:\n");
    fprintf(archivo, "    li $v0, 1           # devolver 1 (true)\n");
    fprintf(archivo, "    jr $ra\n\n");
}

void generarMIPSCompleto(struct ast* nodo, const char* nombreArchivo) {
    printf("Iniciando generacion de codigo MIPS...\n");
    
    FILE* archivo = fopen("ruby.asm", "w");
    if (!archivo) {
        fprintf(stderr, "Error: No se pudo crear el archivo ruby.asm\n");
        printf("=== ERROR AL CREAR ARCHIVO ===\n");
        return;
    }
    
    printf("Archivo ruby.asm creado exitosamente\n");
    
    fprintf(archivo, "# Codigo MIPS generado por el compilador Ruby -> MIPS\n");
    fprintf(archivo, "# Archivo fuente: %s\n", nombreArchivo);
    fprintf(archivo, "# Generado automaticamente\n\n");
    
    // Seccion de datos
    fprintf(archivo, ".data\n");
    fprintf(archivo, "    newline: .asciiz \"\\n\"\n");
    
    // Generar strings de datos
    generarStringsEnDatos(nodo, archivo);
    
    // NO generar constantes float para números enteros
    printf("NO generando constantes float para enteros...\n");
    
    printf("Generando seccion de datos...\n");
    
    // Generar variables de la tabla de simbolos (evitar duplicados)
    int variables_generadas[256] = {0};
    
    for (int i = 0; i < indice; i++) {
        if (tabla[i].nombre != NULL && !variables_generadas[i]) {
            variables_generadas[i] = 1;
            
            // Verificar duplicados y marcarlos
            for (int j = i + 1; j < indice; j++) {
                if (tabla[j].nombre != NULL && strcmp(tabla[i].nombre, tabla[j].nombre) == 0) {
                    variables_generadas[j] = 1;
                    if (strcmp(tabla[j].tipo, "integer") == 0) {
                        tabla[i].integer = tabla[j].integer;
                    } else if (strcmp(tabla[j].tipo, "float") == 0) {
                        tabla[i].floatDecimal = tabla[j].floatDecimal;
                    } else if (strcmp(tabla[j].tipo, "boolean") == 0) {
                        tabla[i].boolean = tabla[j].boolean;
                    }
                }
            }
            
            if (strcmp(tabla[i].tipo, "integer") == 0) {
                fprintf(archivo, "    var_%s: .word %d\n", tabla[i].nombre, tabla[i].integer);
                printf("Variable generada: %s = %d\n", tabla[i].nombre, tabla[i].integer);
            } else if (strcmp(tabla[i].tipo, "float") == 0) {
                fprintf(archivo, "    var_%s: .float %.6f\n", tabla[i].nombre, tabla[i].floatDecimal);
                printf("Variable float generada: %s = %.6f\n", tabla[i].nombre, tabla[i].floatDecimal);
            } else if (strcmp(tabla[i].tipo, "boolean") == 0) {
                fprintf(archivo, "    var_%s: .word %d\n", tabla[i].nombre, tabla[i].boolean);
                printf("Variable boolean generada: %s = %d\n", tabla[i].nombre, tabla[i].boolean);
            } else if (strcmp(tabla[i].tipo, "string") == 0) {
                // Para strings, solo declarar espacio para el puntero
                fprintf(archivo, "    var_%s: .word 0\n", tabla[i].nombre);
                printf("Variable string generada: %s\n", tabla[i].nombre);
            }
        }
    }
    
    fprintf(archivo, "\n.text\n");
    fprintf(archivo, ".globl main\n\n");
    
    // CAMBIO CRÍTICO: Salto directo a main al inicio
    fprintf(archivo, "# Salto directo a main para evitar ejecución de funciones auxiliares\n");
    fprintf(archivo, "j main\n\n");
    
    // Generar funciones auxiliares DESPUÉS del salto a main
    generarFuncionesAuxiliares(archivo);
    
    fprintf(archivo, "main:\n");
    fprintf(archivo, "    # Inicio del programa principal\n");
    
    printf("Generando codigo principal...\n");
    
    // Generar código para el AST
    if (nodo != NULL) {
        generarCodigoMIPSArchivo(nodo, archivo);
        printf("Codigo AST generado exitosamente\n");
    } else {
        fprintf(archivo, "    # Programa vacio\n");
        fprintf(archivo, "    li $t0, 42\n");
        fprintf(archivo, "    move $a0, $t0\n");
        fprintf(archivo, "    li $v0, 1\n");
        fprintf(archivo, "    syscall\n");
        fprintf(archivo, "    la $a0, newline\n");
        fprintf(archivo, "    li $v0, 4\n");
        fprintf(archivo, "    syscall\n");
        printf("Programa vacio generado\n");
    }
    
    fprintf(archivo, "\n    # Terminar programa\n");
    fprintf(archivo, "    li $v0, 10           # Syscall para exit\n");
    fprintf(archivo, "    syscall              # Terminar programa\n");
    
    fclose(archivo);
    
    printf("El archivo ruby.asm ha sido creado exitosamente.\n");
    printf("Puedes ejecutarlo en MARS (MIPS Assembly and Runtime Simulator)\n\n");
    
    printf("=== CODIGO MIPS GENERADO EN ruby.asm ===\n");
    printf("=== COMPILACION COMPLETADA EXITOSAMENTE ===\n");
}
