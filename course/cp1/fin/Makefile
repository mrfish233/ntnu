# REFERENCE: https://stackoverflow.com/questions/52034997/how-to-make-makefile-recompile-when-a-header-file-is-changed

# EDIT HERE
target := fin01 fin02 fin03 fin04

source := $(wildcard *.c)
depend := $(source:.c=.d)
object := $(source:.c=.o)

# compile variables
CC = -gcc
CFLAGS = -Wall -Wextra -MMD -MP -g

# link variables
LDFLAGS = -Wall -Wextra
LDLIBS  = -lm

# .PHONY means these rules get executed even if files of those names exist
.PHONY: all clean

all: $(target)

# EDIT HERE
fin01: fin01.o frac.o
fin02: fin02.o mine.o
fin03: fin03.o firewall.o
fin04: fin04.o wargame.o

-include $(depend)

clean:
	rm -f $(object) $(depend) $(target)
