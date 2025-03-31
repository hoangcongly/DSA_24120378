// 270325.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

bool Search_In_Rotated_Sorted_Arrays(vector<int>& nums, int K)
{
	// 4 5 6 7 8 0 1 2, K=1
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == K) return true;
		if (nums[left] == nums[mid] && nums[mid] == nums[right])
		{
			left++;
			right--;
		}
		else if (nums[mid] >= nums[left])
		{
			if (nums[mid] > K&& K>= nums[right])
			{
				right = mid - 1;
			}
			else left = mid + 1;
		}
		else
		{
			if (nums[mid] < K&& K<=nums[right])
			{
				left = mid + 1;
			}
			else right = mid - 1;
		}
	}
	return false;
}

int main()
{
	vector<int> nums = { 4,5,6,7,0,1,2 };
	int k;
	cin >> k;
	if (Search_In_Rotated_Sorted_Arrays(nums, k)) cout << "y";
	else cout << "n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
