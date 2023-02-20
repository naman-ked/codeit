/*
Given a triangular pyramid with its vertices marked as O, A, B and C and a number N,
the task is to find the number of ways such that a person starting from the origin O initially, reaches back to the origin in N steps. 
In a single step, a person can go to any of its adjacent vertices.

Example 1:
Input:
N = 1
Output: 0
Explanation: The minimum length of a cyclic path is 2.

Example 2:
Input:
N = 2
Output: 3
Explanation: The three paths are : O-A-O, O-B-O, O-C-O
*/

class Solution{   
public:
    
    int countPaths(int N){
        // code here 
        int M = 1e9 + 7;
        long long a = 0, b = 1, x = 0;
        while(--N)
        {
            a = (3*b)%M; b = (2*b+x)%M;
            x = a;
        }
        return a;
    }
}
