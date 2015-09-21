ds: ds.o structures.o
	g++ -g -W ds.o structures.o -o ds
ds.o: ds.cpp
	g++ -g -W -c ds.cpp
structures.o: structures.cpp
	g++ -g -W -c structures.cpp
clean:
	rm -f *.o *~
