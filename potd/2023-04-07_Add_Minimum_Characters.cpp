/*
Given a string str, find the minimum characters to be added at front of the string to make it a palindrome.

Example 1:
Input:
str = ABCD
Output: 3
Explanation: The resultant string after adding 3 characters is DCBABCD. The minimum possible answer is 3.
*/

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int i=0;
        int j=str.length()-1;
        int trim=j;
        int res=0;
        while (i<j){
            if(str[i]==str[j]){
                i+=1;
                j-=1;
            }
            else{
                res+=1;
                i=0;
                trim-=1;
                j=trim;
            }
        }
        return res;
    }
};
