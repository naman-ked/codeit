/*
Given two strings A and B. Find minimum number of times A has to be repeated such that B is a Substring of it. If B can never be a substring then return -1.

Example 1:

Input:
A = "abcd"
B = "cdabcdab"
Output:
3
Explanation:
Repeating A three times (abcdabcdabcd),B is a substring of it. B is not a substring of A when it is repeated less than 3 times.
*/

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        int c = 1;
        string s = A;
        while(A.length() <B.length())
        {
            A = A + s;
            c++;
        }
        if(A.find(B) != -1)return c;
        A = A +s; c++;
        if(A.find(B) != -1)return c;
        return -1;
    }
};
