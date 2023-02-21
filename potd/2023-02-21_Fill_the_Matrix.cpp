/*
Given a matrix with dimensions N x M, entirely filled with zeroes except for one position at co-ordinates X and Y containing '1'.
Find the minimum number of iterations in which the whole matrix can be filled with ones.
Note: In one iteration, '1' can be filled in the 4 neighbouring elements of a cell containing '1'.

Example 1:
Input:
N = 2, M = 3
X = 2, Y = 3
Output: 3 
*/

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        //first approach
        int r,c;
        r=max(x-1,N-x);
        c=max(y-1,M-y);
        return r+c;
        //second approach
        vector<vector<int>> arr;
        for(int i=0;i<N;i++){
             vector<int> a(M,0);
             arr.push_back(a);
        }
          
        queue<pair<int, int> > q;
        q.push({x-1, y-1});
        int i,j,count=0;
        while(!q.empty()){ 
            count++;
            int n=q.size();
            while(n>0){
                tie(i, j) = q.front(); q.pop();
                n--;
                if(arr[i][j]==1) continue;
                arr[i][j] = 1;
                if(i + 1 <  N and arr[i+1][j]==0) q.push({i + 1, j});
                if(i - 1 >= 0 and arr[i-1][j]==0) q.push({i - 1, j});
                if(j + 1 <  M and arr[i][j+1]==0) q.push({i, j + 1});
                if(j - 1 >= 0 and arr[i][j-1]==0) q.push({i, j - 1});
            }
        }
        return count-1;
    }
};
