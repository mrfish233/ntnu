# REFERENCE: https://stackoverflow.com/questions/52034997/how-to-make-makefile-recompile-when-a-header-file-is-changed

# EDIT HERE
target := hw0101 hw0102

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
hw0101: hw0101.o mystring.o
hw0102: hw0102.o mycal.o

-include $(depend)

clean:
	rm -f $(object) $(depend) $(target)
