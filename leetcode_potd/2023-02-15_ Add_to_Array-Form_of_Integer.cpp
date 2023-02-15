/*
The array-form of an integer num is an array representing its digits in left to right order.
For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

Example 1:
Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:
Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:
Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size()-1;
        int res=0,carry=0;
        int i=n;
        vector<int> ans;
        while(i>=0 or k>0){
            if(i>=0)res=num[i]+(k%10)+carry;
            else res=(k%10)+carry;
            if(res<10){
                carry=0;
                ans.push_back(res);
            }
            else{
                ans.push_back(res%10);
                carry=1;
            }
            k=k/10;
            i--;
        }
        reverse(ans.begin(),ans.end());
        if(carry==1)ans.insert(ans.begin(),carry);
        return ans;

    }
};
