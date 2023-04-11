/*
Given the maximum occurrences of a, b, and c in a string. 
Your task is to make the string containing only a, b, and c such that no three consecutive characters are the same.
If the resultant string equals to a+b+c, return the length (a+b+c) otherwise -1.

Example 1:
Input:
a = 3, b = 3, c = 3
Output:  9
Explanation: 
No three consecutive character of the string "abcabcabc" is same.
*/

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int x=a,y=b,z=c;
        if(a%2!=0) a++;
        if(b%2!=0) b++;
        if(c%2!=0) c++;
        if(
        (((a/2)-1)<=(b+c)) and 
        (((b/2)-1)<=(a+c)) and 
        (((c/2)-1)<=(a+b)))
        return x+y+z;
        return -1;
    }
};
