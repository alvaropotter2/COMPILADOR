# Codigo MIPS generado por el compilador Ruby -> MIPS
# Archivo fuente: programa.rb
# Generado automaticamente

.data
    newline: .asciiz "\n"
    var_b: .word 0
    var_a: .word 0
    var_n: .word 0
    var_resultado1: .word 0
    var_resultado2: .word 0

.text
.globl main

main:
    # Inicio del programa principal
    j programa_principal

# Definicion de funcion: suma
suma:
    # Prologo de funcion
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $fp, 0($sp)
    move $fp, $sp
    # Return statement
    # Suma
    add $t1, $t1, $t0
    move $v0, $t1
    # Epilogo de funcion
    move $sp, $fp
    lw $fp, 0($sp)
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra

# Definicion de funcion: factorial
factorial:
    # Prologo de funcion
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $fp, 0($sp)
    move $fp, $sp
    # Condicional
    # Cargar numero: 1
    li $t5, 1
    # Comparacion menor o igual
    sle $t6, $t2, $t5
    beqz $t6, L1_else
    # Return statement
    # Cargar numero: 1
    li $t7, 1
    move $v0, $t7
    j L1_end
L1_else:
    # Return statement
    # Llamada a funcion: factorial
    # Cargar numero: 1
    li $t1, 1
    # Resta
    sub $t2, $t2, $t1
    move $a0, $t2
    jal factorial
    move $t3, $v0       # Guardar resultado
    # Multiplicacion
    mul $t4, $t2, $t3
    move $v0, $t4
L1_end:
    # Epilogo de funcion
    move $sp, $fp
    lw $fp, 0($sp)
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra

programa_principal:
    # Llamada a funcion: suma
    # Cargar numero: 3
    li $t2, 3
    # Cargar numero: 5
    li $t1, 5
    move $a0, $t2
    # Cargar numero: 5
    li $t1, 5
    move $a1, $t1
    jal suma
    move $t3, $v0       # Guardar resultado
    # Asignacion a resultado1
    sw $t3, var_resultado1
    # Imprimir valor
    move $a0, $t3
    li $v0, 1            # Print integer
    syscall
    la $a0, newline      # Print newline
    li $v0, 4
    syscall
    # Llamada a funcion: factorial
    # Cargar numero: 4
    li $t7, 4
    move $a0, $t7
    jal factorial
    move $t0, $v0       # Guardar resultado
    # Asignacion a resultado2
    sw $t0, var_resultado2
    # Imprimir valor
    move $a0, $t0
    li $v0, 1            # Print integer
    syscall
    la $a0, newline      # Print newline
    li $v0, 4
    syscall

    # Terminar programa
    li $v0, 10           # Syscall para exit
    syscall              # Terminar programa
