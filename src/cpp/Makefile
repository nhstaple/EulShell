# Basic static makefile. This will have to be remade as the project gets larger.
Euler.out:
	g++ main.cpp euler/001/*.cpp library/App/Parser/EulerInterface/*.cpp library/App/Parser/*.cpp library/Graphs/*.cpp library/App/*.cpp -c
	g++ *.o -o Euler.out
	rm *.o
	echo "Enter \"./Euler.out\" to start the progarm!"
