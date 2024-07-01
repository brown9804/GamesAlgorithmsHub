CC=gcc

# Files
BASEDIR=.
INCLDIR=$(BASEDIR)/incl
SRCDIR=$(BASEDIR)/src
BINDIR=$(BASEDIR)/bin
DOCDIR=$(BASEDIR)/doc

# Compiler options and flags
CFLAGS=-g -I$(INCLDIR) -D_GNU_SOURCE
LIBRARIES=-lcsfml-graphics -lcsfml-audio
PROGRAM=SpaceInvaders

#######################################
# Targets
#######################################

all: $(BINDIR)/$(PROGRAM)

$(BINDIR)/$(PROGRAM): src/main.o src/inicio.o src/juego.o #src/scores.o
	$(CC) -o $@ $^ $(LIBRARIES)

clean:
	rm -rf $(BINDIR)/$(PROGRAM) src/*.o

run: $(BINDIR)/$(PROGRAM)
	$(BINDIR)/$(PROGRAM)

.PHONY: all clean
