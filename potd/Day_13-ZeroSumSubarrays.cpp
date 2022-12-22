/*
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]
*/
class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        int count=0,sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            if(sum==0)count++;
            if(m.find(sum)!=m.end()){
                count+=m[sum];
                m[sum]++;
            }
            else m[sum]=1;
        }
        return count;
    }
};
