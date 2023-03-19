/*
Geekina gifted Geek a number 'n', and since Geek is away, he asked you to count the number of times the sequence "101" occurs as a subsequence 
in the binary representation of 'n'.

Input:  n = 21
Output: 4

Explanation: 21 in binary is 10101. "101" is occurring as a subsequence in 4 ways viz. - 
101--
1--01
10--1
--101
*/

class Solution {
  public:
    long long count101(long long n) {
        // code here
        string s;
        while(n>0){
            int x=n%2;
            if(x==1)s=s+'1';
            else s=s+'0';
            n=n/2;
        }
        string S2="101";
        int m = s.size() , k = 3;
        vector<long long> count(k, 0);
 
        for (int i = 0; i < m; i++)  // Traversing the string a
        {
            for (int j = k - 1; j >= 0; j--)  // Reverse traversal of b
            {
                if (s[i] == S2[j])
                {
                count[j] += (j == 0 ? 1 : count[j - 1]);
                }
            }
        }
        return count[k-1];
    }
};
