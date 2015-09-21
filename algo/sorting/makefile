generalsort: generalsort.o sort.o
	g++ -g generalsort.o sort.o -o generalsort
generalsort.o: generalsort.cpp
	g++ -W -g -c generalsort.cpp
sort.o: sort.cpp
	g++ -W -g -c sort.cpp
clean:
	rm -f *.o *~
