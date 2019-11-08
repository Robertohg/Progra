// C++ program to sort an array using bucket sort
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

const int arraySize = 1000;
const int range = 100;
using namespace std;


int getRand()
{
	return 1 + rand() % range;
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)


		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	int L[n1], R[n2];


	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];


	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}



void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;


		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}



void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;


	if (l < n && arr[l] > arr[largest])
		largest = l;


	if (r < n && arr[r] > arr[largest])
		largest = r;


	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}


void heapSort(int arr[], int n)
{

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);


	for (int i = n - 1; i >= 0; i--)
	{

		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}




int main()
{

	int arr[arraySize];
	for (int i = 0; i < arraySize - 1; i++)
	{
		arr[i] = getRand();
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	auto start = chrono::high_resolution_clock::now();
	bubbleSort(arr, n);
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
	cout << "BubbleSort: " << duration.count() << " nanosegundos" << endl;

	int arr1[arraySize];
	for (int i = 0; i < arraySize - 1; i++)
	{
		arr1[i] = getRand();
	}
	int arr_size = sizeof(arr1) / sizeof(arr1[0]);
	auto start1 = chrono::high_resolution_clock::now();
	mergeSort(arr1, 0, arr_size - 1);
	auto stop1 = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::nanoseconds>(stop1 - start1);
	cout << "Merge Sort: " << duration1.count() << " nanosegundos" << endl;


	int arr2[arraySize];
	for (int i = 0; i < arraySize - 1; i++)
	{
		arr2[i] = getRand();
	}
	n = sizeof(arr2) / sizeof(arr2[0]);
	auto start2 = chrono::high_resolution_clock::now();
	quickSort(arr2, 0, n - 1);
	auto stop2 = chrono::high_resolution_clock::now();
	auto duration2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);
	cout << "Quick Sort: " << duration2.count() << " nanosegundos" << endl;




	int arr3[arraySize];
	for (int i = 0; i < arraySize - 1; i++)
	{
		arr3[i] = getRand();
	}
	n = sizeof(arr3) / sizeof(arr3[0]);
	auto start3 = chrono::high_resolution_clock::now();
	insertionSort(arr3, n);
	auto stop3 = chrono::high_resolution_clock::now();
	auto duration3 = chrono::duration_cast<chrono::nanoseconds>(stop3 - start3);
	cout << "Insertion Sort: " << duration3.count() << " nanosegundos" << endl;


	int arr4[arraySize];
	for (int i = 0; i < arraySize - 1; i++)
	{
		arr4[i] = getRand();
	}
	n = sizeof(arr4) / sizeof(arr4[0]);
	auto start4 = chrono::high_resolution_clock::now();
	heapSort(arr4, n);
	auto stop4 = chrono::high_resolution_clock::now();
	auto duration4 = chrono::duration_cast<chrono::nanoseconds>(stop4 - start4);
	cout << "Heap Sort: " << duration4.count() << " nanosegundos" << endl;

	return 0;
}
