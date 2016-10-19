/**
*	@file: Sorts.hpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 10.26.15
*	@brief: Implementation of sorts and methods declared in Sorts.h
*/
	


template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
	T temp;
	for (int i=0; i<size-1; i++)
	{
		for (int j=0; j<size-1; j++)
		{
		 	if (arr[j]>arr[j+1])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	assert( Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
	std::default_random_engine generator(time(nullptr));
	while (!isSorted(arr,size))
	{
		
		shuffle(arr, size);
		
	}
	assert( Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
	T temp;
	int j;
	for (int i=1; i<size; i++)
	{
		j=i;
		while ( j>0 && arr[j-1]>arr[j] )
		{
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j--;
		}
	}
	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
	int mid=size/2;
	T* left=arr;
	T* right=arr+mid;
	if (size==0 || size==1)
	{
		return;
	}
	mergeSort(left, mid);
	mergeSort(right, size-mid);
	merge(left,right,mid,size-mid);

	//assert( Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
	quickSortRec(arr,0,size-1,false);
	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
	quickSortRec(arr,0,size-1,true);
	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
	int min;
	T temp;
	for (int i=0; i<size-1; i++)
	{
		min=i;
		for (int j=i+1; j<size; j++)
		{
			if (arr[j] <arr[min])
			{
				min=j;
			}
		}
		if (min>i)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
	for (int i=0; i<size-1; i++)
	{
		if (arr[i] >arr[i+1])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	start=std::chrono::system_clock::now();
	sort(arr,size);
	end=std::chrono::system_clock::now();
	elapsed=(end-start);
	return elapsed.count();
}

template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min, max-1);
	int* arr=new int[size];
	for (int i=0; i<size; i++)
	{
		int randint=distribution(generator);
		arr[i]=randint;
	}
	return arr;
}

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
	T* templist=new T[size1+size2];
	int index1=0;
	int index2=0;
	int tempindex=0;
	while (index1<size1 && index2<size2)
	{
		if (a1[index1] < a2[index2])
		{
			templist[tempindex]=a1[index1];
			tempindex++;
			index1++;
		}
		else
		{
			templist[tempindex]=a2[index2];
			tempindex++;
			index2++;
		}
	}
	if (index1>index2)
	{
		for (int i=index2; i<size2; i++)
		{
			templist[tempindex]=a2[i];
			tempindex++;
		}
	}
	else if(index2>index1)
	{
		for (int i=index1; i<size2; i++)
		{
			templist[tempindex]=a1[i];
			tempindex++;
		}
	}

	for (int i=0; i<size1+size2;i++)
	{
		a1[i]=templist[i];
	}
	delete[] templist;
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
	if (first<last)
	{
		int j=partition(arr, first, last, median);
		quickSortRec(arr,first,j-1, median);
		quickSortRec(arr,j+1,last, median);
	}
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
	T temp;
	int index=findMedian(arr,first,last);
	temp=arr[index];
	arr[index]=arr[last];
	arr[last]=temp;
}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
	if (median==true)
	{
		setMedianPivot(arr,first,last);
	}

	T pivot= arr[last];
	T temp;
	
	while (first < last)
	{
		while (arr[first] <pivot)
		{first++;
		}
		while (arr[last] > pivot)
		{last--;
		}
		if (arr[first] == arr[last])
		{
		first++;
		}
		else if(first < last)
		{
			temp=arr[first];
			arr[first]=arr[last];
			arr[last]=temp;
		}
		
	}
	return last;
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size)
{
	T temp;
	std::uniform_int_distribution<int> distribution(0,size-1);
	std::default_random_engine generator(time(nullptr));

	for (int i=0; i<size; i++)
	{
		int randint=distribution(generator);
		temp=arr[i];
		arr[i]=arr[randint];
		arr[randint]=temp;
	}
	
}

template <typename T>
int Sorts<T>::findMedian(T arr[], int first, int last)
{
	int index;
	int mid=(first+last)/2;
	index=partition(arr,first,last,false);
	while (index != mid)
	{
		if (index<mid)
		{
			index=partition(arr,mid,last,false);
		}
		else
		{
			index=partition(arr,first,mid,false);
		}
	}
	return index;	
}




















