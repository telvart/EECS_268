lab1: main.o Dice.o Colosseum.o Pokemon.o
	g++ -g -Wall -o lab1 main.o Dice.o Colosseum.o Pokemon.o
main.o: main.cpp Dice.h Colosseum.h Pokemon.h
	g++ -g -Wall -c main.cpp
Dice.o: Dice.cpp Dice.h
	g++ -g -Wall -c Dice.cpp
Colosseum.o: Colosseum.cpp Colosseum.h Dice.h Pokemon.h
	g++ -g -Wall -c Colosseum.cpp
Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -g -Wall -c Pokemon.cpp
clean:
	rm *.o lab1
