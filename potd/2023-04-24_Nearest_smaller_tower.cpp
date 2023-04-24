/*
Given an array where each element (arr[i]) represents the height of the tower. 
Find for each tower, the nearest possible tower that is shorter than it. You can look left or right on both sides.
Note : 
If two smaller towers are at the same distance, pick the smallest tower.
If two towers have the same height then we choose the one with a smaller index.

Example 1:
Input: arr[] = {1,3,2}
Output: {-1,0,0}
Explanation: For 0th Index : no tower is smallest, so -1. For 1st Index : For 3, here 1 & 2 both are small & at a same distance, so we will pick 1,
beacuse it has smallest value, so 0(Index) For 2nd Index : here 1 is smaller, so 0(Index) So the final output will be which consistes Indexes are {-1,0,0}.
*/

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n=arr.size();
        vector<int> r;
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(!s.empty()){
                while(!s.empty() and arr[s.top()]>=arr[i])s.pop();
            }    
            if(s.empty())r.push_back(-1);
            else r.push_back(s.top());
            s.push(i);
        }
        reverse(r.begin(), r.end());
        
        vector<int> l;
        stack<int> s2;
        for(int i=0;i<n;i++){
            if(!s2.empty()){
                while(!s2.empty() and arr[s2.top()]>=arr[i])s2.pop();
            }    
            if(s2.empty())l.push_back(-1);
            else l.push_back(s2.top());
            s2.push(i);
        }
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(l[i]==-1 and r[i]==-1) res.push_back(-1);
            else if(l[i]!=-1 and r[i]==-1) res.push_back(l[i]);
            else if(r[i]!=-1 and l[i]==-1) res.push_back(r[i]);
            else {
                if(i-l[i]==r[i]-i){
                    if(arr[l[i]]<=arr[r[i]])res.push_back(l[i]);
                    else res.push_back(r[i]);
                }
                else if(i-l[i]<r[i]-i)res.push_back(l[i]);
                else res.push_back(r[i]);
            }
        }
        return res;
    }
};
