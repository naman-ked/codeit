/*
Given N nodes of a tree and a list of edges. Find the minimum number of nodes to be selected to light up all the edges of the tree.
An edge lights up when at least one node at the end of the edge is selected.

Example 1:
Input:
N = 6
edges[] = {(1,2), (1,3), (2,4), (3,5), (3,6)}
Output: 2
Explanation: Selecting nodes 2 and 3 lights up all the edges.

Example 2:
Input:
N = 3
arr[] = {(1,2), (1,3)}
Output: 1
Explanation: Selecting Node 1 lights up all the edges.
*/

class Solution{
  public:
    vector<int>vis;
    int count=0;
    
    bool dfs(vector<int>adj[], int i)
    {
      vis[i]=1;
      bool select=false;
      for(auto child:adj[i])
      {
          if(!vis[child] and !dfs(adj,child))select=true;   
      }
      if(select)count++;
      return select;
  }
    
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vis=vector<int>(N+1,0);
        vector<int> adj[N+1];
        for(auto ele:edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        dfs(adj,1);
        return count;
    }
};
