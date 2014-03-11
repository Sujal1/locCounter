all: run

run: 
	(cd src && make clean && make && make install)
	(cd test && make && make install)
	(cd bin && ./countlines cpp_sample2.cpp)
	(cd bin && ./test_loc)
	
	
