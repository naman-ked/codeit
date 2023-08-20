/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:
Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the given array.
*/


//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int l=lower_bound(arr,arr+n,x)-arr;
	    if(l==n ||  arr[l]!=x){
	        return 0;
	    }
	    int r=upper_bound(arr,arr+n,x)-arr;
	    return r-l;
	}
	
};
