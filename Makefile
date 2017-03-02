main: processinho.o sjf.o fifo.o edf.o main.o
	g++ -std=c++11 processinho.o sjf.o fifo.o edf.o main.o -o main

processinho.o:
	g++ -std=c++11 -c processinho.cpp

sjf.o:
	g++ -std=c++11 -c sjf.cpp
	
edf.o:
	g++ -std=c++11 -c edf.cpp

fifo.o:
	g++ -std=c++11 -c fifo.cpp

main.o:
	g++ -std=c++11 -c main.cpp
