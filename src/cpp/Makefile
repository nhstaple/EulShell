# Basic static makefile. This will have to be remade as the project gets larger.

FLAGS=-std=c++11 -Wfatal-errors
CC=g++

Euler.out:
	$(CC) $(FLAGS) main.cpp euler/e001/*.cpp euler/*.cpp library/App/Parser/EulerInterface/*.cpp library/App/Parser/*.cpp library/Graphs/*.cpp library/App/*.cpp -c
	$(CC) $(FLAGS) *.o -o Euler.out
	rm *.o
	echo "Enter \"./Euler.out\" to start the progarm!"
