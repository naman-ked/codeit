/*
Given a maze with N cells. Each cell may have multiple entry points but not more than one exit (i.e entry/exit points are unidirectional doors like valves).
You are given an array Edge[] of N integers, where Edge[i] contains the cell index that can be reached from cell i in one step. 
Edge[i] is -1 if the ith cell doesn't have an exit. 
The task is to find the cell with maximum weight (The weight of a cell is the sum of cell indexes of all cells pointing to that cell).
If there are multiple cells with the maximum weight return the cell with highest index.

Note: The cells are indexed with an integer value from 0 to N-1. 
If there is no cell pointing to the ith cell then the weight of the i'th cell is zero.

Example 1:

Input:
N = 4
Edge[] = {2, 0, -1, 2}
Output: 2
Explanation: 
1 -> 0 -> 2 <- 3
weight of 0th cell = 1
weight of 1st cell = 0 
(because there is no cell pointing to the 1st cell)
weight of 2nd cell = 0+3 = 3
weight of 3rd cell = 0
There is only one cell which has maximum weight
(i.e 2) So, cell 2 is the output.

*/
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      unordered_map<int,int> maze;
      
      for(int i=0;i<N;i++){
          if(Edge[i]!=-1){
              maze[Edge[i]]+=i;
          }
      }
      int h1=0,h2=0;
      for(auto m:maze){
          if(m.second>h2){
              h2=m.second;
              h1=m.first;
          }
          else if(m.second==h2)
              h1=max(h1,m.first);
      }
      return h1;
  }
};
