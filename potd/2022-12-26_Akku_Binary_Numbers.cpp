/*
Akku likes binary numbers and she likes playing with these numbers. 
Her teacher once gave her a question.For given value of  L and R, Akku have to find the count of number X, 
which have only three-set bits in it's binary representation such that "L ≤ X ≤ R".Akku is genius, she solved the problem easily. Can you do it ??

Example 1:

Input:
L = 11 and R = 19 
Output: 4
Explanation:
There are 4 such numbers with 3 set bits in 
range 11 to 19.
11 -> 1011
13 -> 1101
14 -> 1110
19 -> 10011

Long Solution
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:

    bool preCompute(int n)
    {
        int x=0;
        while(n>0){
            if(n%2!=0)x++;
            if(x>3) break;
            n=n/2;
        }
        return x==3;
    }
    
    long long solve(long long l, long long r){
        // Code Here
        int count=0;
        for(int i=l;i<=r;i++){
            if(preCompute(i))count++;
        }
        return count;
    }
};
*/
class Solution{
public:
vector<long long>pre;
     void precompute()
    {
       for(int i=0;i<63;i++){
           for(int j=i+1;j<63;j++){
               for(int k=j+1;k<63;k++){
                   long long tmp=pow(2,i)+pow(2,j)+pow(2,k);
                   pre.push_back(tmp);
               }
           }
       }
       sort(pre.begin(),pre.end());
    }
    
    long long solve(long long l, long long r){
        // Code Here
            int hi=upper_bound(pre.begin(),pre.end(),r)-pre.begin();
            int lo=lower_bound(pre.begin(),pre.end(),l)-pre.begin();
            return hi-lo;
    }
    
};
