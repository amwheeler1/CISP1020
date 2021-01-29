ATsys: main.cpp ioHandle.o
	g++ main.cpp ioHandle.o -o ATsys

ioHandle.o: ioHandle.cpp
	g++ -c ioHandle.h stateInf.h ioHandle.cpp

clean:
	rm *.o
	rm *.gch
	rm ATsys

redo:
	make clean
	make
