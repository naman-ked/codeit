/*
Given an array arr[] of size N where every element is in the range from 0 to n-1. 
Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].
NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.

Example 1:
Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation: 
arr[arr[0]] = arr[1] = 0.
arr[arr[1]] = arr[0] = 1.
*/

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        // Your code here
        for(int i = 0; i<n; i++) {
            arr[i] = arr[i] + (arr[arr[i]]%n)*n;
        }
        for(int i = 0; i<n; i++) {
            arr[i] = arr[i]/n;
        }
    }
};

/*Explainiation
Dividend = Divisor * Quotient + Remainder;
So when we divide dividend by Quotient later, we will obtain Divisor.
So, we will first modify our arr[i] as
arr[i]        = (arr[arr[i]]%n)*n  +    arr[i];
Divivend =   Divisor*Quotient  +  Remainder
Later when we do arr[i] / n, we get the Divisor that is arr[arr[i]]%n = arr[arr[i]] as all elements are smaller than n.
