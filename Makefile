#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-02 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/insertionsort.o $(OBJ)/leituraArquivo.o $(OBJ)/memlog.o $(OBJ)/mergesort.o $(OBJ)/bucketsort.o $(OBJ)/ponto.o $(OBJ)/reta.o $(OBJ)/poligono.o $(OBJ)/scandegraham.o $(OBJ)/marchardejarvis.o $(OBJ)/main.o
HDRS = $(INC)/insertionsort.hpp $(INC)/leituraArquivo.hpp $(INC)/memlog.h $(INC)/mergesort.hpp $(INC)/bucketsort.hpp $(INC)/ponto.hpp $(INC)/reta.hpp $(INC)/poligono.hpp $(INC)/scandegraham.hpp $(INC)/marchardejarvis.hpp
CFLAGS = -Wall -c -g3 -I$(INC) -pg

EXE = $(BIN)/main
INPUT_FILE = exemploEntrada.txt
INPUT_FILE2 = exemploEntrada2.txt
INPUT_FILE3 = exemploEntrada3.txt
INPUT_FILE4 = exemploEntrada4.txt
INPUT_FILE5 = ENTRADA10.txt
INPUT_FILE6 = ENTRADA100.txt
INPUT_FILE7 = ENTRADA1000.txt

all:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/insertionsort.o: $(HDRS) $(SRC)/insertionsort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/insertionsort.o $(SRC)/insertionsort.cpp

$(OBJ)/leituraArquivo.o: $(HDRS) $(SRC)/leituraArquivo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/leituraArquivo.o $(SRC)/leituraArquivo.cpp

$(OBJ)/mergesort.o: $(HDRS) $(SRC)/mergesort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/mergesort.o $(SRC)/mergesort.cpp

$(OBJ)/bucketsort.o: $(HDRS) $(SRC)/bucketsort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/bucketsort.o $(SRC)/bucketsort.cpp

$(OBJ)/ponto.o: $(HDRS) $(SRC)/ponto.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ponto.o $(SRC)/ponto.cpp

$(OBJ)/reta.o: $(HDRS) $(SRC)/reta.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/reta.o $(SRC)/reta.cpp

$(OBJ)/poligono.o: $(HDRS) $(SRC)/poligono.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/poligono.o $(SRC)/poligono.cpp

$(OBJ)/scandegraham.o: $(HDRS) $(SRC)/scandegraham.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/scandegraham.o $(SRC)/scandegraham.cpp

$(OBJ)/marchardejarvis.o: $(HDRS) $(SRC)/marchardejarvis.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/marchardejarvis.o $(SRC)/marchardejarvis.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c

run: $(EXE)
	$(EXE) $(FILE)
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
