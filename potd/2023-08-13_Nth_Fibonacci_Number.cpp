/*
Given a positive integer n, find the nth fibonacci number. 
Since the answer can be very large, return the answer modulo 1000000007.
Example 1:
Input: 
n = 2
Output: 
1 
Explanation: 
1 is the 2nd number of fibonacci series.
*/

class Solution {
  public:
    int nthFibonacci(int n){
        // code here
          int a=0,b=1,c,cnt=1;
        while(cnt<n)
        {
            c=(a+b)%1000000007;
            a=b;
            b=c;
            cnt++;
        }
        return c;
    }
};
