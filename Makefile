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

commandline:
	g++ -Wall -c -Iheaders -std=c++11 source/main.cpp -o obj/main.o
	g++ -Wall -c -Iheaders -std=c++11 source/costumer.cpp  -o obj/costumer.o
	g++ -Wall -c -Iheaders -std=c++11 source/order.cpp -o obj/order.o
	g++ -Wall -c -Iheaders -std=c++11 source/salesUI.cpp -o obj/salesUI.o
	g++ -Wall -c -Iheaders -std=c++11 source/sales.cpp -o obj/sales.o
	g++ -Wall -c -Iheaders -std=c++11 source/commandline.cpp -o obj/commandline.o
	g++ -Wall -c -Iheaders -std=c++11 source/management.cpp -o obj/management.o
	g++ -Wall -c -Iheaders -std=c++11 source/topping.cpp -o obj/topping.o
	g++ -Wall -c -Iheaders -std=c++11 source/product.cpp -o obj/product.o
	g++ -Wall -c -Iheaders -std=c++11 source/pizzasize.cpp -o obj/pizzasize.o
	g++ -Wall -c -Iheaders -std=c++11 source/pizza.cpp -o obj/pizza.o
	g++ -Wall -c -Iheaders -std=c++11 source/managerui.cpp -o obj/managerui.o
	g++ -Wall -c -Iheaders -std=c++11 source/place.cpp -o obj/place.o
	g++ -Wall -c -Iheaders -std=c++11 source/preperationUI.cpp -o obj/preperationUI.o
	g++ -Wall -c -Iheaders -std=c++11 source/preperator.cpp -o obj/preperator.o
	g++ -Wall -c -Iheaders -std=c++11 source/pizzasizerepo.cpp -o obj/pizzasizerepo.o
	g++ -Wall -c -Iheaders -std=c++11 source/pizzarepo.cpp -o obj/pizzarepo.o
	g++ -Wall -c -Iheaders -std=c++11 source/placerepo.cpp -o obj/placerepo.o
	g++ -Wall -c -Iheaders -std=c++11 source/productrepo.cpp -o obj/productrepo.o
	g++ -Wall -c -Iheaders -std=c++11 source/toppingrepo.cpp -o obj/toppingrepo.o
	g++ -Wall -c -Iheaders -std=c++11 source/orderrepo.cpp -o obj/orderrepo.o
	g++ obj/main.o obj/sales.o obj/salesUI.o obj/order.o obj/costumer.o obj/commandline.o obj/management.o obj/topping.o obj/product.o obj/pizzasize.o obj/pizza.o obj/managerui.o obj/place.o obj/preperationUI.o obj/preperator.o obj/pizzasizerepo.o obj/pizzarepo.o obj/placerepo.o obj/productrepo.o obj/toppingrepo.o obj/orderrepo.o -o bin/commandline.out 


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
	g++ -Wall -c -Iheaders -std=c++17 source/pizza.cpp tests/pizzaTest.cpp source/topping.cpp source/product.cpp source/pizzasize.cpp
	g++ pizza.o pizzaTest.o topping.o product.o pizzasize.o -o bin/pizzaTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/pizzaTest.out ## Valgrind checks for leaks and access violations productTest test basic functionality ageinst known good
testorder:
	g++ -Wall -c -Iheaders -std=c++17 source/product.cpp source/topping.cpp source/pizza.cpp source/order.cpp source/costumer.cpp tests/orderTest.cpp source/pizzasize.cpp source/place.cpp
	g++ product.o topping.o pizza.o order.o costumer.o orderTest.o pizzasize.o place.o -o bin/orderTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/orderTest.out
testplace:
	g++ -Wall -c -Iheaders -std=c++17 source/place.cpp tests/placeTest.cpp
	g++ place.o placeTest.o -o bin/placeTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/placeTest.out
