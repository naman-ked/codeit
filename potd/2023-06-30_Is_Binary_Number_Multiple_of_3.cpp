/*
Given a number in its binary form find if the given binary number is a multiple of 3. It is recommended to finish the task using one traversal of input binary number.
Example 1:
Input: S = "0011"
Output: 1
Explanation: "0011" is 3, which is divisible by 3.
*/

class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int sum=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                if(i%2==0)sum+=1;
                else sum+=2;
            }
        }
        return sum%3==0?1:0;
	}
};
