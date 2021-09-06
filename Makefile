# makefile adapted from:
# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# IDIR =./src
# CC=gcc
# CFLAGS=-I$(IDIR)

# ODIR=obj
# LDIR =../lib

# LIBS=-lm

# _DEPS = Worker.h
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJ = Initiator.o Worker.o 
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


# $(ODIR)/%.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# run: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# .PHONY: clean

# clean:
# 	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

HW1: Initiator.c Worker.c
	gcc -o HW1 Initiator.c Worker.c -I.