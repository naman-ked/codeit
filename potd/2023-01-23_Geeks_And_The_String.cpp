/*
ur geek loves to play with strings, Currently, he is trying to reduce the size of a string by recursively removing all the consecutive duplicate pairs.
In other words, He can apply the below operations any number of times.
Remove all the consecutive duplicate pairs and concatenate the remaining string to replace the original string.
Your task is to find the string with minimum length after applying the above operations.
Note: If the string length become zero after applying operations, return "-1" as a string.

Example 1:
Input:
aaabbaaccd
Output: 
ad
Explanation: 
Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
*/

class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> c;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(c.empty()){
                c.push(s[i]);
            }
            else{
             if(c.top()==s[i])c.pop();
             else c.push(s[i]);
            }
        }
        string res="";
        while(!c.empty()){
            res=c.top()+res;
            c.pop();
        }
        if(res=="")return "-1";
        return res;
    }
};
