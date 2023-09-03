/*
A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. 
Given a square matrix of size NxN. 
Find the minimum number of operation(s) that are required to make the matrix beautiful. 
In one operation you can increment the value of any one cell by 1.

Example 1:
Input:  N = 2
matrix[][] = {{1, 2},{3, 4}}
Output: 4
Explanation:
Updated matrix:
4 3
3 4
1. Increment value of cell(0, 0) by 3
2. Increment value of cell(0, 1) by 1
Hence total 4 operation are required.
*/



class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here .
            vector<int> vec,vec1;

        int sum=0,ans=0,mx=0;
        int sum1=0,ans1=0,mx1=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=matrix[ i ][ j ];
                sum1+=matrix[ j ][i ];
            }

            vec.push_back(sum);
            vec1.push_back(sum1);

            sum=0;
            sum1=0;
        }
        
        mx=*max_element(vec.begin(),vec.end());
        mx1=*max_element(vec1.begin(),vec1.end());
        
        for(int i=0;i<n;i++)
        {
            ans+=mx-vec[i];
            ans1+=mx1-vec1[i];
        }

        return max(ans,ans1);
    } 
};
