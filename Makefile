# heap_allocation/Makefile
#
# Makefile for heap allocation example
# 
# Nitsan Shai
# nshai@google.com

list: main.c list.c
	gcc -o main main.c list.c 