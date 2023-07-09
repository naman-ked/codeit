/*
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:
Input: N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing number is 6.
*/

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++){
            if(arr[i]>0 and arr[i]<=n && arr[arr[i]-1]!=arr[i]){
                int temp=arr[arr[i]-1];
                arr[arr[i]-1]=arr[i];
                arr[i]=temp;
                i--;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1) return i+1;
        }
        
        return n+1;
    } 
};
