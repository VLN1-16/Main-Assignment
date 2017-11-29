<<<<<<< HEAD
buildingproduct:
	g++ -Wall -c testingProduct.cpp product.cpp
	g++ testingProduct.o product.o -o testingProduct.out
=======
testcostumer:
	g++ -Wall -c -std=c++11 costumer.cpp main2.cpp
	g++ costumer.o main2.o
	rm *.o
>>>>>>> bba44af96ebfaa7bc70d3742568d7ed4b52aabc5
