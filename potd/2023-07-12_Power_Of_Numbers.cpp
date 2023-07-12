/*
Given a number and its reverse. Find that number raised to the power of its own reverse.
Note: As answers can be very large, print the result modulo 109 + 7.

Example 1:
Input: N = 2
Output: 4
Explanation: The reverse of 2 is 2 and after raising power of 2 by 2 we get 4 which gives remainder as 4 when divided by 1000000007.
*/

class Solution{
    public:
    //You need to complete this fucntion
    long long power(int n,int R)
    {
       //Your code here
       long long ans = 1,N=n;
        while(R > 0){
            if(R % 2 == 0){
                N = (N * N)%mod;
                R /= 2;
            }
            else{
                ans = (ans * N)%mod;
                R = R - 1;
            }
        }
        return ans;
    }
};
