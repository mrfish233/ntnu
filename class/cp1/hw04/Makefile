# REFERENCE: https://stackoverflow.com/questions/52034997/how-to-make-makefile-recompile-when-a-header-file-is-changed

source := $(wildcard *.c)
depend := $(patsubst %.c,%.d,$(source))
target = hw0401 hw0402

# link flags
CC = -gcc
CFLAGS = -Wall -Wextra -MMD -MP
LDFLAGS = -Wall -Wextra

# .PHONY means these rules get executed even if files of those names exist
.PHONY: all clean

all: $(target)

hw0401: hw0401.o mysort.o
hw0402: hw0402.o differential.o

-include $(depend)

clean:
	rm *.o *.d $(target)
