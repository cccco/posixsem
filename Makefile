all:
	gcc -std=c99 -o testposixsem posixsem.c -lpthread
