all:	main

main:	main.o	mul.o	mod.o
	gcc -o main main.o mul.o mod.o -larith -L.
main.o:	main.c
	gcc -c -o main.o main.c
mul.o:	mul.c
	gcc -c -o mul.o mul.c
mod.o:	mod.c
	gcc -c -o mod.o mod.c


clean:
	rm -rf *.o
	rm -rf main
