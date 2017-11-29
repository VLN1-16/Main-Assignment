buildingproduct:
	g++ -Wall -c testingProduct.cpp product.cpp
	g++ testingProduct.o product.o -o testingProduct.out
