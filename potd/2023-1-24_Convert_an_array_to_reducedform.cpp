/*
Given an array with N distinct elements, convert the given array to a reduced form where all elements are in range from 0 to N-1.
The order of elements is same, i.e., 0 is placed in place of smallest element, 1 is placed for second smallest element, N-1 is placed for largest element.
Note: You don't have to return anything. You just have to change the the given array.

Example 1:

Input:
N = 3
Arr[] = {10, 40, 20}
Output: 0 2 1
Explanation: 10 is the least element so it
is replaced by 0. 40 is the largest
element so it is replaced by 3-1 = 2. And
20 is the 2nd smallest element so it is
replaced by 1.
*/

class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    vector<int> b;
	    for(int i=0;i<n;i++)b.push_back(arr[i]);
	    sort(b.begin(), b.end());
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++) m[b[i]]=i;
	    for(int i=0;i<n;i++) arr[i]=m[arr[i]];
	}
};
