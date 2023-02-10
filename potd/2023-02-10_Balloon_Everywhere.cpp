/*
Bob is very fond of balloons. Once he visited an amusement park with his mother. 
The mother told Bob that she would buy him a balloon only if he answer her problem right. 
She gave Bob a string S [contains only lowercase characters] and asked him to use the characters of string to form as many instances of the word "balloon" as possible. 
Return the maximum number of instances that can be formed.
Help Bob to solve the problem.
Note: You can use each character in the string at most once.

Example 1:

Input: S: nlaebolko
Output: 1
Explanation:
Here, the number of occurence of 'b' = 1 of occurence of 'a' = 1 of occurence of 'l' = 2 of occurence of 'o' = 2 of occurence of 'n' = 1
So, we can form 1 "balloon" using the letters.
*/

class Solution{
public:
    int maxInstance(string s){
        int b=0,a=0,l=0,o=0,n=0;
        //counting each character
        for(int i=0;i<s.length();i++){
            if(s[i]=='b') b++;
            else if(s[i]=='a') a++;
            else if(s[i]=='l') l++;
            else if(s[i]=='o') o++;
            else if(s[i]=='n') n++;
        }
        
        l=l/2;
        o=o/2;
        //cout<<b<<a<<l<<o<<n; for debugging
        return min(b,min(a,min(l,min(o,n))));
    }
};
