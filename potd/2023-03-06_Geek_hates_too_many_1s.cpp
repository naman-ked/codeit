/*
Given an non-negative integer n. 
You are only allowed to make set bit unset. 
You have to find the maximum possible value of query so that after performing the given operations, no three consecutive bits of the integer query are set-bits. 

Example 1:
Input:
n = 2
Output:  2
Explanation: 
2's binary form is 10, no 3 consecutive set bits are here.  So, 2 itself would be answer.
*/

class Solution {
  public:
    int noConseBits(int n) {
        // code here
        string s= bitset<64>(n).to_string();
        for(int i = 0;i<s.size()-2;i++){
            if(s[i] == '1'&& s[i+1] == '1' && s[i+2] == '1'){
                s[i+2] = '0';
            }
        }
        int ans = stoi(s, 0, 2);
        return ans;
    }
};
