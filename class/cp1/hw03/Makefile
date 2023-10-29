src = $(wildcard *.c)
obj = $(src:.c=.o)

all: $(obj)
	-gcc -Wall -Wextra -o hw0301   hw0301.o mycircle.o -lm
	-gcc -Wall -Wextra -o hw0302   hw0302.o mycontrol.o -lm
	-gcc -Wall -Wextra -o hw0303   hw0303.o binaryForm.o
	-gcc -Wall -Wextra -o hw0304-1 hw0304.o hw0304-1.o
	-gcc -Wall -Wextra -o hw0304-2 hw0304.o hw0304-2.o
	-gcc -Wall -Wextra -o hw0305   hw0305.o diceRolls.o diceMenu.o rpgEvent.o rpgPlayer.o rpgStory.o

%.o: %.c
	-gcc -Wall -Wextra -c $<

clean:
	rm -f hw0301 hw0302 hw0303 hw0304-1 hw0304-2 hw0305 *.o
