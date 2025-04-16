CC = gcc
CXX = g++
CFLAGS = -Wall
CXXFLAGS = -Wall
RM = rm -f

all: cpp_test c_test

# C++ target
cpp_test: cpp_test.o
	$(CXX) $(CXXFLAGS) -o cpp_test cpp_test.o

cpp_test.o: cpp_test.cpp Matrix1.h
	$(CXX) $(CXXFLAGS) -c cpp_test.cpp

# C target
c_test: c_test.o matrix.o
	$(CC) $(CFLAGS) -o c_test c_test.o matrix.o -lm

c_test.o: c_test.c matrix.h
	$(CC) $(CFLAGS) -c c_test.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

clean:
	$(RM) *.o cpp_test c_test

.PHONY: all clean