/*
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
Note: An empty digit sequence is considered to have one decoding. 
It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0s, extra trailing 0s and two or more consecutive 0s then
it is an invalid string.

Example 1:

Input: str = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(123), "LC"(12 3) and "AW"(1 23).
Example 2:

Input: str = "90"
Output: 0
Explanation: "90" cannot be decoded as it's an invalid string and we cannot decode '0'.
*/

class Solution {
	public:
		int CountWays(string s){
		    int m=1e9+7;
		    int n=s.length();
        int count[n+1]; 
        count[0] = 1;
        count[1] = 1;
        //for base condition "01123" should return 0 
        if(s[0]=='0') return 0;
        for (int i = 2; i <= n; i++)
        {
               count[i] = 0;
               // If the last digit is not 0, then last digit must add to the number of words
               if (s[i-1] > '0') count[i] = count[i-1];
                // If second last digit is smaller than 2 and last digit is smaller than 7,
                // then last two digits form a valid character 
                if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') )count[i] =(count[i] + count[i-2])%m;
        }
        return count[n]%m;
		}
};
