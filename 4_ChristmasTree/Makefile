#######################################
# Makefile for Christmas_tree v1
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

OUTFILE=Christmas_tree

# Compiler options and flags
CFLAGS= -std=c11 -g -I $(INCLDIR) -o $(BINDIR)/$(OUTFILE)
LFLAGS=


#######################################
# Targets
#######################################

all: clean build run clean

build: doc
	$(CC) $(CFLAGS) $(LFLAGS) Christmas_tree.c $(SRCDIR)/*.c


clean:
	rm -rf $(BINDIR)/*
	rm -rf $(DOCDIR)/html $(DOCDIR)/latex 

run:
	$(BINDIR)/$(OUTFILE) Christmas_tree

.PHONY: all clean doc














