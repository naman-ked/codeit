/*
You are given an array arr  of length N of 0's and 1's. Find the total number of subarrays of 0's

Example 1:
Input:
N = 4
arr[] = {0, 0, 1, 0}
Output:
4
Explanation:
Following are the subarrays of length 1: {0}, {0}, {0} - 3 length 2: {0, 0} - 1 Total Subarrays: 3 + 1 = 4
*/

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long int count=0;
    long long int res=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) count++;
        else{
            res=res+(count*(count+1)/2);
            count=0;
        }
    }
    res=res+(count*(count+1)/2);
    return res;
}
