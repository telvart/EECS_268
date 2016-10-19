lab3: main.o Test.o
	g++ -g -Wall -std=c++11 -o lab3 main.o Test.o
main.o: main.cpp Node.h Node.hpp DoubleLinkedList.h DoubleLinkedList.hpp
	g++ -g -Wall -std=c++11 -c main.cpp
Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp
clean:
	rm *.o lab3
