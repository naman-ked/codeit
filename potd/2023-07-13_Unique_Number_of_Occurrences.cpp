/*
Given an array arr of N integers, the task is to check whether the frequency of the elements in the array is unique or not. 
Or in other words, there are no two distinct numbers in array with equal frequency. If all the frequency is unique then return true, else return false.

Example 1:
Input:
N = 5
arr = [1, 1, 2, 5, 5]
Output: false
Explanation: The array contains 2 (1’s), 1 (2’s) and 2 (5’s), since the number of frequency of 1 and 5 are the same i.e. 2 times. Therefore, this array does not satisfy the condition.
*/

class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_set<int> s;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++) freq[arr[i]]++;
        
        for(auto f:freq){
            if(s.find(f.second)!=s.end()) return false;
            s.insert(f.second);
        }
        return true;
    }
};
