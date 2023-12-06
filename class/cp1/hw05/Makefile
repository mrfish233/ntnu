# REFERENCE: https://stackoverflow.com/questions/52034997/how-to-make-makefile-recompile-when-a-header-file-is-changed

# EDIT HERE
target := hw0501 hw0502 hw0503

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
hw0501: hw0501.o mystatistics.o
hw0502: hw0502.o myge.o
hw0503: hw0503.o mysphere.o

-include $(depend)

clean:
	rm -f $(object) $(depend) $(target)
