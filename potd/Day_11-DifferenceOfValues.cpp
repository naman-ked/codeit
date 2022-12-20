/*
Given an unsorted array arr[ ] of size n, you need to find the maximum difference of absolute values of elements and indexes, i.e., for i <= j, calculate maximum of | arr[ i ] - arr[ j ] | + | i - j |. 

Example 1:

Input : 
n = 3
arr[ ] = {1, 3, -1}
Output: 5
Explanation:
Maximum difference comes from indexes 
1, 2 i.e | 3 - (-1) | + | 1 - 2 | = 5
*/

class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        // Complete the function
        int sum_max=INT_MIN,sum_min=INT_MAX,diff_max=INT_MIN,diff_min=INT_MAX;
        
        for(int i=0;i<n;i++){
            sum_max=max(sum_max,arr[i]+i);
            sum_min=min(sum_min,arr[i]+i);
            diff_max=max(diff_max,arr[i]-i);
            diff_min=min(diff_min,arr[i]-i);
        }
       
        return max((sum_max-sum_min),(diff_max-diff_min));
    } 
};
