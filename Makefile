CC=gcc
CFLAGS=-ansi -pedantic -Wall

main_test: src/main.o src/tri.o src/liste_chaine.o src/fonction_arbre.o
	$(CC) $(CFLAGS) $^ -o $@
src/main.o : src/main.c  
	$(CC) $(CFLAGS) -c $< -o $@
src/tri.o : src/tri.c
	$(CC) $(CFLAGS) -c $< -o $@
src/liste_chaine.o : src/liste_chaine.c
	$(CC) $(CFLAGS) -c $< -o $@
src/fonction_arbre.o : src/fonction_arbre.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf build/*
	rm -rf src/*.o

.PHONY: clean