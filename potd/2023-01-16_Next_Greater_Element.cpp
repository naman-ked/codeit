/*
Given an array arr[ ] of size n having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance
in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, 
next greater of the last element is always -1.

Example 1:

Input: 
n = 4,
arr[] = [1 3 2 4]
Output:
3 4 4 -1
*/

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long int> res;
        stack<long long int> st;
        for(int i=n-1;i>=0;i--){
            int temp=-1;
            if(!st.empty()){
                while(!st.empty() and st.top()<arr[i]) st.pop();
            }
            if(st.empty())res.push_back(-1);
            else res.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
