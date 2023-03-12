/*
Given a binary matrix (containing only 0 and 1) of order NxN. All rows are sorted already,
We need to find the row number with the maximum number of 1s. Also, find the number of 1s in that row.
Note:
1. In case of a tie, print the smaller row number.
2. Row number should start from 0th index.

Example 1
Input:
N=3
mat[3][3] = {0, 0, 1, 
              0, 1, 1, 
              0, 0, 0}
Output:
Row number = 1
MaxCount = 2
Explanation: Here, max number of 1s is in row number 1and its count is 2.
*/
class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int i=0;
        int j=N-1;
        int m=N;
        int row=0;
        while(i<N and j>=0){
            if(mat[i][j]==1){
                m=min(m,j);
                row=i;
                j--;
            }
            else i++;
        }
        return {row,N-m};
    }
};
