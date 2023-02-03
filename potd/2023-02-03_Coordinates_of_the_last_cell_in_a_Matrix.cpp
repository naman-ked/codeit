/*
Given a binary matrix of dimensions N * M. One can perform the given operation into the matrix.

If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction from up, right, down, or left to
the directions right, down, left, and up respectively.
Initially you start from cell(0, 0), moving in right direction.

The task is to find the indices of the matrix  which leads to outside the matrix from the traversal of the given matrix from the cell (0, 0) 
by performing the operations.

Example 1:

Input:
matrix[][] = {{0,1},{1,0}}
Output: (1,1)
*/
class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int n=matrix.size();
        int m=matrix[0].size();
        char dir='r';
        pair<int,int> res;
        int i=0,j=0;
        while(i>=0 and i<n and j>=0 and j<m){
                res.first = i;  // first part of the pair
                res.second = j; 
                //cout<<i<<" "<<j<<" "<<dir<<" "<<matrix[i][j]<<endl;// second part of the pair
                if(matrix[i][j]==0){
                    if(dir=='r')j++;
                    else if(dir=='d')i++;
                    else if(dir=='u')i--;
                    else if(dir=='l')j--;
                }
                else if(matrix[i][j]==1){
                    matrix[i][j]=0;
                    if(dir=='r'){
                        i++;
                        dir='d';
                    }
                    else if(dir=='d'){
                        j--;
                        dir='l';
                    }
                    else if(dir=='u'){
                        dir='r';
                        j++;
                    }
                    else if(dir=='l'){
                        i--;
                        dir='u';
                    }
                }
        }
        return res;
    }

};
