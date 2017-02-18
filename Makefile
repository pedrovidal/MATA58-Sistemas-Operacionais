main: processinho.o sjf.o fifo.o main.o
	g++ processinho.o sjf.o fifo.o main.o -o main

processinho.o:
	g++ -c processinho.cpp

sjf.o:
	g++ -c sjf.cpp

fifo.o:
	g++ -c fifo.cpp

main.o:
	g++ -c main.cpp
