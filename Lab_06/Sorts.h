/**
*	@file: Sorts.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 10.19.15
*	@brief: Various iterative sorting methods for arrays
*/

#ifndef SORTS_H
#define SORTS_H

#include <ctime>
#include <random>
#include <chrono>
#include <cassert>
#include <functional>

template <typename T>
class Sorts
{

public:
	
	//For the following sort methods, it is assumed the type T is comparable with <,>,<=,>=
	
	/*
	@pre an array exists that has atleast 1 value in it
	@post the array will be sorted in ascending order using the bubble sort algorithm
	@return none
	*/	
	static void bubbleSort(T arr[], int size);

	/*
	@pre an array exists with atleast 1 value in it
	@post the array will be sorted in ascending order using the bogo sort algorithm
	@return none
	*/
	static void bogoSort(T arr[], int size);
	/*
	@pre an array exists with atleast 1 value in it
	@post the array will be sorted in ascending order using the insertion sort algorithm
	@return none
	*/
	static void insertionSort(T arr[], int size);
	/*
	@pre an array exists with atleast 1 value in it
	@post the array will be sorted in ascending order using the selection sort algorithm
	@return none
	*/
	static void selectionSort(T arr[], int size);
	/*
	@pre an array exists with atleast 1 value in it 
	@post none
	@return true if the array is sorted in ascending order, otherwise false
	*/
	static bool isSorted(T arr[], int size);
	/*
	@pre an array exists with atleast 1 value, as well as an std::default_random_engine for random numbers
	@post every element in the array will be randomly swapped with another element in the array
	@return none
	*/
	static void shuffle(T arr[], int size, std::default_random_engine& generator);
	/*
	@pre none
	@post an int array will be created, and filled with random int(s) that are between min and max
	@return a reference to the new array that was created
	*/
	static int* createTestArray(int size, int min, int max);
	/*
	@pre an array exists with atleast 1 value
	@post the array will be sorted, and the elapsed time to sort the array will be recorded
	@return the time elapsed to complete the parameter sort function on the parameter array
	*/
	static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);


};

#include "Sorts.hpp"
#endif

