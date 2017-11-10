*CC=


all:	main
			
main:	main.o addition.o subtraction.o multiplication.o division.o
	$(CC) -o main main.o addition.o subtraction.o multiplication.o division.o
	
main.o:	main.c
	$(CC) -c -o main.o main.c

addition.o:	addition.c
	$(CC) -o addition.o -c addition.c
	
subtraction.o:	subtraction.c
	$(CC) -c -o subtraction.o subtraction.c
	
multiplication.o:	multiplication.c
	$(CC) -c -o multiplication.o multiplication.c
	
division.o:	division.c
	$(CC) -c -o division.o division.c
	
clean: 
	rm -rf *.o
	rm -rf main
