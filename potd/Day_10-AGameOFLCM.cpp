/*
Given an integer N. Find maximum LCM (Least Common Multiple) that can be obtained from four numbers less than or equal to N.
Note: Duplicate numbers can be used.

Example 1:

Input:
N = 4
Output: 12
Explanation:
The four numbers can be [4,4,3,2] or
[4,4,4,3], etc. It can be shown that 12 is
the maximum LCM of four numbers that can
be obtained from numbers less than or equal 
to 4.
*/
class Solution {
  public:
    long long maxGcd(int N) {
        return max(solve(N),solve(N-1));
    }
        // code here
    long solve(int n){
        long ans=n;
        int added=0;
        for(int i=n-1;i>=1;i--){
            if(gcd(ans,i)==1L){
                ans*=i;
                added++;
            }
            if(added==3)return ans;
        }
        return ans;
    }
    long gcd(long a,long b){
        if(a==0)return b;
        return gcd(b%a,a);
    }
};
