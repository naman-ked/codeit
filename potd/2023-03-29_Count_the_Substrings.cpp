/*
Given a string S. The task is to count the number of substrings which contains equal number of lowercase and uppercase letters. 

Example 1:
Input:
S = "gEEk" Output: 3
Explanation: There are 3 substrings of the given string which satisfy the condition. They are "gE", "gEEk" and "Ek".
*/

class Solution
{
    public:
    int countSubstring(string S)
    {
        int l=S.length();
        int res=0;
        for(int i=0;i<l;i++){
            int upper=0,lower=0;
            for(int j=i;j<l;j++){
                if (isupper(S[j]))upper++;
                else lower++;
                if(upper==lower){
                    //cout<<S[i]<<" "<<S[j]<<endl;
                    res++;
                } 
            }
        }
        return res;
    }
};
