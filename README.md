# Main-Assignment
Main Assignment

# Coding rules

Naming classes: Pascal casing

Naming functions inside classes: Pascal casing

Naming variables: Camel casing.

# Classes and their purpose

The command line class contains all menues for users.
The command line class is the top of all function calls
the user gives input (data) to the commandline class

The command line class calls the controller which then calls
the dataclasses to update the files.


All operations from the command line controler should have a corosponding
function in controller f.e. createOrder can be done as a sales person
and should .

# The extra mile
- Diffrent toppings on sections of the pizza


# TODO
- make orders aware of the place they are ordered into #DONE
- places needs to validate phone numbers, See costumers.cpp for implementation 
- Add a nice way in filehandler for it to deal with deactivating places ( This is not necasery, places get written with the order ); Just remove it the normal way #DONE
- Add functions for the preperation to do.
- Create a Interface for delivery people.( the ones that hand over the pizza) 
- Orders have to be verified sane before being registered ( where is it suppose to be made, is there anything on it etc, etc.).
- Færa öll #define yfir í spes skrá, þannig hægt sé að stilla það 
- Láta allar færibreytur sem taka index vera unsigned, það meikar ekki sens að það sé negatíft
- Allt sem getur verið const verði const.
- Skoða leiðir til þess að gera lestur á hlutum hraðari. Ef við bætum pizzu t.d. aðeins þá bætum við heildina svakalega vegna þess hvað það gerist oft. skoða það að lesa öll topping í einu frekar en að láta topping lesa sig sjálft osf.
