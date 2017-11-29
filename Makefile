testcostumer:
	g++ -Wall -c -std=c++11 costumer.cpp main2.cpp
	g++ costumer.o main2.o
	rm *.o
