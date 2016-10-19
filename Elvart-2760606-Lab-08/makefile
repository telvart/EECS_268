lab8: main.o Test.o
	g++ -g -Wall -std=c++11 -o lab8 main.o Test.o

main.o: main.cpp Node.h Node.hpp BSTI.h BinarySearchTree.h BinarySearchTree.hpp
	g++ -g -Wall -std=c++11 -c main.cpp
Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp
clean:
	rm *.o lab8
