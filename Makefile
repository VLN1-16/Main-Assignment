commandline:
	mkdir -p obj bin
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/main.cpp -o obj/main.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/model/costumer.cpp  -o obj/costumer.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/model/order.cpp -o obj/order.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/model/topping.cpp -o obj/topping.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/model/product.cpp -o obj/product.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/model/pizzasize.cpp -o obj/pizzasize.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/model/pizza.cpp -o obj/pizza.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/model/place.cpp -o obj/place.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/ui/salesUI.cpp -o obj/salesUI.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/ui/commandline.cpp -o obj/commandline.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/ui/managerui.cpp -o obj/managerui.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/ui/preperationUI.cpp -o obj/preperationUI.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/ui/deliveryUI.cpp -o obj/deliveryUI.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/repositories/pizzasizerepo.cpp -o obj/pizzasizerepo.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/repositories/pizzarepo.cpp -o obj/pizzarepo.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/repositories/placerepo.cpp -o obj/placerepo.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/repositories/productrepo.cpp -o obj/productrepo.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/repositories/toppingrepo.cpp -o obj/toppingrepo.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/repositories/orderrepo.cpp -o obj/orderrepo.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/repositories/inactiveorderrepo.cpp -o obj/inactiveorderrepo.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/exceptions/iscostumernamevalid.cpp -o obj/iscostumernamevalid.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/exceptions/invalidpizzasize.cpp -o obj/invalidpizzasize.o
	g++ -Wall -c -Iheaders -Iheaders/exceptions -Iheaders/ui -Iheaders/model -Iheaders/repositories -std=c++11 source/exceptions/badnumber.cpp -o obj/badnumber.o
	g++ obj/main.o obj/salesUI.o obj/iscostumernamevalid.o obj/invalidpizzasize.o obj/order.o obj/costumer.o obj/commandline.o obj/topping.o obj/product.o obj/pizzasize.o obj/pizza.o obj/managerui.o obj/place.o obj/preperationUI.o obj/deliveryUI.o obj/pizzasizerepo.o obj/pizzarepo.o obj/placerepo.o obj/productrepo.o obj/toppingrepo.o obj/orderrepo.o obj/inactiveorderrepo.o obj/badnumber.o -o bin/commandline.out
runcommandline:
	./bin/commandline.out
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
	g++ -Wall -c -Iheaders -Iheaders/exceptions -std=c++17 source/product.cpp source/topping.cpp source/pizza.cpp source/order.cpp source/costumer.cpp tests/orderTest.cpp source/pizzasize.cpp source/place.cpp source/exceptions/badnumber.cpp  source/exceptions/invalidpizzasize.cpp  source/exceptions/iscostumernamevalid.cpp
	g++ product.o topping.o pizza.o order.o costumer.o orderTest.o pizzasize.o place.o badnumber.o invalidpizzasize.o iscostumernamevalid.o -o bin/orderTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/orderTest.out
testplace:
	g++ -Wall -c -Iheaders -std=c++17 source/place.cpp tests/placeTest.cpp
	g++ place.o placeTest.o -o bin/placeTest.out
	rm *.o
	valgrind -q --leak-check=full ./bin/placeTest.out
