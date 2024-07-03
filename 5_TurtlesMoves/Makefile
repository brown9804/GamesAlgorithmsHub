#######################################
# Makefile for Turtles Moves v1
#######################################

#######################################
# Variables
#######################################

# C compiler
CC=gcc

# Files
BASEDIR=.
INCLDIR=$(BASEDIR)/incl
SRCDIR=$(BASEDIR)/src
BINDIR=$(BASEDIR)/bin
DOCDIR=$(BASEDIR)/doc

OUTFILE=turtles_mov

# Compiler options and flags
CFLAGS= -std=c11 -g -I $(INCLDIR) -o $(BINDIR)/$(OUTFILE)
LFLAGS=


#######################################
# Targets
#######################################

all: clean build run clean

build: doc
	$(CC) $(CFLAGS) $(LFLAGS) main.c $(SRCDIR)/*.c
clean:
	rm -rf $(BINDIR)/*
	rm -rf $(DOCDIR)/html $(DOCDIR)/latex 

run:
	$(BINDIR)/$(OUTFILE) turtles_mov


.PHONY: all clean doc














