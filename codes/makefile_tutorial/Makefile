# REFERENCE: https://stackoverflow.com/questions/52034997/how-to-make-makefile-recompile-when-a-header-file-is-changed

source := $(wildcard *.c)
depend := $(patsubst %.c,%.d,$(source))
target = hw01 hw02

# link flags
CC = -gcc
CFLAGS = -Wall -Wextra -MMD -MP
LDFLAGS = -Wall -Wextra

# .PHONY means these rules get executed even if files of those names exist.
.PHONY: all clean

all: $(target)

hw01: hw01.o foo.o
hw02: hw02.o bar.o

-include $(depend)

clean:
	rm *.d *.o $(target)
