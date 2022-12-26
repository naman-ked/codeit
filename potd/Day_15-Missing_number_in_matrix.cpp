/*
Given a matrix of size n x n such that it has only one 0, Find the positive number (greater than zero) to be placed in place of the 0 such that sum of the numbers in every row, column and two diagonals become equal. If no such number exists, return -1.

Note: Diagonals should be only of the form matrix[i][i] and matrix[i][n-i-1]. n is always greater than 1.
 

Example 1:

Input: matrix = {{5, 5}, {5, 0}}
Output: 5
Explanation: The matrix is
5 5
5 0
Therefore If we place 5 instead of 0, all
the element of matrix will become 5. 
Therefore row 5+5=10, column 5+5=10 and 
diagonal 5+5=10, all are equal.
*/
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        
        long long int row_sum=0,sum=0;
        long long int res=0;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<n;j++){
                sum+=matrix[i][j];
            }
        if(row_sum==0) row_sum=sum;
        else if(row_sum!=sum and res==0){
            res=abs(row_sum-sum);
            break;
        }
        }
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][j]=res;break;
                    
                }
            }
        }
        
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<n;j++){
                sum=sum+matrix[i][j];
            }
            s.insert(sum);
        }
        
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<n;j++){
                sum=sum+matrix[j][i];
            }
            s.insert(sum);
        }
        sum=0;
        for(int i=0;i<n;i++){
                sum=sum+matrix[i][i];
            }
        s.insert(sum);
        sum=0;
        for(int i=0;i<n;i++){
                sum=sum+matrix[i][n-i-1];
            }
        s.insert(sum);
        if(res==0 or s.size()!=1)return -1;
        return res;
        
    }
};
