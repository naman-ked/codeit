/*
A special compression mechanism can arbitrarily delete 0 or more characters and replace them with the deleted character count.
Given two strings, S and T where S is a normal string and T is a compressed string, determine if the compressed string  T is valid for the plaintext string S. 

Example 1:
Input:
S = "GEEKSFORGEEKS"
T = "G7G3S"
Output: 1
Explanation: We can clearly see that T is a valid compressed string for S.

Example 2:
Input:
S = "DFS"
T = "D1D"
Output : 0
Explanation: T is not a valid compressed string.
*/

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int n=T.length();
        int c=0;
        int x=0;
        for(int i=0;i<n;i++){
            if(isdigit(T[i])){
                x=x*10+(int(T[i]-'0'));
            }
            else{
              c=c+x;            
              if(i<n and S[c]!=T[i]) return 0; 
              x=0;
              c++;
            } 
        }
        c=c+x;
        if(c==S.length()) return 1;
        return 0;
    }
};
