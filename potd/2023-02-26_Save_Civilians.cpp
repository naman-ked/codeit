/*
Some civilians are partying in a grid of dimensions n * m. Some terrorists also sneaked into the party and occupied some cells.
Each cell in the grid will either be empty or can accommodate at most one person which can be either {civilian, terrorist, or soldier}.
Assuming that the terrorists can move in any direction (left, up, right, above) if the corresponding cell is empty or contains a civilian 
find if there exists an arrangement of soldiers such that none of the civilians got harmed or report if that is impossible.
Note:
Initially, no soldiers are on the grid
Soldiers can only be deputed into empty cells. 
Neither of Soldiers or Civilians can't move.
Many braveheart soldiers are there hence you need not minimize the soldiers.
grid[i][j] = 'E' represents an empty cell, grid[i][j] = 'T' represents a terrorist, grid[i][j] = 'C' represents a civiliana, and grid[i][j] = 'S' represents a soldier.

Input:
n = 5, m = 5 
grid = [ [E, E, E, C, E], 
[E, E, C, C, E], 
[E, C, E, E, E], 
[E, E, T, T, E], 
[E, E, E, E, E]]
Output:Possible

*/

class Solution {
  public:
    bool saveCivilians(int n, int m, vector<string> &grid) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='E')grid[i][j]='S';
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='T'){
                    if(i<n-1 and grid[i+1][j]=='C')return 0;
                    else if(i>0 and grid[i-1][j]=='C')return 0;
                    else if(j>0 and grid[i][j-1]=='C')return 0;
                    else if(j<m-1 and grid[i][j+1]=='C') return 0;
            }
        }
    }
    return 1;
    }
};
