/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. 
If there is no possible substring then print -1.

Example 1:
Input:
S = "aabacbebebe", K = 3
Output:  7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.
*/


//User function template for C++
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int ans=0,mx=0;
    unordered_map<char,int> un;
    int i=0,j=0;
    while(j<s.size()){
        un[s[j]]++;
        j++;
        while(un.size() > k){
            un[s[i]]--;
            if(un[s[i]]==0)    un.erase(s[i]);
            i++;
        }
        ans=max(ans,j-i);
    }
    if(un.size() < k) return -1;
    else if(un.size()==k)    return max(ans,j-i);
    else    return ans;
    }
};
