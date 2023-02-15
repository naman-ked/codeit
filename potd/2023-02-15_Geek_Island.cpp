/*
Geeks Island is represented by an N * M matrix mat. 
The island is touched by the Indian Ocean from the top and left edges and the Arabian Sea from the right and bottom edges.
Each element of the matrix represents the height of the cell.
Due to the rainy season, the island receives a lot of rainfall, and the water can flow in four directions(up, down, left, or right) from one cell to another 
one with height equal or lower.
You need to find the number of cells from where water can flow to both the Indian Ocean and the Arabian Sea.

Example 1:
Input:
N = 5, M = 5
mat[][] =    {{1, 3, 3, 2, 4},
               {4, 5, 6, 4, 4},
               {2, 4, 5, 3, 1},
               {6, 7, 1, 4, 5},
               {6, 1, 1, 3, 4}}
Output:
8
Explanation:
Indian    ~   ~   ~   ~   ~
Ocean  ~  1   3   3   2  (4) *
        ~  4   5  (6) (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (6)  1   1   3   4  *           
           *   *   *   *   * Arabian Sea
Water can flow to both ocean and sea from the cells
denoted by parantheses().For example at index(1,2), the height of that island is 6. 
If a water drop falls on that island, water can flow to up direction(as 3<=6) and reach to Indian Ocean. 
ALso, water can flow to right direction(as 6>=4>=4) and reach to Arabian Sea.
*/

class Solution{   
public:
    int m, n;
    int ans=0;
    vector<vector<bool> > arb, ind;
    queue<pair<int, int> > q;
    int water_flow(vector<vector<int>> &mat,int N,int M){
    m=N;
    n=M;
    // Write your code here.
    if(mat.size()==0) return ans;
    ind = arb = vector<vector<bool>>(m,vector<bool>(n, false));
    for(int i=0; i<m; i++) bfs(mat, ind, i, 0), bfs(mat,arb, i, n-1);
    for(int i=0; i<n; i++) bfs(mat, ind, 0, i), bfs(mat,arb, m-1, i);             
    return ans;
    }
    
    void bfs(vector<vector<int>>& mat,vector<vector<bool>>& visited, int i, int j){        
        q.push({i, j});
        while(!q.empty()){
            cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
            tie(i, j) = q.front(); q.pop();
            if(visited[i][j]) continue;
            visited[i][j] = true;
            if(arb[i][j] && ind[i][j]) ans++;
            if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) q.push({i + 1, j});
            if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) q.push({i - 1, j});
            if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) q.push({i, j + 1});
            if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) q.push({i, j - 1});
        }
    }
};
