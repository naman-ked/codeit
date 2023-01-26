/*
Given a string S that consists of only alphanumeric characters and dashes. 
The string is separated into N + 1 groups by N dashes. Also given an integer K. 
We want to reformat the string S, such that each group contains exactly K characters, except for the first group, 
which could be shorter than K but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, 
and you should convert all lowercase letters to uppercase.
Return the reformatted string.

Example 1:
Input:   S = "5F3Z-2e-9-w", K = 4
Output: "5F3Z-2E9W"
*/

class Solution
{
   public:
    string ReFormatString(string S, int K){
        if(S=="-") return "";
        string res = "";
        int count = 0;
        int n=S.size();
        //upper case
        for(int i=0;i<n;i++) {
             if(S[i] >= 97 && S[i] <= 122) S[i] = toupper(S[i]);
        }
        //remove dashes
        for(int i=0;i<n;i++) {
             if(S[i] !='-') res+=S[i];
        }
        S=res;
        res="";
        n=S.size();
        int b=n/K;
        while(b>0)
        {  
          res="-"+S.substr(n-K,K)+res;          
          b--;
          n=n-K;
        }
        int c=n%K;
        if(c>0)res=S.substr(0,c)+res;
        if(res[0] == '-') res = res.substr(1,res.size());
        return res;
    }
};
