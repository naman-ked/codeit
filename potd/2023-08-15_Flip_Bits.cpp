/*
Given an array A[] consisting of 0’s and 1’s. A flip operation is one in which you turn 1 into 0 and a 0 into 1. 
You have to do at most one “Flip” operation of any subarray. Formally, select a range (l, r) in the array A[], such that (0 ≤ l ≤ r < n) holds 
and flip the elements in this range to get the maximum ones in the final array. You can possibly make zero operations to get the answer.

Example 1:
Input:
N = 5
A[] = {1, 0, 0, 1, 0} 
Output: 4
Explanation:
We can perform a flip operation in the range [1,2] After flip operation array is : [ 1 1 1 1 0 ] Count of one after fliping is : 4

Time : O(n) and Space : O(1)

Approach : Kadane's Algorithm

Prerequisite : Kadane's Algorithm

Code  : -> 
*/

class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int curr_sum = 0, count_one = 0, max_sum = 0;
        for (int i = 0; i < n; i++){
            if (a[i] == 1)
            count_one++;
            int val = (a[i]==0)?1:-1;
            curr_sum += val;
            max_sum = max(max_sum,curr_sum);
            if (curr_sum < 0)
            curr_sum = 0;
        }
        return max_sum+count_one;
    }
};
