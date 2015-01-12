
all: test.out

test.out: main.o bwindow.o Agent.o Population.o Obstacle.o
	g++ -o test.out main.o Agent.o Population.o Obstacle.o bwindow.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp
	g++ -c main.cpp 

bwindow.o: bwindow.cpp bwindow.h
	g++ -c bwindow.cpp

Agent.o: Agent.cpp Agent.h
	g++ -c Agent.cpp

Population.o: Population.cpp Population.h
	g++ -c Population.cpp

Obstacle.o: Obstacle.cpp Obstacle.h
	g++ -c Obstacle.cpp
	
clean:
	rm *.o *.out

mrproper: clean
	rm test.out