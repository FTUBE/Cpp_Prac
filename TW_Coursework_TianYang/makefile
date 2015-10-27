main: main.o Receipt.o Goods.o
	g++ main.o Receipt.o Goods.o -o main

main.o: main.cpp
	g++ -c main.cpp

Receipt.o: Receipt.cpp
	g++ -c Receipt.cpp

goods.o: Goods.cpp
	g++ -c Goods.cpp

clean:
	rm -f *.o *~ in *# main
