lab5: main.o PreconditionViolationException.o FarmAnimal.o Chicken.o Cow.o CyberChicken.o AnimalPen.o
	g++ -g -Wall -std=c++11 -o lab5 main.o PreconditionViolationException.o FarmAnimal.o Chicken.o Cow.o CyberChicken.o AnimalPen.o

main.o: main.cpp Node.h Node.hpp StackInterface.h Stack.h Stack.hpp PreconditionViolationException.h
	g++ -g -Wall -std=c++11 -c main.cpp
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -Wall -std=c++11 -c PreconditionViolationException.cpp
FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -Wall -std=c++11 -c FarmAnimal.cpp
Chicken.o: Chicken.h Chicken.cpp
	g++ -g -Wall -std=c++11 -c Chicken.cpp
Cow.o: Cow.h Cow.cpp
	g++ -g -Wall -std=c++11 -c Cow.cpp
CyberChicken.o: CyberChicken.h CyberChicken.cpp
	g++ -g -Wall -std=c++11 -c CyberChicken.cpp
AnimalPen.o: AnimalPen.h AnimalPen.cpp
	g++ -g -Wall -std=c++11 -c AnimalPen.cpp
clean:
	rm *.o lab5
