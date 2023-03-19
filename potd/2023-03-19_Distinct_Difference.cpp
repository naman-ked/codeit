/*
Given an array A[] of length N. For each index i (1<=i<=N), find the diffference between the number of distinct element in it's left and right side in the array. 

Example 1:
Input:
N = 3
arr[] = {4, 3, 3}
Output: {-1, 0, 2}
Explanation: For index i=1, there are 0 distinct element in the left side of it, and 1 distinct element(3) in it's right side. So difference is 0-1 = -1. 
Similarly for index i=2, there is 1 distinct element (4) in left side of it, and 1 distinct element(3) in it's right side. So difference is 1-1 = 0.
Similarly for index i=3, there are 2 distinct elements (4 and 3) in 
*/

class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int> b;
        unordered_map<int,int> s;
        unordered_set<int> s2;
        
        for(int a:A)s[a]++;
        
        for(int a:A){
            if(s[a]==1) s.erase(a);
            else s[a]--;
            b.push_back(s2.size()-s.size());
            s2.insert(a);
        }
        return b;
    }
};
