CC = gcc
RM = rm -rf
CFLAGS = -Wall -O2
CPPFLAGS = -I.
LDFLAGS = -L/usr/lib -lm

PROGNAME = prog
PACKAGE=$(PROGNAME)
HEADERS = grapheadjl.h tools.h opt2list.h grapheadjv.h opt2vec.h
OBJ = main.o grapheadjl.o tools.o opt2list.o grapheadjv.o opt2vec.o
SOURCES = $(OBJ:.o=.c)

all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROGNAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<


clean:
	$(RM) $(PROGNAME) $(OBJ)  