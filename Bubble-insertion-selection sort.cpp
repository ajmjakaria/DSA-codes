
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
	//loop for passes
	for (int i = 0; i < n-1; ++i)
	{
		int swapped = 0;
		for(int j = 0; j < n-1 - i; j++)
		{
			if(arr[j+1] < arr[j])
			{
				//swap(arr[j+1], arr[j])
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = 1;
			}
		}
		if(swapped == 0) //already sorted
			break;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}

void insertionSort(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1; //j is the immediate left element
		//shift elements greater than key
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key; //place key to the correct position
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}

void selectionSort(int arr[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		int minIndex = i;
		//loop to find the min element
		for(int j = i+1; j < n; j++)
		{
			if(arr[minIndex] > arr[j])
				minIndex = j;
		}
		//swap minimum element with the first element of the unsorted part
		int temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] =temp;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}


int main()
{
	int arr[] = {5, 3, 8, 4, 2};
	int size  = sizeof(arr)/sizeof(arr[0]);
	// bubbleSort(arr, size);
	// insertionSort(arr, size);
	selectionSort(arr, size);
	return 0;
}
