CC = g++
CFLAGS = -std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

DEPS = FibLFSR.hpp PhotoMagic.hpp

OBJECTS = FibLFSR.o PhotoMagic.o test.o main.o

PROGRAM = test
PHOTOMAGIC_PROGRAM = PhotoMagic

LIBRARY = PhotoMagic.a

.PHONY: all clean lint

all: $(PROGRAM) $(LIBRARY) $(PHOTOMAGIC_PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): test.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(PHOTOMAGIC_PROGRAM): PhotoMagic.o FibLFSR.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LIBRARY): FibLFSR.o PhotoMagic.o
	ar rcs $@ $^

clean:
	rm -f .o $(PROGRAM) $(PHOTOMAGIC_PROGRAM) $(LIBRARY)

lint:
	cpplint.cpp *.hpp
