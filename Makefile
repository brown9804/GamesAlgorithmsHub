#######################################
# Makefile for Flooodfill v1
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

OUTFILE=floodfill

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

run:
	$(BINDIR)/$(OUTFILE) floodfill


.PHONY: all clean doc














