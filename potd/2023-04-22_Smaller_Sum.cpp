/*
You are given an array arr of n integers. 
For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].

Example 1:
Input:
n = 3
arr = {1, 2, 3}
Output: 0 1 3
Explanation: For 1, there are no elements lesser than itself. For 2, only 1 is lesser than 2. And for 3, 1 and 2 are lesser than 3, so the sum is 3.
*/

class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        unordered_map<int,long long> s;
        for(int a:arr){
            s[a]++;
        }
        
        vector<int> a;
        for (auto i : s){
            a.push_back(i.first);
        }
        sort(a.begin(),a.end());
        
        long long sum=0;
        unordered_map<int,long long> m;
        for(int b:a){
            m[b]=sum;
            sum+=(b*s[b]);
        }
        vector<long long> res;
        for(int b:arr){
            res.push_back(m[b]);
        }
        return res;
    }
};
