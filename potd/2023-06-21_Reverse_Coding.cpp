/*
You will be given an integer n, your task is to return the sum of all natural number less than or equal to n.
As the answer could be very large, return answer modulo 109+7.
Example 1:
Input:  n = 6
Output: 21
Explanation: 1+2+3+4+5+6 = 21
*/

class Solution {
  public:
    int sumOfNaturals(int n) {
        // code here
        int mod=pow(10,9)+7;
        if(n%2==0){
            long long int x=n/2;
            long long int y=n+1;
            long long int z= (x*y)%mod;
            return z;
        }
        else {
            long long int x=(n+1)/2;
            long long int z=(n*x)%mod;
            return z;
        }
    }
};
