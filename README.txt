Dan Butcher
9/6/21
Homework 1
CS 370

Program Description:
This program dynamically allocates memory on the heap, stores random integers, and computes divisability ratios on those integers.

Execution:
DButcherHW1 [SEED]
seed - an integer number the seeds the random number generation.

File List:
Initator.c - The entry/exit point of the program. Input validation.
Worker.h - Header file for Worker.c
Worker.c - Does the actual work of creating random arrays on the heap and calculating their divisability.
makefile - VERY simple make file, includes `make build' (creates executable DButcherHW1), and `make clean` (deletes the executable)

Notes:
Nothing out of the ordinary, output matches the sample output for seeds 7 and 23.

No Memory Leaks:
valgrind -q --leak-check=full --show-leak-kinds=all --verbose ./DButcherHW1 7
==57210== Memcheck, a memory error detector
==57210== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==57210== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==57210== Command: ./DButcherHW1 7
==57210== 
[Initiator]: With seed: 7
[Worker]: Number of iterations is: 77
[Worker]: Iteration with maximum fully divisable elements is 59
[Initiator]: Average ratio is: 0.122461
==57210== 
==57210== HEAP SUMMARY:
==57210==     in use at exit: 0 bytes in 0 blocks
==57210==   total heap usage: 78 allocs, 78 frees, 38,872 bytes allocated
==57210== 
==57210== All heap blocks were freed -- no leaks are possible
==57210== 
==57210== For lists of detected and suppressed errors, rerun with: -s
==57210== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Memory Leak! (commented out free)
valgrind -q --leak-check=full --show-leak-kinds=all --verbose ./DButcherHW1 7 
==57932== Memcheck, a memory error detector
==57932== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==57932== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==57932== Command: ./DButcherHW1 7
==57932== 
[Initiator]: With seed: 7
[Worker]: Number of iterations is: 77
[Worker]: Iteration with maximum fully divisable elements is 59
[Initiator]: Average ratio is: 0.122461
==57932== 
==57932== HEAP SUMMARY:
==57932==     in use at exit: 37,848 bytes in 77 blocks
==57932==   total heap usage: 78 allocs, 1 frees, 38,872 bytes allocated
==57932== 
==57932== 37,848 bytes in 77 blocks are definitely lost in loss record 1 of 1
==57932==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==57932==    by 0x109469: allocateArray (in /home/db/School/CS370-OS/CS370HW1/DButcherHW1)
==57932==    by 0x109374: get_running_ratio (in /home/db/School/CS370-OS/CS370HW1/DButcherHW1)
==57932==    by 0x1092B9: main (in /home/db/School/CS370-OS/CS370HW1/DButcherHW1)
==57932== 
==57932== LEAK SUMMARY:
==57932==    definitely lost: 37,848 bytes in 77 blocks
==57932==    indirectly lost: 0 bytes in 0 blocks
==57932==      possibly lost: 0 bytes in 0 blocks
==57932==    still reachable: 0 bytes in 0 blocks
==57932==         suppressed: 0 bytes in 0 blocks
==57932== 
==57932== For lists of detected and suppressed errors, rerun with: -s
==57932== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

Questions:
1. The difference between malloc and calloc is that malloc allocates memory from the heap but does not initialize it. Calloc allocates and initializes data to 0.
2. False, malloc takes the size in bytes of memory to allocate.
3. If memory is not properly freed, a memory leak occurs. A memory leak is wasted memory space.
4. The headerfile is useful in the linking phase to the compiler. It also declares functions that will be defined later in the code. C uses a single pass compiler.
Initializer.h is not necessary because it is the top of the program and any subsequent calls to the functions in Initializer.c would be valid.
5. The * operator dereferences a pointer, it returns the value at the memory address.
The & operator returns a memory address of the given variable.