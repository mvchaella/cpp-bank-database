testec: driver.o llist.o
	g++ -o testec driver.o llist.o

driver.o: driver.cpp
	g++ -ansi -pedantic-errors -Wall -c driver.cpp

llist.o: llist.cpp
	g++ -ansi -pedantic-errors -Wall -c llist.cpp  
