#include "Array_Hashing.h"

class ArrayProcessor {
private:
    vector<int> nums;
    pair<int, int> findMostFrequentElement()
    {
        unordered_map<int, int> freq;
        int maxCount = 0;
        int maxElement = -1;
        for (int num : nums)
        {
            freq[num]++;
            if (freq[num] > maxCount)
            {
                maxCount = freq[num];
                maxElement = num;
            }
        }
        return { maxElement, maxCount };
    }
    bool hasPairWithSum(int K)
    {
        unordered_set<int> a;
        for (int num : nums)
        {
            if (a.count(K - num)) return true;
            a.insert(num);
        }
        return false;
    }
    bool hasSubarrayWithZeroSum()
    {
        unordered_set<int> a;
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
            if (sum == 0 || a.count(sum)) return true;
            a.insert(sum);
        }
        return false;
    }
    int longestSubarrayWithSumK(int K)
    {
        unordered_map<int, int> sumInd;
        sumInd[0] = -1;
        int prefixSum = 0;int maxLen = 0;
        for (int i = 0; i < nums.size();i++)
        {
            prefixSum += nums[i];
            if (sumInd.count(prefixSum - K))
            {
                maxLen = max(maxLen, i - sumInd[prefixSum - K]);
            }
            if (!sumInd.count(prefixSum))
            {
                sumInd[prefixSum] = i;
            }
        }
        return maxLen;
    }
    bool arePermutations(string s1, string s2)
    {
        if (s1.size() != s2.size()) return false;
        unordered_map<char, int> freq;
        for (char c : s1)
        {
            freq[c]++;
        }
        for (char c : s2)
        {
            freq[c]--;
            if (freq[c] < 0) return false;
        }
        return true;
    }
    bool hasDuplicate(vector<int>& nums)
    {
        set<int> a;
        for (int num : nums)
        {
            a.insert(num);
        }
        return a.size() < nums.size();
    }
    bool isAnagram(string s1, string s2)
    {
        if (s1.size() != s2.size()) return false;
        map<char, int> freq;
        for (char c : s1)
        {
            freq[c]++;
        }
        for (char c : s2)
        {
            if (freq[c] == 0) return false;
            freq[c]--;
        }
        return true;
    }
    vector<vector<string>> GroupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramGroup;
        for (string str : strs)
        {
            string strSorted = str;
            sort(strSorted.begin(), strSorted.end());
            anagramGroup[strSorted].push_back(str);
        }
        for (auto group : anagramGroup)
        {
            result.push_back(group.second);
        }
        return result;
    }
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto a : freq)
        {
            pq.push({ a.second,a.first });
        }
        for (int i = 0; i < k;i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};