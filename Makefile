
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
pizza:
	g++ -Wall -c -std=c++11 pizza.cpp topping.cpp main2.cpp product.cpp
	g++ pizza.o topping.o main2.o product.o 

places:
	g++ -Wall -c -std=c++11 place.cpp testToppings.cpp
	g++ place.o testToppings.o
	rm *.o
testorder:
	g++ -c -Wall -std=c++17 main4.cpp order.cpp topping.cpp pizza.cpp costumer.cpp product.cpp
	g++ main4.o order.o topping.o pizza.o costumer.o product.o
