/*
Given an integer N.Create a string using only lowercase characters from a to z that follows the given rules.
When N is even:
Use N/2 characters from the beginning of a-z and N/2 characters from the ending of a-z.
When N is greater than 26,continue repeating the instructions until length of string becomes N.

When N is odd:
Case 1: If the sum of digits of N is even, Select (N+1)/2 characters from the beginning of a-z and (N-1)/2 characters from the ending of a-z.
Case 2: If the sum of digits of N is odd, Select (N-1)/2 characters from the beginning of a-z and (N+1)/2 characters from the ending of a-z.
When N is greater than 26,continue repeating the instructions until length of string becomes N.

Example 1:

Input: 
N=21
Output: 
abcdefghijpqrstuvwxyz
Explanation:
Since 21 is odd and sum of digits of 21 is also odd,we take (21-1)/2=10  characters from the beginning and  (21+1)/2=11 characters from the end of a-z.

Example 2:
Input:
N=28 
Output: 
abcdefghijklmnopqrstuvwxyzaz
Explanation: 
Since 28>26, we keep repeating the process until length of string becomes 28.
*/


class Solution {
  public:
  
    bool sumofDigits(int n){
        int s=0;
        while(n>0){
            s+=(n%10);
            n=n/10;
        }
        return s%2==0;
    }
    
    
    string BalancedString(int N) {
        // code here
        int s=0,e=0;
        string a="",res="";
        for(int i=97;i<=122;i++)a+=char(i);
        int f=N;
        while(N > 26){
            res += a;
            N -= 26;
        }
        if(N%2==0){
            s=N/2;
            e=N/2;
        }
        else{
            if(sumofDigits(f)){
                s=(N+1)/2;
                e=(N-1)/2;
            }
            else {
                s=(N-1)/2;
                e=(N+1)/2;
            }
        }
       res += a.substr(0, s);
       res += a.substr((26 - e), e);
       return res;
    }
};