/*
Given an array A of n positive numbers. 
The task is to find the first index in the array such that the sum of elements before it is equal to the sum of elements after it.
Note:  Array is 1-based indexed.

Example 1:
Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 3 
Explanation: For second test case at position 3 elements before it (1+3) = elements after it (2+2). 
*/

class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        // code here
        int s=0;
        for(int a:A) s+=a;
        
        int bef_sum=0;
        for(int i=0;i<A.size();i++){
            s=s-A[i];
            if(bef_sum==s) return i+1;
            bef_sum+=A[i];
        }
        return -1;
    }
};
