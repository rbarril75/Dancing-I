EXEC = barril1-MP1

DEPS = main.o

COMPILER = gcc
COMPILER_OPTS = -c -g -Wall

LINKER = gcc
LINKER_OPTS = -framework GLUT -framework OpenGL -framework Carbon

all : $(EXEC)

$(EXEC) : $(DEPS)
	$(LINKER) -o $(EXEC) $(LINKER_OPTS) $(DEPS)

main.o : main.c
	$(COMPILER) $(COMPILER_OPTS) main.c

clean : 
	-rm *.o $(EXEC)

