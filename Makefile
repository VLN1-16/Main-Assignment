buildingproduct:
	g++ -Wall -c -Iheaders -std=c++17 source/testingProduct.cpp source/product.cpp source/pizza.cpp source/topping.cpp
	g++ testingProduct.o product.o pizza.o topping.o -o testingProduct.out -o bin/buildingproduct.out
	rm *.o

toppingDatabase:
	g++ -Wall -c -Iheaders -std=c++17 topping.cpp product.cpp testToppings.cpp
	g++ topping.o product.o testToppings.o -o bin/toppingDatabase.out
	rm *.o

pizza:
	g++ -Wall -c -Iheaders -std=c++17 pizza.cpp topping.cpp main2.cpp product.cpp
	g++ pizza.o topping.o main2.o product.o -o bin/pizza.out
	rm *.o

places:
	g++ -Wall -c -Iheaders -std=c++17 place.cpp testToppings.cpp
	g++ place.o testToppings.o -o bin/places.out
	rm *.o

testorder:
	g++ -c -Wall -Iheaders -std=c++17 main4.cpp order.cpp topping.cpp pizza.cpp costumer.cpp product.cpp
	g++ main4.o order.o topping.o pizza.o costumer.o product.o -o bin/testorder.out
	rm *.o 


testall: 
	make testproduct 
	make testcostumer
	make testtopping
	make testpizza
	make testorder
testproduct:
	g++ -Wall -c -std=c++17 -Iheaders source/product.cpp tests/productTest.cpp 
	g++ product.o productTest.o -o bin/productTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/productTest.out ## Valgrind checks for leaks and access violations productTest test basic functionality ageinst known good 
testcostumer:
	g++ -Wall -c -Iheaders -std=c++17 source/costumer.cpp tests/costumerTest.cpp
	g++ costumer.o costumerTest.o -o bin/costumerTest.out 
	rm *.o
	valgrind -q --leak-check=full ./bin/costumerTest.out ## Valgrind checks for leaks and access violations productTest test basic functionality ageinst known good 
testtopping:
	g++ -Wall -c -Iheaders -std=c++17 tests/toppingTest.cpp source/topping.cpp source/product.cpp
	g++ toppingTest.o topping.o product.o -o bin/toppingTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/toppingTest.out ## Valgrind checks for leaks and access violations productTest test basic functionality ageinst known good 
testpizza:
	g++ -Wall -c -Iheaders -std=c++17 source/pizza.cpp tests/pizzaTest.cpp source/topping.cpp source/product.cpp
	g++ pizza.o pizzaTest.o topping.o product.o -o bin/pizzaTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/pizzaTest.out ## Valgrind checks for leaks and access violations productTest test basic functionality ageinst known good 
testorder:
	g++ -Wall -c -Iheaders -std=c++17 source/product.cpp source/topping.cpp source/pizza.cpp source/order.cpp source/costumer.cpp tests/orderTest.cpp
	g++ product.o topping.o pizza.o order.o costumer.o orderTest.o -o bin/orderTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/orderTest.out
