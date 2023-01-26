/*
Geek is extremely punctual but today even he is not feeling like doing his homework assignment.
He must start doing it immediately in order to meet the deadline. For the assignment, Geek needs to type a string s.
To reduce his workload, he has decided to perform one of the following two operations till he gets the string.
Append a character at the end of the string.
Append the string formed thus far to the end of the string. (This can not be done more than once.)
Help Geek find the minimum operations required to type the given string.

Example 1:
Input:
s = abcabca
Output: 5
Explanation: a -> ab -> abc -> abcabc -> abcabca
*/

class Solution {
  public:
    int minOperation(string s) {
        // code here
        string p="";
        int n=s.length();
        int count=n;
        for(int i=0;i<n;i++){
            p=p+s[i];
            string t  = s.substr(i+1,n);
            int found = t.find(p);
            if (found != string::npos){
                count=min(count,i+2+(n-2*(i+1)));
            }
        }
        return count;
    }
};
