main:main.o Date.o ModiD.o Calendar.o
	g++ main.o Date.o ModiD.o Calendar.o -o main
main.o: main.cpp
	g++ -c main.cpp
Date.o:Date.cpp
	g++ -c Date.cpp
ModiD.o:ModiD.cpp
	g++ -c ModiD.cpp
Calendar.o:Calendar.cpp
	g++ -c Calendar.cpp
clean:
	rm -f *.o *~ *# main
