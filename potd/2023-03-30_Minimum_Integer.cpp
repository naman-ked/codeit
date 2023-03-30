/*
You are given an array A of size N. Let us denote S as the sum of all integers present in the array. 
Among all integers present in the array, find the minimum integer X such that S ≤ N*X.

Example 1:
Input:
N = 3,
A = { 1, 3, 2}
Output: 2
Explanation: Sum of integers in the array is 6.since 6 ≤ 3*2, therefore 2 is the answer.
*/

class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        // code here
        long long int s=0;
        for(int a:A){
            s=s+a;
        }
        int res=INT_MAX;
        for(int a:A){
            if(((long)N*a)>=s){
                res=min(res,a);
            }
        }
        return res;
    }
};
