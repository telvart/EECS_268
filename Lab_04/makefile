
lab4: main.o PreconditionViolationException.o Test.o
	g++ -g -Wall -std=c++11 -o lab4 main.o PreconditionViolationException.o Test.o

main.o: main.cpp Node.h Node.hpp StackInterface.h Stack.h Stack.hpp PreconditionViolationException.h

	g++ -g -Wall -std=c++11 -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -Wall -std=c++11 -c PreconditionViolationException.cpp

Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp


clean:
	rm *.o lab4
