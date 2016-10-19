lab7: main.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o Test.o
	g++ -g -Wall -std=c++11 -o lab7 main.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o Test.o

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 -c main.cpp

SortDriver.o: SortDriver.cpp SortDriver.h
	g++ -g -Wall -std=c++11 -c SortDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.cpp NumberFileGenerator.h
	g++ -g -Wall -std=c++11 -c NumberFileGenerator.cpp

NumberFileDriver.o: NumberFileDriver.cpp NumberFileDriver.h
	g++ -g -Wall -std=c++11 -c NumberFileDriver.cpp

Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp

clean:
	rm *.o lab7

