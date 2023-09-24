/*
Given an array A of n positive numbers. 
The task is to find the first equilibrium point in an array.
Equilibrium point in an array is a position such that the sum of 
elements before it is equal to the sum of elements after it.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

Example 1:
Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 
3 
Explanation:  
equilibrium point is at position 3 as sum of elements before it (1+3) =
sum of elements after it (2+2). 
*/

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        int sum2=0;
        for(int i=0;i<n;i++){
            sum-=a[i];
            if(sum==sum2) return i+1;
            sum2+=a[i];
        }
        return -1;
    }
};
