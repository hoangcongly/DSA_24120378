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
void heapify(int*a, int n, int i)
{
	int largest=i;
	int left= 2*i+1;
	int right=2*i+2;
	if(left<n&& a[left]> a[largest]) largest=left;
	if(right<n&& a[right]> a[largest]) largest=right;
	if(largest!=i)
	{
		swap(a[i], a[largest]);
		heapify(a,n,largest);
	}
}
void printArrays(int*a, int n)
{
	for(int i=0; i< n; i++) 
	{
		cout << a[i] << "\t";
	}
}
void heapSort(int*a, int n)
{
	for(int i=n/2-1; i>=0; i--)
	{
		heapify(a,n,i);
	}
	cout << "Sau khi tạo Heap: ";
	printArrays(a,n);
	for(int i=n-1; i>0; i--)
	{
		swap(a[0],a[i]);
		heapify(a, i,0);
		cout << "Buoc: " << n-i << ": ";
		printArrays(a,n);
	}
}
// 1 1 1 2 2 3 4 4 4 4 5 5 
void abc(int*a, int n)
{
	
	int count=1;
	for(int i=1; i<n; i++)
	{
		if(a[i]==a[i-1]) 
		{
			count++;
		}
		else
		{
			cout << a[i-1]<< ": "<< count<< endl;
			count=1;
		}
		cout << a[n-1] << ": " << count << endl;
		
	}
}
void shop(int*a, int n)
{
	// 1 1 1 2 2 3 4 4 4 4 5 5 
	int freq[100]={0};

	int d=0;
	for(int i=0; i<n; i++)
	{
		freq[a[i]]++;
	}
	for(int i=0; i<100; i++)
	{
		if(freq[a[i]]>0) d++;
	}
	int ind=0;
	int*nums=new int[d];

	int*count=new int[d];

	for(int i=0; i<100; i++ )
	{
		if(freq[i]>0) 
		{
			nums[ind++]=i;
			count[ind++]= freq[i];
		}
	}
	for(int i=0; i< d-1; i++)
	{
		for(int j=i+1; j<d; j++)
		{
			swap(count[i], count[j]);
            swap(nums[i], nums[j]);
		}
	}
	for (int i = 0; i < d; i++)
    cout << nums[i] << ": " << count[i] << endl;
}
bool Search_In_Rotated_Sorted_Arrays(vector<int>&nums, int K)
{
	// 4 5 6 7 8 0 1 2, K=1
	int left=0;
	int right=nums.size()-1;
	while(left<=right)
	{
		int mid= left+(right-left)/2;
		if(nums[mid]==K) return true;
		else if(nums[mid]>=nums[left])
		{
			if(nums[mid]>K)
			{
				right=mid-1;
			}
			else left=mid+1;
		}
		else
		{
			if(nums[mid]<K)
			{
				left=mid+1;
			}
			else right=mid-1;
		}
	}
}
