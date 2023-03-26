/*
You are given an array arr of n strings. 
The strings consist of lowercase Latin letters. 
The value of each string is defined as the difference between the number of consonants and vowels.
You have to find the string with the maximum value. 
If there is a tie between some strings, the first one should be returned.
Input:
n = 3
arr = {"house","car","tree"}
Output: "house"
Explanation: The strings "house" and "car" both have value 1. So, "house" should be answer.
*/

class Solution {
  public:
    string valuableString(int n, vector<string> &arr) {
        // code here
       
        int v=-1;
        string res="";
        for(string s:arr){
              int co=0,vo=0;
            for(char c:s){
                if(c!='a' and c!='e' and c!='i' and c!='o' and c!='u')
                co++;
                else vo++;
            }
            if(abs(vo-co)>v){
                v=abs(vo-co);
                res=s;
            }
        }
        return res;
    }
};
