/*
Given an array of integers of size n and an integer k, find all the pairs in the array whose absolute difference is divisible by k.
Example 1:

Input:
n = 3
arr[] = {3, 7, 11}
k = 4
Output:
3
Explanation:
(11-3) = 8 is divisible by 4
(11-7) = 4 is divisible by 4
(7-3) = 4 is divisible by 4
*/

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
        unordered_map<long long int,long long int> m;
        long long int a,b;
        long long int count=0;
        for(int i=0;i<n;i++){
            a=arr[i]%k;
            if(m.find(a)!=m.end())count+=m[a];
            m[a]++;
        }
        return count;
    }
};
