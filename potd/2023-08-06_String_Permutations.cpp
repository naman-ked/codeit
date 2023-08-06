/*
Given a string S. The task is to find all permutations (need not be different) of a given string.

Example 1:
Input:
S = AAA
Output: AAA AAA AAA AAA AAA AAA
Explanation: There are total 6 permutations, as given in the output.
*/

class Solution{
    public:
    void help(int ind,string &s,vector<string>&res){
        if(ind==s.size()){
            res.push_back(s);
            return;
        }
        for(int i=ind;i<s.size();i++){
            swap(s[i],s[ind]);
            help(ind+1,s,res);
            swap(s[i],s[ind]);
        }
    }
        
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string> res;
        help(0,s,res);
        sort(res.begin(),res.end());
        return res;
    }
};
