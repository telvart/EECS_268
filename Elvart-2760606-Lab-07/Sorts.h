/**
*	@file: Sorts.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 10.26.15
*	@brief: Various iterative and recursive sorting methods for arrays of numbers
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
	@post sorts the array using the merge sort algorithm
	@return none
	*/
	static void mergeSort(T arr[], int size);
	/*
	@pre an array exists with atleast 1 value in it
	@post quickSortRec will be called with the median paramter as false
	*/
	static void quickSort(T arr[], int size);
	/*
	@pre an array exists with atleast 1 value in it
	@post quickSortRec will be called with the median flag set to true
	*/
	static void quickSortWithMedian(T arr[], int size);
	/*
	@pre an array exists with atleast 1 value in it 
	@post none
	@return true if the array is sorted in ascending order, otherwise false
	*/
	static bool isSorted(T arr[], int size);
	/*
	@pre an array exists with atleast 1 value
	@post the array will be sorted, and the elapsed time to sort the array will be recorded
	@return the time elapsed to complete the parameter sort function on the parameter array
	*/
	static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);
	/*
	@pre none
	@post an int array will be created, and filled with random int(s) that are between min and max
	@return a reference to the new array that was created
	*/
	static int* createTestArray(int size, int min, int max);


private:
	/*
	@pre 2 sorted arrays exist atleast 1 value in each of them
	@post the two arrays will combined into 1 sorted array
	@return none
	*/
	static void merge(T* a1, T* a2, int size1, int size2);
	/*
	@pre an array exists with atleast 1 value in it
	@post the array will be sorted using the quick sort method
	@return none
	*/
	static void quickSortRec(T arr[], int first, int last, bool median);
	/*
	@pre an array exists with atleast 1 value in it
	@post the median value of the array will be put in the last index of the array
	@return none
	*/
	static void setMedianPivot(T arr[], int first, int last);
	/*
	@pre an array exists with atleast 1 value in it
	@post partitions the array according the the pivot value
	@return none
	*/
	static int partition(T arr[], int first, int last, bool median);
	/*
	@pre an array exists
	@post each value in the array will be randomply swapped with another index in the array
	@return none
	*/
	static void shuffle(T arr[], int size);
	
	/*
	@pre an array exists
	@post the array could be partitioned a few times
	@return the index of the median value of the array
	*/
	static int findMedian(T arr[], int first, int last);


};

#include "Sorts.hpp"
#endif

