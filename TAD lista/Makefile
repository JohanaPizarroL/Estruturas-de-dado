all: item.o lista.o cliente.o
	gcc item.o lista.o cliente.o -o lista -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

lista.o:
	gcc -c lista.c -o lista.o
	 
cliente.o:
	gcc -c cliente.c -o cliente.o
	 
clean:
	rm *.o lista

run:
	./lista
