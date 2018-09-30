## Variables Declaration ##
# Executable
BIN_NAME = graph_library

# Extensions
SRC_EXT = cpp
HEAD_EXT = h
OUT_EXT = o

# Compiler and flags
CC = g++
CC_FLAGS = -std=c++11 -Wall -Wextra -Werror -g

# Commands
RM = rm -rf

# Files
GB = graph_base
DG = directed_graph
MAIN = main

## Makefile Functions Declaration ##

# This will be run when "make" or "make default" command is given
default: $(BIN_NAME)

$(BIN_NAME): main.o $(GB).o $(DG).o
	$(CC) $(CC_FLAGS) -o $(BIN_NAME) $(MAIN).o $(GB).o $(DG).o

$(MAIN).o: $(MAIN).cpp
	$(CC) $(CC_FLAGS) -c $(MAIN).cpp -o $(MAIN).o

$(GB).o: $(GB).cpp $(GB).h
	$(CC) $(CC_FLAGS) -c $(GB).cpp $(GB).h -o $(GB).o

$(DG).o: $(DG).cpp $(DG).h
	$(CC) $(CC_FLAGS) -c $(DG).cpp $(DG).h -o $(DG).o

# This will be run when "make clean" command is given
clean:
	$(RM) *.o $(BIN_NAME) *~
