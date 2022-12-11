/*
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

Example 1 :

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Example 2:

Input : arr = [2, 4, 1, 3], k = 4
Output: False
Explanation: There is no possible solution.
*/
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int> freq(k,0);
        for(int n:nums){
            int y=n%k;
            if(freq[(k-y)%k]!=0) freq[(k-y)%k]--;
            else    freq[y]++;
        }
        for(int n:freq){
            if(n!=0)    return false;
        }
        return true;
    }
};
