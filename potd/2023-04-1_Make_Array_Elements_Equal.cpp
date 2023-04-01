
/*
You are given an integer N. Consider an array arr having N elements where arr[i] = 2*i+1. (The array is 0-indexed)
You are allowed to perform the given operation on the array any number of times:
1) Select two indices i and j and increase arr[i] by 1 and decrease arr[j] by 1.
Your task is to find the minimum number of such operations required to make all the elements of the array equal.

Example 1:
Input:
N = 3
Output:
2
Explanation:
Initially the array is {1, 3, 5}. If we perform the operation once on the indices 0 and 2, the resulting array will be {2, 3, 4}. If we again 
perform the operation once on the indices 0and 2, the resulting array will be {3, 3, 3}.Hence, the minimum operations required is 2 in this case. 
*/

class Solution {
  public:
    long long int minOperations(int N) {
        // Code here
        long long int x=N/2;
        long long int y=x+1;
        if(N%2==0) return x*x;
        return x*y;
    }
};
