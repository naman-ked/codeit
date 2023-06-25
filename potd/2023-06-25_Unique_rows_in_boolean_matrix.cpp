/*
Given a binary matrix your task is to find all unique rows of the given matrix in the order of their appearance in the matrix.

Example 1:
Input:
row = 3, col = 4 
M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
Output: $1 1 0 1 $1 0 0 1 $
Explanation: Above the matrix of size 3x4 looks like
1 1 0 1
1 0 0 1
1 1 0 1
The two unique rows are R1: {1 1 0 1} and R2: {1 0 0 1}.  As R1 first appeared at row-0 and R2 appeared at row-1, in the resulting list, R1 is kept before R2.
*/

class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        vector<vector<int>> res;
        unordered_set<string> s;
        for(int i=0;i<row;i++){
            vector<int> b;
            string str="";
            for(int j=0;j<col;j++){
                str+=M[i][j];
                b.push_back(M[i][j]);
            }
            if(s.find(str)==s.end()){
                s.insert(str);
                res.push_back(b);
            }
        }
        return res;
    }
};
