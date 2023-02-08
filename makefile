Ecole_groupe1.exe: main.c ecole.o classe.o eleve.o
	gcc main.c ecole.o classe.o eleve.o -o Ecole_groupe1.exe


ecole.o: ecole.c ecole.h classe.o
	gcc -c ecole.c

classe.o: classe.c classe.h eleve.o
	gcc -c classe.c

eleve.o: eleve.c eleve.h
	gcc -c eleve.c



clean :
	rm *.o 
