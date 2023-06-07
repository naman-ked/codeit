/*
Given a number N, find the least prime factors for all numbers from 1 to N.  The least prime factor of an integer X is the smallest prime number that divides it.
Note :
1 needs to be printed for 1.
You need to return an array/vector/list of size N+1 and need to use 1-based indexing to store the answer for each number.
Input: N = 6
Output: [0, 1, 2, 3, 2, 5, 2] 
Explanation: least prime factor of 1 = 1,
least prime factor of 2 = 2,
least prime factor of 3 = 3,
least prime factor of 4 = 2,
least prime factor of 5 = 5,
least prime factor of 6 = 2.
So answer is[1, 2, 3, 2, 5, 2]. 
*/

class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
         vector<int> ans(n + 1);
         ans[1] = 1;
         for (int i = 2; i <= n; i++) {
            ans[i] = i;
         }
         for (int i = 2; i * i <= n; i++) {
            if (ans[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (ans[j] == j) {
                    ans[j] = i;
                    }
                }
            }
         }
    return ans;
    }
};
