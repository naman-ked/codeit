/*
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

Example 1:
Input : 
n = 4, k = 10
a[] = {1, 2, 3, 4}
Output : 7
Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} , {1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
*/

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=1;
        for(int i=0; i<n;i++){
            int j=i;
            long long mul=a[i];
            while(j<n and mul < k){
                j++;
                ans++;
                mul = mul*a[j];
            }
        }
        return ans-1;
    }
};
