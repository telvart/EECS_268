/**
*	@file: main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/11/15
*	@brief: A place to interact with maze files and their traversal
*/


#include <iostream>
#include "MazeWalker.h"
#include "MazeReader.h"
#include "Test.h"
#include "ArrayHelper.h"

void printarray(const int* const* array, int rows, int cols)
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			std::cout<<array[i][j]<<"  ";
		}
	}
}

int main(int argc, char** argv)
{
	Test Tester;
	bool exitfound;
	ArrayHelper<int> visitedPrinter;
//	For some reason main wont work and i get seg faults, but the test class works fine idk.
//	on earlier attempts main worked fine but now i just get seg faults, i dont think its coming from mazewalker
//

	if (argc<3 && argv>0)
	{
		Tester.runTests();
	}
	else if (argc>=3)
	{
		std::string mode=argv[1];
		try
		{
			MazeReader reader(argv[2]);

			if (mode=="-dfs")
			{
				MazeWalker walker(reader.getMaze(),reader.getRows(),reader.getCols(),reader.getStartRow(),reader.getStartCol(),Search::DFS);
				exitfound=walker.walkMaze();

				std::cout<<"\nStarting Position: "<<reader.getStartRow()<<", "<<reader.getStartCol()
					 <<"\nSize: "<<reader.getRows()<<", "<<reader.getCols()<<"\n";
				//printarray(walker.getVisited(),walker.getVisitedRows(),walker.getVisitedCols());
				visitedPrinter.print2DArray(walker.getVisited(), walker.getVisitedRows(),walker.getVisitedCols(),"  ");
			}
			else if (mode=="-bfs")
			{
				MazeWalker walker(reader.getMaze(),reader.getRows(),reader.getCols(),reader.getStartRow(),reader.getStartCol(),Search::BFS);
				exitfound=walker.walkMaze();

				std::cout<<"\nStarting Position: "<<reader.getStartRow()<<", "<<reader.getStartCol()
					 <<"\nSize: "<<reader.getRows()<<", "<<reader.getCols()<<"\n";
				visitedPrinter.print2DArray(walker.getVisited(), walker.getVisitedRows(),walker.getVisitedCols(),"  ");			
			}


			if (exitfound)
			{
				std::cout<<"\nWe escaped the maze!\n";
			}
			else
			{
				std::cout<<"\nThere was no way out!\n";
			}

		}
		catch(MazeCreationException& e)
		{
			std::cout<<"\n"<<e.what();
		}

	}

	return 0;

}
