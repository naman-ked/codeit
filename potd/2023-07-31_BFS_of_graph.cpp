/*
Given a directed graph. The task is to do the Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. 
Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. 
Also, you should only take nodes directly or indirectly connected from Node 0 into consideration.
Input:
Output: 0 1 2 3 4
Explanation: 
0 is connected to 1,2, and 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of a given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool visited[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        visited[0]=true;
        queue<int> q;
        q.push(0);
        vector<int> res;
        while(!q.empty()){
            
            int u=q.front();
            q.pop();
            res.push_back(u);
            
            for(int x:adj[u]){
                if(visited[x]==false){
                    visited[x]=true;
                    q.push(x);
                }
            }
            
        }
        return res;
    }
};
