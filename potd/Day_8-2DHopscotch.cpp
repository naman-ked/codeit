class Solution{
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        int count=0;
        if(ty==0)
        {
            //if column index is odd
            if(j&1)
            {
                if(i+1<n)count+=mat[i+1][j];
                if(i-1>=0)count+=mat[i-1][j];
                if(i+1<n and j+1<m)count+=mat[i+1][j+1];
                if(i+1<n and j-1>=0)count+=mat[i+1][j-1];
                if(j+1<m)count+=mat[i][j+1];
                if(j-1>=0)count+=mat[i][j-1];
            }
            else
            {
                if(i+1<n)count+=mat[i+1][j];
                if(i-1>=0)count+=mat[i-1][j];
                if(i-1>=0 and j-1>=0)count+=mat[i-1][j-1];
                if(i-1>=0 and j+1<m)count+=mat[i-1][j+1];
                if(j+1<m)count+=mat[i][j+1];
                if(j-1>=0)count+=mat[i][j-1];
            }
        }
        else
        {
            //if ty==1 then we can move two steps
            
            if(j&1)
            {
                if(i+2<n)count+=mat[i+2][j];
                if(i-2>=0)count+=mat[i-2][j];
                if(i-1>=0 and j-1>=0)count+=mat[i-1][j-1];
                if(i-1>=0 and j+1<m)count+=mat[i-1][j+1];
                if(j+2<m)count+=mat[i][j+2];
                if(j-2>=0)count+=mat[i][j-2];
                if(i+1<n and j+2<m)count+=mat[i+1][j+2];
                if(i+1<n and j-2>=0)count+=mat[i+1][j-2];
                if(i+2<n and j+1<m)count+=mat[i+2][j+1];
                if(i+2<n and j-1>=0)count+=mat[i+2][j-1];
                if(j+2<m and i-1>=0)count+=mat[i-1][j+2];
                if(j-2>=0 and i-1>=0)count+=mat[i-1][j-2];
            }
            else
            {
                if(i+2<n)count+=mat[i+2][j];
                if(i-2>=0)count+=mat[i-2][j];
                if(i+1<n and j+1<m)count+=mat[i+1][j+1];
                if(i+1<n and j-1>=0)count+=mat[i+1][j-1];
                if(j+2<m)count+=mat[i][j+2];
                if(j-2>=0)count+=mat[i][j-2];
                if(i-1>=0 and j+2<m)count+=mat[i-1][j+2];
                if(i-1>=0 and j-2>=0)count+=mat[i-1][j-2];
                if(i-2>=0 and j+1<m)count+=mat[i-2][j+1];
                if(i-2>=0 and j-1>=0)count+=mat[i-2][j-1];
                if(j+2<m and i+1<n)count+=mat[i+1][j+2];
                if(j-2>=0 and i+1<n)count+=mat[i+1][j-2];
                
            }
        }
        return count;
    }
};
