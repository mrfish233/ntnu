all: linked_list.o stack.o main.c
	-gcc main.c linked_list.o stack.o -Wall -Wextra -o main

linked_list: linked_list.c
	-gcc -c linked_list.c -Wall -Wextra -o linked_list.o

stack: stack.c
	-gcc -c stack.c -Wall -Wextra -o stack.o

clean:
	rm -rf main *.o
