run: main.c lib.h lib.c menu.c
	gcc -Wall main.c lib.h lib.c menu.c
clean: 
	rm -R *.out *.gch 


