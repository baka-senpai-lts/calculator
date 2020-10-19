all: main

main: handler.o main.o
	g++ handler.o main.o -o main

handler.o: handler.cpp
	g++ -c handler.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -Rf *.o main