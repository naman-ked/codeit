/*
Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
To scramble the string, we may choose any non-leaf node and swap its two children. 
Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.

Note: Scrambled string is not the same as an Anagram.
Print "Yes" if S2 is a scrambled form of S1 otherwise print "No".

Example 1:

Input: S1="coder", S2="ocder"
Output: Yes
Explanation: ocder is a scrambledform of coder.

    ocder
   /    \
  oc    der
 / \    
o   c  
As "ocder" can represent it as a binary tree by partitioning it into two non-empty substrings.
We just have to swap 'o' and 'c' to get "coder".
*/

class Solution{
    unordered_map<string,bool> mm;
    public:
     bool isScramble(string S1, string S2){
        //code her
        if(S1==S2) return true;
        if(mm.find(S1+S2)!=mm.end()) return mm[S1+S2];
        int n=S1.size();
        string temp="";
        for(int i=0;i<n-1;i++){
            temp+=S1[i];
            bool a=isScramble(temp,S2.substr(0,i+1));
            bool b=isScramble(temp,S2.substr(n-i-1,i+1));
            bool c=isScramble(S1.substr(i+1,n-i-1),S2.substr(i+1,n-i-1));
            bool d=isScramble(S1.substr(i+1,n-i-1),S2.substr(0,n-i-1));
            if((a and c) or(b and d)) return true;
        }
        return mm[S1+S2] =false;
    }  
};
