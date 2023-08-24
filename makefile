# the compiler
CC = gcc-10

# the compiler flags
CFLAGS += -std=c17
CFLAGS += -no-pie
CFLAGS += -g3
CFLAGS += -ggdb
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Warray-bounds
CFLAGS += -Wconversion
CFLAGS += -Wmissing-braces
CFLAGS += -Wno-parentheses
CFLAGS += -Wpedantic
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wwrite-strings
CFLAGS += -Winline
#CFLAGS += -s

#CFLAGS += -fanalyzer
#CFLAGS += -fno-builtin
#CFLAGS += -fno-common
#CFLAGS += -fno-omit-frame-pointer
#CFLAGS += -fsanitize=address
#CFLAGS += -fsanitize=undefined
#CFLAGS += -fsanitize=bounds-strict
#CFLAGS += -fsanitize=leak
#CFLAGS += -fsanitize=null
#CFLAGS += -fsanitize=signed-integer-overflow
#CFLAGS += -fsanitize=bool
#CFLAGS += -fsanitize=pointer-overflow
#CFLAGS += -fsanitize-address-use-after-scope
#CFLAGS += -O2

SRC = src
OBJ = obj
SRCS= $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

LIBDIR = lib
LIB = $(LIBDIR)/list.a

TEST = tests
TESTS = $(wildcard $(TEST)/*.c)
TESTBINS = $(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS)) 

all: $(LIB)

$(LIB): $(LIBDIR) $(OBJ) $(OBJS)
	ar -cvrs $(LIB) $(OBJS)

$(OBJ)/%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

$(LIBDIR):
	mkdir $@

$(TEST)/bin/%: $(TEST)/%.c
	$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lcriterion
	
test: $(LIB) $(TEST)/bin $(TESTBINS) 
	for test in $(TESTBINS) ; do ./$$test ; done

clean:
	$(RM) -rf $(LIBDIR) $(OBJ) $(TESTBINS)

.PHONY: clean
.DELETE_ON_ERROR:
