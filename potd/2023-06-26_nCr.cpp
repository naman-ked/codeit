/*
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.
Example 1:
Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 
*/

class Solution{
public:
    int mod=1e9+7; 
    int nCr(int n, int r){
        if(r>n) return 0;
        vector<int> pascal;
        for(int i=0;i<=n;i++){
            vector<int> v(i+1,1);
            for(int j=1;j<i;j++){
                v[j]=(pascal[j]+pascal[j-1])%mod;
            }
            pascal=v;
        }
        return pascal[r];
    }
};
