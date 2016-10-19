lab2: main.o Node.o LinkedList.o Test.o
	g++ -g -Wall -std=c++11 -o lab2 main.o Node.o LinkedList.o Test.o
main.o: main.cpp LinkedList.h Test.h
	g++ -g -Wall -std=c++11 -c main.cpp
Node.o: Node.cpp Node.h
	g++ -g -Wall -std=c++11 -c Node.cpp
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -g -Wall -std=c++11 -c LinkedList.cpp
Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp
clean:
	rm *.o lab2
