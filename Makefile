# Makefile for 370 HW 1

build: Initiator.c Worker.c
	gcc Initiator.c Worker.c -o DButcherHW1 -I.

clean:
	rm -f DButcherHW1