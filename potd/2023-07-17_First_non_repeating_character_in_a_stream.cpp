/*
Given an input stream A of n characters consisting only of lower case alphabets. 
While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point.
If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. 
If there is no such character then append '#' to the answer.

Example 1:
Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
*/

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>v(26,-1);
            string res = "";
            for(int i = 0;i<A.size();i++){
                if(v[A[i]-'a']==-1)v[A[i]-'a'] = i;
                else v[A[i]-'a']=INT_MAX;
                int j,temp = INT_MAX;
                for(j = 0;j<26;j++){
                    if(v[j]!=-1)temp = min(temp,v[j]);
                }
                if(temp==INT_MAX)res+='#';
                else res+=A[temp];
            }
            return res;
		}
};
