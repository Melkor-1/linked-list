CFLAGS 	:= -s
CFLAGS 	+= -std=c17
CFLAGS 	+= -no-pie
#CFLAGS += -g3
#CFLAGS += -ggdb
CFLAGS 	+= -Wall
CFLAGS 	+= -Wextra
CFLAGS 	+= -Warray-bounds
CFLAGS 	+= -Wconversion
CFLAGS 	+= -Wmissing-braces
CFLAGS 	+= -Wno-parentheses
CFLAGS 	+= -Wno-format-truncation
CFLAGS 	+= -Wpedantic
CFLAGS 	+= -Wstrict-prototypes
CFLAGS 	+= -Wwrite-strings
CFLAGS 	+= -Winline
CFLAGS 	+= -O2

NAME	:= libslist_$(shell uname -m)-$(shell uname -s)
LIBDIR 	:= bin
SLIB  	:= $(LIBDIR)/$(NAME).a
DLIB  	:= $(LIBDIR)/$(NAME).so
SRCS 	:= $(wildcard src/*.c)
OBJS 	:= $(patsubst src/%.c, obj/%.o, $(SRCS)) 
LDLIBS 	:= -lcriterion

TESTBIN := $(patsubst test/%.c, test/bin/%, $(wildcard test/*.c)) 

all: $(SLIB) $(DLIB)

$(SLIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^ 

$(DLIB): $(OBJS)
	$(CC) $(CFLAGS) -fPIC -shared $(SRCS) -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test/bin/%: test/%.c
	$(CC) $(CFLAGS) $< $(OBJS) -o $@ $(LDLIBS)
	
test: $(SLIB) $(TESTBIN) 
	for test in $(TESTBIN) ; do ./$$test ; done

clean:
	$(RM) -rf $(OBJS) $(TESTBIN)

fclean:
	$(RM) $(SLIB) $(DLIB)

.PHONY: fclean clean all test
.DELETE_ON_ERROR:
