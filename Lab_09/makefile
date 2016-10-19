lab9: main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o Test.o
	g++ -g -Wall -std=c++11 -o lab9 main.o MazeReader.o MazeCreationException.o MazeWalker.o Test.o Position.o
main.o: main.cpp ArrayHelper.h ArrayHelper.hpp
	g++ -g -Wall -std=c++11 -c main.cpp
MazeReader.o: MazeReader.cpp MazeReader.h
	g++ -g -Wall -std=c++11 -c MazeReader.cpp
MazeCreationException.o: MazeCreationException.cpp MazeCreationException.h
	g++ -g -Wall -std=c++11 -c MazeCreationException.cpp
MazeWalker.o: MazeWalker.cpp MazeWalker.h
	g++ -g -Wall -std=c++11 -c MazeWalker.cpp
Position.o: Position.cpp Position.h
	g++ -g -Wall -std=c++11 -c Position.cpp
Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp
clean:
	rm *.o lab9
	
