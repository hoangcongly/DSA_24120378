#include "sort_search.h"

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void selection_Sort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}
void insertion_sort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void Bubble_Sort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
void Merge(int a1[], int n1, int a2[], int n2, int result[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2)
	{
		if (a1[i] < a2[i])
		{
			result[k++] = a1[i++];
		}
		result[k++] = a2[j++];
	}
	while (i < n1)
	{
		result[k++] = a1[i++];
	}
	while (j < n2)
	{
		result[k++] = a2[j++];
	}
}
enum PivotStrategy
{
	FIRST_ELEMENT,
	MIDDLE_ELEMENT,
	MEDIAN_OF_THREE
};
int choose_Pivot(int* a, int low, int high, PivotStrategy stra)
{
	if (stra == FIRST_ELEMENT) return low;
	else if (stra == MIDDLE_ELEMENT) return (low + high) / 2;
	else
	{
		int mid = (low + high) / 2;
		if (a[low] <= a[mid] && a[mid] <= a[high] ||
			a[low] >= a[mid] && a[mid] >= a[high])
		{
			return mid;
		}
		else if (a[mid] <= a[low] && a[low] <= a[high] ||
			a[mid] >= a[low] && a[low] >= a[high])
		{
			return low;
		}
		else return high;
	}
}
int partition(int* a, int low, int high, PivotStrategy stra)
{
	int pivotIndex = choose_Pivot(a, low, high, stra);
	swap(a[pivotIndex], a[high]);
	int pivot = a[high];
	int i = low - 1;
	for (int j = low;j < high; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return i + 1;
}
void quick_Sort_Heaper(int* a, int low, int high, PivotStrategy stra)
{
	if (low < high)
	{
		int pi = partition(a, low, high, stra);
		quick_Sort_Heaper(a, low, pi - 1, stra);
		quick_Sort_Heaper(a, pi+1,high, stra);
	}
}
void quickSort(int arr[], int n, PivotStrategy strategy) 
{
	quick_Sort_Heaper(arr, 0, n - 1, strategy);
}
bool ascendingOrder(int a, int b)
{
	return a < b;
}
bool descendingOrder(int a, int b)
{
	return a > b;
}
void Heapify(int arr[], int n, int i, bool(*comparator)(int, int))
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if(left<n&& comparator(arr[largest],arr[left]))
		largest=left;
	if (right < n && comparator(arr[largest], arr[right]))
		largest = right;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest, comparator);
	}
}
void HeapSort(int arr[], int n, bool(*comparator)(int, int))
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapify(arr, n,i, comparator);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0, comparator);
	}
}
void ins_sort(int* a, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j > 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void merge(int* a, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++) L[i] = a[left + i];
	for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
	int i = 0; 
	int j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	while (i < n1)
	{
		a[k++] = L[i++];
	}
	while (j < n2)
	{
		a[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
}
void hybridSortRecursive(int* a, int left, int right, int thresold)
{
	if (right - left + 1 <= thresold)
	{
		ins_sort(a, left, right);
		return;
	}
	int mid = left + (right - left) / 2;
	hybridSortRecursive(a, left, mid, thresold);
	hybridSortRecursive(a, mid,right, thresold);
	merge(a, left, mid, right);
}