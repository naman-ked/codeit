/*
There are M job applicants and N jobs.  
Each applicant has a subset of jobs that he/she is interested in.
Each job opening can only accept one applicant and a job applicant can be appointed for only one job. 
Given a matrix G with M rows and N columns where G(i,j) denotes ith applicant is interested in the jth job. 
Find the maximum number of applicants who can get the job.

Example 1:

Input: 
M = 3, N = 5
G = {{1,1,0,1,1},{0,1,0,0,1},{1,1,0,1,1}}
Output: 3
Explanation: There is one of the possible assignment- First applicant gets the 1st job. Second applicant gets the 2nd job. Third applicant gets the 4th job.

*/
class Solution {
public:
	 int maximumMatch(vector<vector<int>>&G){
        int m = G.size();
        int n = G[0].size();
        int match[n];
        memset(match, -1, sizeof(match)); //setting all values of array to -1
        int res = 0;
        for (int i = 0; i < m; i++) {  //no of job applicants loop
            vector<bool> used(n, false);     
            if (dfs(G, i, used, match)) res++;
        }
        return res;
    }

    //arrays are always pass by reference
    bool dfs(vector<vector<int>>& G, int u, vector<bool>& used, int match[]) {
        
        for (int v = 0; v < G[0].size(); v++) {       //no of jobs loop
            if (G[u][v] == 1 && !used[v]) {
                    used[v] = true;
                    
                    if (match[v] == -1 || dfs(G, match[v], used, match)) {  
                        //checking if the assigned value to match can be assigned another job
                        match[v] = u;
                        return true;
                    }
                }
            }
        return false;
        } 
   };
