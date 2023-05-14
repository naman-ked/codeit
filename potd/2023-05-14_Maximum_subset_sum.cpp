/*
Given an array A of size N. 
Find the maximum subset-sum of elements that you can make from the given array such that for every two consecutive elements in the array, at least one of the elements is present in our subset. 

Example 1:
Input:  N = 4
A[] = {1, -1, 3, 4}
Output: 8
Explanation: We can choose 0th,2nd & 3rd index(0 based Index),so that it can satisfy the condition & can make maximum sum 8. 
*/

class Solution {
  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        int first=A[0];
        int second=0;
        for(int i=1;i<N;i++){
            second=max(first,second)+A[i];
            swap(first,second);
        }
        return max(first,second);
    }
};
