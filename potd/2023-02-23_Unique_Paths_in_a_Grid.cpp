/*
You are given a matrix grid of n x  m size consisting of values 0 and 1.
A value of 1 means that you can enter that cell and 0 implies that entry to that cell is not allowed.
You start at the upper-left corner of the grid (1, 1) and you have to reach the bottom-right corner (n, m) such that you can only 
move in the right or down direction from every cell.
Your task is to calculate the total number of ways of reaching the target modulo (109+7).
Note: The first (1, 1) and last cell (n, m) of the grid can also be 0

Example 1:
Input:
n = 3, m = 3
grid[][] = {{1, 1, 1};
            {1, 0, 1};
            {1, 1, 1}}
Output:
2
Explanation:
1 1 1
1 0 1
1 1 1 This is one possible path.
1 1 1
1 0 1
1 1 1 This is another possible path.
*/

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        int mod=pow(10,9)+7;
        int N=grid.size();
        int M=grid[0].size();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]!=0){
                    if(i==0 and j!=0 and grid[i][j-1]==0) grid[i][j]=0;
                    else if(j==0 and i!=0 and grid[i-1][j]==0)grid[i][j]=0;
                    else if(i!=0 and j!=0)grid[i][j]=(grid[i-1][j] + grid[i][j-1])%mod;
                }
            }
        }
        return grid[n-1][m-1];
    }
};
