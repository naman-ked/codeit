/*
You are given a string s. You need to reverse the string.

Example 1:
Input:
s = Geeks
Output: skeeG
*/

//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        string ans = "";
        for(int i=str.size()-1;i>=0;i--)
        {
            ans.push_back(str[i]);
        }
        return ans;
    }
};
