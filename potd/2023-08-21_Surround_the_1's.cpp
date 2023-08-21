/*
Given a matrix of order nxm, composed of only 0's and 1's, 
find the number of 1's in the matrix that are surrounded by an even number (>0) of 0's. 
The surrounding of a cell in the matrix is defined as the elements above, below, on left, 
on right as well as the 4 diagonal elements around the cell of the matrix. 
Hence, the surrounding of any matrix elements is composed of 8 elements. 
Find the number of such 1's.

Example 1:

Input: 
matrix = {{1, 0, 0}, 
          {1, 1, 0}, 
          {0, 1, 0}}
Output: 
1
Explanation: 
1 that occurs in the 1st row and 1st column, has 3 surrounding elements 0,1 and 1. The occurrence of zero is odd. 
1 that occurs in 2nd row and 1st column has 5 surrounding elements 1,0,1,1 and 0. The occurrence of zero is even. 
1 that occurs in 2nd row and 2nd column has 8 surrounding elements. The occurrence of 0 is odd. 
Similarly, for the 1 that occurs in 3rd row and 2nd column, the occurrence of zero in it's 5 surrounding elements is odd. 
Hence, the output is 1.
*/

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size();
        int m=matrix[0].size();
        int res=0,zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                zero=0;
                if(matrix[i][j]==1){
                    if(i-1>=0 && matrix[i-1][j]==0)zero++;
                    if(i+1<=n-1 && matrix[i+1][j]==0)zero++;
                    if(j-1>=0 && matrix[i][j-1]==0)zero++;
                    if(j+1<=m-1 && matrix[i][j+1]==0)zero++;
                    if(i-1>=0 && j-1>=0 && matrix[i-1][j-1]==0)zero++;
                    if(i+1<=n-1 && j+1<=m-1 && matrix[i+1][j+1]==0)zero++;
                    if(i-1>=0 && j+1<=m-1 && matrix[i-1][j+1]==0)zero++;
                    if(i+1<=n-1 && j-1>=0 && matrix[i+1][j-1]==0)zero++;
                    // cout<<zero<<" "<<i<<" "<<j<<endl;
                    if(zero>0 and zero%2==0) res++;    
                }
            }
        }
        return res;
    }
};
