## Variables Declaration ##
# Executable
PROG_NAME = graph_library

# Compiler and flags
CC = g++
CC_FLAGS = -std=c++11 -Wall -Wextra -g

# Commands
RM = rm -rf

# Files
GB = graph_base
DG = directed_graph
MAIN = main
OUT_OBJS = $(GB).o $(DG).o $(MAIN).o

## Makefile Functions Declaration ##

# This will be run when "make" or "make default" command is given
default: $(PROG_NAME)

$(PROG_NAME): $(OUT_OBJS)
	$(CC) -o $(PROG_NAME) $(OUT_OBJS)

$(GB).o: $(GB).cpp $(GB).h
	$(CC) $(CC_FLAGS) -c $(GB).cpp $(GB).h

$(DG).o: $(DG).cpp $(DG).h
	$(CC) $(CC_FLAGS) -c $(DG).cpp $(DG).h

$(MAIN).o: $(MAIN).cpp
	$(CC) $(CC_FLAGS) -c $(MAIN).cpp

# This will be run when "make clean" command is given
clean:
	$(RM) *.o *.out *.exe $(PROG_NAME) *~
