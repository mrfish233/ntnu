all: mycircle.o mycontrol.o hw0304-1.o hw0304-2.o diceRolls.o diceMenu.o
	-gcc -o hw0301 hw0301.c mycircle.o -lm -Wall -Werror
	-gcc -o hw0302 hw0302.c mycontrol.o -lm -Wall -Werror
	-gcc -o hw0303 hw0303.c -Wall -Werror
	-gcc -o hw0304-1 hw0304.c hw0304-1.o -Wall -Werror
	-gcc -o hw0304-2 hw0304.c hw0304-2.o -Wall -Werror
	-gcc -o hw0305 hw0305.c diceRolls.o diceMenu.o -Wall -Werror

mycircle: mycircle.c
	-gcc -o mycircle.o -c mycircle.c -lm -Wall -Werror

mycontrol: mycontrol.c
	-gcc -o mycontrol.o -c mycontrol.c -lm -Wall -Werror

hw0304-1: hw0304-1.c
	-gcc -o hw0304-1.o -c hw0304-1.c -Wall -Werror

hw0304-2: hw0304-2.c
	-gcc -o hw0304-2.o -c hw0304-2.c -Wall -Werror

diceRolls: diceRolls.c diceMenu.c
	-gcc -o diceRolls.o -c diceRolls.c -Wall -Werror
	-gcc -o diceMenu.o -c diceMenu.c -Wall -Werror

clean:
	rm -f hw0301 hw0302 hw0303 hw0304-1 hw0304-2 hw0305 *.o
