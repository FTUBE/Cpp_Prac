main:main.o comp.o
	g++ comp.o main.o -o main
main.o:main.cpp
	g++ -c main.cpp
comp.o:comp.cpp
	g++ -c comp.cpp
clean:
	rm -f *.o *~ *# main
