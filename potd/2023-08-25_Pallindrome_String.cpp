/*
Given a string S, check if it is palindrome or not.

Example 1:
Input: S = "abba"
Output: 1
Explanation: S is a palindrome

Example 2:
Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
*/

//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int n = S.length();
        int i=0,j=n-1;
        while(i<=j){
            if(S[i]!=S[j]){
                return 0;
            }
            i++;
            j--;
        }
        return true;
	}

};
