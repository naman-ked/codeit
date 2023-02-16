/*
Geek is in a geekland which have a river and some stones in it.
Initially geek can step on any stone. Each stone has a number on it representing the value of exact step geek can move. 
If the number is +ve then geeks can move right and if the number is -ve then geeks can move left. 
Bad Stones are defined as the stones in which if geeks steps, will reach a never ending loop whereas good stones are the stones which are safe from never ending loops.
Return the number of good stones in river.

Example 1:
Input: [2, 3, -1, 2, -2, 4, 1]
Output: 3
Explanation: Index 3, 5 and 6 are safe only. As index 1, 4, 2 forms a cycle and from index 0 you can go to index 2 which is part of cycle.

Example 2:
Input: [1, 0, -3, 0, -5, 0]
Output: 2
Explanation: Index 2 and 4 are safe only. As index 0, 1, 3, 5 form cycle.
*/

class Solution{
public:
    //dfs since it mentioned graph in topic tag so it hinted me we could solve it through dfs
    int dfs(vector<int> &arr,vector<bool> &visited,int i,int n,int res,unordered_set<int> &good){
        
        visited[i]=true;
        res++;
        int x=i+arr[i];
        //cout<<x<<endl;    debugging
        if(x==i) return 0;
        if(x>=0 and x<n){
            if(!visited[x]) res=dfs(arr,visited,x,n,res,good);
            else if(good.find(x)!=good.end()) good.insert(i);
            else res=0;
        }
        if(res>0)good.insert(i);
        //cout<<i<<" "<<arr[i]<<" "<<res<<endl;   debugging
        return res;
    }
    
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<bool> visited(n+1,false);
        unordered_set<int> good;   //set for manintaing the good stones
        int count=0; //number of good stones
        for(int i=0;i<n;i++){
            if(!visited[i]) count+=dfs(arr,visited,i,n,0,good);
        }
        return count;
    }  
};
