#ifndef ARRAY_HASHING
#define ARRAY_HASHING

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> findMostFrequentElement();
bool hasPairWithSum(int K);
bool hasSubarrayWithZeroSum();
int longestSubarrayWithSumK(int K);
bool arePermutations(string s1, string s2);
bool hasDuplicate(vector<int>& nums);
bool isAnagram(string s1, string s2);
vector<vector<string>> GroupAnagrams(vector<string>& strs);
vector<int> topKFrequent(vector<int>& nums, int k);

#endif // !ARRAY_HASHING
