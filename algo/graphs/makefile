graphs: graphs.o components.o
	g++ graphs.o components.o -Wall -o graphs
graphs.o: graphs.cpp
	g++ -c graphs.cpp -Wall
components.o: components.cpp
	g++ -c components.cpp -Wall
clean:
	rm -f *.o *~ graphs
