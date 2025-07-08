# Makefile para el Compilador Ruby a MIPS Completo

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
FLEX = flex
BISON = bison

# Archivos principales
LEXER_FILE = ruby_lexer.flex
PARSER_FILE = ruby_parser.y
LEXER_OUTPUT = lex.yy.c
PARSER_OUTPUT = ruby_parser.tab.c
PARSER_HEADER = ruby_parser.tab.h

# Archivos fuente
SOURCES = AST_ruby.c generar_mips_completo.c tabla_simbolos.c tabla_simbolos_funciones.c $(LEXER_OUTPUT) $(PARSER_OUTPUT)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = ruby_compiler

# Regla principal
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo "Enlazando el compilador completo..."
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Compilador generado: $(EXECUTABLE)"

# Generar parser con Bison
$(PARSER_OUTPUT) $(PARSER_HEADER): $(PARSER_FILE)
	@echo "Generando parser con Bison..."
	$(BISON) -d $(PARSER_FILE)

# Generar lexer con Flex
$(LEXER_OUTPUT): $(LEXER_FILE) $(PARSER_HEADER)
	@echo "Generando lexer con Flex..."
	$(FLEX) $(LEXER_FILE)

# Compilar archivos objeto específicos
lex.yy.o: $(LEXER_OUTPUT) $(PARSER_HEADER)
	@echo "Compilando lexer..."
	$(CC) $(CFLAGS) -c $< -o $@

ruby_parser.tab.o: $(PARSER_OUTPUT) $(PARSER_HEADER)
	@echo "Compilando parser..."
	$(CC) $(CFLAGS) -c $< -o $@

AST_ruby.o: AST_ruby.c AST_ruby.h
	@echo "Compilando AST..."
	$(CC) $(CFLAGS) -c $< -o $@

generar_mips_completo.o: generar_mips_completo.c AST_ruby.h tabla_simbolos.h
	@echo "Compilando generador de MIPS..."
	$(CC) $(CFLAGS) -c $< -o $@

tabla_simbolos.o: tabla_simbolos.c tabla_simbolos.h
	@echo "Compilando tabla de símbolos..."
	$(CC) $(CFLAGS) -c $< -o $@

tabla_simbolos_funciones.o: tabla_simbolos_funciones.c tabla_simbolos_funciones.h
	@echo "Compilando tabla de funciones..."
	$(CC) $(CFLAGS) -c $< -o $@

# Ejecutar un archivo específico
run: $(EXECUTABLE)
	@if [ -z "$(FILE)" ]; then \
		echo "Uso: make run FILE=archivo.rb [OUTPUT=salida.asm]"; \
		exit 1; \
	fi
	@OUTPUT_FILE=$(if $(OUTPUT),$(OUTPUT),$(basename $(FILE)).asm); \
	echo "Compilando $(FILE) -> $$OUTPUT_FILE"; \
	./$(EXECUTABLE) $(FILE) $$OUTPUT_FILE

# Ejecutar tests
test: $(EXECUTABLE)
	@echo "Ejecutando tests..."
	@for file in test*.rb; do \
	if [ -f "$$file" ]; then \
	echo "Compilando $$file..."; \
	./$(EXECUTABLE) "$$file"; \
	fi \
	done

# Limpiar archivos generados
clean:
	@echo "Limpiando archivos generados..."
	rm -f $(OBJECTS)
	rm -f $(LEXER_OUTPUT)
	rm -f $(PARSER_OUTPUT)
	rm -f $(PARSER_HEADER)
	rm -f $(EXECUTABLE)
	rm -f *.asm
	@echo "Limpieza completada."

# Limpiar solo archivos objeto
clean-obj:
	@echo "Limpiando archivos objeto..."
	rm -f $(OBJECTS)

# Mostrar ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make          - Compilar el compilador"
	@echo "  make clean    - Limpiar archivos generados"
	@echo "  make run FILE=archivo.rb - Compilar un archivo Ruby específico"
	@echo "  make test     - Ejecutar todos los tests"
	@echo "  make help     - Mostrar esta ayuda"

.PHONY: all run test clean clean-obj help
