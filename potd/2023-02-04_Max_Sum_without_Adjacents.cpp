/*
Given an array Arr of size N containing positive integers. 
Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Example 1:

Input:
N = 6  Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3 and 5, then Arr[0]+Arr[3]+Arr[5] = 5+100+5 = 110.

*/

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // initial variables
	    int sum=arr[1];
	    int prev=arr[0];
	    //length checking
	    if(n==0) return 0;
 	    else if(n==1) return prev;
	    else if(n==2) return max(sum,prev);
	    //dp
	    for(int i=2;i<n;i++){
	        int s=arr[i]+arr[i-2];
	        sum=max(sum,s);
	        arr[i-1]=max(arr[i-2],arr[i-1]);
	        arr[i]=s;
	    }
	    return sum;
	}
};
