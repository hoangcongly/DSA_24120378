#include <iostream>
#include <vector>
#include <set>
using namespace std;

void different_value(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool kt = false;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				kt = true;
				break;
			}
		}
		if (!kt)
		{
			cout << a[i] << "\t";
		}
	}
}

int dfr_val(int*a , int n)
{
	set<int> se;
	for (int i = 0; i <n; i++)
	{
		se.insert(a[i]);
	}
	return se.size();
}
void giao_2_mang(int* a, int* b, int m, int n)
{
	set<int> s1;
	set<int> s2;
	for (int i=0; i<m; i++)
	{
		s1.insert(a[i]);
	}
	for (int j = 0; j < n; j++)
	{
		
	}
}

int main()
{
	/*int n;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cnt[a[i]] = 1;
	}*/
	for()
}