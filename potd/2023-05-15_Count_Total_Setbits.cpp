/*
You are given a number N. Find the total number of setbits in the numbers from 1 to N. 
Example 1:
Input: N = 3
Output: 4
Explaination: 1 -> 01, 2 -> 10 and 3 -> 11. So total 4 setbits.
*/

class Solution {
  public:
    long long countBits(long long N) {
        // code here
        long long ans = 0;
        for(int i = 1; i <= N; i++)
            ans += __builtin_popcount(i);
        return ans;
    }
};

__builtin_popcount()  is a built-in function of GCC compiler. This function is used to count the number of set bits in an unsigned integer. 
Syntax:
__builtin_popcount(int number);
Parameter: This function only takes unsigned or positive integers as a parameter.
Time Complexity:O(1)
