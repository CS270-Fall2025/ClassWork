# Macros
CC = gcc
#CFLAGS =
# CFLAGS = -g
CFLAGS = -D NDEBUG
# CFLAGS = -D NDEBUG -O
#CFLAGS = -Wall -Wextra

# Pattern rule
%.o: %.c
	$(CC) $(CFLAGS) -c $<


# Dependency rules for non-file targets
all: testintmath
clean:
	rm -f testintmatch *.o


testintmath: testintmath.o intmath.o
	$(CC) $(CFLAGS)  $^ -o $@

testintmath.o: testintmath.c intmath.h
#	$(CC) $(CFLAGS)  -c $<

intmath.o: intmath.c intmath.h
#	$(CC) $(CFLAGS)  -c $<
