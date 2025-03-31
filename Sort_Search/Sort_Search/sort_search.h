#ifndef SORT_SEARCH.H
#define SORT_SEARCH.H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int& a, int& b);
void selection_Sort(int* a, int n);
void insertion_sort(int* a, int n);
void Bubble_Sort(int* a, int n);
void Merge(int a1[], int n1, int a2[], int n2, int result[]);
enum PivotStrategy
{
	FIRST_ELEMENT,
	MIDDLE_ELEMENT,
	MEDIAN_OF_THREE
};
int choose_Pivot(int* a, int low, int high, PivotStrategy stra);
int partition(int* a, int low, int high, PivotStrategy stra);
void quick_Sort_Heaper(int* a, int low, int high, PivotStrategy stra);
void quickSort(int arr[], int n, PivotStrategy strategy);
bool ascendingOrder(int a, int b);
bool descendingOrder(int a, int b);
void Heapify(int arr[], int n, int i, bool(*comparator)(int, int));
void HeapSort(int arr[], int n, bool(*comparator)(int, int));

#endif // !SORT_SEARCH.H
