SHELL   = /bin/sh
CC      = g++ 
FLAGS   = 
CFLAGS  = -fPIC 
TARGET  = countlines
INC=-I ../src/ 

SOURCES = $(shell echo *.cpp)
HEADERS = $(shell echo *.hpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: run
run:  test_loc.o 
	$(CC) -o test_loc ../lib/test_loc.o  ../lib/locCounter.o  
        
test_loc.o:
	$(CC) -c $(SOURCES)  $(INC) -o ../lib/test_loc.o

install:
	mv test_loc ../bin/

clean:
	rm -rf ../lib/test_loc.o test_loc

