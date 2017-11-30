
buildingproduct:
	g++ -Wall -c testingProduct.cpp product.cpp pizza.cpp topping.cpp
	g++ testingProduct.o product.o pizza.o topping.o -o testingProduct.out
	rm *.o

testcostumer:
	g++ -Wall -c -std=c++11 costumer.cpp main2.cpp
	g++ costumer.o main2.o
	rm *.o

toppingDatabase:
	g++ -Wall -c -std=c++11 topping.cpp product.cpp testToppings.cpp
	g++ topping.o product.o testToppings.o
	rm *.o
