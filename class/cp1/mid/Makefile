src = $(wildcard *.c)
obj = $(src:.c=.o)

all: $(obj)
	-gcc -Wall -Wextra -o mid01 mid01.o
	-gcc -Wall -Wextra -o mid02 mid02.o
	-gcc -Wall -Wextra -o mid03 mid03.o
	-gcc -Wall -Wextra -o mid04 mid04.o parity.o
	-gcc -Wall -Wextra -o mid05 mid05.o weight.o

%.o: %.c
	-gcc -Wall -Wextra -c $<

clean:
	rm mid01 mid02 mid03 mid04 mid05 *.o
