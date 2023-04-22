/*
You are given an array arr of n elements. 
In one operation you can pick two indices i and j, such that arr[i] >= arr[j] and replace the value of arr[i] with (arr[i] - arr[j]). 
You have to minimize the values of the array after performing any number of such operations.

Example 1:
Input: n = 3
arr = {3,2,4}
Output: 1
Explanation:
1st Operation : We can pick 4 & 3, subtract 4-3 => {3,2,1}
2nd Opeartion : We can pick 3 & 2, subtarct 3-2 => {1,2,1}
3rd Operation : We can pick 1 & 2, subtract 2-1 => {1,1,1}
4th Opeartion : We can pick 1 & 1, subtract 1-1 => {1,0,1}
5th Operation : We can pick 1 & 1, subtract 1-1 => {0,0,1}
After this no operation can be performned, so maximum no is left in the array is 1, so the ans is 1.
*/

class Solution{
public:
    int findGCD(int a, int b){
        if(b == 0)
          return a;
        return findGCD(b, a%b);
    }
    
    int minimumNumber(int n,vector<int> &arr){
        // Code here
        int result = arr[0];
        for(int i = 1; i < n; i++){
            result = findGCD(result, arr[i]);
        }
        return result;
    }
};
