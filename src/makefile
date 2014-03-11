all: all

all:  countlines.o locCounter.o
	g++ ../lib/countlines.o ../lib/locCounter.o   -o countlines 

countlines.o:
	g++ -c countlines.cpp -o ../lib/countlines.o

locCounter.o:
	g++ -c locCounter.cpp -o ../lib/locCounter.o

install:
	mv countlines ../bin/
clean:
	rm -rf ../lib/*o ../bin/countlines
