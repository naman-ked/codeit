/*
You are given a sorted array a of length n. 
For each i(0<=i<=n-1), you have to make all the elements of the array from index 0 till i equal, using minimum number of operations.
In one operation you either increase or decrease the array element by 1.
You have to return a list which contains the minimum number of operations for each i, to accomplish the above task.

Note:
1. 0-based indexing.
2. For each index, you need to consider the same array which was given to you at the start.

Example 1:
Input:  N=4 A={1,6,9,12}
Output: 0 5 8 14
*/

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<n;i++){
            int ind=i/2;
            ans.push_back(a[i]-a[ind]+ans[i-1]);
        }
        return ans;
    }
};
