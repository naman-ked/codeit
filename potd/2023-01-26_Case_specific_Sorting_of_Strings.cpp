/*
Given a string S consisting of only uppercase and lowercase characters. 
The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character
then it should not have a lowercase character after being sorted and vice versa.

Example 1:
Input:
N = 12
S = defRTSersUXI
Output: deeIRSfrsTUX
Explanation: Sorted form of given string with the same case of character as that in original string is deeIRSfrsTUX
*/

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {     
        int u=0,l=0;
        string res="";
        string uch="",lch="";
        for(int i=0;i<n;i++){
            char ch=str[i];
            if(ch >= 'A' && ch <= 'Z')uch+=ch;
            else lch+=ch;
        }
        sort(uch.begin(), uch.end());
        sort(lch.begin(), lch.end());
        for(int i=0;i<n;i++){
            char ch=str[i];
            if(ch >= 'A' && ch <= 'Z'){
                res+=uch[u];u++;
            }
            else{
                res+=lch[l];l++;
            }
        }
        return res;
    }
};
