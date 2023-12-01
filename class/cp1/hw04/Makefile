# REFERENCE: https://stackoverflow.com/questions/52034997/how-to-make-makefile-recompile-when-a-header-file-is-changed

# EDIT HERE
target := hw0401 hw0402 hw0403 hw0404 hw0405

source := $(wildcard *.c)
depend := $(source:.c=.d)
object := $(source:.c=.o)

# compile variables
CC = -gcc
CFLAGS = -Wall -Wextra -MMD -MP

# link variables
LDFLAGS = -Wall -Wextra
LDLIBS  = -lm

# .PHONY means these rules get executed even if files of those names exist
.PHONY: all clean

all: $(target)

# EDIT HERE
hw0401: hw0401.o mysort.o
hw0402: hw0402.o derivative.o
hw0403: hw0403.o gsat_calculate.o
hw0404: hw0404.o mychess.o
hw0405: hw0405.o mahjong.o mahjong_yaku.o

-include $(depend)

clean:
	rm -f $(object) $(depend) $(target)
