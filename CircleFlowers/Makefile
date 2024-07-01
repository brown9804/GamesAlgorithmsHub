#######################################
# Makefile for flower_circle_turtle v1
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

OUTFILE=flower_circle_turtle

# Compiler options and flags
CFLAGS= -std=c11 -g -I $(INCLDIR) -o $(BINDIR)/$(OUTFILE)
LFLAGS=


#######################################
# Targets
#######################################

all: clean build run clean

build: doc
	
	$(CC) $(CFLAGS) $(LFLAGS) flower_circle_turtle.c $(SRCDIR)/*.c

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(DOCDIR)/html $(DOCDIR)/latex 

run:
	$(BINDIR)/$(OUTFILE) flower_circle_turtle


.PHONY: all clean doc














