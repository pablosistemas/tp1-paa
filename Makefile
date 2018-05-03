CC		= g++
MAIN	= src/main/main.cc

ESTRUTURAS_FOLDER	= src/Estruturas
ALGORITMOS_FOLDER	= src/Algoritmos
MAIN_FOLDER	= src/main
BIN_FOLDER = bin

SOURCES = \
		Pontes.o\
		Dijkstra.o\
		Dfs.o\
		Corredor.o\
		Grafo.o\

HEADERS_FOLDER = src/Util/

LDFLAGS	= -c
CFLAGS	= -Wall -std=c++14 -g -Wdelete-non-virtual-dtor -Wno-unknown-pragmas
PROGRAM	= tp1
OBJECTS	= (SOURCES: .cc = .o)

INPUT	= entrada
OUTPUT	= saida

all : $(PROGRAM)

Pontes.o : $(ALGORITMOS_FOLDER)/Pontes/Pontes.cc
	$(CC) $(LDFLAGS) $(CFLAGS) $(ALGORITMOS_FOLDER)/Pontes/Pontes.cc

Dijkstra.o : $(ALGORITMOS_FOLDER)/Dijkstra/Dijkstra.cc
	$(CC) $(LDFLAGS) $(CFLAGS) $(ALGORITMOS_FOLDER)/Dijkstra/Dijkstra.cc

Dfs.o : $(ALGORITMOS_FOLDER)/Dfs/Dfs.cc
	$(CC) $(LDFLAGS) $(CFLAGS) $(ALGORITMOS_FOLDER)/Dfs/Dfs.cc

Corredor.o : $(ESTRUTURAS_FOLDER)/Corredor/Corredor.cc
	$(CC) $(LDFLAGS) $(CFLAGS) $(ESTRUTURAS_FOLDER)/Corredor/Corredor.cc

Grafo.o : $(ESTRUTURAS_FOLDER)/Grafo/Grafo.cc
	$(CC) $(LDFLAGS) $(CFLAGS) $(ESTRUTURAS_FOLDER)/Grafo/Grafo.cc

tp1: Grafo.o Corredor.o Dfs.o Dijkstra.o Pontes.o $(MAIN) 
	([ -d bin/ ] && rm -rf bin/) || true
	mkdir bin
	$(CC) $(CFLAGS) $(SOURCES) $(MAIN) -I $(HEADERS_FOLDER) -o $(BIN_FOLDER)/$(PROGRAM)
	rm ./*.o

clean:
	rm *.o $(BIN_FOLDER)/$(PROGRAM)

run:
	$(BIN_FOLDER)/$(PROGRAM) $(INPUT) $(OUTPUT)
