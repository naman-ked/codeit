/** Given two binary strings A and B consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.


Example 1:

Input:
A = "1101", B = "111"
Output: 10100
**/

class Solution{
public:	
	string addBinary(string a, string b)
	{
	    int i = a.length()-1;
        int j = b.length()-1;
        string ans;
        int carry = 0;
        
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry += a[i] - '0';
                i--;
            }
            if(j>=0){
                carry += b[j] - '0';
                j--;
            }
            
            ans += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        int c=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                break;
            }
            c++;
        }
        ans=ans.substr(c);
        return ans;
	}
};
